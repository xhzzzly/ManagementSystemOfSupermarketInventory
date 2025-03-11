#ifndef USER_PASSWORD_MANAGEMENT_H
#define USER_PASSWORD_MANAGEMENT_H

void userPasswordManagement(void);

/*
    * 说明：获取普通员工密码
    * 形参：无
    * 返回值：普通员工密码 (char[50])
*/
char* getEmployeePassword(void);

/*
    * 说明：获取管理员密码
    * 形参：无
    * 返回值：管理员密码 (char[50])
*/
char* getAdminPassword(void);

#endif