#include "permissionDegree.h"
#include "productInformationManagement.h"
#include "inventoryManagement.h"
#include "userPasswordManagement.h"
#include "dataReadingAndStorage.h"

#include <cstdio>
#include <cstdlib>

void mainMenu()
{
    while (1) {
        system("cls");

        // 进入功能的权限判断留给子功能模块

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
            productInformationManagement();
            break;
        case 2:
            /* 库存管理 */
            inventoryManagement();
            break;
        case 3:
            /* 用户密码管理 */
            userPasswordManagement();
            break;
        case 4:
            /* 数据读取与存储 */
            dataReadingAndStorage();
            break;
        default:
            printf("\t\t输入错误，请重新输入\n");
            system("pause");
            break;
        }
    }
}