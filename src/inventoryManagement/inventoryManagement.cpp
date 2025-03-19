#include "permissionDegree.h"
#include "productInformationManagement.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

void goodsIn();
void goodsOut();
void inventoryWarning();
void expirationDateWarning();

void inventoryManagement()
{
    system("cls");
    printf("\t\t  ------------- \n");
    printf("\t\t|  1. 入库           |\n");
    printf("\t\t|  2. 出库           |\n");
    printf("\t\t|  3. 库存预警       |\n");
    printf("\t\t|  4. 限用日期预警   |\n");
    printf("\t\t|  0. 返回上一级菜单 |\n");
    printf("\t\t  ------------- \n");
    printf("\t\t  请选择功能：");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            goodsIn();
            break;
        case 2:
            goodsOut();
            break;
        case 3:
            inventoryWarning();
            break;
        case 4:
            expirationDateWarning();
            break;
        case 0:
            return;
        default:
            printf("\t\t输入错误，请重新输入\n");
            system("pause");
            break;
    }
}

void goodsIn()
{
    system("cls");
    if (getPermissionDegree() == 1) {
        printf("\t\t权限不足\n");
        system("pause");
        return;
    }
    printf("\t\t请输入商品ID：");
    char id[100];
    scanf("%s", id);
    for (int i = 0; i < products.size(); i++) {
        if (strcmp(products[i].id, id) == 0) {
            products[i].inventory++;
            printf("\t\t入库成功\n");
            system("pause");
            return;
        }
    }
    printf("\t\t未找到该商品\n");
    system("pause");
}

void goodsOut()
{
    system("cls");
    if (getPermissionDegree() == 1) {
        printf("\t\t权限不足\n");
        system("pause");
        return;
    }
    printf("\t\t请输入商品ID：");
    char id[100];
    scanf("%s", id);
    for (int i = 0; i < products.size(); i++) {
        if (strcmp(products[i].id, id) == 0) {
            products[i].inventory--;
            if (products[i].inventory >= 0) {
                printf("\t\t出库成功\n");
            } else {
                products[i].inventory = 0;
                printf("\t\t库存不能低于0，已置为0\n");
            }
            system("pause");
            return;
        }
    }
    printf("\t\t未找到该商品\n");
    system("pause");
}

void inventoryWarning()
{
    system("cls");
    printf("\t\t请输入库存预警值：");
    int warningValue;
    scanf("%d", &warningValue);
    for (int i = 0; i < products.size(); i++) {
        if (products[i].inventory < warningValue) {
            printf("\t\t商品ID：%s 库存不足\n", products[i].id);
        }
    }
    for (int i = 0; i < products.size(); i++) {
        if (products[i].inventory < warningValue - 10 && products[i].inventory >= warningValue) {
            printf("\t\t商品ID：%s 库存接近预警值\n", products[i].id);
        }
    }
    system("pause");
}

int compareDate(const Product &a, const Product &b)
{
    return (a.y - b.y) * 365 + (a.m - b.m) * 30 + (a.d - b.d);
}

void expirationDateWarning()
{
    system("cls");
    printf("\t\t请输入限用日期预警值：");
    int warningValue;
    scanf("%d", &warningValue);
    for (int i = 0; i < products.size(); i++) {
        if (compareDate(products[i], products[0]) < warningValue) {
            printf("\t\t商品ID：%s 限用日期不足\n", products[i].id);
        }
    }
    for (int i = 0; i < products.size(); i++) {
        if (compareDate(products[i], products[0]) < warningValue - 10 && compareDate(products[i], products[0]) >= warningValue) {
            printf("\t\t商品ID：%s 限用日期接近预警值\n", products[i].id);
        }
    }
    system("pause");
}