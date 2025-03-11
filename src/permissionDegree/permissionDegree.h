#ifndef PERMISSION_DEGREE_H
#define PERMISSION_DEGREE_H

/*
 * 说明：获取当前权限等级
 * 形参：无
 * 返回值：权限等级：1-游客，2-普通员工，3-管理员
*/
int getPermissionDegree();

void setPermissionDegree(int degree);

#endif