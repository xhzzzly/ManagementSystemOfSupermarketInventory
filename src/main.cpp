#include "logInSystem.h" /* ����ϵͳ */
#include "mainMenu.h" /* ���˵� */
#include "userPasswordManagement.h" /* �û�������� */

#include <cstdio>
#include <cstdlib>

/* ������������ʵ����main������ */
void exitPrompt();

int main()
{
	/* ��ʼ���û��������ģ�� */
	initUserPasswordManagement();

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
void exitPrompt()
{
	system("cls");
	printf("\t\t��л��ʹ�ñ����п�����ϵͳ\n");
	system("pause");
}
