#include "header.h"
#include <ncurses.h>
//#include "gameplay_buyer2.c"
//#include "gameplay_manager.c"
//#include "tests.c"

#define MAX_CLIENTS 100
#define MAX_STOCK 100


int main() {
    int choix;
    
    // Initialisation de ncurses
    initscr();
    clear();
    noecho();
    cbreak();
    
    // Affichage du menu d'accueil
    printw("------------------------------\n");
    printw("        Cy ShopShop\n");
    printw("    Concession de voitures\n");
    printw("------------------------------\n\n");
    printw("Appuyez sur n'importe quelle touche pour continuer...\n");
    refresh();
    getch();
    clear();
    
    do {
        printw("----- Concession de voitures -----\n");
        printw("1. Buyer mode\n");
        printw("2. Manager mode\n");
        printw("3. Leave\n");
        printw("Choice : ");
        refresh();
        
        echo();
        scanw("%d", &choix);
        noecho();
        
        switch (choix) {
            case 1:
                clear();
                main_gp_buyer2();
                break;
            case 2:
                clear();
                main_manager();
                break;
            case 3:
                clear();
                printw("Merci d'avoir utilisé notre concession de voitures. Au revoir !\n");
                break;
            default:
                clear();
                printw("Choix invalide. Veuillez sélectionner une option valide.\n");
                break;
        }

        printw("\nAppuyez sur n'importe quelle touche pour continuer...\n");
        refresh();
        getch();
        clear();
    } while (choix != 3);

    // Restauration des paramètres du terminal
    endwin();

    return 0;
}
