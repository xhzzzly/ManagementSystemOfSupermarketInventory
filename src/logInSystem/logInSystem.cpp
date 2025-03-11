#include "permissionDegree.h"
#include "userPasswordManagement.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int logInSystem(void)
{
    system("cls");
    printf("\t\t   ------------------  \n");
    printf("\t\t|  请选择你要登录的身份  |\n");
    printf("\t\t|  1. 游客               |\n");
    printf("\t\t|  2. 普通员工           |\n");
    printf("\t\t|  3. 管理员             |\n");
    printf("\t\t   ------------------  \n");
    printf("\t\t请输入你的选择：");

    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        setPermissionDegree(1);
    } else if (choice == 2) {
        char password[50];
        printf("\t\t请输入密码：");
        scanf("%s", password);
        if (strcmp(password, getEmployeePassword()) != 0) {
            printf("\t\t密码错误！\n");
            system("pause");
            return 0;
        }
        setPermissionDegree(2);
    } else if (choice == 3) {
        char password[50];
        printf("\t\t请输入密码：");
        scanf("%s", password);
        if (strcmp(password, getAdminPassword()) != 0) {
            printf("\t\t密码错误！\n");
            system("pause");
            return 0;
        }
        setPermissionDegree(3);
    } else {
        printf("\t\t输入错误！\n");
        system("pause");
        return 0;
    }

    printf("\t\t登录成功！\n");
    system("pause");
    return 1;
}