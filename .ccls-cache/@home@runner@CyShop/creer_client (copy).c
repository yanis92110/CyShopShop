#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "structures.c"

Client creer_client(){
    int verif=0;
    Client a;
    printf("last name ?\n");
    scanf("%s", a.name);
    printf("name ?\n");
    scanf("%s", a.surname);
    char tab[3];
    char oui[3]="yes";
    char non[3]="no";
    while ((strcmp(tab, "yes") != 0) && (strcmp(tab, "no") != 0) && (verif != 3)){
        printf("Have you ever bought in our store (answer yes or no) ?\n");
        verif = scanf("%s",tab);
    }
    if (strcmp(tab,"yes")==0){
        //importer historique 
    }
    else if (strcmp(tab, "no") == 0){
        //creer fichier historique pour ce client
        char historique[60] = "";
        sprintf(historique, "%s.%s.historique", a.name, a.surname);
        FILE* fichier = fopen(historique, "w");
        if (fichier != NULL) {
            printf("The file %s was succesfully created\n", historique);
            fclose(fichier);
        } else {
            printf("Impossible to create the file %s.\n", historique);
        }
    }
    return a;
}
