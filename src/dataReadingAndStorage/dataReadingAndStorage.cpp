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
    printf("\t\t|  1. ��ȡ����       |\n");
    printf("\t\t|  2. �洢����       |\n");
    printf("\t\t|  0. ������һ���˵� |\n");
    printf("\t\t  ------------- \n");
    printf("\t\t  ��ѡ���ܣ�");
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
            printf("\t\t�������\n");
            system("pause");
            return;
    }
}

void readData()
{
    system("cls");
    printf("\t\t�������ļ�����");
    char fileName[100];
    scanf("%s", fileName);
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\t\t�ļ���ʧ��\n");
        system("pause");
        return;
    }
    printf("\t\t�ļ��򿪳ɹ�\n");
    products.clear();
    while (!feof(file)) {
        Product product;
        fscanf(file, "%s %s %lf %lf %d %d %d %d\n", product.id, product.name, &product.purchasePrice, &product.sellingPrice, &product.inventory, &product.y, &product.m, &product.d);
        products.push_back(product);
    }
    fclose(file);
    printf("\t\t���ݶ�ȡ�ɹ�\n");
    system("pause");
}

void storeData()
{
    system("cls");
    if (getPermissionDegree() == 1) {
        printf("\t\tȨ�޲���\n");
        system("pause");
        return;
    }
    printf("\t\t�洢����\n");
    printf("\t\t�������ļ�����");
    char fileName[100];
    scanf("%s", fileName);
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("\t\t�ļ���ʧ��\n");
        system("pause");
        return;
    }
    for (int i = 0; i < products.size(); i++) {
        fprintf(file, "%s %s %lf %lf %d %d %d %d\n", products[i].id, products[i].name, products[i].purchasePrice, products[i].sellingPrice, products[i].inventory, products[i].y, products[i].m, products[i].d);
    }
    printf("\t\t���ݴ洢�ɹ�\n");
    fclose(file);
    system("pause");
}