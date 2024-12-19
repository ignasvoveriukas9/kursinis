#ifndef COASTLINETRADER_H
#define COASTLINETRADER_H

#include <cwchar>

#include "EventDetector.h"
#include "Price.h"

class CoastlineTrader {
 private:
  bool mode;

 public:
  // mode true for long false for short
  CoastlineTrader(bool mode);
  // 1 buy, -1 sell, 0 do nothing
  int run(int event);
};

#endif  // !COASTLINETRADER_H