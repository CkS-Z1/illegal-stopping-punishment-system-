#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void location_input(char* location_output[], int location_num)
{
    char* location[12] = 
    {
        "���Ƹ�С", "ͼ���", "��е¥", "����ѧԺ", "������", 
        "�϶���", "�����ѧԺ", "����ѧԺ", "�вٳ�", "����������", 
        "����԰", "ѧ����������"
    };

    // Ϊ location_output[location_num] �����ڴ�
    location_output[location_num] = malloc(strlen(location[location_num]) + 1);
    if (location_output[location_num] == NULL)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        return;
    }

    // �����ַ���
    strcpy(location_output[location_num], location[location_num]);
}
void violation_input(char* violation_output[12][4], int location, int violation)
{
    // Υͣ��ΪԤ��
    char* locations[12][4] = 
    {
        {"δ���涨ͣ������������ͨ��", "����ռ�����е�", "����ͣ�ڽ�ͣ����", "����ͣ��У԰�����"},
        {"����ͣ��ͼ������", "δ���涨ͣ��", "ռ�òм���ͣ��λ", "����ͣ���̻�����"},
        {"����ͣ�ڻ�е¥�����", "δ���涨ͣ��", "����ͣ������˨ǰ", "����ͣ��Ӧ��ͨ��"},
        {"����ͣ�ڹ���ѧԺ���", "δ���涨ͣ��", "ռ�ý�ְ��ͣ��λ", "����ͣ���̻�����"},
        {"����ͣ�����������", "δ���涨ͣ��", "����ͣ��Ӧ��ͨ��", "����ͣ�ڹ���ͨ��"},
        {"����ͣ���϶��ų����", "δ���涨ͣ��", "����ͣ�����е���", "����ͣ�ڽ�ͣ����"},
        {"ռ��ʵ�����豸װж��", "ͣ��ѧԺ����̨��ǰ", "ռ������Դ�����λ", "��ռ����ר��ͣ����"},
        {"ͣ���������ͨ��", "��ѧԺ����·��Υͣ", "ռ�÷ÿͳ�λ", "������˨ǰΥ��ͣ��"},
        {"ͣ�����˶���Ӧ��ͨ��", "ռ���ܵ��ܱ߻�����", "�ڹ���ϯ�����ͣ��", "��ռ�ٳ���Χ�ǻ�������"},
        {"��������¥����ͨ��", "ռ����������ר�ó�λ", "���������г���ǰͣ��", "ҹ��Υͣ����ʱ��ͣ��"},
        {"ʻ��԰���̵�ͣ��", "ռ���ּ䲽�е�", "�ں��߹۾�ƽ̨Υͣ", "ͣ����԰����խ·��"},
        {"�ڻ��鳵����ڴ�ͣ��", "ͣ�������ľ����̻���","����������Ա����ͨ��","δ���涨ͣ��"}
    };

    // Ϊ violation_output[location][violation] �����ڴ�
    violation_output[location][violation] = malloc(strlen(locations[location][violation]) + 1);
    if (violation_output[location][violation] == NULL)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        return;
    }

    // �����ַ���
    strcpy(violation_output[location][violation], locations[location][violation]);
}