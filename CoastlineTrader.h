#ifndef COASTLINETRADER_H
#define COASTLINETRADER_H

#include "EventDetector.h"
#include "Price.h"

class CoastlineTrader {
 private:
  bool mode;
  double delta;
  EventDetector eventDetector;

 public:
  // mode true for long false for short
  CoastlineTrader(double delta, bool mode);
  void run(Price price);
};

#endif  // !COASTLINETRADER_H
