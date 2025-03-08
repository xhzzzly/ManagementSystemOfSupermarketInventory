#include <stdio.h>
#include <stdlib.h>

#include "config.h" /* �����ļ�������Щȫ�ֱ��� */
#include "logInSystem.h" /* ����ϵͳ */
#include "mainMenu.h" /* ���˵� */

/* ȫ�ֱ�����Ϊ����Դ�ļ�����������˵����config.h�� */
int permission = 0;

/* ������������ʵ����main������ */
void exitPrompt(void);

int main(void)
{
	/* ���빦�� */
	while (logInSystem() == 0) {
		printf("\t\t�Ƿ�������ԣ�����0�˳�ϵͳ��");
		int choice;
		scanf("%d", &choice);
		if (choice == 0) {
			exitPrompt();
			return 0;
		}
	}
	
	/* �������˵� */
	mainMenu();
	
	exitPrompt();
	return 0;
}

/*
 * �������ܣ�ϵͳ�˳���ʾ��
 * ��������
 * ����ֵ����
*/
void exitPrompt(void)
{
	system("cls");
	printf("\t\t��л��ʹ�ñ����п�����ϵͳ\n");
	system("pause");
}
