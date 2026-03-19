#ifndef DEPENSE_H
#define DEPENSE_H
#include <sqlite3.h>

#define max_depenses 500

typedef struct depense
{
    int id;
    char description[100];
    char categorie[50];
    float montant;
    char date[11]; 
} Depense;
sqlite3 *ouvrir_db();
void fermer_db(sqlite3 *db);
void supprimer_depense(sqlite3 *db, int id);
void ajouter_depense(sqlite3 *db, Depense *d);
float total_par_categorie(sqlite3 *db, const char *categorie);
float total_du_mois(sqlite3 *db );
void definir_budget(sqlite3 *db, float budget);
float get_budget(sqlite3 *db );
int charger_depenses(sqlite3 *db, Depense *depenses);
#endif