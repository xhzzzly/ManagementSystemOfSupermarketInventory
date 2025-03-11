#include "permissionDegree.h"
#include "productInformationManagement.h"

#include <cstdio>
#include <cstdlib>
#include <vector>

void readData();
void storeData();

void dataReadingAndStorage()
{
    system("cls");
    printf("\t\t  ------------- \n");
    printf("\t\t|  1. 读取数据       |\n");
    printf("\t\t|  2. 存储数据       |\n");
    printf("\t\t|  0. 返回上一级菜单 |\n");
    printf("\t\t  ------------- \n");
    printf("\t\t  请选择功能：");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            readData();
            break;
        case 2:
            storeData();
            break;
        case 0:
            return;
        default:
            printf("\t\t输入错误\n");
            system("pause");
            return;
    }
}

void readData()
{
    system("cls");
    printf("\t\t请输入文件名：");
    char fileName[100];
    scanf("%s", fileName);
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\t\t文件打开失败\n");
        system("pause");
        return;
    }
    printf("\t\t文件打开成功\n");
    products.clear();
    while (!feof(file)) {
        Product product;
        fscanf(file, "%s %s %lf %lf %d %d %d %d\n", product.id, product.name, &product.purchasePrice, &product.sellingPrice, &product.inventory, &product.y, &product.m, &product.d);
        products.push_back(product);
    }
    fclose(file);
    printf("\t\t数据读取成功\n");
    system("pause");
}

void storeData()
{
    system("cls");
    if (getPermissionDegree() == 1) {
        printf("\t\t权限不足\n");
        system("pause");
        return;
    }
    printf("\t\t存储数据\n");
    printf("\t\t请输入文件名：");
    char fileName[100];
    scanf("%s", fileName);
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("\t\t文件打开失败\n");
        system("pause");
        return;
    }
    for (int i = 0; i < products.size(); i++) {
        fprintf(file, "%s %s %lf %lf %d %d %d %d\n", products[i].id, products[i].name, products[i].purchasePrice, products[i].sellingPrice, products[i].inventory, products[i].y, products[i].m, products[i].d);
    }
    printf("\t\t数据存储成功\n");
    fclose(file);
    system("pause");
}