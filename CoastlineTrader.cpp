#include "CoastlineTrader.h"

#include <cstdio>

#include "EventDetector.h"
#include "Price.h"

CoastlineTrader::CoastlineTrader(double delta, bool mode)
    : eventDetector(EventDetector(delta)), delta(delta), mode(mode) {}

void CoastlineTrader::run(Price price) {
  int event = eventDetector.getIntrinsicEvent(price.price);

  // Long
  if (mode) {
    if (event < 0) {
      // TODO implement buy
      printf("Buy long\r\n");
    } else if (event == 2 && true) {  // TODO implement isProfitable
      // TODO implemnt sell
      printf("Sell long\r\n");
    }
  } else {  // Short
    if (event > 0) {
      // TODO implement buy
      printf("Buy short\r\n");
    } else if (event == -2 && true) {  // TODO implement isProfitable
      // TODO implement sell
      printf("Sell short\r\n");
    }
  }
}
