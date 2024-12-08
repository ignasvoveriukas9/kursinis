#include "DbFiller.h"

#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

#include "Price.h"

int DbFiller::fillFromCryptoarchive(char *dbFile, std::string table,
                                    std::string csvFile, std::string ticker) {
  int count = 0;
  // File pointer
  std::fstream fin;

  fin.open(csvFile, std::ios::in);

  std::vector<std::string> row;
  std::string line, word, temp;

  // Open database
  int rc = sqlite3_open(dbFile, &dbManager.db);

  if (rc) {
    fprintf(stderr, "Can't open databese: %s\r\n",
            sqlite3_errmsg(dbManager.db));
    return -1;
  }

  while (getline(fin, line)) {
    row.clear();
    // getline(fin, line);

    std::stringstream s(line);

    while (getline(s, word, '|')) {
      row.push_back(word);
    }

    ++count;

    if (count % 1000 == 0) {
      fprintf(stderr, std::to_string(count).c_str());
    }

    dbManager.insertRow(
        table, Price{ticker, std::stoi(row [ 0 ]), std::stod(row [ 1 ])});
  }

  sqlite3_close(dbManager.db);

  return count;
}
