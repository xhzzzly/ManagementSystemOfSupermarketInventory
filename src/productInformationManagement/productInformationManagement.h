#ifndef PRODUCT_INFORMATION_MANAGEMENT_H
#define PRODUCT_INFORMATION_MANAGEMENT_H

typedef struct {
    char id[100];
    char name[100];
    double purchasePrice;
    double sellingPrice;
    int y, m, d; /* �������� */
} Product;

void productInformationManagement();

#endif