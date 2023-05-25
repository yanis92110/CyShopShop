#include "header.h"


#define MAX_STOCK_SIZE 100






int mainnew_car() {
    int sizecita = 0;
    int sizesuv = 0;
    int sizesport = 0;
    Car stockcita[MAX_STOCK_SIZE];
    Car stocksuv[MAX_STOCK_SIZE];
    Car stocksport[MAX_STOCK_SIZE];
    
    load_stock(stockcita, &sizecita, "stockcita.txt");
    load_stock(stocksuv, &sizesuv, "stocksuv.txt");
    load_stock(stocksport, &sizesport, "stocksport.txt");
    int tempsize = 0;
    int verif=0;
    
    printf("What type of vehicle do you want to add? (0=Sportive, 1=City-dweller car,2=SUV)\n");
    verif = scanf("%d", &tempsize);
    while (verif != 1 || tempsize < 0 || tempsize > 2) {
        printf("You have to choose between the numbers 0, 1 and 2\n");
        printf("What type of vehicle is it? (0=Sportive, 1=City-dweller car, 2=SUV)\n");
        verif = scanf("%d", &tempsize);
    
    
    
      
    
    if (tempsize == 0) {
        new_car(stocksport, &sizesport, tempsize);
    } else if (tempsize == 1) {
        new_car(stockcita, &sizecita, tempsize);
    } else if (tempsize == 2) {
        new_car(stocksuv, &sizesuv, tempsize);
    } else {
        printf("Invalid vehicle type.\n");
        return 1;
    }

    printf("Current stock:\n");
    printf("City-dweller cars:\n");
    print_stock(stockcita, sizecita);
    printf("SUVs:\n");
    print_stock(stocksuv, sizesuv);
    printf("Sportive cars:\n");
    print_stock(stocksport, sizesport);

    save_stock(stockcita, sizecita, "stockcita.txt");
    save_stock(stocksuv, sizesuv, "stocksuv.txt");
    save_stock(stocksport, sizesport, "stocksport.txt");

  
    return 0;
}
}