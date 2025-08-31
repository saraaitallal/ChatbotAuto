#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE *f = fopen("voitures.txt", "r");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return 1;
    }

    char type[20], carburant[20], budget[20], usage[20];
    int places;
    char ligne[200];

    printf("Bienvenue dans l'assistant automobile !\n\n");
    printf("Veuillez repondre avec vos criteres souhaites :\n\n")
    printf("Quel type de voiture cherchez-vous ? (citadine / SUV / berline) : ");
    scanf("%s", type);

    printf("Quel type de carburant preferez-vous ? (essence / diesel / hybride / electrique) : ");
    scanf("%s", carburant);

    printf("Quel est votre budget ? (bas / moyen / eleve) : ");
    scanf("%s", budget);

    printf("Quel est votre usage principal ? (ville / route / tous) : ");
    scanf("%s", usage);

    printf("Combien de places voulez-vous ? (2 / 4 / 5 / 7) : ");
    scanf("%d", &places);

    printf("\nRecherche en cours.....\n");

    int match = 0;

    while (fgets(ligne, sizeof(ligne), f)) {
        // Découper la ligne en morceaux avec strtok
        char *nom = strtok(ligne, ";");
        char *t = strtok(NULL, ";");
        char *c = strtok(NULL, ";");
        char *b = strtok(NULL, ";");
        char *u = strtok(NULL, ";");
        char *p_str = strtok(NULL, ";\n");

        int p = atoi(p_str); // convertir le nombre de places en entier

        if (nom && t && c && b && u && p_str &&
            strcmp(t, type) == 0 &&
            strcmp(c, carburant) == 0 &&
            strcmp(b, budget) == 0 &&
            strcmp(u, usage) == 0 &&
            p == places) {
            printf(" %s\n", nom);
            match = 1;
        }
    }

    if (!match) {
        printf("Aucun modele ne correspond exactement a vos criteres.\n");
    }

    fclose(f);
    return 0;
}
