#include <allfunc.h>
#include <stdio.h>

//���û�ע��
void rigister_login(int *func)
{
	int save_picture;
	struct USER temp={0};//�洢��Ϣ���û��ṹ�� 
	char judge[10]="\0";//�����жϵ�����
    mouse_off(&mouse);
    draw_login_visiter_rigister();
	save_picture=SaveBMP(430,635,630,660);

	

    while(1)
    {
        mouse_show(&mouse);
		// �������¼�
		if(mouse_press(460, 240, 700, 290)==1)   //�����˺�//200, 200, 800, 550
		{
			mouse_off(&mouse);
			bar1(460, 240, 700, 290,0xffff);
			strcpy(temp.name,"\0");
			Getinfo(470,250,temp.name,10,460, 240, 700, 290);
			mouse_on(mouse);
		}
		else if(mouse_press(460, 340, 700, 390)==1)    //��������
		{
			mouse_off(&mouse);
			bar1(460, 340, 700, 390,0xffff);
			strcpy(temp.code,"\0");
			Getcode(470,355,temp.code,10,460, 340, 700, 390);
			mouse_on(mouse);
		}
		else if(mouse_press(460, 440, 700, 490)==1)     //������������
		{
			mouse_off(&mouse);
			bar1(460, 440, 700, 490,0xffff);
			strcpy(judge,"\0");
			Getcode(470,450,judge,10,460, 440, 700, 490);
			mouse_on(mouse);
		}
		if(mouse_press(330,560,430,620)==1)     //���ȷ�ϼ�
		{
			if(strcmp(temp.name,"\0")!=0)//�û�����Ϊ�� 
			{
				if(strcmp(temp.code,"\0")!=0)//���벻Ϊ�� 
				{
					if(!strcmp(temp.code,judge))//����������ͬ 
			        {
				      if(save_user(temp)==0)
                      {
						prt_hz24(430,635,"ע��ɹ���",0,"HZK\\Hzk24h");
						delay(1500);	
						*func=2;
						mouse_off(&mouse);
				        break;
                      }
                      else
                      {
                        prt_hz24(430,635,"�û����ѱ�ע�ᣡ",10,"HZK\\Hzk24h");
                        delay(1500);
				        LoadBMP(430,635,630,660,save_picture);
                      }
			        }
			        else
			        {
				      prt_hz24(430,635,"�������벻��ͬ��",0,"HZK\\Hzk24h");
				      delay(1500);
				      LoadBMP(430,635,630,660,save_picture);
			        }  
				}
				else
				{
					prt_hz24(430,635,"����Ϊ�գ�",0,"HZK\\Hzk24h");
				    delay(1500);
				   LoadBMP(430,635,630,660,save_picture);
				}	
			}
			else
			{
				prt_hz24(570,575,"�û���Ϊ�գ�",0,"HZK\\Hzk24h");
				delay(1500);
				bar1(570,575,800,600,0xffff);
			}	
		}
		 if(mouse_press(300,560,450,620)==1)
            {
                puthz(450, 650, "ע��ɹ�", 24, 30, 0x000000);
				
                delay(500);
                *func=0;
				mouse_off(&mouse);
                break;
            }
        else if(mouse_press(580,560,680,620)==1)
            {
                *func=2;
				mouse_off(&mouse);
                break;
            }
    }
}

//������Ա��¼
void staff_login(int *func)
{
	int pre3 = 0, pre4 = 0;
	char name[10]="\0";
	char code[10]="\0";
	int save_picture;

	save_picture=SaveBMP(430,635,630,660);
    mouse_off(&mouse);
    draw_login_admin();
    mouse_on(mouse);
    while(1)
    {
         // �����ͣ״̬
        int hover_visitor = (mouse.x >= 300 && mouse.x <= 450 && mouse.y >= 560 && mouse.y <= 620);
        int hover_admin = (mouse.x >= 580 && mouse.x <= 680 && mouse.y >= 560 && mouse.y <= 620);

        mouse_show(&mouse);
       
        // ���¹���Ա��ť
		if (hover_visitor != pre3) 
        {
            mouse_off(&mouse); // �ر����
			bar1(300, 560, 450, 620, 0xFFFFFF); // �ָ�����
            draw_botton(300, 560, 450, 620, hover_visitor ? 0xDDDDDD : 0xFFFFFF, 0x000000);
            puthz_coverd(290, 575, "����Ա��¼", 5, 32, 30, hover_visitor ? 0xFF0000 : 0x000000);
            pre3 = hover_visitor;
            mouse_on(mouse); // �ػ����

        }
        if (hover_admin != pre4)
        {
            mouse_off(&mouse); // �ر����
			bar1(580, 560, 680, 620, 0xFFFFFF);
            draw_botton(580, 560, 680, 620, hover_admin ? 0xDDDDDD : 0xFFFFFF, 0x000000);
            puthz_coverd(590, 575, "����", 2, 32, 30, hover_admin ? 0xFF0000 : 0x000000);
            pre4 = hover_admin;
            mouse_on(mouse);
        }
		if(mouse_press(460, 370, 700, 420)==1)
		{
			mouse_off(&mouse);
			strcpy(name,"\0");
			bar1(460, 370, 700, 420,0xffff);
			Getinfo(502,398,name,9,460, 370, 700, 420);//�õ��˺� 
			mouse_on(mouse);
		}
		else if(mouse_press(460, 445, 700, 495)==1)//�������� 
		{
			mouse_off(&mouse);
			strcpy(code,"\0");
			bar1(460, 445, 700, 495,0xffff);
			Getcode(502,468,code,9,460, 445, 700, 495);//�õ����� 
			mouse_on(mouse);
		}
		else if(mouse_press(300,560,450,620)==1)//�����¼
		{
			if(strcmp("1",name)==0&&strcmp("1",code)==0)
			{
				*func=5;
				mouse_off(&mouse);
				break;
			}
			else
			{
				prt_hz24(430,635,"��Ϣ�����ϣ�",0,"HZK\\Hzk24h");
				delay(1500);
				LoadBMP(430,635,630,660,save_picture);
			}
		}
		else if(mouse_press(580,560,680,620)==1)
        {
            *func=0;
			mouse_off(&mouse);
            break;
        }
		
    }
}

//�û�ʹ���˺ŵ�¼
void user_login(int *func,int *unum)
{
    FILE *fp;
	char name[10]="\0";
	char code[10]="\0";
    int i=-5;
	int pre1 = 0, pre2 = 0,pre3=0;
	int save_picture;
	USERS user={0};
    UserList UL={0};
	InitUList(&UL);
	ReadAllUser(&UL);

    mouse_off(&mouse);
    draw_login_visiter();
	if((fp=fopen("data.dat","rb+"))==NULL)
	{
		printf("error!\n");
		exit(0);
	}
	save_picture=SaveBMP(430,635,630,660);
    mouse_on(mouse);
	fseek(fp,0,SEEK_END);

    while(1)
    {
       	int hover_visitor = (mouse.x >= 250 && mouse.x <= 350 && mouse.y >= 560 && mouse.y <= 620);
        int hover_admin = (mouse.x >= 440 && mouse.x <= 560 && mouse.y >= 560 && mouse.y <= 620);
        int hover_return = (mouse.x >= 660 && mouse.x <= 760 && mouse.y >= 560 && mouse.y <= 620);
        mouse_show(&mouse);
        
        if (hover_visitor != pre1) 
            {
                mouse_off(&mouse); // �ر����
				bar1(250, 560, 350, 620, 0xFFFFFF); // �ָ�����
                draw_botton(250, 560, 350, 620, hover_visitor ? 0xDDDDDD : 0xFFFFFF, 0x000000);
                puthz_coverd(240, 575, "�ÿ͵�¼", 4, 32, 30, hover_visitor ? 0xFF0000 : 0x000000);
                pre1 = hover_visitor;
                mouse_on(mouse); // �ػ����
            }
            if (hover_admin != pre2)
            {
                mouse_off(&mouse); // �ر����
				bar1(440, 560, 560, 620, 0xFFFFFF);
                draw_botton(440, 560, 560, 620, hover_admin ? 0xDDDDDD : 0xFFFFFF, 0x000000);
                puthz_coverd(440, 575, "�û�ע��", 4, 32, 30, hover_admin ? 0xFF0000 : 0x000000);
                pre2 = hover_admin;
                mouse_on(mouse);
            }
            if (hover_return != pre3)
            {
                mouse_off(&mouse); // �ر����
				bar1(660, 560, 760, 620, 0xFFFFFF);
                draw_botton(660, 560, 760, 620, hover_return ? 0xDDDDDD : 0xFFFFFF, 0x000000);
                puthz_coverd(680, 575, "����", 2, 32, 30, hover_return ? 0xFF0000 : 0x000000);
                pre3 = hover_return;
                mouse_on(mouse);
			}
		if(mouse_press(460, 370, 700, 420)==1)//����˺ſ� 
		{
			mouse_off(&mouse);
			strcpy(name,"\0");
			bar1(460, 370, 700, 420,0xffff);
			Getinfo(470,385,name,10,460, 370, 700, 420);//�õ��˺� 
			mouse_on(mouse);
		}
        else if(mouse_press(460, 445, 700, 495)==1)//�������� 
		{
			mouse_off(&mouse);
			strcpy(code,"\0");
			bar1(460, 445, 700, 495,0xffff);
			Getcode(470,460,code,10,460, 445, 700, 495);//�õ����� 
			mouse_on(mouse);
		}
        if(mouse_press(250,560,350,620)==1)//�����¼
        {
            i=Check_info(UL,name,code);
            if(i>=0)
			{
				FILE *fp_data, *fp_temp;
				USERS temp,temp1;
    			int found = 0;
				int current_pos[5];
				int j;
				// ���������ļ� data.dat
				if ((fp_data = fopen("data.dat", "rb+")) == NULL) 
				{
					perror("�޷����ļ� data.dat");
					exit(EXIT_FAILURE);
				}
				
				// ���� data.dat �ļ��������Ƿ����ͬ���û�
				while (fread(&temp, sizeof(USERS), 1, fp_data) == 1) 
				{
					if (strcmp(temp.user_name, name) == 0&&found<=5) 
					{
						found++;
						current_pos[found-1] = ftell(fp_data) - sizeof(USERS); // ��¼��ǰ�ļ�ָ��λ��
					}
				}
				if (found > 0) 
				{
					// ����ҵ��û�����������Υ������д����ʱ�ļ� data1.dat
					if ((fp_temp = fopen("data1.dat", "wb")) == NULL) 
					{
						perror("�޷����ļ� data1.dat");
						fclose(fp_data);
						exit(EXIT_FAILURE);
					}
					for ( j = 0; j < found; j++) 
					{
						fseek(fp_data, current_pos[j], SEEK_SET); // ��λ����ǰ��¼
						fread(&temp, sizeof(USERS), 1, fp_data);
						fwrite(&temp, sizeof(USERS), 1, fp_temp);
					}
					 printf("�û� %s ������Υ����������ȡ�� data1.dat �ļ��У��� %d ����¼��\n", name, found);
					*func = 26; // �����û�������
					fclose(fp_data);
					fclose(fp_temp);
					DestroyUList(&UL);
					mouse_off(&mouse);
					break;
				}
				else
				{
					*unum=i;
					DestroyUList(&UL);
					strcpy(user.user_name,name);
					strcpy(user.pass_word,code);
					user.if_fine=0;
					user.fine[0]=0;
					user.if_against=0;
					fseek(fp,0,SEEK_END);
					fwrite(&user,sizeof(USERS),1,fp);
					fclose(fp);
					*func=3;      //����������
					data_select(name);
					mouse_off(&mouse);
					break;
				}
			}
			if(i==-2)//����������� 
			{
				prt_hz24(430,635,"�������",0,"HZK\\Hzk24h");
			    delay(1500);
				LoadBMP(430,635,630,660,save_picture);
			}
			if(i==-3)//�û������� 
			{
				prt_hz24(430,635,"�û������ڣ�",0,"HZK\\Hzk24h");
			    delay(1500);
				LoadBMP(430,635,630,660,save_picture);
			} 
        }
        else if(mouse_press(660,560,760,620)==1)
        {
            *func=0;
			fclose(fp);
			mouse_off(&mouse);
            break;
        }
        
		else if(mouse_press(440,560,560,620)==1)
		{
			*func=4;
			fclose(fp);
			mouse_off(&mouse);
			DestroyUList(&UL);
			break;
		}
    }

}
