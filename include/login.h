#ifndef __login_H__
#define __login_H__
#include "allfunc.h"
#pragma pack(push, 1) // ����Ϊ1�ֽڶ���
 typedef struct
    {
        char user_name[10];         // �û���
        char pass_word[10];         // ����
        int fine[8];                // ��һ��Υ�½��ڶ���Υ�¿۷�,�������Ӧ����Ҫ��,
        int if_fine;                // �Ƿ�Υ��
        int if_against;             // �Ƿ�����
        char fine_time[20];         // Υ��ʱ��
        char carboard[80];       // ���ƺţ�ÿ�����ƺ����9���ַ� + '\0'
        char brand[10];            // ����Ʒ��
        int location;             // Υ�µص�
        int violation;           // Υ����Ϊ*/
        
    } USERS;
 #pragma pack(pop)   
//�����¼
void staff_login(int* func);

//���Ƶ�¼����
void draw_user_login(void);
//�û���¼����
void user_login(int *func,int *unum);
//ע��
void rigister_login(int *func);


#endif