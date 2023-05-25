//partie du gp acheteur ou on achete les voitures : FINI ET SANS CRASH (sans détails)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct {
    char brand[20];
    char category[20];
    char model[20];
    int reference;
    double price;
} Cars;

void toLower(char* word) {
    int i = 0;
    while (word[i] != '\0') {
        word[i] = tolower(word[i]);
        i++;
    }
}

void clearTerminal() {
    system("clear");
}

void buffer(){
  int i=0;
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {}
}

// Tableau de voitures sportives
Cars sportivesCars[] = {
    {"Audi", "Sportive", "R8", 001, 150000.0}, //sportivesCars[0]
    {"BMW", "Sportive", "M4", 002, 130000.0}, //sportivesCars[1]
    {"Porsche", "Sportive", "911", 003, 180000.0}, //sportivesCars[2]
    
};
int numSportives = sizeof(sportivesCars) / sizeof(sportivesCars[0]);

// Tableau de voitures SUV
Cars SUVCars[] = {
    {"Audi", "SUV", "Q7", 101, 90000.0}, //SUVCars[0]
    {"BMW", "SUV", "X5", 102, 95000.0}, //SUVCars[1]
    {"Mercedes", "SUV", "GLE", 103, 100000.0}, //SUVCars[2]
    
};
int numSUV = sizeof(SUVCars) / sizeof(SUVCars[0]);

// Tableau de voitures citadines
Cars cityCars[] = {
    {"Renault", "Citadine", "Clio", 201, 20000.0}, //cityCars[0]
    {"Peugeot", "Citadine", "208", 202, 22000.0}, //cityCars[1]
    {"Volkswagen", "Citadine", "Polo", 203, 19000.0}, //cityCars[2]
    
};
int numCityCars = sizeof(cityCars) / sizeof(cityCars[0]);

// Fonction pour afficher les voitures d'une catégorie donnée
void showCars(Cars* cars, int numCars) {
  printf("REF || BRAND || MODEL || CATEGORY || PRICE   \n");
  printf("=============================================================\n");
  for (int i = 0; i < numCars; i++) {  
    printf("%d - %s - %s - %s - %.2f $\n", cars[i].reference, cars[i].brand, cars[i].model, cars[i].category, cars[i].price);
  }
}

// Fonction principale
int main() {
    int card = 0;
    int category = 0;
    int reference = 0;
    int verif = 0; 
    float cart = 0;
    float* kart =&cart;
    char answer[5];
    int choice = 0;
    int i = 0;

    //Nettoyer le terminal
  clearTerminal();

    // Demander la catégorie de voiture souhaitée
  do {
    printf("                                                          Cars in the cart : %d\n",i);
    printf("So first, choose a category of cars (1,2 or 3) :\n");
    printf("         1. Sportives\n");
    printf("         2. SUV\n");
    printf("         3. City cars\n");
    printf("Your choice : ");
    verif = scanf("%d", &category);
    if (verif != 1 || (category != 1 && category != 2 && category != 3)){
      do {
      printf("The selected category is not valid. Please retry.\n");
      buffer();
      printf("  ->  ");
      verif = scanf("%d", &category);
      } while (verif != 1 || (category != 1 && category != 2 && category != 3));
    }
    else {
    }
    buffer();
    verif = 0;
    clearTerminal();

    // Proposer les différentes voitures dispo selon la catégorie
    
    if (category == 1) {
      showCars(sportivesCars, numSportives);
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car that you want)\n");
      printf("  ->  ");
      verif = scanf("%d",&reference);
      if (verif == 1 && reference >=1 && reference <= numSportives){
      }
      else {
        do {
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d",&reference);
          printf("  ->  ");
        } while (verif != 1 || reference<1 || reference>numSportives);
      }
      buffer();
      choice = reference;
      printf("Congrats ! You're now the proud owner of a %s %s !\n", sportivesCars[choice-1].brand , sportivesCars[choice-1].model);
      cart = cart + sportivesCars[choice-1].price;
      reference = 0;
      
    } else if (category == 2) {
      showCars(SUVCars, numSUV);
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car that you want)\n");
      printf("  ->  ");
      verif = scanf("%d",&reference);
      if (verif == 1 && reference >=101 && reference <= numSUV +100){
      }
      else {
        do {
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d",&reference);
          printf("  ->  ");
        } while (verif != 1 || reference<101 || reference>numSUV + 100);
      }
      buffer();
      choice = reference-100;
      printf("Congrats ! You're now the proud owner of a %s %s !\n",SUVCars[choice-1].brand, SUVCars[choice-1].model);
      cart = cart + SUVCars[choice-1].price;
      reference = 0;

    } else if (category == 3) {
      showCars(cityCars, numCityCars);
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car that you want)\n");
      printf("  ->  ");
      verif = scanf("%d",&reference);
      if (verif == 1 && reference >=201 && reference <= numCityCars + 200){
      }
      else {
        do {
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d",&reference);
          printf("  ->  ");
        } while (verif != 1 || reference<201 || reference>numCityCars + 200);
      }
      buffer();
      choice = reference - 200;
      printf("Congrats ! You're now the proud owner of a %s %s !\n",cityCars[choice-1].brand, cityCars[choice-1].model);
      cart = cart + cityCars[choice-1].price;
      reference = 0;
    }
    
    printf("Do you want to continue your shopping ? (enter 'yes' or 'no')\n");
    printf("  ->  ");
    scanf("%s",answer);
    toLower(answer);
    while (strcmp(answer,"yes") != 0 && strcmp(answer,"no") != 0){
      printf("Please don't play and enter a correct answer...\n");
      printf("  ->  ");
      scanf("%s",answer);
    }
    clearTerminal();
    i=i+1;
  } while (strcmp(answer,"yes") == 0);

  //Procéder au paiement
  
  printf("OK ! So you have in your cart %d cars so you will have to pay %.2f $.\n",i,cart);
  printf("Please enter your secret card number. (it's for a friend) \n");
  printf("  ->  ");
  verif = scanf("%d",&card);
  if (verif == 1 && card >=1000 && card <=9999) {
    printf("Thanks !\n");
  }
  else {
    do {
      printf("Your datas are safe with us please enter your number card.\n");
      buffer();
      printf("  ->  ");
      verif = scanf("%d",&card);
    } while (verif != 1 || card < 1000 || card > 9999);
    printf("Thanks !\n");
  }
  
return 0;
}