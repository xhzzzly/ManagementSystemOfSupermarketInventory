#ifndef PRODUCT_INFORMATION_MANAGEMENT_H
#define PRODUCT_INFORMATION_MANAGEMENT_H

struct Product {
    char id[100];
    char name[100];
    double purchasePrice;
    double sellingPrice;
    int inventory;
    int y, m, d; /* 限用日期 */
};

#include <vector>
extern std::vector<Product> products;

/*
    * 说明：产品信息管理
    * 输入参数：无
    * 返回值：无
*/
void productInformationManagement();

#endif