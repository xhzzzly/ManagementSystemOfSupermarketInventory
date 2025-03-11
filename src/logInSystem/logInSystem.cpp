#include "permissionDegree.h"
#include "userPasswordManagement.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int logInSystem(void)
{
    system("cls");
    printf("\t\t   ------------------  \n");
    printf("\t\t|  ��ѡ����Ҫ��¼�����  |\n");
    printf("\t\t|  1. �ο�               |\n");
    printf("\t\t|  2. ��ͨԱ��           |\n");
    printf("\t\t|  3. ����Ա             |\n");
    printf("\t\t   ------------------  \n");
    printf("\t\t���������ѡ��");

    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        setPermissionDegree(1);
    } else if (choice == 2) {
        char password[50];
        printf("\t\t���������룺");
        scanf("%s", password);
        if (strcmp(password, getEmployeePassword()) != 0) {
            printf("\t\t�������\n");
            system("pause");
            return 0;
        }
        setPermissionDegree(2);
    } else if (choice == 3) {
        char password[50];
        printf("\t\t���������룺");
        scanf("%s", password);
        if (strcmp(password, getAdminPassword()) != 0) {
            printf("\t\t�������\n");
            system("pause");
            return 0;
        }
        setPermissionDegree(3);
    } else {
        printf("\t\t�������\n");
        system("pause");
        return 0;
    }

    printf("\t\t��¼�ɹ���\n");
    system("pause");
    return 1;
}