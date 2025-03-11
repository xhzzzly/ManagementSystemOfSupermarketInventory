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
    printf("\t\t|  1. �����Ʒ��Ϣ    |\n");
    printf("\t\t|  2. �޸���Ʒ��Ϣ    |\n");
    printf("\t\t|  3. ɾ����Ʒ��Ϣ    |\n");
    printf("\t\t|  4. ��ѯ��Ʒ��Ϣ    |\n");
    printf("\t\t|  6. ��ʾ��Ʒ��Ϣ    |\n");
    printf("\t\t|  0. ������һ���˵�  |\n");
    printf("\t\t  ------------------ \n");
    printf("\t\t  ��ѡ���ܣ�");
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
            printf("\t\t�����������������\n");
            system("pause");
            break;
    }
}

void addProduct()
{
    if (getPermissionDegree() == 1) {
        printf("\t\t��û��Ȩ�޽��д˲���\n");
        system("pause");
        return;
    }
    Product product;
    printf("\t\t��������ƷID��");
    scanf("%s", product.id);
    printf("\t\t��������Ʒ���ƣ�");
    scanf("%s", product.name);
    printf("\t\t��������Ʒ���ۣ�");
    scanf("%lf", &product.purchasePrice);
    printf("\t\t��������Ʒ�ۼۣ�");
    scanf("%lf", &product.sellingPrice);
    printf("\t\t��������Ʒ�������ڣ��� �� �գ���");
    scanf("%d %d %d", &product.y, &product.m, &product.d);
    products.push_back(product);
    printf("\t\t��Ʒ��ӳɹ�\n");
    system("pause");
}

void modifyProduct()
{
    if (getPermissionDegree() != 3) {
        printf("\t\t��û��Ȩ�޽��д˲���\n");
        system("pause");
        return;
    }
    printf("\t\t������Ҫ�޸ĵ���ƷID��");
    char id[100];
    scanf("%s", id);
    for (int i = 0; i < products.size(); i++) {
        if (strcmp(products[i].id, id) == 0) {
            printf("\t\t�������µ���ƷID��");
            scanf("%s", products[i].id);
            printf("\t\t�������µ���Ʒ���ƣ�");
            scanf("%s", products[i].name);
            printf("\t\t�������µ���Ʒ���ۣ�");
            scanf("%lf", &products[i].purchasePrice);
            printf("\t\t�������µ���Ʒ�ۼۣ�");
            scanf("%lf", &products[i].sellingPrice);
            printf("\t\t�������µ���Ʒ�������ڣ��� �� �գ��Կո�ָ�����");
            scanf("%d %d %d", &products[i].y, &products[i].m, &products[i].d);
            printf("\t\t��Ʒ�޸ĳɹ�\n");
            system("pause");
            return;
        }
    }
    printf("\t\tδ�ҵ�����Ʒ\n");
    system("pause");
}

void deleteProduct()
{
    if (getPermissionDegree() != 3) {
        printf("\t\t��û��Ȩ�޽��д˲���\n");
        system("pause");
        return;
    }
    printf("\t\t������Ҫɾ������ƷID��");
    char id[100];
    scanf("%s", id);
    for (int i = 0; i < products.size(); i++) {
        if (strcmp(products[i].id, id) == 0) {
            products.erase(products.begin() + i);
            printf("\t\t��Ʒɾ���ɹ�\n");
            system("pause");
            return;
        }
    }
    printf("\t\tδ�ҵ�����Ʒ\n");
    system("pause");
}

void searchProduct()
{
    printf("\t\t1. ����ƷID��ѯ\n");
    printf("\t\t2. ����Ʒ���Ʋ�ѯ\n");
    printf("\t\t��ѡ���ѯ��ʽ��");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("\t\t��������ƷID��");
            char id[100];
            scanf("%s", id);
            for (int i = 0; i < products.size(); i++) {
                if (strcmp(products[i].id, id) == 0) {
                    printf("\t\t��ƷID��%s\n", products[i].id);
                    printf("\t\t��Ʒ���ƣ�%s\n", products[i].name);
                    printf("\t\t��Ʒ���ۣ�%.2lf\n", products[i].purchasePrice);
                    printf("\t\t��Ʒ�ۼۣ�%.2lf\n", products[i].sellingPrice);
                    printf("\t\t��Ʒ�������ڣ�%d��%d��%d��\n", products[i].y, products[i].m, products[i].d);
                    system("pause");
                    return;
                }
            }
            printf("\t\tδ�ҵ�����Ʒ\n");
            system("pause");
            break;
        case 2:
            printf("\t\t��������Ʒ���ƣ�");
            char name[100];
            scanf("%s", name);
            for (int i = 0; i < products.size(); i++) {
                if (strcmp(products[i].name, name) == 0) {
                    printf("\t\t��ƷID��%s\n", products[i].id);
                    printf("\t\t��Ʒ���ƣ�%s\n", products[i].name);
                    printf("\t\t��Ʒ���ۣ�%.2lf\n", products[i].purchasePrice);
                    printf("\t\t��Ʒ�ۼۣ�%.2lf\n", products[i].sellingPrice);
                    printf("\t\t��Ʒ�������ڣ�%d��%d��%d��\n", products[i].y, products[i].m, products[i].d);
                    system("pause");
                    return;
                }
            }
            printf("\t\tδ�ҵ�����Ʒ\n");
            system("pause");
            break;
        default:
            printf("\t\t�����������������\n");
            system("pause");
            break;
    }
}

void displayProduct()
{
    for (int i = 0; i < products.size(); i++) {
        printf("\t\t��ƷID��%s\n", products[i].id);
        printf("\t\t��Ʒ���ƣ�%s\n", products[i].name);
        printf("\t\t��Ʒ���ۣ�%.2lf\n", products[i].purchasePrice);
        printf("\t\t��Ʒ�ۼۣ�%.2lf\n", products[i].sellingPrice);
        printf("\t\t��Ʒ�������ڣ�%d��%d��%d��\n", products[i].y, products[i].m, products[i].d);
    }
    system("pause");
}
