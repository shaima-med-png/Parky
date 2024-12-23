#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "service.h"

int ajouterService(char *nomfichier, service s) {
    FILE *f = fopen(nomfichier, "a");
    if (f != NULL) {
        fprintf(f, "%d %s %d %s\n", s.id, s.nom, s.prix, s.agent);
        fclose(f);
        return 1;
    }
    return 0;
}

int modifierService(char *nomfichier, int id, service s) {
    FILE *f = fopen(nomfichier, "r");
    FILE *temp = fopen("temp.txt", "w");
    int found = 0;

    if (f != NULL && temp != NULL) {
        service temp_s;
        while (fscanf(f, "%d %s %d %s", &temp_s.id, temp_s.nom, &temp_s.prix, temp_s.agent) != EOF) {
            if (temp_s.id == id) {
                fprintf(temp, "%d %s %d %s\n", s.id, s.nom, s.prix, s.agent);
                found = 1;
            } else {
                fprintf(temp, "%d %s %d %s\n", temp_s.id, temp_s.nom, temp_s.prix, temp_s.agent);
            }
        }
        fclose(f);
        fclose(temp);
        remove(nomfichier);
        rename("temp.txt", nomfichier);
    }

    return found;
}

int supprimerService(char *nomfichier, int id)
 {
    FILE *f = fopen(nomfichier, "r");
    FILE *temp = fopen("temp.txt", "w");
    int found = 0;

    if (f != NULL && temp != NULL) {
        service temp_s;
        while (fscanf(f, "%d %s %d %s", &temp_s.id, temp_s.nom, &temp_s.prix, temp_s.agent) != EOF) {
            if (temp_s.id != id) {
                fprintf(temp, "%d %s %d %s\n", temp_s.id, temp_s.nom, temp_s.prix, temp_s.agent);
            } else {
                found = 1;
            }
        }
     }
     if (found) {
       remove(nomfichier);
       rename("temp.txt", nomfichier);
    } else {
        remove("temp.txt"); // Supprime le fichier temporaire inutile
    }

    return found;
}

void afficherService(char *nomfichier) {
    FILE *f = fopen(nomfichier, "r");
    if (f == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s.\n", nomfichier);
        return;
    }

    service s;
    printf("Liste des services :\n");
    while (fscanf(f, "%d %s %d %s", &s.id, s.nom, &s.prix, s.agent) != EOF) {
        printf("ID : %d, Nom : %s, Prix : %d, Agent : %s\n", s.id, s.nom, s.prix, s.agent);
    }
    fclose(f);
}

service *chercherService_parId(char *nomfichier, int id) {
    FILE *f = fopen(nomfichier, "r");
    static service s;
    if (f != NULL) {
        while (fscanf(f, "%d %s %d %s", &s.id, s.nom, &s.prix, s.agent) != EOF) {
            if (s.id == id) {
                fclose(f);
                return &s;
            }
        }
        fclose(f);
    }
    return NULL;
}

int affecterService(char *nomfichier, int id, const char *agent) 
{
    FILE *f = fopen(nomfichier, "r");
    FILE *temp = fopen("temp.txt", "w");
    int found = 0;

    if (f != NULL && temp != NULL) {
        service s;
        while (fscanf(f, "%d %s %d %s", &s.id, s.nom, &s.prix, s.agent) != EOF) {
            if (s.id == id) {
                strcpy(s.agent, agent);
                found = 1;
            }
            fprintf(temp, "%d %s %d %s\n", s.id, s.nom, s.prix, s.agent);
        }
        fclose(f);
        fclose(temp);
        remove(nomfichier);
        rename("temp.txt", nomfichier);
    }

    return found;
}
