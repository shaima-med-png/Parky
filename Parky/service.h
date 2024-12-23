#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED

#include <stdio.h>

typedef struct {
    int id;
    char nom[50];
    int prix;
    char agent[50]; // Nom de l'agent affecté
} service;
int ajouterService(char *nomfichier, service s);
int modifierService(char *nomfichier, int id, service s);
int supprimerService(char *nomfichier, int id);
void afficherService(char *nomfichier);
service *chercherService_parId(char *nomfichier, int id);
int affecterService(char *nomfichier, int id, const char *agent);

#endif
