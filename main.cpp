#include <cstdio>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "Agent.h"
#include "DbManager.h"
#include "Price.h"

int main() {
  DbManager dbManager;

  Agent agent = Agent(true, 0.01);

  std::vector<Price> priceList = dbManager.getPrices(
      "test.db", "cryptoarchiveBTCUSDT", 1502942939, 1503002341);

  for (int i = 0; i < priceList.size(); ++i) {
    agent.run(priceList [ i ]);
  }

  std::cout << "Hello, world!" << std::endl;

  return 0;
}
