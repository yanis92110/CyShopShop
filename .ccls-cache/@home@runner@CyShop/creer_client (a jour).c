#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "structures.c"

Client creer_client(){
    int verif=0;
    Client a;
    printf("last name ?\n");
    scanf("%s", a.nom);
    printf("name ?\n");
    scanf("%s", a.prenom);
    char tab[3];
    char oui[3]="yes";
    char non[2]="no";
    while ((strcmp(tab, "yes") != 0) && (strcmp(tab, "no") != 0) && (verif != 3)){
        printf("Have you already bought on our store (answer yes or no) ?\n");
        verif = scanf("%s",tab);
    }
    if (tab=="yes"){
        //importer historique 
    }
    else if (strcmp(tab, "no") == 0){
        //creer fichier historique pour ce client
        char historique[60] = "";
        sprintf(historique, "%s.%s.historique", a.nom, a.prenom);
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
int main(){
    FILE *source = fopen("structures.c", "rb");
    FILE *destination = fopen("creer_client.c", "wb");
     if (source == NULL || destination == NULL) { 
        printf("Error when launching the files\n");
        return 1;
    }
    Client client;
    while (!feof(source) && fread(&client, sizeof(client), 1, source)) { 
        fwrite(&client, sizeof(client), 1, destination);  
    }
     fclose(source); 
    fclose(destination); 
    client=creer_client();
    return 0;
}