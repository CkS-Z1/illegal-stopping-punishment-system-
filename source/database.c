#include"allfunc.h"
void data_select(char* username)
{
   
    FILE *fp;
    USERS temp;
    int found=0;
    if((fp=fopen("data.dat","rb+"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    while(fread(&temp,sizeof(USERS),1,fp))
    {
        if(strcmp(temp.user_name,username)==0)
        {
            found=1;
            break;
        }
        
    }
    fclose(fp);
    if(found)
    {
        FILE *fp1;
        if((fp1=fopen("data1.dat","wb"))==NULL)
        {
            printf("error!\n");
            exit(0);
        }
        fwrite(&temp,sizeof(USERS),1,fp1);
        fclose(fp1);
    }
        
}
void data_reselect()
{
    FILE *fp, *fp1;
    USERS temp, temp1;
    long record_pos = 0;
    int found = 0;

    // ����ʱ�ļ�
    if ((fp = fopen("data1.dat", "rb")) == NULL) 
    {
        perror("�޷�����ʱ�ļ�");
        exit(EXIT_FAILURE);
    }
    fseek(fp, -(long)sizeof(USERS), SEEK_END); // ��λ���ļ�ĩβǰ�����һ���ṹ��
    // ��ȡ��ʱ����
    if (fread(&temp, sizeof(USERS), 1, fp) != 1) 
    {
        fclose(fp);
        printf("��ʱ�ļ���ȡʧ��\n");
        return;
    }
    fclose(fp);

    // �����ļ�
    if ((fp1 = fopen("data.dat", "rb+")) == NULL) 
    {
        perror("�޷������ļ�");
        exit(EXIT_FAILURE);
    }

    // ����ƥ���¼
    while ( fread(&temp1, sizeof(USERS), 1, fp1) == 1) 
    {
        if (strcmp(temp1.user_name, temp.user_name) == 0)
         {
            found = 1;
            record_pos = ftell(fp1) - sizeof(USERS);
        }
    }

    // ���¼�¼
    if (found) 
    {
        fseek(fp1, record_pos, SEEK_SET);
        if (fwrite(&temp, sizeof(USERS), 1, fp1) != 1) 
        {
            printf("��¼����ʧ��\n");
        }
        fflush(fp1);
    } else {
        printf("δ�ҵ�ƥ���û���¼\n");
    }

    fclose(fp1);
}
void find_and_print_carplate(const char *username)
{
    FILE *fp;
    USERS temp;
    int found = 0;

    // �� data.dat �ļ�
    if ((fp = fopen("data.dat", "rb")) == NULL) 
    {
        printf("�޷����ļ� data.dat\n");
        return;
    }

    // �����ļ�������ƥ����û�
    while (fread(&temp, sizeof(USERS), 1, fp) == 1) 
    {

        if (strcmp(temp.user_name, username) == 0) 
        {
            found = 1;
            break;
        }
    }
    fclose(fp);

    // ����ҵ��û���������ƺ�
    if (found) 
    {
        printf("�û���: %s\n", temp.user_name);
        printf("���ƺ�: %s\n", temp.carboard);

        // ��ͼ�ν�������ʾ���ƺ�
        prt_hz16_asc16_size(150, 300, 3, 3, temp.carboard, 0x000000, "HZK\\hzk16");
    } else 
    {
        printf("δ�ҵ��û���Ϊ %s ���û���¼��\n", username);
    }
}