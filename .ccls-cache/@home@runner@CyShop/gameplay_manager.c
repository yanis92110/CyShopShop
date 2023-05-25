#include "header.h"

int main_manager() {
    int verif=0;
    char tab[4];
    int sizecita = 0;
    int sizesuv = 0;
    int sizesport = 0;
    int tempsize = 0;
    Car stockcita[MAX_STOCK_SIZE];
    Car stocksuv[MAX_STOCK_SIZE];
    Car stocksport[MAX_STOCK_SIZE];
    clearTerminal();
    load_stock(stockcita, &sizecita, "stockcita.txt");
    load_stock(stocksuv, &sizesuv, "stocksuv.txt");
    load_stock(stocksport, &sizesport, "stocksport.txt");
    printf("Hey, here is the today's stock !\n");
    printf("\n");
    printf("City dweller cars : \n");
    printf("\n");
    print_stock(stockcita,sizecita);
    printf("\n");
    printf("Sports cars : \n");
    printf("\n");
    print_stock(stocksport,sizesport);
    printf("\n");
    printf("SUV cars: \n");
    printf("\n");
    print_stock(stocksuv,sizesuv);
    printf("\n");

    comeBack :
    printf("Do you have some news cars to comand ?\n");
    verif=yes_no(tab,verif);
    if(verif==1){
       verif=0;
       printf("What type of vehicle do you want to add? (0=Sportive, 1=City-dweller car,2=SUV or enter '9' to go back)\n");
       verif=scanf("%d",&tempsize);
       while(verif != 1 || tempsize != 0 || tempsize != 2 || tempsize !=1 || tempsize != 9){
        buffer();
        printf("Please enter a correct number, 0 for a Sportive Car, 1 for a City-dweller car or 2 SUV)\n");
        verif = scanf("%d", &tempsize);
       }
       
      if (tempsize == 0) {
          new_car(stocksport, &sizesport, tempsize);
      } else if (tempsize == 1) {
          new_car(stockcita, &sizecita, tempsize);
      } else if (tempsize == 2) {
          new_car(stocksuv, &sizesuv, tempsize);
      } else if (tempsize == 9) {
        goto comeBack;
      } else {
          printf("Invalid vehicle type.\n");
          return 1;
    }
    save_stock(stockcita, sizecita, "stockcita.txt");
    save_stock(stocksuv, sizesuv, "stocksuv.txt");
    save_stock(stocksport, sizesport, "stocksport.txt");
    }
    else if(verif==-1){
      printf("Error when yes_no\n");
      return 0;
    }
    printf("Do you have some cars to delete ?\n");
    verif=yes_no(tab,verif);
    if(verif==1){
      printf("What type of car do you want to delete ? (0=Sportive, 1= City Dweller, 2= SUV or enter '9' to go back)\n");
      verif=scanf("%d",&tempsize);
      while(verif != 1 || tempsize!= 0 || tempsize!= 2||tempsize!=9|| tempsize!=1){
       if (tempsize==9) {
        goto comeBack;
       }
       printf("Please enter a correct number, 0 for a Sportive Car, 1 for a City-dweller car or 2 SUV)\n");
       verif = scanf("%d", &tempsize);
       }
      if(tempsize==0){
        delete_car(stocksport, sizesport,"stocksport.txt");
      }
      else if(tempsize==1){
        delete_car(stockcita, sizecita,"stockcita.txt");
      }
      else if(tempsize==2){
        delete_car(stocksuv, sizesuv,"stocksuv.txt");
      }

      
      }
    save_stock(stockcita, sizecita, "stockcita.txt");
    save_stock(stocksuv, sizesuv, "stocksuv.txt");
    save_stock(stocksport, sizesport, "stocksport.txt");
    

  return 0;
}
