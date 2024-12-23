#include "InventoryManager.h"

#include <cstdio>

InventoryManager::InventoryManager(double unitSize)
    : originalUnitSize(unitSize), currentUnitSize(unitSize) {}

void InventoryManager::updateUnitSize(double probabilityIndicator) {
  if (probabilityIndicator <= 0.1) {
    currentUnitSize = originalUnitSize * 0.1;
  } else if (probabilityIndicator <= 0.5) {
    currentUnitSize = originalUnitSize * 0.5;
  } else {
    currentUnitSize = originalUnitSize;
  }
}

void InventoryManager::buyOrder(double price, double fraction) {
  currentInventorySize += currentUnitSize * fraction;
  currentInventoryCost += currentUnitSize * fraction * price;
}

bool InventoryManager::isProfitable(double price, int mode) {
  if ((double)mode * currentInventoryCost <
      (double)mode * currentInventorySize * originalUnitSize * price) {
    return true;
  }
  return false;
}

void InventoryManager::sellPosition(double price, int mode) {
  double sellCost = currentInventorySize * originalUnitSize * price;

  printf("sell position of size: %f, for %f, for profit %f\r\n",
         mode * currentInventorySize, sellCost,
         (double)mode * sellCost - (double)mode * currentInventoryCost);
  currentInventorySize = 0;
  currentInventoryCost = 0;
}
