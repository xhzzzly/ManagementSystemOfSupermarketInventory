#ifndef USER_PASSWORD_MANAGEMENT_H
#define USER_PASSWORD_MANAGEMENT_H

/*
    * ˵������ʼ���û��������ģ��
    * �βΣ���
    * ����ֵ����

*/
void initUserPasswordManagement(void);

/*
    * ˵�����û��������
    * �βΣ���
    * ����ֵ����
*/
void userPasswordManagement(void);

/*
    * ˵������ȡ��ͨԱ������
    * �βΣ���
    * ����ֵ����ͨԱ������ (char[50])
*/
char* getEmployeePassword(void);

/*
    * ˵������ȡ����Ա����
    * �βΣ���
    * ����ֵ������Ա���� (char[50])
*/
char* getAdminPassword(void);

#endif