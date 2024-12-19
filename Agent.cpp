#include "Agent.h"

#include <cstdio>

#include "CoastlineTrader.h"
#include "EventDetector.h"
#include "Price.h"

Agent::Agent(bool mode, double delta)
    : eventDetector(delta), coastlineTrader(mode), mode(mode) {}

void Agent::run(Price price) {
  int intrinsicEvent = eventDetector.detectEvent(price.price);
  int action = coastlineTrader.run(intrinsicEvent);

  // TODO implement liquidity

  if (action == 1) {
    // TODO implement buy
    printf("buy\r\n");
  } else if (action == -1) {
    // TODO implement sell
    printf("sell\r\n");
  }
}
