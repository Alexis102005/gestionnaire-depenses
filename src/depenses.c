#include <sqlite3.h>
#include <stdio.h>

sqlite3 *ouvrir_db() {
    sqlite3* db;
    sqlite3_open("depenses.db", &db);