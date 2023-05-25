//#include <stdio.h>
//#include <stdlib.h>
#include "structures.h"
#include "tests.c"
#include <ctype.h>
#include <string.h>

Client creer_client(){
    int verif=0;
    Client a;
    printf("What is your last name ?\n");
    scanf("%s", a.name);
    printf("What is first name ?\n");
    scanf("%s", a.surname);
    char tab[4];
    char oui[3]="yes";
    char non[2]="no";
    while ((strcmp(tab, "yes") != 0) && (strcmp(tab, "no") != 0)/* && (verif != 3)*/){
        printf("Have you ever bought in our store (answer yes or no) ?\n");
        verif = scanf("%s",tab);
        converttoMin(tab);
    }
    if (strcmp(tab,"yes")==0){
        char historic[60]="";
        sprintf(historic,"%s.%s.historic.txt",a.name, a.surname);
        FILE* file=fopen(historic,"r");
        if(file==NULL){
          printf("Your historic can't be found.\nMake sure you entered your correct name or you might don't have an account.\n");
          fclose(file);
        }
        else{
          printf("Here is your historic:\n");
          char lines[100];
          while(fgets(lines, sizeof(lines), file)!=NULL){
            printf("%s\n", lines);
          }
          fclose(file);
        }
    }
    else if (strcmp(tab, "no") == 0){
        //creer fichier historique pour ce client
        char historic[60] = "";
        char path[100]="";
        sprintf(historic, "%s.%s.historic.txt", a.name, a.surname);
        sprintf(path, "historic/%s.%s.historic.txt", a.name, a.surname);
        FILE* file = fopen(historic, "w");
        if (file != NULL) {
            //verifier si fichier existe deja
            printf("The file %s was succesfully created\n", historic);
          
            int result = rename(historic,path);
            if(result!=0){
              printf("Can't deplace the file\n");
              return a;
            }
            printf("The file was succesfully moved\n");
            fclose(file);
        } else {
            printf("Impossible to create the file %s.\n", historic);
        }
    }
    return a;

}
/*int main(){
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
}*/