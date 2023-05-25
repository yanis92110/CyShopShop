#include "import.h"
#include "header.h"

int main_gerant() {
    int verif=0;
    char tab[4];
    char oui[3]="oui";
    char non[3]="non";
    printf("Hey, here is the today's stock !\n");
    
    printf("Do you have some news cars to add to the stock ?\n");
    verif=yes_no(tab,verif);
    
    if(verif==1){
      new_car();
    }
    printf("How ");
    verif=scanf("%s\n");
  
  
    while(verif!=1){
      printf("You have to enter a valid number (between 1 and 50)");
      printf("Enter how ")
    }
  
}
