#include "InventoryManager.h"

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

void InventoryManager::buyOrder(double price) {
  currentInventorySize += currentUnitSize;
  currentInventoryCost += currentUnitSize * price;
}
