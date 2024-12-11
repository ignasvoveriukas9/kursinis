#ifndef EVENTDETECTOR_H
#define EVENTDETECTOR_H

#include <sys/types.h>

#include <random>
class EventDetector {
 private:
  int mode;
  double extreme;
  double referance;
  double delta;
  bool initalized = false;

  void init(double price);

 public:
  EventDetector(double delta);
  int getIntrinsicEvent(double price);
};

#endif
