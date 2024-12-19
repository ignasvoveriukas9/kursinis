#include "CoastlineTrader.h"

#include <cstdio>

CoastlineTrader::CoastlineTrader(bool mode) : mode(mode) {}

int CoastlineTrader::run(int event) {
  // Long
  if (mode) {
    if (event < 0) {
      return 1;
    } else if (event == 2 && true) {  // TODO implement isProfitable
      return -1;
    }
  } else {  // Short
    if (event > 0) {
      return 1;
    } else if (event == -2 && true) {  // TODO implement isProfitable
      return -1;
    }
  }

  return 0;
}
