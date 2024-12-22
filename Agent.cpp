#include "Agent.h"

#include <cstdio>

#include "CoastlineTrader.h"
#include "EventDetector.h"
#include "InventoryManager.h"
#include "Price.h"
#include "ProbabilityIndicator.h"

Agent::Agent(bool mode, double deltaUp, double deltaDown, double unitSize)
    : eventDetector(deltaUp, deltaDown),
      coastlineTrader(mode),
      mode(mode),
      probabilityIndicator(50.0, deltaUp),
      inventoryManager(unitSize) {}

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
    inventoryManager.buyOrder(price.price);
    // TODO implement threshold adjustment
    printf("current inventory: %f\r\n", inventoryManager.getInventorySize());
  } else if (action == -1) {
    inventoryManager.sellPosition(price.price);
    // TODO implement threshold adjustment
  }
}
