#ifndef AGENT_H
#define AGENT_H

#include "CoastlineTrader.h"
#include "EventDetector.h"
#include "Price.h"

class Agent {
 private:
  EventDetector eventDetector;
  CoastlineTrader coastlineTrader;
  // true for long, false for short
  bool mode;

 public:
  Agent(bool mode, double delta);
  void run(Price price);
};

#endif  // !AGENT_H
