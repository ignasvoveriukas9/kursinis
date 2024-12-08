#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <sqlite3.h>

#include <string>

#include "Price.h"

class DbManager {
 private:
  char *zErrMsg = 0;
  int rc;
  char *sql;

 public:
  void createTable(std::string table);
  int doseTableExist(std::string table);

 public:
  sqlite3 *db;
  void insertRow(std::string table, Price price);
};

#endif
