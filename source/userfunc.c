#include"allfunc.h"


void user_function(int *page)
{
    int save_picture16; // ����ԭ����
    int is_query_open = 0; // ��־��������¼�Ƿ��ڲ�ѯ����
    int is_query_open1 = 0;
    int pre1 = 0;//����������������ͣЧ��
    //int i;
    //char*carboard1[8];
    FILE*fp;
    char username[10];
    long current_pos = 0;
    USERS temp ;
    data_reselect();
    //��ȡ��ʱ�ļ��е�����

    if((fp=fopen("data1.dat","rb+"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    Readbmp64k(0, 0, "bmp\\user1.bmp");
    bar1(30, 120, 500, 710, 0xd4a6f8); // (0,0)��(1024,768)�İ�ɫ���� 
    puthz(35, 50, "�û�", 32, 30, 0x000000); // �û���
     fseek(fp,0,SEEK_SET);
        fread(username,sizeof(username)-1,1,fp);
        username[sizeof(username)-1]='\0';
        if(username[0] == '\0')
        {
            put_asc16_size(120,50,2,2,"error",0x000000);
        }    
        else
        {
            put_asc16_size(120, 50, 2, 2, username, 0x000000); // �������û�������
        }
    
    find_and_print_carplate(username);
    puthz(250, 50, "����", 32, 30, 0x000000); // �ʺ���
    puthz(35, 150, "������Ϣ", 48, 45, 0x000000);
    puthz(35, 250, "���ƺ�", 32, 30, 0x000000);
    puthz(35, 350, "��������", 32, 30, 0x000000);

    bar1(500, 120, 740, 390, 0x00CC33); // (0,0)��(1024,768)�İ�ɫ����
    puthz(500, 150, "�û���ѯ��", 48, 45, 0x000000);

    draw_botton(540, 240, 700, 300, 0xFFFFFF, 0x000000);
    puthz_coverd(530, 255, "��ѯΥ�����", 6, 32, 30, 0x000000);//���һ�ε������棬�ٴε������ԭ����
    draw_botton(540, 310, 700, 370, 0xFFFFFF, 0x000000);
    puthz_coverd(530, 325, "�鿴Υ����Ƭ", 6, 32, 30, 0x000000);//���һ�ε������棬�ٴε������ԭ����  

    bar1(500, 390, 740, 670, 9159e4); // (0,0)��(1024,768)�İ�ɫ����
    puthz(500, 410, "�û�������", 48, 45, 0x000000);
    
    draw_botton(540, 510, 700, 570, 0xFFFFFF, 0x000000);
    puthz_coverd(530, 525, "��ȫ֪ʶѧϰ", 6, 32, 30, 0x000000);
    draw_botton(540, 590, 700, 650, 0xFFFFFF, 0x000000);
    puthz_coverd(560, 605, "Υ�´���", 4, 32, 30, 0x000000);

    puthz(770, 250, "��Դ������������",24, 25, 0x000000);
    puthz(740, 283, "�����·���ť��������",24, 25, 0x000000);//��ʾ��

    draw_botton(800, 370, 960, 430, 0xFFFFFF, 0x000000);
    puthz_coverd(820, 385, "��������", 4, 32, 30, 0x000000);//�������߰�ť������ͣЧ��

    puthz(755, 490, "�����˽���లȫ֪ʶ",24, 25, 0x000000);
    puthz(740, 523, "������ఴť����ѧϰ",24, 25, 0x000000);//��ʾ��
    
       
        memset(&temp, 0, sizeof(USERS)); // ��� temp �ṹ��
        // ��ȡΥ�¼�¼
        fseek(fp, 0, SEEK_SET); // ��λ���ļ���ʼ
        while (fread(&temp, sizeof(USERS), 1, fp) == 1)
        {
            if (strcmp(temp.user_name, username) == 0)
            {
                current_pos = ftell(fp) - sizeof(USERS); // ��ȡ��ǰ��¼��ƫ����
                                
            }
        }
        fseek(fp, current_pos, SEEK_SET); // ��λ����ǰ��¼��λ��
        fread(&temp, sizeof(USERS), 1, fp); // ��ȡ��ǰ��¼
        fclose(fp);     
        put_car_picture(temp);
        
    draw_confirmbotton(830, 650, "�鿴��ʷΥ��"); // ������һ��
    draw_confirmbotton(830, 710, "����������"); // ����������

    while (1)
    {
        int hover_visitor = (mouse.x >= 800 && mouse.x <= 960 && mouse.y >= 370 && mouse.y <= 415);
        mouse_show(&mouse);
        
        if(hover_visitor != pre1)//�������߰�ť����ͣЧ��
        {
           mouse_off(&mouse); // �ر����
            // �ָ�����
            bar1(800, 370, 960, 430, 0xFFFFFF);
            draw_botton(800, 370, 960, 430, hover_visitor ? 0xDDDDDD : 0xFFFFFF, 0x000000);
            puthz_coverd(820, 385, "��������", 4, 32, 30, hover_visitor ? 0xFF0000 : 0x000000);
            pre1 = hover_visitor;
            mouse_on(mouse);
        }
        if (mouse_press(540, 240, 700, 300) == 1)
        {
            if (!is_query_open)
            {
               
                is_query_open=watch_func1(temp);
                
            }
            else
            {
                
                is_query_open = 0; // ���Ϊ��ѯ�����ѹر�
                break;
            }
        }
        if(mouse_press(540, 310, 700, 370)==1)
        {
            if(!is_query_open1)
            {
                
                is_query_open1=watch_func2(temp);
                    
            }
            else
            {
                is_query_open1 = 0; // ���Ϊ��ѯ�����ѹر�
                break;
            }

            
            
            
        }
        
        if(mouse_press(830, 650, 950, 710)==1)
        {
            if(temp.if_fine==1||temp.if_fine==2)
            {
                *page=15;
                break;
            }
            else if(temp.if_fine==0)
            {
                puthz(765, 580, "��û��Υ�¼�¼", 32, 30, 0xFF068);
                delay(500);
                LoadBMP(765, 580, 1000, 630, save_picture16);
            }
        }
        if(mouse_press(830, 710, 950, 770)==1)
        {
            data_reselect();
            *page=0;
            break;
        }
       if (mouse_press(800, 370, 960, 430) == 1)
        {
            int if_fine = -1;
            fp= fopen("data1.dat", "rb+");
            // ����ԭ����
            save_picture16=SaveBMP(765, 580, 1000, 630);
            // ��λ�� if_fine ��λ��
            if (fseek(fp, 36+current_pos, SEEK_SET) != 0)
            {
                printf("�ļ�ָ�붨λʧ�ܣ�\n");
                return;
            }

            // ��ȡ if_fine ��ֵ
            if (fread(&if_fine, sizeof(int), 1, fp) != 1)
            {
                printf("��ȡ if_fine ʧ�ܣ�\n");
                return;
            }
           

            // ���� if_fine ��ֵ�����Ƿ���תҳ��
            if (if_fine == 1)
            {
                *page = 27;  // ��ת��ҳ�� 27
                break;
            }
            else
            {
                // �����ʾ���򱳾�
               
                puthz(765, 580, "��û��Υ�¼�¼", 32, 30, 0xFF068);
                delay(500);
                LoadBMP(765, 580, 1000, 630, save_picture16);

            }
        }
        if(mouse_press(540, 510, 700, 570)==1)
        {
            *page=28;
            break;
        }
        if(mouse_press(540, 590, 700, 650)==1)
        {
            int if_fine = -1;
            int if_against=-1;
            int save_picture17;
            save_picture16=SaveBMP(765, 580, 1000, 630);
            save_picture17=SaveBMP(765, 580, 1000, 630);
            fp= fopen("data1.dat", "rb+");
            // ��λ�� if_fine ��λ��
            if (fseek(fp, 36+current_pos, SEEK_SET) != 0)
            {
                printf("�ļ�ָ�붨λʧ�ܣ�\n");
                return 0;
            }

            // ��ȡ if_fine ��ֵ
            if (fread(&if_fine, sizeof(int), 1, fp) != 1)
            {
                printf("��ȡ if_fine ʧ�ܣ�\n");
                return 0;
            }
             if(fread(&if_against, sizeof(int), 1, fp) != 1)
            {
                printf("��ȡ if_against ʧ�ܣ�\n");
                return;
            }

            // ���� if_fine ��ֵ�����Ƿ���תҳ��
            if (if_fine == 1&&if_against==0)
            {
                
                *page = 29;  // ��ת��ҳ�� 27
                fclose(fp);
                break;
            }
            else if(if_fine==1&&if_against==1)
            {
                puthz(765, 580, "������������", 32, 30, 0xFF068);

                delay(500);
                LoadBMP(765, 580, 1000, 630, save_picture16);// �����ʾ���򱳾�
            }
            else
            {
                puthz(765, 580, "��û��Υ�¼�¼", 32, 30, 0xFF068);
                delay(500);
                LoadBMP(765, 580, 1000, 630, save_picture16);// �����ʾ���򱳾�
            }
        }
    }
}

void safe_learning(int *page)
{
    
    int is_query_open = 0; 
    // ��־��������¼�Ƿ��ڲ�ѯ����
    int save_picture16; // ����ԭ����
    int save_picture17;

    Readbmp64k(0, 0, "bmp\\user1.bmp");   
    
    puthz(350, 50, "��ȫ֪ʶѧϰ", 48, 50, 0x000000);
    puthz(250, 150, "���пƼ���ѧ��������������", 32, 40, 0x000000);
   
    rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
    bar1(60, 210, 964, 660, 0xFFFFFF);

    draw_confirmbotton(250, 680, "������һ��"); // ������һ��
    draw_confirmbotton(610, 680, "����������"); // ����������
    
    puthz(80, 250,"��һ��",32,30,0x000000);
    puthz(110, 300,"У԰���ɵ����ࡢ��ѧ��������¥�����ڡ���������Ա�ܼ���ͨ����������",24,25,0x000000);
    puthz(75, 330,"��ͣ�Ż���������ʩ��ͣ��λ�ĳ��⡣������ͣ��λͣ��Ӧ���ع淶��ͣ����λ��",24,25,0x000000);
    puthz(75, 360,"���ÿ�ѹͣ���ߡ�",24,25,0x000000);
    puthz(80, 400,"�ڶ���",32,30,0x000000);
    puthz(110, 440,"У԰�ڻ���������ʻӦ���ؽ�ͨ���򣬲��ó�����ʻ���������У�����ռ����",24,25,0x000000);
    puthz(75, 470,"�е���ʻ��������У԰�������ȡ�",24,25,0x000000);
    puthz(80, 510,"������",32,30,0x000000);
    puthz(110, 550,"��У԰��ͣ�Ż�������Ӧ������۲��ź˶����շѱ�׼����ͣ�ŷ��á�",24,25,0x000000);

    bar2(258,626,288,656,0x000000);
    puthz(300,630,"����֪����ͬ������������Ը����ѭ��������",24,25,0x000000);

    /*prt_hz24_asc32(25, 150,"У԰���ɵ����ࡢ��ѧ��������¥�����ڡ���������Ա�ܼ���ͨ���������Ͻ�ͣ�Ż�����,��ʩ��ͣ��λ�ĳ��⡣������ͣ��λͣ��Ӧ���ع淶,ͣ����λ,���ÿ�ѹͣ���ߡ�", 0x000000, "HZK\\HZK24s");
    prt_hz24_asc32(25, 250,"У԰�ڻ���������ʻӦ���ؽ�ͨ����,���ó�����ʻ,��������,����ռ�����е���ʻ,������У԰�������ȡ�", 0x000000, "HZK\\HZK24s");
    prt_hz24_asc32(25, 350,"��У԰��ͣ�Ż�����,Ӧ������۲��ź˶����շѱ�׼����ͣ�ŷ��á�", 0x000000, "HZK\\HZK24s");
    */
    
    while (1)
    {
        mouse_show(&mouse);
        
        if (mouse_press(250, 680, 370, 740) == 1)
        {
            if(is_query_open!=1)
            {
                mouse_off(&mouse);
                save_picture17 = SaveBMP(258, 586, 800, 650);//����ԭ����,��Ϊ290����Ϊ220
                //Readbmp64k(450, 350, "bmp\\warning.bmp");Ч�����ã���Ϊ�����
                puthz(300, 600, "���û�ȷ��ͬ��У԰������ȫ��������", 24, 25, 0xFF068);
                delay(1000);
                LoadBMP(258, 586, 800, 650, save_picture17);
            }
            else
            {
                *page = 26;
                break;
            }
        }
        if (mouse_press(610, 680, 730, 740) == 1)
        {
            *page = 20;
            break;
        }
        if(mouse_press(258,626,288,656)==1)
        {
            if (!is_query_open)
            {
               mouse_off(&mouse);
               save_picture16 = SaveBMP(258, 626, 288, 656);
               delay(200);
               DrawCheckmark(272,645,30,0xFF068);
               is_query_open = 1;
            
            }
            else
            {
                delay(200);
                mouse_off(&mouse);
                LoadBMP(258, 626, 288, 656, save_picture16);
                is_query_open = 0;
            }
            
        }
    }
}
void fun_against(int *page)
{
    int save_picture18; // ����ԭ����
    int save_picture19;
    int save_picture20;
    int save_picture21;
    int save_picture22;
    int save_picture23;
    int save_picture24;
    int is_query_open = 0; // ��־��������¼�Ƿ��ڲ�ѯ����
    int is_query_open1 = 0;
    int false_query_open1 = 0;
    int false_query_open2 = 0;
    int false_query_open3 = 0;
    int textbox_open = 0;
    FILE*fp;
    int if_fine;
    long current_pos;
    
    if((fp=fopen("data1.dat","rb+"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    fseek(fp, 0, SEEK_END);
    current_pos = ftell(fp)-(long)sizeof(USERS);
    mouse_off(&mouse);
    Readbmp64k(0, 0, "bmp\\user1.bmp");
    mouse_show(&mouse);
    fseek(fp, 24+current_pos, SEEK_SET);
    //���߹�����
    fclose(fp);
    puthz(400, 50, "��������", 48, 50, 0x000000);
    puthz(50, 150, "��ѡ��������������", 32, 35, 0x000000);
    rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
    bar1(60, 210, 964, 660, 0xFFFFFF);
    
    bar2(150, 270, 190, 310, 0x000000);//ѡ����
    puthz(220, 265, "�����з�", 48, 50, 0x000000);
    bar2(600, 270, 640, 310, 0x000000);
    puthz(670, 265, "��������", 48, 50, 0x000000);
    puthz(80, 350, "����д������������", 32, 35, 0x000000);
    rounded_bar(140, 400, 904, 600, 10, 0xFFFFFF, 0xFFFFFF, 0);
    save_picture20 = SaveBMP(140, 400, 904, 600);

    draw_confirmbotton(150, 680, "������һ��"); // ������һ��
    draw_confirmbotton(420, 680, "�ύ����"); // �ύ����
    draw_confirmbotton(720, 680, "����������"); // ����������
    //Ҫ���Ϸ�������ȹ���
    save_picture18 = SaveBMP(150, 270, 190, 310);
    save_picture19 = SaveBMP(600, 270, 640, 310);
    while (1)
    {
        mouse_show(&mouse);
        if(mouse_press(150, 680, 270, 740)==1)
        {
            *page=26;
            break;
        }
        if(mouse_press(420, 680, 540, 740)==1)
        {
            if_fine=1;
            fp=fopen("data1.dat","rb+");
            puthz(450, 620, "���߳ɹ�", 24, 30, 0xFF068);
            fseek(fp, 38+current_pos, SEEK_SET);
            fwrite(&if_fine, 2, 1, fp);
            fseek(fp, 0, SEEK_SET);
            data_reselect();
            fclose(fp);
            delay(500);
            *page=26;
            break;
        }
        if(mouse_press(720, 680, 840, 740)==1)
        {
            *page=0;
            break;
        }
        if (mouse_press(150, 270, 190, 310) == 1)
        {
           
            if (!is_query_open)
            {
                mouse_off(&mouse);
                // ����ԭ����
                LoadBMP(600, 270, 640, 310, save_picture19);
                delay(200);
                DrawCheckmark(169,294,40,0xFF068);
                textbox_open=1;//�����з�
                is_query_open = 1; // ���Ϊ��ѯ�����Ѵ�
                is_query_open1=0;//��������з�ʱ���������ص�״̬�ر�
            }
            else
            {
                // ����ԭ����
                delay(200);
                mouse_off(&mouse);
                // ����ԭ����
                LoadBMP(140, 400, 904, 600, save_picture20);
                LoadBMP(150, 270, 190, 310, save_picture18);
                LoadBMP(600, 270, 640, 310, save_picture19);
                is_query_open = 0; // ���Ϊ��ѯ�����ѹر�
                textbox_open=0;
            }
            if(is_query_open1==0&&is_query_open==1)
            {
                LoadBMP(140, 400, 904, 600, save_picture20);
                //��ʱ�ǵ�����󴦷���״̬������д�����󴦷��ķ�Ӧ����
                bar2(160, 430, 190, 460, 0x000000);
                puthz(220, 425,"��������ͣ�ŵ�����", 32, 35, 0x000000);
                bar2(160, 480, 190, 510, 0x000000);
                puthz(220, 479,"����Υͣ���ͷ�������", 32, 35, 0x000000);
                bar2(160, 540, 190, 570, 0x000000);
                puthz(220, 543,"����ԭ�򣬵ȴ�����Ա����", 32, 35, 0x000000);
                
            }
        }
        if (mouse_press(600, 270, 640, 310) == 1)
        {
           
            if (!is_query_open1)
            {
                mouse_off(&mouse);
                // ����ԭ����
                
                delay(200);
                DrawCheckmark(619,294,40,0xFF068);
                is_query_open1 = 1; // ���Ϊ��ѯ�����Ѵ�
                is_query_open=0;//����������ص�״̬�������з���״̬�ر�
                LoadBMP(150, 270, 190, 310, save_picture18);
                textbox_open=2;//��������

            }
            else
            {
                delay(200);
                mouse_off(&mouse);
                // ����ԭ����
                LoadBMP(600, 270, 640, 310, save_picture19);
                LoadBMP(140, 400, 904, 600, save_picture20);
                is_query_open1 = 0; // ���Ϊ��ѯ�����ѹر�
                textbox_open=0;
            }
            
            if(is_query_open1==1&&is_query_open==0)
            {
                //��ʱ�ǵ���������ص�״̬������д���������صķ�Ӧ����
                LoadBMP(140, 400, 904, 600, save_picture20);
                bar2(160, 430, 190, 460, 0x000000);
                puthz(220, 425,"����������", 32, 35, 0x000000);
                bar2(160, 480, 190, 510, 0x000000);
                puthz(220, 479,"�����۷ֹ���", 32, 35, 0x000000);
                bar2(160, 540, 190, 570, 0x000000);
                puthz(220, 543,"����ԭ�򣬵ȴ�����Ա����", 32, 35, 0x000000);
            }
        }  
        if(mouse_press(160, 430, 190, 460)==1)
        {
            if(!false_query_open1)
            {
                mouse_off(&mouse);
                save_picture21 = SaveBMP(160, 430, 190, 460);
                DrawCheckmark(176,448,30,0xFF068);
                if(textbox_open==1)//��Ӧ�����з��еĳ�������ͣ�ŵ�����
                {
                    fp=fopen("data1.dat","rb+");
                    fseek(fp, 24+current_pos, SEEK_SET);
                    if_fine=1;
                    fwrite(&if_fine, 2, 1, fp);
                    fseek(fp, -2, SEEK_CUR);
                    fclose(fp);
                }
                else if(textbox_open==2)//��Ӧ���������еĴ���������
                {
                    if_fine=1;
                    fp=fopen("data1.dat","rb+");
                    fseek(fp, 24+current_pos, SEEK_SET);
                    fseek(fp, 6, SEEK_CUR);
                    fwrite(&if_fine, 2, 1, fp);
                    fseek(fp, -8, SEEK_CUR);
                    fclose(fp);
                }
                delay(200);
                mouse_show(&mouse);
                false_query_open1= 1 ;
            }
            else
            {
                mouse_off(&mouse);
                LoadBMP(160, 430, 190, 460, save_picture21);
                delay(200);
                /*if(textbox_open==1)
                {
                    fseek(fp, 2, SEEK_CUR);
                    fwrite("0", 2, 1, fp);
                    fseek(fp, -4, SEEK_CUR);
                }
                else if(textbox_open==2)
                {
                    fseek(fp, 6, SEEK_CUR);
                    fwrite("0", 2, 1, fp);
                    fseek(fp, -8, SEEK_CUR);
                }*/
                mouse_show(&mouse);
                false_query_open1 = 0;
            }
        } 
        if(mouse_press(160, 480, 190, 510)==1)
        {
            if(!false_query_open2)
            {
                mouse_off(&mouse);
                save_picture22 = SaveBMP(160, 480, 190, 510);
                DrawCheckmark(176,498,30,0xFF068);
                if(textbox_open==1)//��Ӧ�����з��еĳ�������Υͣ���ͷ�������
                {
                    if_fine=1;
                    fp=fopen("data1.dat","rb+");
                    fseek(fp, 24+current_pos, SEEK_SET);
                    fseek(fp, 2, SEEK_CUR);
                  fwrite(&if_fine, 2, 1, fp);
                    fseek(fp, -4, SEEK_CUR);
                    fclose(fp);
                }
                else if(textbox_open==2)//��Ӧ���������еĴ����۷ֹ���
                {
                    if_fine=1;
                    fp=fopen("data1.dat","rb+");
                    fseek(fp, 24+current_pos, SEEK_SET);
                    fseek(fp, 8, SEEK_CUR);
                    fwrite(&if_fine, 2, 1, fp);
                    fseek(fp, -10, SEEK_CUR);
                    fclose(fp);
                }
                delay(200);
                mouse_show(&mouse);
                false_query_open2= 1 ;
            }
            else
            {
                mouse_off(&mouse);
                LoadBMP(160, 480, 190, 510, save_picture22);
                delay(200);
                /*if(textbox_open==1)
                {
                    fseek(fp, 2, SEEK_CUR);
                    fwrite("0", 2, 1, fp);
                    fseek(fp, -4, SEEK_CUR);
                }
                else if(textbox_open==2)
                {
                    fseek(fp, 8, SEEK_CUR);
                    fwrite("0", 2, 1, fp);
                    fseek(fp, -10, SEEK_CUR);
                }*/
                mouse_show(&mouse);
                false_query_open2 = 0;
            }
        }
        if(mouse_press(160, 540, 190, 570)==1)
        {
            if(!false_query_open3)
            {
                mouse_off(&mouse);
                save_picture23 = SaveBMP(160, 540, 190, 570);
                DrawCheckmark(176,558,30,0xFF068);
                delay(200);
                mouse_show(&mouse);
                if(textbox_open==1)//��Ӧ�����з��е�����ԭ�򣬵ȴ�����Ա����
                {
                    if_fine=1;
                    fp=fopen("data1.dat","rb+");
                    fseek(fp, 24+current_pos, SEEK_SET);
                    fseek(fp, 4, SEEK_CUR);
                    fwrite(&if_fine, 2, 1, fp);
                    fseek(fp, -6, SEEK_CUR);
                    fclose(fp);
                }
                else if(textbox_open==2)//��Ӧ���������е�����ԭ�򣬵ȴ�����Ա����
                {
                    if_fine=1;
                    fp=fopen("data1.dat","rb+");
                    fseek(fp, 24+current_pos, SEEK_SET);
                    fseek(fp, 10, SEEK_CUR);
                   fwrite(&if_fine, 2, 1, fp);
                    fseek(fp, -12, SEEK_CUR);
                    fclose(fp);
                }
                false_query_open3= 1 ;
            }
            else
            {
                mouse_off(&mouse);
                LoadBMP(160, 540, 190, 570, save_picture23);
                delay(200);
                /*if(textbox_open==1)
                {
                    fseek(fp, 4, SEEK_CUR);
                    fwrite("0", 2, 1, fp);
                    fseek(fp, -6, SEEK_CUR);
                }
                else if(textbox_open==2)
                {
                    fseek(fp, 10, SEEK_CUR);
                    fwrite("0", 2, 1, fp);
                    fseek(fp, -12, SEEK_CUR);
                }*/
                mouse_show(&mouse);
                false_query_open3 = 0;
            }
        } 
    }
}
