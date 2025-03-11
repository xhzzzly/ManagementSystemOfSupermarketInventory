#include "productInformationManagement.h"
#include "permissionDegree.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

std::vector<Product> products;

void addProduct();
void modifyProduct();
void deleteProduct();
void searchProduct();
void displayProduct();

void productInformationManagement()
{
    system("cls");
    printf("\t\t  ------------------ \n");
    printf("\t\t|  1. 添加商品信息    |\n");
    printf("\t\t|  2. 修改商品信息    |\n");
    printf("\t\t|  3. 删除商品信息    |\n");
    printf("\t\t|  4. 查询商品信息    |\n");
    printf("\t\t|  6. 显示商品信息    |\n");
    printf("\t\t|  0. 返回上一级菜单  |\n");
    printf("\t\t  ------------------ \n");
    printf("\t\t  请选择功能：");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            modifyProduct();
            break;
        case 3:
            deleteProduct();
            break;
        case 4:
            searchProduct();
            break;
        case 5:
            displayProduct();
            break;
        case 6:
            displayProduct();
            break;
        case 0:
            return;
        default:
            printf("\t\t输入错误，请重新输入\n");
            system("pause");
            break;
    }
}

void addProduct()
{
    if (getPermissionDegree() == 1) {
        printf("\t\t您没有权限进行此操作\n");
        system("pause");
        return;
    }
    Product product;
    printf("\t\t请输入商品ID：");
    scanf("%s", product.id);
    printf("\t\t请输入商品名称：");
    scanf("%s", product.name);
    printf("\t\t请输入商品进价：");
    scanf("%lf", &product.purchasePrice);
    printf("\t\t请输入商品售价：");
    scanf("%lf", &product.sellingPrice);
    printf("\t\t请输入商品限用日期（年 月 日）：");
    scanf("%d %d %d", &product.y, &product.m, &product.d);
    products.push_back(product);
    printf("\t\t商品添加成功\n");
    system("pause");
}

void modifyProduct()
{
    if (getPermissionDegree() != 3) {
        printf("\t\t您没有权限进行此操作\n");
        system("pause");
        return;
    }
    printf("\t\t请输入要修改的商品ID：");
    char id[100];
    scanf("%s", id);
    for (int i = 0; i < products.size(); i++) {
        if (strcmp(products[i].id, id) == 0) {
            printf("\t\t请输入新的商品ID：");
            scanf("%s", products[i].id);
            printf("\t\t请输入新的商品名称：");
            scanf("%s", products[i].name);
            printf("\t\t请输入新的商品进价：");
            scanf("%lf", &products[i].purchasePrice);
            printf("\t\t请输入新的商品售价：");
            scanf("%lf", &products[i].sellingPrice);
            printf("\t\t请输入新的商品限用日期（年 月 日，以空格分隔）：");
            scanf("%d %d %d", &products[i].y, &products[i].m, &products[i].d);
            printf("\t\t商品修改成功\n");
            system("pause");
            return;
        }
    }
    printf("\t\t未找到该商品\n");
    system("pause");
}

void deleteProduct()
{
    if (getPermissionDegree() != 3) {
        printf("\t\t您没有权限进行此操作\n");
        system("pause");
        return;
    }
    printf("\t\t请输入要删除的商品ID：");
    char id[100];
    scanf("%s", id);
    for (int i = 0; i < products.size(); i++) {
        if (strcmp(products[i].id, id) == 0) {
            products.erase(products.begin() + i);
            printf("\t\t商品删除成功\n");
            system("pause");
            return;
        }
    }
    printf("\t\t未找到该商品\n");
    system("pause");
}

void searchProduct()
{
    printf("\t\t1. 按商品ID查询\n");
    printf("\t\t2. 按商品名称查询\n");
    printf("\t\t请选择查询方式：");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("\t\t请输入商品ID：");
            char id[100];
            scanf("%s", id);
            for (int i = 0; i < products.size(); i++) {
                if (strcmp(products[i].id, id) == 0) {
                    printf("\t\t商品ID：%s\n", products[i].id);
                    printf("\t\t商品名称：%s\n", products[i].name);
                    printf("\t\t商品进价：%.2lf\n", products[i].purchasePrice);
                    printf("\t\t商品售价：%.2lf\n", products[i].sellingPrice);
                    printf("\t\t商品限用日期：%d年%d月%d日\n", products[i].y, products[i].m, products[i].d);
                    system("pause");
                    return;
                }
            }
            printf("\t\t未找到该商品\n");
            system("pause");
            break;
        case 2:
            printf("\t\t请输入商品名称：");
            char name[100];
            scanf("%s", name);
            for (int i = 0; i < products.size(); i++) {
                if (strcmp(products[i].name, name) == 0) {
                    printf("\t\t商品ID：%s\n", products[i].id);
                    printf("\t\t商品名称：%s\n", products[i].name);
                    printf("\t\t商品进价：%.2lf\n", products[i].purchasePrice);
                    printf("\t\t商品售价：%.2lf\n", products[i].sellingPrice);
                    printf("\t\t商品限用日期：%d年%d月%d日\n", products[i].y, products[i].m, products[i].d);
                    system("pause");
                    return;
                }
            }
            printf("\t\t未找到该商品\n");
            system("pause");
            break;
        default:
            printf("\t\t输入错误，请重新输入\n");
            system("pause");
            break;
    }
}

void displayProduct()
{
    for (int i = 0; i < products.size(); i++) {
        printf("\t\t商品ID：%s\n", products[i].id);
        printf("\t\t商品名称：%s\n", products[i].name);
        printf("\t\t商品进价：%.2lf\n", products[i].purchasePrice);
        printf("\t\t商品售价：%.2lf\n", products[i].sellingPrice);
        printf("\t\t商品限用日期：%d年%d月%d日\n", products[i].y, products[i].m, products[i].d);
    }
    system("pause");
}
