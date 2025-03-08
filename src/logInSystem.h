#ifndef LOG_IN_SYSTEM_H
#define LOG_IN_SYSTEM_H

#include "config.h"

/* 说明：登入系统函数。登入成功后，会将用户权限写入全局变量permission中
 * 参数：无
 * 返回值：0代表登入失败，1代表登入成功
 * 注意：注意修改变量permission
 */
int logInSystem(void);

#endif