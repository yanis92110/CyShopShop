#include "import.h"
void save_stock(Car* stock, int size, const char* stocktxt) {
    FILE* file = fopen(stocktxt, "w");

    if (file == NULL) {
        printf("Error when trying to open the file.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "Brand: %s\n", stock[i].brand);
        fprintf(file, "Model: %s\n", stock[i].model);
        fprintf(file, "Reference: %d\n", stock[i].reference);
        fprintf(file, "Price: %.2f\n", stock[i].price);
        fprintf(file, "Size: %d\n", stock[i].size);
        fprintf(file, "\n");
    }

    fclose(file);
}

void load_stock(Car** stock, int* size, const char* stocktxt) {
    FILE* file = fopen(stocktxt, "r");

    if (file == NULL) {
        printf("Error when trying to open the file.\n");
        return;
    }

    while (!feof(file)) {
        Car a;
        int verif = 0;

        verif = fscanf(file, "Brand: %s\n", a.brand);
        verif = fscanf(file, "Model: %s\n", a.model);
        verif = fscanf(file, "Reference: %d\n", &a.reference);
        verif = fscanf(file, "Price: %f\n", &a.price);
        verif = fscanf(file, "Size: %d\n", &a.size);

        if (verif == EOF) {
            break;
        }

        if (a.size == 0) {
            (*size) += 1;
            *stock = realloc(*stock, (*size) * sizeof(Car));
            (*stock)[(*size) - 1] = a;
        } else if (a.size == 1) {
            (*size) += 2;
            *stock = realloc(*stock, (*size) * sizeof(Car));
            (*stock)[(*size) - 2] = a;
        } else {
            (*size) += 4;
            *stock = realloc(*stock, (*size) * sizeof(Car));
            (*stock)[(*size) - 4] = a;
        }
    }

    fclose(file);
}
