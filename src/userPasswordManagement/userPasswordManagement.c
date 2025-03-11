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
        printf("\t\t未找到密码文件，将使用默认密码。\n");
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
        printf("\t\t密码文件写入失败！你的修改无法保存到文件中。\n");
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
        printf("\t\t权限不足！\n");
        system("pause");
        return;
    }

    printf("\t\t   ----------------------  \n");
    printf("\t\t|  请选择你要修改的密码    |\n");
    printf("\t\t|  1. 普通员工密码         |\n");
    printf("\t\t|  2. 管理员密码           |\n");
    printf("\t\t|  3. 重置所有密码为默认值 |\n");
    printf("\t\t|  0. 返回                 |\n");
    printf("\t\t   ----------------------  \n");
    printf("\t\t请输入你的选择：");

    int choice;
    scanf("%d", &choice);
    char password1[50];
    char password2[50];
    if (choice == 1) {
        printf("\t\t请输入新的普通员工密码：");
        scanf("%s", password1);
        printf("\t\t请再次输入普通员工密码：");
        scanf("%s", password2);
        if (strcmp(password1, password2) != 0) {
            printf("\t\t两次输入不一致！\n");
            system("pause");
            return;
        }
        strcpy(employeePassword, password1);
        writePasswordToFile();
    } else if (choice == 2) {
        printf("\t\t请输入新的管理员密码：");
        scanf("%s", password1);
        printf("\t\t请再次输入管理员密码：");
        scanf("%s", password2);
        if (strcmp(password1, password2) != 0) {
            printf("\t\t两次输入不一致！\n");
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
        printf("\t\t输入错误！\n");
        system("pause");
        return;
    }

    printf("\t\t修改成功！\n");
    system("pause");
}