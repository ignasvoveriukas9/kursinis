#include "EventDetector.h"

EventDetector::EventDetector(double delta) : delta(delta) {}

void EventDetector::init(double price) {
  mode = 1;
  extreme = price;
  referance = price;
  initalized = true;
}

int EventDetector::getIntrinsicEvent(double price) {
  if (!initalized) {
    init(price);
  }

  if (mode == 1) {
    if (price > extreme) {
      extreme = price;
      if (((price - referance) / referance) > delta) {
        referance = extreme;
        // Up Overshoot
        return 2;
      }
    } else if (((price - extreme) / extreme) < -delta) {
      extreme = price;
      referance = price;
      mode = -1;
      // Directional Change Down
      return 1;
    }
  } else if (mode == -1) {
    if (price < extreme) {
      extreme = price;
      if (((price - referance) / referance) < -delta) {
        referance = extreme;
        // Down Overshoot
        return -2;
      }
    } else if (((price - extreme) / extreme) > delta) {
      extreme = price;
      referance = price;
      mode = 1;
      // Directional Change Up
      return -1;
    }
  }
  // No Event
  return 0;
}
