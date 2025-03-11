#ifndef PRODUCT_INFORMATION_MANAGEMENT_H
#define PRODUCT_INFORMATION_MANAGEMENT_H

struct Product {
    char id[100];
    char name[100];
    double purchasePrice;
    double sellingPrice;
    int inventory;
    int y, m, d; /* �������� */
};

#include <vector>
extern std::vector<Product> products;

void productInformationManagement();

#endif