#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stock.h"

Car new_car(Car** stock, int* size) {
    int verif = 0;
    Car a;

    printf("Enter the name of the brand: \n");
    scanf("%s", a.brand);
    printf("Enter the name of the model: \n");
    scanf("%s",a.model);
    printf("Enter the reference of the product: \n");
    verif = scanf("%d", &a.reference);
    while (verif != 1 || a.reference < 1000 || a.reference > 9999) {
        printf("The reference has to be between 1000 and 9999 inclusive.\n");
        printf("Enter the reference: \n");
        verif = scanf("%d", &a.reference);
    }

    verif = 0;

    printf("Enter the quantity to add: \n");
    verif = scanf("%d", &a.quantity);
    while (verif != 1 || a.quantity < 1 || a.quantity > 15) {
        printf("The quantity has to be between 1 and 15\n");
        printf("Enter the quantity to add: \n");
        verif = scanf("%d", &a.quantity);
    }

    verif = 0;
    
    printf("How much does the car cost?\n");
    verif = scanf("%f", &a.price);
    while (verif != 1 || a.price < 500) {
        printf("Too cheap! The car must cost at least 500€\n");
        printf("How much does the car cost?\n");
        verif = scanf("%f", &a.price);
    }

    verif = 0;

    printf("What type of vehicle is it? (0=Sportive, 1=City-dweller car, 2=SUV)\n");
    verif = scanf("%d", &a.size);
    while (verif != 1 || a.size < 0 || a.size > 2) {
        printf("You have to choose between the numbers 0, 1 and 2\n");
        printf("What type of vehicle is it? (0=Sportive, 1=City-dweller car, 2=SUV)\n");
        verif = scanf("%d", &a.size);
    }
    for(int i = 0 ; i < a.quantity ; i++){
    if (a.size == 1) {
        *size += 1;
        *stock = realloc(*stock, (*size) * sizeof(Car));
        strcpy((*stock)[*size - 1].brand, a.brand);
        strcpy((*stock)[*size - 1].model, a.model);
        (*stock)[*size - 1].size = 1;
    } else if (a.size == 2) {
        *size += 2;
        *stock = realloc(*stock, (*size) * sizeof(Car));
        strcpy((*stock)[*size - 2].brand, a.brand);
        strcpy((*stock)[*size - 2].model, a.model);
        (*stock)[*size - 2].size = 2;
    } else {
        *size += 3;
        *stock = realloc(*stock, (*size) * sizeof(Car));
        strcpy((*stock)[*size - 3].brand, a.brand);
        strcpy((*stock)[*size - 3].model, a.model);
        (*stock)[*size - 3].size = 3;
    }
    }
    return a;
}
void afficher_stock(Car* stock, int size) {
    for (int i = 0; i < size; i++) {
        //on affiche la quantite du stock mais pas en adequation avec la quantite quon a donne au dessus
        printf("Product : %s %s, Quantity : %d, Size : %d, Adress : %p\n", stock[i].brand,stock[i].model,  stock[i].quantity, stock[i].size, (void*)&stock[i]);
    }
}

int main_product() {
    int size = 0;
    Car* stock = NULL;
    Car a;

    a = new_car(&stock, &size);
    afficher_stock(stock,size);
    return 0;
    }

