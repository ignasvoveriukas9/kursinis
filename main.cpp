#include <cstdio>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>

#include "DbManager.h"
#include "Price.h"

int main() {
  DbManager dbManager;

  dbManager.insertRow("test.db", "cryptoarchive_BTCUSDT",
                      Price{"BTCUSDT", time(0), 100000.69});

  std::cout << "Hello, world!" << std::endl;

  return 0;
}
