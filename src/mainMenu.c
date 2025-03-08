#include "mainMenu.h"

#include <stdio.h>
#include <stdlib.h>

void mainMenu(void)
{
    while (1) {
        system("cls");
        printf("\t\t   ---------------  \n");
        printf("\t\t|  超市库存管理系统  |\n");
        printf("\t\t|  1. 商品信息管理   |\n");
        printf("\t\t|  2. 库存管理       |\n");
        printf("\t\t|  3. 用户密码管理   |\n");
        printf("\t\t|  4. 数据读取与存储 |\n");
        printf("\t\t|  0. 退出系统       |\n");
        printf("\t\t   ---------------  \n");
        printf("\t\t请选择：");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            return;
        case 1:
            /* 商品信息管理 */
            break;
        case 2:
            /* 库存管理 */
            break;
        case 3:
            /* 用户密码管理 */
            break;
        case 4:
            /* 数据读取与存储 */
            break;
        default:
            printf("\t\t输入错误，请重新输入\n");
            system("pause");
            break;
        }
    }
}