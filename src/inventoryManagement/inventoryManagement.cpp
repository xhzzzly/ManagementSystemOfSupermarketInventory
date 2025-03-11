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
    printf("\t\t|  1. ���           |\n");
    printf("\t\t|  2. ����           |\n");
    printf("\t\t|  3. ���Ԥ��       |\n");
    printf("\t\t|  4. ��������Ԥ��   |\n");
    printf("\t\t|  0. ������һ���˵� |\n");
    printf("\t\t  ------------- \n");
    printf("\t\t  ��ѡ���ܣ�");
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
            printf("\t\t�����������������\n");
            system("pause");
            break;
    }
}

void goodsIn()
{
    system("cls");
    if (getPermissionDegree() == 1) {
        printf("\t\tȨ�޲���\n");
        system("pause");
        return;
    }
    printf("\t\t��������ƷID��");
    char id[100];
    scanf("%s", id);
    for (int i = 0; i < products.size(); i++) {
        if (strcmp(products[i].id, id) == 0) {
            products[i].inventory++;
            printf("\t\t���ɹ�\n");
            system("pause");
            return;
        }
    }
    printf("\t\tδ�ҵ�����Ʒ\n");
    system("pause");
}

void goodsOut()
{
    system("cls");
    if (getPermissionDegree() == 1) {
        printf("\t\tȨ�޲���\n");
        system("pause");
        return;
    }
    printf("\t\t��������ƷID��");
    char id[100];
    scanf("%s", id);
    for (int i = 0; i < products.size(); i++) {
        if (strcmp(products[i].id, id) == 0) {
            products[i].inventory--;
            if (products[i].inventory >= 0) {
                printf("\t\t����ɹ�\n");
            } else {
                products[i].inventory = 0;
                printf("\t\t��治�ܵ���0������Ϊ0\n");
            }
            system("pause");
            return;
        }
    }
    printf("\t\tδ�ҵ�����Ʒ\n");
    system("pause");
}

void inventoryWarning()
{
    system("cls");
    printf("\t\t��������Ԥ��ֵ��");
    int warningValue;
    scanf("%d", &warningValue);
    for (int i = 0; i < products.size(); i++) {
        if (products[i].inventory < warningValue) {
            printf("\t\t��ƷID��%s ��治��\n", products[i].id);
        }
    }
    for (int i = 0; i < products.size(); i++) {
        if (products[i].inventory < warningValue - 10 && products[i].inventory >= warningValue) {
            printf("\t\t��ƷID��%s ���ӽ�Ԥ��ֵ\n", products[i].id);
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
    printf("\t\t��������������Ԥ��ֵ��");
    int warningValue;
    scanf("%d", &warningValue);
    for (int i = 0; i < products.size(); i++) {
        if (compareDate(products[i], products[0]) < warningValue) {
            printf("\t\t��ƷID��%s �������ڲ���\n", products[i].id);
        }
    }
    for (int i = 0; i < products.size(); i++) {
        if (compareDate(products[i], products[0]) < warningValue - 10 && compareDate(products[i], products[0]) >= warningValue) {
            printf("\t\t��ƷID��%s �������ڽӽ�Ԥ��ֵ\n", products[i].id);
        }
    }
    system("pause");
}