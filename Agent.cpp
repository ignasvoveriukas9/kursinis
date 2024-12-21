#include "Agent.h"

#include <cstdio>

#include "CoastlineTrader.h"
#include "EventDetector.h"
#include "Price.h"
#include "ProbabilityIndicator.h"

Agent::Agent(bool mode, double deltaUp, double deltaDown)
    : eventDetector(deltaUp, deltaDown),
      coastlineTrader(mode),
      mode(mode),
      probabilityIndicator(50.0, deltaUp) {}

void Agent::run(Price price) {
  int intrinsicEvent = eventDetector.detectEvent(price.price);
  int action = coastlineTrader.run(intrinsicEvent);

  int probabilityIndicatorEvent =
      eventDetector.detectProbabilityIndicatorEvent(price.price);
  probabilityIndicator.updateProbabilityIndicator(probabilityIndicatorEvent);

  if (action == 1) {
    // TODO implement buy
    printf("buy\r\n");
  } else if (action == -1) {
    // TODO implement sell
    printf("sell\r\n");
  }
}
