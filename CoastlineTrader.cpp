#include "CoastlineTrader.h"

#include <cstdio>

#include "InventoryManager.h"

CoastlineTrader::CoastlineTrader(bool mode) : mode(mode) {}

int CoastlineTrader::run(int event, double price,
                         InventoryManager &inventoryManager) {
  // Long
  if (mode) {
    if (event < 0) {
      return 1;
    } else if (event == 2 && inventoryManager.isProfitable(price)) {
      return -1;
    }
  } else {  // Short
    if (event > 0) {
      return 1;
    } else if (event == -2 && inventoryManager.isProfitable(price)) {
      return -1;
    }
  }

  return 0;
}
