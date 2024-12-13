#include <cstdio>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "DbFiller.h"
#include "EventDetector.h"
#include "Price.h"

int main() {
  // DbFiller dbFiller;
  DbManager dbManager;

  // dbManager.insertRow("test.db", "test", Price{"tik", 177777777777, 69.69});

  // int count = dbFiller.fillFromCryptoarchive(
  //"test.db", "cryptoarchiveSOLUSDT", "../../data/SOLUSDT.csv", "SOLUSDT");

  // std::cout << std::to_string(count) << std::endl;

  EventDetector eventDetector = EventDetector(0.0025);

  double prices [] = {
      1.112, 1.1125, 1.113, 1.1135, 1.114, 1.1145, 1.115, 1.1155, 1.115, 1.1145,
      1.114, 1.1135, 1.113, 1.1125, 1.112, 1.1115, 1.111, 1.1115, 1.112, 1.1125,
      1.113, 1.1125, 1.112, 1.1115, 1.111, 1.1105, 1.11,  1.1095, 1.109, 1.1085,
      1.108, 1.1075, 1.107, 1.1065, 1.106, 1.1055, 1.105};

  int event;

  for (int i = 0; i < 37; ++i) {
    event = eventDetector.getIntrinsicEvent(prices [ i ]);

    if (event == 0) {
      std::cout << "No event" << std::endl;
    } else if (event == 2) {
      std::cout << "Up Overshoot at: " << std::to_string(prices [ i ])
                << std::endl;
    } else if (event == -2) {
      std::cout << "Down Overshoot" << std::to_string(prices [ i ])
                << std::endl;
    } else if (event == 1) {
      std::cout << "Direction Change Down" << std::to_string(prices [ i ])
                << std::endl;
    } else if (event == -1) {
      std::cout << "Direction Change Up" << std::to_string(prices [ i ])
                << std::endl;
    }
  }

  std::vector<Price> priceList = dbManager.getPrices(
      "test.db", "cryptoarchiveBTCUSDT", 1502942939, 1502943541);

  for (int i = 0; i < priceList.size(); ++i) {
    std::cout << priceList [ i ].ticker << " "
              << std::to_string(priceList [ i ].time) << " "
              << std::to_string(priceList [ i ].price) << std::endl;
  }

  std::cout << "Hello, world!" << std::endl;

  return 0;
}
