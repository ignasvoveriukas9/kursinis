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
  void buyOrder(double price, double fraction);
  bool isProfitable(double price, int mode);
  void sellPosition(double price, int mode);
};

#endif  // !INVENTORYMANAGER_H
