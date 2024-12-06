#include "DbManager.h"

#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

#include "Price.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  for (int i = 0; i < argc; i++) {
    printf("%s = %s\r\n", azColName [ i ], argv [ i ] ? argv [ i ] : "NULL");
  }
  printf("\r\n");
  return 0;
}

void DbManager::createTable() {
  // Open database
  rc = sqlite3_open("test.db", &db);

  if (rc) {
    fprintf(stderr, "Can't open databese: %s\r\n", sqlite3_errmsg(db));
    return;
  } else {
    fprintf(stderr, "Opened database successfully\r\n");
  }

  // SQL statement
  sql =
      "CREATE TABLE priceData("
      "ticker TEXT NOT NULL,"
      "time BIGINT NOT NULL,"
      "openPrice REAL NOT NULL,"
      "PRIMARY KEY (ticker, time));";

  // Execute SQL statement
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\r\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Table created successfully\r\n");
  }

  // Close database
  sqlite3_close(db);

  return;
}

void DbManager::insertRow(std::string table, Price price) {
  // Open database
  rc = sqlite3_open("test.db", &db);

  if (rc) {
    fprintf(stderr, "Can't open databese: %s\r\n", sqlite3_errmsg(db));
    return;
  } else {
    fprintf(stderr, "Opened database successfully\r\n");
  }

  // SQL statement
  std::ostringstream builder;
  builder << "INSERT INTO " << table << " (ticker, time, openPrice)"
          << " VALUES ('" << price.ticker << "', " << std::to_string(price.time)
          << ", " << std::to_string(price.price) << ");";

  std::string sqlString = builder.str();
  sql = sqlString.data();

  // Execute SQL statement
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\r\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Record created successfully\r\n");
  }

  // Close database
  sqlite3_close(db);

  return;
}
