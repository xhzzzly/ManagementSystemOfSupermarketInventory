#include "mainMenu.h"

#include <stdio.h>
#include <stdlib.h>

void mainMenu(void)
{
    while (1) {
        system("cls");
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
            break;
        case 2:
            /* ������ */
            break;
        case 3:
            /* �û�������� */
            break;
        case 4:
            /* ���ݶ�ȡ��洢 */
            break;
        default:
            printf("\t\t�����������������\n");
            system("pause");
            break;
        }
    }
}