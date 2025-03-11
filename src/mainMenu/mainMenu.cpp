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

        // ���빦�ܵ�Ȩ���ж������ӹ���ģ��

        printf("\t\t   ---------------  \n");
        printf("\t\t|  ���п�����ϵͳ  |\n");
        printf("\t\t|  1. ��Ʒ��Ϣ����   |\n");
        printf("\t\t|  2. ������       |\n");
        printf("\t\t|  3. �û��������   |\n");
        printf("\t\t|  4. ���ݶ�ȡ��洢 |\n");
        printf("\t\t|  0. �˳�ϵͳ       |\n");
        printf("\t\t   ---------------  \n");
        printf("\t\t��ѡ��");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            return;
        case 1:
            /* ��Ʒ��Ϣ���� */
            productInformationManagement();
            break;
        case 2:
            /* ������ */
            inventoryManagement();
            break;
        case 3:
            /* �û�������� */
            userPasswordManagement();
            break;
        case 4:
            /* ���ݶ�ȡ��洢 */
            dataReadingAndStorage();
            break;
        default:
            printf("\t\t�����������������\n");
            system("pause");
            break;
        }
    }
}