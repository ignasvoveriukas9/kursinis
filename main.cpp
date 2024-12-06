#include <cstdio>
#include <ctime>
#include <iostream>
#include <ostream>

#include "DbManager.h"
#include "Price.h"

int main() {
  DbManager dbManager;

  dbManager.insertRow("priceData", Price{"BTCUSDT", time(0), 100000.69});

  std::cout << "Hello, world!" << std::endl;

  return 0;
}
