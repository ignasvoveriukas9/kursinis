#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <sqlite3.h>

#include <string>

#include "Price.h"

class DbManager {
 private:
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  char *sql;

  void createTable();

 public:
  void insertRow(std::string table, Price price);
};

#endif
