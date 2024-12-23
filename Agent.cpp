#include "Agent.h"

#include <cstdio>

#include "CoastlineTrader.h"
#include "EventDetector.h"
#include "InventoryManager.h"
#include "Price.h"
#include "ProbabilityIndicator.h"

Agent::Agent(int mode, double delta, double unitSize)
    : eventDetector(delta, delta),
      coastlineTrader(mode),
      mode(mode),
      probabilityIndicator(50.0, delta),
      inventoryManager(unitSize),
      deltaOriginal(delta) {}

void Agent::adjustThresholds() {
  double inventorySize = inventoryManager.getInventorySize() * (double)mode;

  if (inventorySize >= 15.0 && inventorySize < 30.0) {
    eventDetector.updateDelta(0.75 * deltaOriginal, 1.5 * deltaOriginal);
    fraction = 0.5;
  } else if (inventorySize >= 30.0) {
    eventDetector.updateDelta(0.5 * deltaOriginal, 2.0 * deltaOriginal);
    fraction = 0.25;
  } else if (inventorySize <= -15.0 && inventorySize > -30.0) {
    eventDetector.updateDelta(1.5 * deltaOriginal, 0.75 * deltaOriginal);
    fraction = 0.5;
  } else if (inventorySize <= -30.0) {
    eventDetector.updateDelta(2.0 * deltaOriginal, 0.5 * deltaOriginal);
    fraction = 0.25;
  } else {
    eventDetector.updateDelta(deltaOriginal, deltaOriginal);
    fraction = 1.0;
  }
}

void Agent::run(Price price) {
  int intrinsicEvent = eventDetector.detectEvent(price.price);
  int action =
      coastlineTrader.run(intrinsicEvent, price.price, inventoryManager);

  int probabilityIndicatorEvent =
      eventDetector.detectProbabilityIndicatorEvent(price.price);
  probabilityIndicator.updateProbabilityIndicator(probabilityIndicatorEvent);

  if (action == 1) {
    inventoryManager.updateUnitSize(
        probabilityIndicator.getProbabilityIndicator());
    inventoryManager.buyOrder(price.price, fraction);
    adjustThresholds();
    printf("current inventory: %f\r\n", inventoryManager.getInventorySize());
  } else if (action == -1) {
    inventoryManager.sellPosition(price.price);
    adjustThresholds();
  }
}
