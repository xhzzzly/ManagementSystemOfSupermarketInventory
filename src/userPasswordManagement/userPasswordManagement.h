#ifndef USER_PASSWORD_MANAGEMENT_H
#define USER_PASSWORD_MANAGEMENT_H

/*
    * ˵������ʼ���û��������ģ��
    * �βΣ���
    * ����ֵ����

*/
void initUserPasswordManagement();

/*
    * ˵�����û��������
    * �βΣ���
    * ����ֵ����
*/
void userPasswordManagement();

/*
    * ˵������ȡ��ͨԱ������
    * �βΣ���
    * ����ֵ����ͨԱ������ (char[50])
*/
char* getEmployeePassword();

/*
    * ˵������ȡ����Ա����
    * �βΣ���
    * ����ֵ������Ա���� (char[50])
*/
char* getAdminPassword();

#endif