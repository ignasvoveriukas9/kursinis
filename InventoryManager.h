#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

class InventoryManager {
 private:
  double originalUnitSize;
  double currentUnitSize;
  // size in originalUnitSize
  double currentInventorySize = 0;
  double currentInventoryCost = 0;

 public:
  InventoryManager(double UnitSize);
  double getUnitSize() { return currentUnitSize; }
  double getInventorySize() { return currentInventorySize; }
  double getInventoryCost() { return currentInventoryCost; }
  void updateUnitSize(double probabilityIndicator);
  void buyOrder(double price);
};

#endif  // !INVENTORYMANAGER_H
