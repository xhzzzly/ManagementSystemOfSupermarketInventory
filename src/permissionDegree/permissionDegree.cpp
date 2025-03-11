/* 0为默认值，1为游客，2为普通员工，3为管理员*/
int permission = 0;

int getPermissionDegree() {
    return permission;
}

void setPermissionDegree(int degree) {
    permission = degree;
}