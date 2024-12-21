#ifndef AGENT_H
#define AGENT_H

#include "CoastlineTrader.h"
#include "EventDetector.h"
#include "Price.h"
#include "ProbabilityIndicator.h"

class Agent {
 private:
  EventDetector eventDetector;
  CoastlineTrader coastlineTrader;
  ProbabilityIndicator probabilityIndicator;
  // true for long, false for short
  bool mode;
  double deltaUp, deltaDown;

 public:
  Agent(bool mode, double deltaUp, double deltaDown);
  void run(Price price);
};

#endif  // !AGENT_H
