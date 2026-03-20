#include <string.h>
#include <stdio.h>
#include "../include/depense.h"

sqlite3 *ouvrir_db() {
    sqlite3 *db;
sqlite3_open("depenses.db", &db);
sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS depenses (id INTEGER PRIMARY KEY AUTOINCREMENT, description TEXT, categorie TEXT, montant REAL, date TEXT)", NULL, NULL, NULL);
return db;
}
void fermer_db(sqlite3 *db) {
    sqlite3_close(db);
}
void ajouter_depense(sqlite3 *db, Depense *d){
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, 
    "insert into depenses (description, categorie, montant, date) values (?, ?, ?, ?)", -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, d->description, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, d->categorie, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 3, d->montant);
    sqlite3_bind_text(stmt, 4, d->date, -1, SQLITE_STATIC);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
