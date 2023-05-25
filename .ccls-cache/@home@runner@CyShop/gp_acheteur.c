#include "header.h"
#include "import.h"



int yes_no(char answer[], int verif) {
  printf("  ->  ");
  verif = scanf("%s", answer);
  buffer();
  toLower(answer);
  if (verif == 1 &&
      (strcmp(answer, "yes") == 0 || (strcmp(answer, "no") == 0))) {
  } else {
    do {
      printf("Please, answer us correctly... (enter 'yes' or 'no') \n");
      printf("  ->  ");
      verif = scanf("%s", answer);
      buffer();
    } while (verif != 1 ||
             (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0));
  }
  if (strcmp(answer, "yes") == 0) {
    return 1;
  } else {
    return 0;
  }
}

void showCars(Car *cars, int numCars) {
  printf("REF || BRAND || MODEL || CATEGORY || PRICE   \n");
  printf("=============================================================\n");
  for (int i = 0; i < numCars; i++) {
    printf("%d - %s - %s - %s - %.2f $\n", cars[i].reference, cars[i].brand,
           cars[i].model, cars[i].category, cars[i].price);
  }
}

void createClient(Client client) {
  char filename[50];

  clearTerminal();

  printf("Enter your name: ");
  scanf("%s", client.name);

  clearTerminal();

  printf("Enter your surname: ");
  scanf("%s", client.surname);

  clearTerminal();

  sprintf(filename, "%s_%s.txt", client.name, client.surname);

  FILE *file = fopen(filename, "w");
  if (file != NULL) {
    fprintf(file, "Name: %s\n", client.name);
    fprintf(file, "Surname: %s\n", client.surname);
    fprintf(file, "ID: %d\n", client.id);
    fprintf(file, "Purchase history:\n");
    fclose(file);
    printf("Client file created: %s\n", filename);
  } else {
    printf("Error creating client file.\n");
  }
  clearTerminal();
}

// Tableau de voitures sportives
Car sportivesCars[] = {
    {"Audi", "Sportive", "R8", 001, 150000.0},     // sportivesCars[0]
    {"BMW", "Sportive", "M4", 002, 130000.0},      // sportivesCars[1]
    {"Porsche", "Sportive", "911", 003, 180000.0}, // sportivesCars[2]
    {"BMW", "Sportive", "M5", 004, 135000.0},       // sportivesCars[3]
    {"Honda", "Sportive", "Civic Type R", 005, 39000.0}, // sportivesCars[4]
    {"Ferrari", "Sportive", "F40", 006, 1300000.0},      // sportivesCars[5]
    {"Toyota", "Sportive", "Supra", 007, 52500.0},        // sportivesCars[6]
};
int numSportives = sizeof(sportivesCars) / sizeof(sportivesCars[0]);

// Tableau de voitures SUV
Car SUVCars[] = {
    {"Audi", "SUV", "Q7", 101, 90000.0},       // SUVCars[0]
    {"BMW", "SUV", "X5", 102, 95000.0},        // SUVCars[1]
    {"Mercedes", "SUV", "GLE", 103, 100000.0}, // SUVCars[2]
    {"Rolls Royce", "SUV", "Cullinan", 104, 400000.0}, // SUVCars[3]
    {"Lamborghini", "SUV", "Urus", 105, 205000.0}, // SUVCars[4]
    {"Honda", "SUV", "FR-V", 106, 24000.0}, // SUVCars[5]

};
int numSUV = sizeof(SUVCars) / sizeof(SUVCars[0]);

// Tableau de voitures citadines
Car cityCars[] = {
    {"Renault", "Citadine", "Clio", 201, 20000.0},    // cityCars[0]
    {"Peugeot", "Citadine", "208", 202, 22000.0},     // cityCars[1]
    {"Volkswagen", "Citadine", "Polo", 203, 19000.0}, // cityCars[2]
    {"Citroën", "Citadine", "C3", 204, 17000.0},     // cityCars[3]
    {"Cupra", "Citadine", "Born", 205, 39000.0}, // cityCars[2]

};
int numCityCars = sizeof(cityCars) / sizeof(cityCars[0]);

// Fonction principale
int main_gp_acheteur() {
  char filename[50];
  char card[6];
  int category = 0;
  int reference = 0;
  int verif = 0;
  float cart = 0;
  float *kart = &cart;
  char answer[5];
  int choice = 0;
  int i = 0;
  FILE *file = fopen(filename, "w");
  Date today;
  int r = 0;
  int count = 0;

  // Nettoyer le terminal
  clearTerminal();

  int id = 0;
  int index;
  Client client;

  printf("Hello ! Welcome to CYShopShop !\n");
  printf("=============================================================\n");
  printf("Did you already come in our store ? (enter 'yes' or 'no') \n");
  index = yes_no(answer, verif);

  if (index == 1) {
    printf("Do you already have an account ? (enter 'yes' or 'no') \n");
    index = yes_no(answer, verif);
    clearTerminal();
    if (index == 1) {
      printf("OK. Let's start to shop !\n");
      // vérifier si il y a bien le dossier
    } else if (index == 0) {
      printf("Do you want to create an account in our shop ? (enter 'yes' or "
             "'no')\n");
      index = yes_no(answer, verif);
      if (index == 1) {
        createClient(client);
      } else if (index == 0) {
        printf("No problem. Let's start to shop !\n");
      }
    }
  } else if (index == 0) {
    printf("Do you want to create an account in our shop ? (enter 'yes' or "
           "'no')\n");
    index = yes_no(answer, verif);
    if (index == 1) {
      createClient(client);
    } else if (index == 0) {
      clearTerminal();
      printf("No problem. Let's start to shop !\n");
    }
  }

  // Demander la date du jour
  printf("Before we start, please enter today's date : \n");
  printf("=============================================================\n");
  printf("To start, in what year do we live ?\n");
  printf("  ->  ");
  verif = scanf("%d", &today.year);
  buffer();
  if (verif != 1 || today.year < 1885 || today.year > 2023) {
    do {
      printf("Enter a correct year number.\n");
      verif = scanf("%d", &today.year);
      buffer();
    } while (verif != 1 || today.year < 1885 || today.year > 2023);
  } else {
  }

  printf("Then, what's the month ? (the number)\n");
  printf("  ->  ");
  verif = scanf("%d", &today.month);
  buffer();
  if (verif != 1 || today.month < 1 || today.month > 12) {
    do {
      printf("Enter a correct month number.\n");
      verif = scanf("%d", &today.month);
      buffer();
    } while (verif != 1 || today.month < 1 || today.month > 12);
  } else {
  }
  printf("Now, what's the day ? (the number)\n");
  printf("  ->  ");
  verif = scanf("%d", &today.day);
  buffer();
  if (verif == 1) {
    if (today.month == 02) {
      if (today.day >= 1 && today.day <= 28) {
      } else {
        do {
          printf("Enter a correct day number.\n");
          verif = scanf("%d", &today.day);
          buffer();
        } while (verif != 1 || today.day < 1 || today.day > 28);
      }
    } else if (today.month == 1 || today.month == 3 || today.month == 5 ||
               today.month == 7 || today.month == 8 || today.month == 10 ||
               today.month == 12) {
      if (today.day >= 1 && today.day <= 31) {
      } else {
        do {
          printf("Enter a correct day number.\n");
          verif = scanf("%d", &today.day);
          buffer();
        } while (verif != 1 || today.day < 1 || today.day > 31);
      }
    } else {
      if (today.day >= 1 && today.day <= 30) {
      } else {
        do {
          printf("Enter a correct day number.\n");
          verif = scanf("%d", &today.day);
          buffer();
        } while (verif != 1 || today.day < 1 || today.day > 30);
      }
    }
  } else {
    do {
      printf("Please enter a digit.\n");
      verif = scanf("%d", &today.day);
      buffer();
    } while (verif != 1);
  }

  clearTerminal();
goback:
  do {
    printf("                                                          Cars in "
           "the cart : %d\n",
           i);
    printf("So first, choose a category of cars (1,2 or 3) :\n");
    printf("         1. Sportives\n");
    printf("         2. SUV\n");
    printf("         3. City cars\n");
    printf("Your choice : ");
    verif = scanf("%d", &category);
    if (verif != 1 || (category != 1 && category != 2 && category != 3)) {
      do {
        printf("The selected category is not valid. Please retry.\n");
        buffer();
        printf("  ->  ");
        verif = scanf("%d", &category);
      } while (verif != 1 || (category != 1 && category != 2 && category != 3));
    } else {
    }
    buffer();
    verif = 0;
    clearTerminal();

    // Proposer les différentes voitures dispo selon la catégorie
    if (category == 1) {
      showCars(sportivesCars, numSportives);
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car "
             "that you want or enter '0' to come back to the menu)\n");
      printf("  ->  ");
      verif = scanf("%d", &reference);
      if (verif == 1 && reference >= 1 && reference <= numSportives) {
      } else if (verif == 1 && reference == 0) {
        clearTerminal();
        goto goback;
      } else {
        do {
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d", &reference);
          printf("  ->  ");
        } while (verif != 1 || reference < 1 || reference > numSportives);
      }
      buffer();
      choice = reference;
      fprintf(file, "Date: %d/%d/%d à %d : %d : %d, Car: %s %s , Price: %.2f\n",
              today.day, today.month, today.year, today.hour, today.minute,
              today.second, sportivesCars[choice - 1].brand,
              sportivesCars[choice - 1].model, sportivesCars[choice - 1].price);
      printf("Congrats ! You're now the proud owner of a %s %s !\n",
             sportivesCars[choice - 1].brand, sportivesCars[choice - 1].model);
      cart = cart + sportivesCars[choice - 1].price;
      reference = 0;

    } else if (category == 2) {
      showCars(SUVCars, numSUV);
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car "
             "that you want or enter '0' to come back to menu)\n");
      printf("  ->  ");
      verif = scanf("%d", &reference);
      if (verif == 1 && reference >= 101 && reference <= numSUV + 100) {
      } else if (verif == 1 && reference == 0) {
        clearTerminal();
        goto goback;
      } else {
        do {
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d", &reference);
          printf("  ->  ");
        } while (verif != 1 || reference < 101 || reference > numSUV + 100);
      }
      buffer();
      choice = reference - 100;
      printf("Congrats ! You're now the proud owner of a %s %s !\n",
             SUVCars[choice - 1].brand, SUVCars[choice - 1].model);
      cart = cart + SUVCars[choice - 1].price;
      reference = 0;

    } else if (category == 3) {
      showCars(cityCars, numCityCars);
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car "
             "that you want or enter '0' to come back to menu)\n");
      printf("  ->  ");
      verif = scanf("%d", &reference);
      if (verif == 1 && reference >= 201 && reference <= numCityCars + 200) {
      } else if (verif == 1 && reference == 0) {
        clearTerminal();
        goto goback;
      } else {
        do {
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d", &reference);
          printf("  ->  ");
        } while (verif != 1 || reference < 201 ||
                 reference > numCityCars + 200);
      }
      buffer();
      choice = reference - 200;
      printf("Congrats ! You're now the proud owner of a %s %s !\n",
             cityCars[choice - 1].brand, cityCars[choice - 1].model);
      cart = cart + cityCars[choice - 1].price;
      reference = 0;
    }

    printf("Do you want to continue your shopping ? (enter 'yes' or 'no')\n");
    printf("  ->  ");
    scanf("%s", answer);
    answer[]=convertMin(answer);
    while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0) {
      printf("Please don't play and enter a correct answer...\n");
      printf("  ->  ");
      scanf("%s", answer);
    }
    clearTerminal();
    i = i + 1;
  } while (strcmp(answer, "yes") == 0);

  // Procéder au paiement

  printf(
      "OK ! So you have in your cart %d cars so you will have to pay %.2f $.\n",
      i, cart);
  if (cart != 0) {
    printf("Please enter your card number. (it's for a friend) \n");
    printf("  ->  ");
    verif = scanf("%s",card);
    buffer();
    if ((strlen(card) == 4) && (testAnswer(card) == 1)){
      printf("Thanks !\n");
    }
    else{
      do {
        printf("Your datas are safe with us please enter your number card.\n");
        printf("  ->  ");
        verif = scanf("%s",card);
        buffer();
      } while ((strlen (card) != 4) || (testAnswer(card) == 0));
      printf("Thanks !\n");
    } 
  } else {
    printf("So we hope you will come back soon ! Bye bye !\n");
  }
  return 0;
}
//elyes dcp je fais 3 tableaux stock et 3 fichiers texte pour chaque taille ?