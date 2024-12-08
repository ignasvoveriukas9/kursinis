#include <cstdio>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>

#include "DbFiller.h"
#include "Price.h"

int main() {
  DbFiller dbFiller;
  // DbManager dbManager;

  // dbManager.insertRow("test.db", "test", Price{"tik", 177777777777, 69.69});

  int count = dbFiller.fillFromCryptoarchive(
      "test.db", "cryptoarchiveBTCUSDT", "../../data/BTCUSDT.csv", "BTCUSDT");

  // std::cout << std::to_string(count) << std::endl;

  std::cout << "Hello, world!" << std::endl;

  return 0;
}
