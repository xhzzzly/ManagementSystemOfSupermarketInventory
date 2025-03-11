#include "permissionDegree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char employeePassword[50] = "employee";
char adminPassword[50] = "admin";

char* getEmployeePassword(void)
{
    return employeePassword;
}

char* getAdminPassword(void)
{
    return adminPassword;
}

void initUserPasswordManagement(void)
{
    FILE *fp = fopen("password.dat", "rb");
    if (fp == NULL) {
        printf("\t\tδ�ҵ������ļ�����ʹ��Ĭ�����롣\n");
        system("pause");
        return;
    } else {
        fread(employeePassword, sizeof(char), 50, fp);
        fread(adminPassword, sizeof(char), 50, fp);
        fclose(fp);
    }
}

void writePasswordToFile(void)
{
    FILE *fp = fopen("password.dat", "wb");
    if (fp == NULL) {
        printf("\t\t�����ļ�д��ʧ�ܣ�����޸��޷����浽�ļ��С�\n");
        system("pause");
        return;
    } else {
        fwrite(employeePassword, sizeof(char), 50, fp);
        fwrite(adminPassword, sizeof(char), 50, fp);
        fclose(fp);
    }
}

void userPasswordManagement(void)
{
    system("cls");

    if (getPermissionDegree() != 3) {
        printf("\t\tȨ�޲��㣡\n");
        system("pause");
        return;
    }

    printf("\t\t   ----------------------  \n");
    printf("\t\t|  ��ѡ����Ҫ�޸ĵ�����    |\n");
    printf("\t\t|  1. ��ͨԱ������         |\n");
    printf("\t\t|  2. ����Ա����           |\n");
    printf("\t\t|  3. ������������ΪĬ��ֵ |\n");
    printf("\t\t|  0. ����                 |\n");
    printf("\t\t   ----------------------  \n");
    printf("\t\t���������ѡ��");

    int choice;
    scanf("%d", &choice);
    char password1[50];
    char password2[50];
    if (choice == 1) {
        printf("\t\t�������µ���ͨԱ�����룺");
        scanf("%s", password1);
        printf("\t\t���ٴ�������ͨԱ�����룺");
        scanf("%s", password2);
        if (strcmp(password1, password2) != 0) {
            printf("\t\t�������벻һ�£�\n");
            system("pause");
            return;
        }
        strcpy(employeePassword, password1);
        writePasswordToFile();
    } else if (choice == 2) {
        printf("\t\t�������µĹ���Ա���룺");
        scanf("%s", password1);
        printf("\t\t���ٴ��������Ա���룺");
        scanf("%s", password2);
        if (strcmp(password1, password2) != 0) {
            printf("\t\t�������벻һ�£�\n");
            system("pause");
            return;
        }
        strcpy(adminPassword, password1);
        writePasswordToFile();
    } else if (choice == 3) {
        strcpy(employeePassword, "employee");
        strcpy(adminPassword, "admin");
        writePasswordToFile();
    } else if (choice == 0) {
        return;
    } else {
        printf("\t\t�������\n");
        system("pause");
        return;
    }

    printf("\t\t�޸ĳɹ���\n");
    system("pause");
}