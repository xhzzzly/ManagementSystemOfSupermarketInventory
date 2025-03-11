#ifndef USER_PASSWORD_MANAGEMENT_H
#define USER_PASSWORD_MANAGEMENT_H

/*
    * 说明：初始化用户密码管理模块
    * 形参：无
    * 返回值：无

*/
void initUserPasswordManagement();

/*
    * 说明：用户密码管理
    * 形参：无
    * 返回值：无
*/
void userPasswordManagement();

/*
    * 说明：获取普通员工密码
    * 形参：无
    * 返回值：普通员工密码 (char[50])
*/
char* getEmployeePassword();

/*
    * 说明：获取管理员密码
    * 形参：无
    * 返回值：管理员密码 (char[50])
*/
char* getAdminPassword();

#endif