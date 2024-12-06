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

  void createTable(char *dbFile, std::string table);
  int doseTableExist(char *dbFile, std::string table);

 public:
  void insertRow(char *dbFile, std::string table, Price price);
};

#endif
