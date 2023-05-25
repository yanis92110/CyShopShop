#include <stdio.h>
#include <stdlib.h>


//FICHIER POUR TESTER LES CONDITIONS ET FONCTIONS

int testInt(const char* chaine){
  int i=0;
  if(chaine[i]=='-'){
    printf("Veuillez entrer un nombre positif\n");
  }
  while(chaine[i]!='\0'){
    if((chaine[i]<0)||(chaine[i]>9)){
      return 0;
    }
  }
  return 1;
  }
}