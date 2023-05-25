
#include"header.h"



int main_del(){
    int sizecita = 0;
    int sizesuv = 0;
    int sizesport = 0;
    Car stockcita[MAX_STOCK_SIZE];
    Car stocksuv[MAX_STOCK_SIZE];
    Car stocksport[MAX_STOCK_SIZE];
    //load_stock(stocksuv,&sizesuv, "stocksuv.txt");
    //delete_car(stocksuv, sizesuv, "stocksuv.txt");
    load_stock(stocksport,&sizesport, "stocksport.txt");
    delete_car(stocksport, sizesport, "stocksport.txt");
    return 0;
}