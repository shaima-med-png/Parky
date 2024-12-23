#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "service.h"

int main() {
    int choix, id, prix;
    char nom_rech[50], agent[50];
    service *s_rech; // Pointeur pour stocker le résultat des recherches

    // Déclaration et initialisation des services
    service s1 = {1, "Service_Nettoyage", 100, ""};
    service s2 = {2, "Service_Lavage", 200, ""};
    char nomfichier[] = "services.txt";

    while (1) {
        printf("\n=== Menu Gestion des Services ===\n");
        printf("1. Ajouter un service\n");
        printf("2. Modifier un service\n");
        printf("3. Supprimer un service\n");
        printf("4. Rechercher un service (par ID)\n");
        printf("5. Afficher tous les services\n");
        printf("6. Affecter un service\n");
        printf("0. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: // Ajouter un service
                printf("Ajouter quel service ? (1 pour s1, 2 pour s2) : ");
                scanf("%d", &id);
                if (id == 1) {
                    if (ajouterService(nomfichier, s1)) {
                        printf("Service ajouté avec succès.\n");
                    } else {
                        printf("Erreur : impossible d'ajouter le service.\n");
                    }
                } else if (id == 2) {
                    if (ajouterService(nomfichier, s2)) {
                        printf("Service ajouté avec succès.\n");
                    } else {
                        printf("Erreur : impossible d'ajouter le service.\n");
                    }
                } else {
                    printf("ID de service invalide.\n");
                }
                break;

            case 2: // Modifier un service
                printf("Entrer l'ID du service à modifier : ");
                scanf("%d", &id);
                printf("Entrer le nouveau nom : ");
                scanf("%s", s2.nom);
                printf("Entrer le nouveau prix : ");
                scanf("%d", &s2.prix);
                if (modifierService(nomfichier, id, s2)) {
                    printf("Service modifié avec succès.\n");
                } else {
                    printf("Erreur : Service introuvable.\n");
                }
                break;

            case 3: // Supprimer un service
                printf("Entrer l'ID du service à supprimer : ");
                scanf("%d", &id);
                if (supprimerService(nomfichier, id)) {
                    printf("Service supprimé avec succès.\n");
                } else {
                    printf("Erreur : Service introuvable.\n");
                }
                break;

            case 4: // Rechercher un service par ID
                printf("Entrez l'ID du service à rechercher : ");
                scanf("%d", &id);
                s_rech = chercherService_parId(nomfichier, id);
                if (s_rech != NULL) {
                    printf("Service trouvé :\n");
                    printf("ID : %d, Nom : %s, Prix : %d, Agent : %s\n",
                           s_rech->id, s_rech->nom, s_rech->prix, s_rech->agent);
                } else {
                    printf("Désolé, ce service n'est pas disponible.\n");
                }
                break;

            case 5: // Afficher tous les services
                afficherService(nomfichier);
                break;

            case 7: // Affecter un service
                printf("Entrer l'ID du service à affecter : ");
                scanf("%d", &id);
                printf("Entrer le nom de l'agent : ");
                scanf("%s", agent);
                if (affecterService(nomfichier, id, agent)) {
                    printf("Agent affecté avec succès.\n");
                } else {
                    printf("Erreur : Service introuvable ou agent non affecté.\n");
                }
                break;

            case 0: // Quitter le programme
                printf("Quitter le programme.\n");
                return 0;

            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    }
    return 0;
}
