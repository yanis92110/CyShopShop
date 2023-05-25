#include "header.h"
#include "gameplay_buyer.c"
//#include "gameplay_buyer2.c"
#include "gameplay_manager.c"



int main() {
    message();
    printf("Welcome to CyShopShop !\n");
    printf("There are 2 modes:\n");
    printf("-Manager mode: You have access to the stock, the clients folder and you can command cars.\n");
  printf("===============================================\n");
  printf("-Buyer mode: You are a consumer and you can purchase cars on our shop.\n");

  int verif=0;
  char choose[10];
  do{
    printf("Which mode do you want to play ? (type 'buyer' or 'manager'\n");
    verif=scanf("%s",choose);
    testInt(choose);
    convertMin(choose);
  }while((verif!=1) || (strcmp(choose, "buyer") != 0 && strcmp(choose, "manager") != 0));
  if(strcmp(choose,"buyer")==0){
    printf("You have chosen the buyer mode, have fun !\n");
    sleep(1);
    main_gp_buyer2();
  }
  else if(strcmp(choose,"manager")==0){
    printf("You have chosen the manager mode, have fun !\n");
    sleep(2);
    main_manager();
  }
return 0;
}
