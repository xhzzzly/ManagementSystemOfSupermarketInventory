#include <stdio.h>
#include <stdlib.h>

#include "config.h" /* 配置文件，存着些全局变量 */
#include "logInSystem.h" /* 登入系统 */
#include "mainMenu.h" /* 主菜单 */

/* 全局变量，为所有源文件共享，声明及说明在config.h中 */
int permission = 0;

/* 函数声明，其实现在main函数后 */
void exitPrompt(void);

int main(void)
{
	/* 登入功能 */
	while (logInSystem() == 0) {
		printf("\t\t是否继续尝试？输入0退出系统：");
		int choice;
		scanf("%d", &choice);
		if (choice == 0) {
			exitPrompt();
			return 0;
		}
	}
	
	/* 进入主菜单 */
	mainMenu();
	
	exitPrompt();
	return 0;
}

/*
 * 函数功能：系统退出提示语
 * 参数：无
 * 返回值：无
*/
void exitPrompt(void)
{
	system("cls");
	printf("\t\t感谢您使用本超市库存管理系统\n");
	system("pause");
}
