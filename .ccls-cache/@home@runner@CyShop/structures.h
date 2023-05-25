#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



  typedef struct{
      char brand[25];
      char model[30];
      char category[20];
      int reference;
      int quantity;
      float price;
      int size; //0=Sportive, 1=City-dweller car, 2=SUV
      
  }Car;


  typedef struct{
      int hour;
      int minute;
      int second;
      int day;
      int month;
      int year;
  }Date;

  typedef struct{
     char name[25];
     char surname[25];
     int id;
     float points;
  }Client;
  
