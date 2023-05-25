#include "import.c"

int main(){
  Client client1;
  int verif=0;
  char tab[4];
  while ((strcmp(tab, "yes") != 0) && (strcmp(tab, "no") != 0) && (verif != 3)){
    printf("Welcome to CyShopShop ! Do you already have an account ?\n");
    verif = scanf("%s",tab);
    }
  if(strcmp(tab,"yes")==0){
    printf("What is your name?\n");
    char tempname[50];
    scanf("%s",tempname);
    printf("What is your surname ?\n");
    char tempsurname[50];
    scanf("%s",tempsurname);
    char path[100];
    sprintf(path,"%s.%s.historic.txt",tempname,tempsurname);
    FILE* file=fopen(path,"r");
    if(file==NULL){
      printf("You don't have an account!\n");
    }
    printf("Here is your historic !\n");
    
  }
  return 0;
}