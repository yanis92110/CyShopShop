#include <stdio.h>
#include <stdlib.h>
#include "tests.c"
#include <ctype.h>
#include <string.h>



  typedef struct{
      char brand[25];
      char model[60];
      int reference;
      int quantity;
      float price;
      int height;//0=Sportive, 1=City-dweller car, 2=SUV
  }Produit;

  typedef struct {
      int hour;
      int minute;
      int second;
  }Heure;
  //on devrait fusionner les structures date et heure non ? pq pas
  typedef struct{
      int day;
      int month;
     int year;
  }Date;

  typedef struct{
     char name[25];
     char surname[25];
  }Client;
  
