#include "logInSystem.h" /* 登入系统 */
#include "mainMenu.h" /* 主菜单 */
#include "userPasswordManagement.h" /* 用户密码管理 */

#include <cstdio>
#include <cstdlib>

/* 函数声明，其实现在main函数后 */
void exitPrompt();

int main()
{
	/* 初始化用户密码管理模块 */
	initUserPasswordManagement();

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
void exitPrompt()
{
	system("cls");
	printf("\t\t感谢您使用本超市库存管理系统\n");
	system("pause");
}
