#include"allfunc.h"     
#include<stdio.h>
//ע�������Ϊ����ģ���������һ�в��������Ѿ�Ԥ��                                                                                                                                                                                                                                                                                                                                                            #include<allfunc.h>
//Υͣ��Ϣģ��Ԥ��
void showTransferAnimation1(void) 
{
    /* Բ������ */
    int centerX = 512;  /* Բ��x���� */
    int centerY = 300;  /* Բ��y���� */
    int radius = 80;    /* Բ�뾶 */
    int barWidth = 10;  /* ������� */
    int barHeight = 20; /* �����߶� */
    int i, angle, x, y;
    
    /* ���ֲ��� */
    int textX = 350;    /* ������ʼx���� */
    int textY = 500;    /* ����y���� */
    
    /* ������� */
    bar1(50, 120, 974, 600, 0xFFFFFF);
    
    /* ����Բ�� */
    angle = 0;
    while(angle < 360) {
        x = centerX + radius * cos(angle * 3.14159 / 180);
        y = centerY + radius * sin(angle * 3.14159 / 180);
        bar1(x, y, x+1, y+1, 0x000000);
        angle += 5;
    }
    
    /* �������� */
    i = 0;
    while(i < 12) 
    {
        angle = i * 30;
        x = centerX + radius * cos(angle * 3.14159 / 180) - barWidth/2;
        y = centerY + radius * sin(angle * 3.14159 / 180) - barHeight/2;
        bar1(x, y, x+barWidth, y+barHeight, 0x000000);
        delay(100);
        i++;
    }
    
    /* �����ʾ���� */
    puthz(textX, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+32, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+64, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+96, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+128, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+160, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+192, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+224, textY, "Ϣ", 32, 40, 0x000000);
    delay(200);
    puthz(textX+256, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+288, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+320, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+352, textY, "��", 32, 40, 0x000000);
    delay(1000);
}
void showLoadingAnimation(void) 
{
    int centerX = 915;   /* Բ��x����(830+1000)/2 */
    int centerY = 200;   /* Բ��y����(50+350)/2 */
    int radius = 80;     /* Բ�뾶 */
    int barWidth = 10;   /* ������� */
    int barHeight = 20;  /* �����߶� */
    int barCount = 12;   /* �������� */
    int i, angle, x, y;
    int prevAngle, prevX, prevY;
    
    /* ��ռ������� */
    bar1(830, 50, 1000, 350, 0xFFFFFF);
    
    /* ����Բ�α߿� */
    for(angle = 0; angle < 360; angle++)
     {
        x = centerX + radius * cos(angle * 3.14159 / 180);
        y = centerY + radius * sin(angle * 3.14159 / 180);
        bar1(x, y, x+1, y+1, 0x000000);
    }
    
    /* ����ѭ�� */
    for(i = 0; i < barCount; i++) 
    {
        /* �����һ֡ */
        if(i > 0) {
            prevAngle = (i-1) * 360/barCount;
            prevX = centerX + radius * cos(prevAngle * 3.14159 / 180) - barWidth/2;
            prevY = centerY + radius * sin(prevAngle * 3.14159 / 180) - barHeight/2;
            bar1(prevX, prevY, prevX+barWidth, prevY+barHeight, 0xFFFFFF);
        }
        
        /* ���Ƶ�ǰ���� */
        angle = i * 360/barCount;
        x = centerX + radius * cos(angle * 3.14159 / 180) - barWidth/2;
        y = centerY + radius * sin(angle * 3.14159 / 180) - barHeight/2;
        bar1(x, y, x+barWidth, y+barHeight, 0x000000);
        
        delay(200); /* ���ƶ����ٶ� */
    }
}
//��Ϣ���䶯��
void showTransferAnimation(void) 
{
    /* Բ������ */
    int centerX = 512;  /* Բ��x���� */
    int centerY = 300;  /* Բ��y���� */
    int radius = 80;    /* Բ�뾶 */
    int barWidth = 10;  /* ������� */
    int barHeight = 20; /* �����߶� */
    int i, angle, x, y;
    
    /* ���ֲ��� */
    int textX = 350;    /* ������ʼx���� */
    int textY = 500;    /* ����y���� */
    
    /* ������� */
    bar1(100, 150, 924, 600, 0xFFFFFF);
    
    /* ����Բ�� */
    angle = 0;
    while(angle < 360) {
        x = centerX + radius * cos(angle * 3.14159 / 180);
        y = centerY + radius * sin(angle * 3.14159 / 180);
        bar1(x, y, x+1, y+1, 0x000000);
        angle += 5;
    }
    
    /* �������� */
    i = 0;
    while(i < 12) 
    {
        angle = i * 30;
        x = centerX + radius * cos(angle * 3.14159 / 180) - barWidth/2;
        y = centerY + radius * sin(angle * 3.14159 / 180) - barHeight/2;
        bar1(x, y, x+barWidth, y+barHeight, 0x000000);
        delay(100);
        i++;
    }
    
    /* �����ʾ���� */
    puthz(textX, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+32, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+64, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+96, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+128, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+160, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+192, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+224, textY, "Ϣ", 32, 40, 0x000000);
    delay(200);
    puthz(textX+256, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+288, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+320, textY, "��", 32, 40, 0x000000);
    delay(200);
    puthz(textX+352, textY, "��", 32, 40, 0x000000);
    delay(1000);
}
//���ƴ�ӡ����
void printPlates(int baseX, int baseY, char plates[8][10]) 
{
    int row, col;
    int x = baseX;
    int y = baseY;
    
    for(row = 0; row < 8; row++) 
    {
        // �����ճ���
        if(plates[row][0] == '\0') continue;
        
        // ��ӡ��ǰ���Ƶ������ַ�
        for(col = 0; col < 10 && plates[row][col] != '\0'; col++)
        {
            // ���������ַ�(GBK˫�ֽ�)
            if((unsigned char)plates[row][col] >= 0xA0) 
            {
                char temp[3];
                temp[0] = plates[row][col];
                temp[1] = plates[row][col+1];
                temp[2] = '\0';
                puthz(x, y, temp, 32, 30, 0x000000);
                col++; // ������һ���ֽ�
                x += 32;
            }
            else  // ����Ӣ��/����(���ֽ�)
            {
                Put_Asc16_Size(x, y, 3, 3, plates[row][col], 0x000000);
                x += 30;
            }
        }
        
        // ���д���
        x = baseX;
        y += 50;  // �м��50����
    }
}

void draw_map_clear(void)
//�����Ļ��Ƶ�ͼ�ı�ҪԪ��
{
    mouse_off(&mouse);
    bar1(0, 0, 1024, 768, 0xFFFFFF); 
    Readbmp64k(0, 0, "bmp\\map4.bmp");
    draw_main_toolbotton(0, 0xBD32, "�����Ϣ", "չʾ");
    draw_main_toolbotton(264, 0xBD32, "ʵʱΥ��", "����");
    draw_main_toolbotton(528, 0xBD32, "��������", "����");
}
void draw_the_map(void)
{
    mouse_off(&mouse);
    bar1(0, 0, 1024, 768, 0xFFFFFF); 
    Readbmp64k(0, 0, "bmp\\map4.bmp");
    draw_main_toolbotton(0, 0xBD32, "�����Ϣ", "չʾ");
    draw_main_toolbotton(264, 0xBD32, "ʵʱΥ��", "����");
    draw_main_toolbotton(528, 0xBD32, "��������", "����");
    bar1(353, 131, 377, 155, 0xFF068); // ���Ƹ�С
    bar1(185, 335, 209, 359, 0xFF068); // ͼ���
    bar1(505, 293, 529, 317, 0xFF068); // ��е¥
    bar1(535, 65, 559, 89, 0xFF068);   // ����ѧԺ
    bar1(490, 450, 514, 474, 0xFF068); // ������
    bar1(37, 500, 61, 524, 0xFF068);   // �϶���
    bar1(171, 487, 195, 511, 0xFF068); // �����ѧԺ
    bar1(320, 425, 344, 449, 0xFF068); // ����ѧԺ
    bar1(627, 465, 651, 489, 0xFF068); // �вٳ�
    bar1(654, 153, 678, 177, 0xFF068); // ����������
    bar1(62, 245, 86, 269, 0xFF068);   // ����԰
    bar1(115, 105, 139, 129, 0xFF068); // ѧ����������
    bar1(710, 243, 734, 267, 0xFF068); // ��ʿ������

}
//����Ա��������
void draw_map(int *page)
{
    draw_map_clear();
    Readbmp64k(800,0,"bmp\\AIA.bmp");
    puthz(800, 270, "�𾴵Ĺ���Ա", 32, 30, 0x000000);
    puthz(800, 320, "��ӭʹ��", 48, 50, 0x000000);
    puthz(800, 400, "Υͣ����ϵͳ", 32, 30, 0x000000);
    puthz(830, 540, "������ఴť���в���", 32, 30, 0x000000);
    draw_confirmbotton(830, 680, "����������"); // ����������
    while (1)
    {
        mouse_show(&mouse);  
        if(mouse_press(0,590,264,750)==1)
        {
            *page=6;
            break;
        }
        if(mouse_press(264,590,518,750)==1)
        {
            *page=7;
            break;
        }
        if(mouse_press(528,590,792,750)==1)
        {
            *page=8;
            break;
        }
        if (mouse_press(830, 680, 1024, 740) == 1) 
        {
            *page=0;  
            break;
        }   
    }
}
//�����Ϣ��ѯ
void watcher(int *page) { 
    char* locations[] = {
       "���Ƹ�С", "ͼ���", "��е¥", "����ѧԺ", "������",
       "�϶���", "�����ѧԺ", "����ѧԺ", "�вٳ�", "����������",
       "����԰", "ѧ����������", "��ʿ������"
    };
    int i=0;
    int x_start = 100;  // ��ʼX����
    int y_start = 600;  // ��ʼY����
    int x_offset = 120; // ÿ����Ŀ��ˮƽ���
    int y_offset = 40;  // ÿ����Ŀ�Ĵ�ֱ���
    int font_size = 16; // ���ִ�С��16x16
    int color = 0xFF068;  // ������ɫ
    int part = 16;  // ÿ�����ֵĿ��
    int selected = 0;
    char locationName[50], brand[50], function[100];    
    int max_width = 600; // �����
    
    int x = x_start, y = y_start;
    // �ر���꣬��ֹ����ʱ���ִ���
    mouse_off(&mouse);
    bar1(0,0,1024,768,0xFFFFFF);
    Readbmp64k(0, 0, "bmp\\map4.bmp");
    // ���Ƽ�ؽ���
    prt_hz24_asc32(50, 710, "��صص���Ϣ", 0x000000, "HZK\\HZK24s"); // ����
    //���ƹ��ܰ�ť
    rounded_bar(830, 50, 1000, 350, 20, 0xFFFFFF, 0x000000, 0);
    puthz(840,70,"�豸״��",24,25,0x000000);
    bar1(830, 500,1000,560,0x32CD32);
    puthz(840,520,"����豸״̬",24,25,0xFFFFFFF);
    bar1(830, 600, 1000, 660, 0x32CD32); 
    puthz(840, 620, "������һҳ", 24, 25, 0xFFFFFF);
    // �������м�صص�
    bar1(353, 131, 377, 155, 0xFF068); // ���Ƹ�С
    bar1(185, 335, 209, 359, 0xFF068); // ͼ���
    bar1(505, 293, 529, 317, 0xFF068); // ��е¥
    bar1(535, 65, 559, 89, 0xFF068);   // ����ѧԺ
    bar1(490, 450, 514, 474, 0xFF068); // ������
    bar1(37, 500, 61, 524, 0xFF068);   // �϶���
    bar1(171, 487, 195, 511, 0xFF068); // �����ѧԺ
    bar1(320, 425, 344, 449, 0xFF068); // ����ѧԺ
    bar1(627, 465, 651, 489, 0xFF068); // �вٳ�
    bar1(654, 153, 678, 177, 0xFF068); // ����������
    bar1(62, 245, 86, 269, 0xFF068);   // ����԰
    bar1(115, 105, 139, 129, 0xFF068); // ѧ����������
    bar1(710, 243, 734, 267, 0xFF068); // ��ʿ������
    // ��������λ������
    for (i = 0; i < sizeof(locations) / sizeof(locations[0]); i++) 
    {
        // ��ʾ����
        puthz(x, y, (char*)locations[i], font_size, part, color);
        // ���º����꣬�����������ȣ�����
        x += x_offset;
        if (x + x_offset > x_start + max_width) 
        {
            x = x_start; // ����Ϊ��ʼX����
            y += y_offset; // ���У����Ӵ�ֱƫ��
        }
    }
    {
        int x_start = 90;  // �����ʼX����
        int y_start =  580;  // �����ʼY����
        int cell_width = 120;  // ÿ����Ԫ��Ŀ��
        int cell_height = 40;  // ÿ����Ԫ��ĸ߶�
        int rows = 3;  // ��������
        int cols = 5;  // ��������
        int font_size = 16;  // �����С
        int color = 0x000000;  // ������ɫ

        int i, j, index = 0;

        // ���Ʊ��
        for (i = 0; i < rows; i++) 
        {
            for (j = 0; j < cols; j++)
            {
                int x = x_start + j * cell_width;
                int y = y_start + i * cell_height;

                // ���Ƶ�Ԫ��߿�
                bar1(x, y, x + cell_width, y + 1, color); // �ϱ߿�
                bar1(x, y, x + 1, y + cell_height, color); // ��߿�
                bar1(x + cell_width - 1, y, x + cell_width, y + cell_height, color); // �ұ߿�
                bar1(x, y + cell_height - 1, x + cell_width, y + cell_height, color); // �±߿�

            }
        }
    }
    while (1) 
    {
        mouse_show(&mouse);
        // ��صص������
        if (mouse_press(830, 600, 1024, 660) == 1) 
        {
            *page = 5;  // ����������
            mouse_off(&mouse);
            break;
        }
        if(mouse_press(830, 500,1000,560)==1)
        {
           mouse_off(&mouse);
            rounded_bar(830, 50, 1000, 350, 20, 0xFFFFFF, 0x000000, 0); 
            showLoadingAnimation();
            rounded_bar(830, 50, 1000, 350, 20, 0xFFFFFF, 0x000000, 0); 
            puthz(840,160,"�豸����",24,25,0x000000);
            bar1(830, 500,1000,560,0x32CD32);
            puthz(840,520,"����Ա��֪��",24,25,0xFFFFFFF);
            delay(500);
            //puthz(840,70,"�豸״��",24,25,0x000000);
            bar1(830, 500,1000,560,0x32CD32);
            puthz(840,520,"����豸״̬",24,25,0xFFFFFFF);
            rounded_bar(830, 50, 1000, 350, 20, 0xFFFFFF, 0x000000, 0);   
            puthz(840,70,"�豸״��",24,25,0x000000);
        }
        //��������Ϣ�鿴
        if (mouse_press(353, 131, 377, 155) == 1) 
        {
           
            strcpy(locationName, "���Ƹ�С");
            strcpy(brand, "��������");
            strcpy(function, "������Ƶ����");
            mouse_off(&mouse);
            bar1(353, 131, 377, 155, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(185, 335, 209, 359) == 1) 
        {
            strcpy(locationName, "ͼ���");
            strcpy(brand, "��");
            strcpy(function, "������Ƶ���");
            mouse_off(&mouse);
            bar1(185, 335, 209, 359, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(505, 293, 529, 317) == 1) 
        {
            strcpy(locationName, "��е¥");
            strcpy(brand, "��������");
            strcpy(function, "������Ƶ���");
            mouse_off(&mouse);
            bar1(505, 293, 529, 317, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(535, 65, 559, 89) == 1) 
        {
            strcpy(locationName, "����ѧԺ");
            strcpy(brand, "��");
            strcpy(function, "������Ƶ���");
            mouse_off(&mouse);
            bar1(535, 65, 559, 89, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(490, 450, 514, 474) == 1) 
        {
            strcpy(locationName, "������");
            strcpy(brand, "��������");
            strcpy(function, "������Ƶ����");
            mouse_off(&mouse);
            bar1(490, 450, 514, 474, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(37, 500, 61, 524) == 1) 
        {
            strcpy(locationName, "�϶���");
            strcpy(brand, "��������");
            strcpy(function, "����ʶ����");
            mouse_off(&mouse);
            bar1(37, 500, 61, 524, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(171, 487, 195, 511) == 1) 
        {
            strcpy(locationName, "�����ѧԺ");
            strcpy(brand, "��������");
            strcpy(function, "Զ����Ƶ���");
            bar1(171, 487, 195, 511, 0xFF068);
            mouse_off(&mouse);
            selected = 1;
        } 
        else if (mouse_press(320, 425, 344, 449) == 1) 
        {
            strcpy(locationName, "����ѧԺ");
            strcpy(brand, "��������");
            strcpy(function, "����ʶ����");
            mouse_off(&mouse);
            bar1(320, 425, 344, 449, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(627, 465, 651, 489) == 1) 
        {
            strcpy(locationName, "�вٳ�");
            strcpy(brand, "��");
            strcpy(function, "ȫ�����");
            mouse_off(&mouse);
            bar1(627, 465, 651, 489, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(654, 153, 678, 177) == 1) 
        {
            strcpy(locationName, "����������");
            strcpy(brand, "��������");
            strcpy(function, "����ͣ�������");
            mouse_off(&mouse);
            bar1(654, 153, 678, 177, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(62, 245, 86, 269) == 1) 
        {
            strcpy(locationName, "����԰");
            strcpy(brand, "��������");
            strcpy(function, "�˹�����Ѳ����");
            mouse_off(&mouse);
            bar1(62, 245, 86, 269, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(115, 105, 139, 129) == 1) 
        {
            strcpy(locationName, "ѧ����������");
            strcpy(brand, "��");
            strcpy(function, "�������ܼ��");
            mouse_off(&mouse);
            bar1(115, 105, 139, 129, 0xFF068);
            selected = 1;
        } 
        else if (mouse_press(710, 243, 734, 267) == 1) 
        {
            strcpy(locationName, "��ʿ������");
            strcpy(brand, "��������");
            strcpy(function, "�Ž�ͣ��������");
            bar1(710, 243, 734, 267, 0xFF068);
            mouse_off(&mouse);
            selected = 1;
        }
        // ���ѡ����ĳ����ص㣬��ʾ��ϸ��Ϣ����
        if (selected) 
        {
            mouse_off(&mouse);
            bar1(312, 200, 792, 500, 0xFFFFFF); // ������Ϣ���ڱ���
            bar1(312, 200, 792, 230, 0x000000); // ������
            puthz(345, 200, "�������", 24, 25, 0xFFFFFF); // ����
            puthz(322, 260, "�ص㣺", 24, 25, 0x000000);
            puthz(402, 260, locationName, 24, 25, 0x000000);
            puthz(322, 300, "Ʒ�ƣ�", 24, 25, 0x000000);
            puthz(402, 300, brand, 24, 25, 0x000000);
            puthz(322, 340, "���ܣ�", 24, 25, 0x000000);
            puthz(402, 340, function, 24, 25, 0x000000);
            //���з��ذ�ť
            bar1(450, 400, 650, 450, 0x32CD32);  // ��ɫ��ť
            puthz(520, 415, "����", 24, 25, 0xFFFFFF);  // ��ť���֣���ɫ��
            //�ȴ��û�����
            while (1) {
                mouse_show(&mouse);
                //������ذ�ť��ˢ�½���
                if (mouse_press(450, 400, 650, 450) == 1) {
                    mouse_off(&mouse);
                    watcher(page); // ���»��ƽ���   
                    return;
                }
            }
          }          
       }
    }





//����Ա�˳�ʼ�������ö˿�
void handle(int *page) 
{
    //��ʼ������
    char *locations[20][4] = {
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
    char* location[] = {
        "���Ƹ�С", "ͼ���", "��е¥", "����ѧԺ", "������", 
        "�϶���", "�����ѧԺ", "����ѧԺ", "�вٳ�", "����������", 
        "����԰", "ѧ����������"
    };
    static time_t lastViolationTime = 0;
    static int violationInterval = 0;//����¼�����ʱ�������
    USERS s = {0};
    USERS temp;
    long current_pos = 0;
    int locations_coords[12][4] = 
    {
        {353, 131, 377, 155}, {185, 335, 209, 359}, {505, 293, 529, 317}, {535, 65, 559, 89},
        {490, 450, 514, 474}, {37, 500, 61, 524}, {171, 487, 195, 511}, {320, 425, 344, 449},
        {627, 465, 651, 489}, {654, 153, 678, 177}, {62, 245, 86, 269}, {115, 105, 139, 129}
    };
    int locationIdx = -1, violationIdx = 0;
    int violationHandled = 0;
    int clicked = 0;
    int i = 0;
    int record_count = 0;
    long file_size;
    FILE* fp = NULL;
    int found_count = 0;
    mouse_off(&mouse);
    //�ļ�����
    fp = fopen("data.dat", "rb+");
    if (fp == NULL) 
    {
        fp = fopen("data.dat", "wb+");
        if (fp == NULL) 
        {
            perror("�ļ�����ʧ��");
            exit(EXIT_FAILURE);
        }
    }
    fseek(fp, 0, SEEK_END);
    record_count = ftell(fp) / sizeof(USERS);
     fseek(fp, 0, SEEK_SET); // �����ļ�ָ�뵽��ͷ
    {
        int j;
        // ��ȡ�ļ��е����м�¼ 
        for (j = 0; j < record_count; j++) 
        {
            current_pos = ftell(fp);  // ��¼��ǰ�ļ�ָ��λ��
            if (fread(&temp, sizeof(USERS), 1, fp) != 1) 
            {
                perror("��ȡ��¼ʧ��");
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            if (temp.if_fine == 0||temp.if_fine==2)
             {  // ���� if_fine == 0 �� if_fine == 2�ļ�¼
                s= temp;  // �����������ļ�¼��ֵ�� s
                found_count++;
                break;
            }
        }
    }
    fclose(fp);
    srand((unsigned int)time(NULL));//���������
    //�������
    mouse_off(&mouse);
    bar1(0, 0, 1024, 768, 0xFFFFFF);
    Readbmp64k(0, 0, "bmp\\map4.bmp");
    for (i = 0; i < 12; i++) 
    {
        bar1(locations_coords[i][0], locations_coords[i][1], 
             locations_coords[i][2], locations_coords[i][3], 0xFF068);
    }
    draw_main_toolbotton(0, 0xBD32, "��ʷΥ��", "��ѯ");
    draw_main_toolbotton(264, 0xBD32, "ʵʱΥ��", "����");
    draw_main_toolbotton(528, 0xBD32, "�۷�׼��", "�鿴");
    bar1(830, 600, 1000, 660, 0x32CD32);
    puthz(840, 620, "����������", 24, 25, 0xFFFFFF);
    //��ʼ��ʱ�������
    if (violationInterval == 0) 
    {
        violationInterval = 20 + rand() % 6; // ���10-15��
        lastViolationTime = time(NULL);
    }
    draw_confirmbotton(830, 710, "����������"); // ����������
    while (1) 
    {
        mouse_show(&mouse);
        if(mouse_press(830,710,1000,760)==1)
        {
            *page=0;  // ����������
            mouse_off(&mouse);
            break;
        }
        //ʱ����Ʋ����¼�д��
        
        if (violationHandled == 0 && record_count < 100) 
        {
            time_t currentTime = time(NULL);
            if (difftime(currentTime, lastViolationTime) >= violationInterval) 
            {
                locationIdx = rand() % 12;
                violationIdx = rand() % 4;
                if(s.brand[0]=='\0')
                {
                    s.brand[0]='1'+rand()%5;
                    s.brand[1]='\0';
                }
                s.location = locationIdx;
                s.violation = violationIdx;
                s.if_against = 0;
                //if (plate_count > 0) {
                    //int plate_idx = rand() % plate_count;
                    //strcpy(s[record_count].carboard[0], plates[plate_idx]);
                //}
                 // ���ļ�ָ�����¶�λ���ü�¼����ʼλ��
                 fp= fopen("data.dat", "rb+");
                fseek(fp, current_pos, SEEK_SET);
                
                if (fwrite(&s, sizeof(USERS), 1, fp) != 1) 
                {
                    perror("д��ʧ��");
                    fclose(fp);
                    exit(0);
                }
                fflush(fp); // ˢ���ļ�������
                fclose(fp);
                violationHandled = 1;
                clicked = 0;
                bar1(locations_coords[locationIdx][0], locations_coords[locationIdx][1],
                     locations_coords[locationIdx][2], locations_coords[locationIdx][3], 0xFF0000);
                
                // ���ü�ʱ��
                violationInterval = 30 + rand() % 6;
                lastViolationTime = currentTime;
            }
        }
        
        //ȷ�������ͼ��ť����ܽ�һ������
        if (mouse_press(locations_coords[locationIdx][0], locations_coords[locationIdx][1],
                       locations_coords[locationIdx][2], locations_coords[locationIdx][3]) == 1)
        {
            clicked = 1;
            mouse_off(&mouse);
            bar1(locations_coords[locationIdx][0], locations_coords[locationIdx][1],
                 locations_coords[locationIdx][2], locations_coords[locationIdx][3], 0x00CC33);
            bar1(800, 400, 1020, 500, 0xFFFFFF);
            puthz(810, 420, location[locationIdx], 24, 35, 0x000000);
            puthz(810, 450, locations[locationIdx][violationIdx], 24, 25, 0x000000);
            mouse_show(&mouse);
        }
        if (clicked == 1) 
        {
            if (mouse_press(264, 590, 518, 750) == 1) 
            {
                *page = 10;
                break;
            }
            if (mouse_press(840, 628, 950, 700) == 1) 
            {
                mouse_off(&mouse);
                bar1(800, 400, 1020, 500, 0xFFFFFF);
                bar1(locations_coords[locationIdx][0], locations_coords[locationIdx][1],
                     locations_coords[locationIdx][2], locations_coords[locationIdx][3], 0xFF068);
                violationHandled = 0;
                clicked = 0;
            }
        }
        //������ť
        if (mouse_press(0, 590, 264, 750) == 1) 
        {
            *page = 12;
            break;
        }
        if (mouse_press(518, 590, 782, 750) == 1) 
        {
            *page = 13;
            break;
        }
        if (mouse_press(830, 600, 1000, 660) == 1)
         {
            *page = 5;

            break;
        }
    }
}



//����Ա�˴���
void deal_window(int *page) 
{
    char* location[] = {
        "���Ƹ�С", "ͼ���", "��е¥", "����ѧԺ", "������", 
        "�϶���", "�����ѧԺ", "����ѧԺ", "�вٳ�", "����������", 
        "����԰", "ѧ����������"
    };
    char *locations[20][4] = {
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
    USERS v = {0};
    FILE *fp = NULL;
    int record_count = 0;
    long file_size;
    int click = -1;
    int i;
    USERS temp;
    long current_pos = 0;
    int found_count = 0;
   
    //��ʼ���ļ�ָ��ͼ�¼��
    fp = fopen("data.dat", "rb+");
    if (fp == NULL) 
    {
        fp = fopen("data.dat", "wb+");
        if (fp == NULL) 
        {
            mouse_off(&mouse);
            bar1(0, 0, 1024, 768, 0xFFFFFF);
            puthz(400, 300, "�޷����������ļ�", 32, 40, 0xFF0000);
            puthz(400, 350, "�����������", 32, 40, 0xFF0000);
            mouse_show(&mouse);
            while(!mouse_press(0, 0, 1024, 768));
            *page = 7;
            return;
        }
    }
    //��ȷ��ȡ�ļ���С
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    record_count = file_size / sizeof(USERS);
    fseek(fp, 0, SEEK_SET);
  
    //���ڼ�¼��>0ʱ�����ڴ�
   {
        int j;
        // ��ȡ�ļ��е����м�¼ 
        for (j = 0; j < record_count; j++) 
        {
            current_pos = ftell(fp);  // ��¼��ǰ�ļ�ָ��λ��
            if (fread(&temp, sizeof(USERS), 1, fp) != 1) 
            {
                perror("��ȡ��¼ʧ��");
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            if (temp.if_fine == 0||temp.if_fine==2)
             {  // ���� if_fine == 0 ��if_fine==2�ļ�¼
                v= temp;  // �����������ļ�¼��ֵ�� s
                found_count++;
                break;
            }
        }
    }
     // ���û���ҵ����������ļ�¼
    if (found_count == 0) 
    {
        bar1(400, 300, 624, 350, 0xFFFFFF);
        puthz(400, 300, "��Υ�¼�¼�ɴ���", 32, 40, 0xFF0000);
        fclose(fp);
        return;
    }
    if(v.if_fine==0)
    {
        // ����ҵ����������ļ�¼����������
        // ���㵱ǰ��¼��ƫ����
        //��ʼ������
        mouse_off(&mouse);
        bar1(0, 0, 1024, 768, 0xFFFFFF);
        Readbmp64k(0, 0, "bmp\\user1.bmp");
        // ���ƽ���Ԫ��
        puthz(50, 50, "��������ҳ", 48, 50, 0x000000);
        rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
        // ��ʾ��ǰ��¼��Ϣ
        puthz(150, 180, "Υͣ����", 32, 40, 0x000000);
    
        {
            int row, col, offset;
            int x, y;
            int baseX = 350, baseY = 180;
            char plateBuf[80];
            char temp[10];
            // ��λ���������ݿ�ʼ��������ȡ 80 �ֽڳ������ݣ�8�����ƣ�ÿ��10�ֽڣ�
            fseek(fp, current_pos, SEEK_SET);  // ��λ��ָ����¼
            fseek(fp,60, SEEK_CUR);  // ����ǰ60�ֽ�,������ƺ�
            fread(plateBuf, sizeof(plateBuf), 1, fp);
            
            // ��ʼ�����ֻ꣬��ʼ��һ�Σ���֤���������ͬһ��
            x = baseX;
            y = baseY;
            
            // ����8�����Ʋ���
            for(row = 0; row < 8; row++)
            {
                offset = row * 10;
                for(col = 0; col < 10 && plateBuf[offset + col] != '\0'; )
                {
                    // ���Ϊ�����ַ���GBK�����£�����Ϊ˫�ֽ��жϣ�
                    if((unsigned char)plateBuf[offset + col] >= 0xA0)
                    {
                        char temp[3];
                        temp[0] = plateBuf[offset+col];
                        temp[1] = plateBuf[offset+col+1];
                        temp[2] = '\0';
                        puthz(x, y, temp, 32, 30, 0x000000);
                        col += 2;
                        x += 32;
                    }
                    else  // Ӣ�Ļ�����Ϊ���ֽ�
                    {
                        Put_Asc16_Size(x, y, 3, 3, plateBuf[offset+col], 0x000000);
                        col++;
                        x += 30;
                    }
                }
            }
        }
        fclose(fp);
        //puthz(300, 180, v[current_index].carboard, 32, 40, 0x000000);
        puthz(150, 230, "Υͣ�ص�", 32, 40, 0x000000);
        puthz(330, 230, location[v.location], 32, 40, 0x000000);
        puthz(150, 280, "Υͣ��Ϊ", 32, 40, 0x000000);
        puthz(330, 280, locations[v.location][v.violation], 32, 40, 0x000000);
        //��Ϊ��Ӧ��Ƭ��ӡ
        //��һ�ࣺ�������Υ��
        if  ((v.location == 0 && v.violation == 0) ||  // ��������ͨ��
        (v.location == 2 && v.violation == 2) ||  // ����˨ǰ
        (v.location == 4 && v.violation == 2) ||  // Ӧ��ͨ��
        (v.location == 9 && v.violation == 0) ||  // ��������ͨ��
        (v.location == 11 && v.violation == 0)){  // ��������ͨ��
        Readbmp64k(300, 350, "bmp\\3.bmp");
        }
        // �ڶ��ࣺ�����Υ��
        if((v.location == 0 && v.violation == 3) ||  // У԰�����
        (v.location == 1 && v.violation == 0) ||  // ͼ������
        (v.location == 2 && v.violation == 0) ||  // ��е¥�����
        (v.location == 3 && v.violation == 0) ||  // ����ѧԺ���
        (v.location == 4 && v.violation == 0) ||  // ���������
        (v.location == 5 && v.violation == 0)) { // �϶��ų����
        Readbmp64k(300, 350, "bmp\\5.bmp");
        } 
        
        // �����ࣺ���⳵λռ��//(v[current_index].location == 11 && v[current_index]v.violation == 1))
        if ((v.location == 1 && v.violation == 2) ||  // �м��˳�λ
        (v.location == 3 && v.violation == 2) ||  // ��ְ����λ
        (v.location == 6 && v.violation == 2) ||  // ����Դ���λ
        (v.location == 7 && v.violation == 2) ||  // �ÿͳ�λ
        (v.location == 9 && v.violation == 1) )  // �������˳�λ
        {// �������˳�λ
        Readbmp64k(300, 350, "bmp\\1.bmp");
        }
        // �����ࣺ�̻�/���е�Υ�� (click=4)
        if ((v.location == 0 && v.violation == 1) ||  // ռ�����е�
        (v.location == 1 && v.violation == 3) ||  // �̻�����
        (v.location == 3 && v.violation == 3) ||  // �̻�����
        (v.location == 5 && v.violation == 2) ||  // ���е���
        (v.location == 10 && v.violation == 1)) {  // �����̻���
        Readbmp64k(300, 350, "bmp\\6.bmp");
        }
    // �����ࣺ��������Υ�� (click=5)
        if((v.location == 6 && v.violation == 1) ||  // ѧԺ̨��ǰ
        (v.location == 7 && v.violation == 1) ||  // ����·��
        (v.location == 8 && v.violation == 1) ||  // �ܵ�������
        (v.location == 9 && v.violation == 3) ||  // ҹ��Υͣ
        (v.location == 11 && v.violation == 3)) {  // ҹ��Υͣ
        Readbmp64k(300, 350, "bmp\\2.bmp");
        }
        
        // �����ࣺ����Υ�� (click=6)
        else{
            Readbmp64k(300, 350, "bmp\\4.bmp");
        }
        

        // �۷�ѡ�ť
        bar1(220, 520, 350, 560, 0xFFD700);
        puthz(230, 520, "�۶���", 32, 40, 0x000000);
        bar1(420, 520, 550, 560, 0xFFD700);
        puthz(430, 520, "�����", 32, 40, 0x000000);
        bar1(620, 520, 750, 560, 0xFFD700);
        puthz(630, 520, "��ʮ��", 32, 40, 0x000000);
        draw_botton(600, 405, 700, 455, 0xFFFFFF, 0x000000);
        puthz_coverd(590, 415, "�����϶�", 2, 32, 30, 0x000000);
        // ������ť
        draw_botton(250, 635, 350, 695, 0xFFFFFF, 0x000000);
        puthz_coverd(230, 652, "������ҳ", 4, 32, 30, 0x000000);
        draw_botton(440, 635, 560, 695, 0xFFFFFF, 0x000000);
        puthz_coverd(430, 652, "�ύ����", 4, 32, 30, 0x000000);
        draw_botton(660, 635, 760, 695, 0xFFFFFF, 0x000000);
        puthz_coverd(650, 652, "����鿴", 2, 32, 30, 0x000000);
    }
    
    // ��ѭ��
    while (1) 
    {
        mouse_show(&mouse);
        if(v.if_fine==2)
        {
            *page=14;
            break;
        }
        
        if (record_count == 0) 
        {
            bar1(400, 300, 624, 350, 0xFFFFFF);
            draw_botton(660, 635, 760, 695, 0xFFFFFF, 0x000000);
            puthz(400, 300, "��Υ�¼�¼�ɴ���", 32, 40, 0xFF0000);
        }
        //ϣ����ɫ��ʵ����ʾ��
        if(mouse_press(600, 405, 700, 455)==1)
        {
            draw_botton(600, 405, 650, 455, 0xFFFFFF, 0x32CD320);
            puthz_coverd(590, 415, "�����϶�", 2, 32, 30, 0x000000);
            click=0;
        }
        if (mouse_press(220, 520, 350, 560)==1) 
        {
            bar1(220, 520, 350, 560, 0x32CD32);
            puthz(230, 520, "�۶���", 32, 40, 0x000000);
            click=2;
        }
        if(mouse_press(420, 520, 550, 560)==1)
        {
            bar1(420, 520, 550, 560, 0x32CD32);
            puthz(430, 520, "�����", 32, 40, 0x000000);
            click=5;
        }
        if(mouse_press(620, 520, 750, 560)==1)
        {
            bar1(620, 520, 750, 560, 0x32CD32);
            puthz(630, 520, "��ʮ��", 32, 40, 0x000000);
            click=10;
        }
        
        if (mouse_press(440, 635, 560, 695) == 1 && click != -1) 
        {    
            // ���µ�ǰ��¼�Ĵ�����Ϣ
            v.if_fine = 1;
            v.fine[0] = click * 10;  // ������
            v.fine[1] = click;      // �۷�ֵ
            if (click == 0) 
            {
                v.if_fine = 0;  // ���ѡ�������϶���������������
            }

            // �����µĴ�����¼׷�ӵ��ļ�ĩβ
            fp= fopen("data.dat", "rb+");
            if (fp== NULL) 
            {
                perror("�޷����ļ�����׷��д��");
                fclose(fp);
                exit(0);
            }
            strcpy(v.fine_time,"���¶�ʮ��");
            fseek(fp, current_pos, SEEK_SET);  // ��λ����ǰ��¼
            if (fwrite(&v, sizeof(USERS), 1, fp) != 1)
             {
                perror("д��ʧ��");
                fclose(fp);
                exit(0);
            }
            //fflush(fp); // ˢ���ļ�������
            // ��ת����ʷ��¼ҳ��
            showTransferAnimation1();
            *page=7;
            
           fclose(fp);
            break;
        }

        // ���ذ�ť
        if (mouse_press(250, 635, 350, 695) == 1) 
        {
            *page = 7;
            break;
        }
        // ����鿴
        if (mouse_press(660, 635, 760, 695) == 1) 
        {
            *page = 11;
            break;
        }
        if(*page==7)
        {
           
            break;
        }
        if(*page==11)
        {
            break;
        }
    }
}




void charge_deal(int *page) 
{
    //��ʼ������
    char* location[] = 
    {
        "���Ƹ�С", "ͼ���", "��е¥", "����ѧԺ", "������", 
        "�϶���", "�����ѧԺ", "����ѧԺ", "�вٳ�", "����������", 
        "����԰", "ѧ����������"
    };
    //Υͣ��ΪԤ��
    char *locations[20][4] = 
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
    //��������Ԥ��
    char *charges[6]=
    {
            "��������ͣ�ŵ�����",
            "����Υͣ���ͷ�������",
            "����ԭ�򣬵ȴ�����Ա����",
            "��������ͣ�ŵ�����",
            "����Υͣ���ͷ�������",
            "����ԭ�򣬵ȴ�����Ա����",
        };
    FILE *fp = NULL;
    int deside=-1;
    USERS records = {0};
    int record_count = 0;
    int i;
    int j;
    int y_offset = 330; // ��ʼY����
    long current_pos = 0;
    int found_count = 0;
    USERS temp;
    int is_query1=0;
    int is_query2=0;
    //�ļ������Լ���¼������ȡ
    fp = fopen("data.dat", "rb+");
    if (fp == NULL) 
    {
        perror("�ļ���ʧ��");
        return;
    }
    fseek(fp, 0, SEEK_END);
    record_count = ftell(fp) / sizeof(USERS);
    fseek(fp, 0, SEEK_SET); // ���ļ�ָ�����¶�λ����ͷ
    //��ȡ��¼
    {
        int j;
        // ��ȡ�ļ��е����м�¼ 
        for (j = 0; j < record_count; j++) 
        {
            current_pos = ftell(fp);  // ��¼��ǰ�ļ�ָ��λ��
            if (fread(&temp, sizeof(USERS), 1, fp) != 1) 
            {
                perror("��ȡ��¼ʧ��");
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            if (temp.if_against == 1)
             {  // ���� if_against == 1 �ļ�¼
                records = temp;  // �����������ļ�¼��ֵ�� s
                found_count++;
                break;
            }
        }
    }
    fclose(fp);
    if (found_count == 0) 
    {
        bar1(400, 300, 624, 350, 0xFFFFFF);
        puthz(400, 300, "�޴��������ɴ���", 32, 40, 0xFF0000);
        fclose(fp);
        *page=5;
       
        return;
        
    }

    else
    {
        
        mouse_off(&mouse);
        bar1(0, 0, 1024, 768, 0xFFFFFF);
        Readbmp64k(0, 0, "bmp\\user1.bmp");
        rounded_bar(50, 120, 974, 600, 10, 0xBDBD, 0xFFFFFF, 0);
        bar1(60, 130, 964, 580, 0xFFFFFF);
        puthz(400, 50, "���ߴ���", 48, 50, 0x000000);
        puthz(150, 180, "���߳���", 32, 40, 0x000000);
    // printPlates(330, 180, records[count].carboard); 
        //puthz(300, 180, records[count].plate, 32, 40, 0x000000);
        prt_hz16_asc16_size(330, 180, 3, 3, records.carboard, 0x000000,"HZK\\hzk16");
        puthz(150, 230, "��¼�ص�", 32, 40, 0x000000);
        puthz(330, 230, location[records.location], 32, 40, 0x000000);
        puthz(150, 280, "��¼��Ϊ", 32, 40, 0x000000);
        puthz(330, 280, locations[records.location][records.violation], 32, 40, 0x000000);
        puthz(150, 330, "��������", 32, 40, 0x000000);
        for (j = 2; j < 8; j++) 
        {
            if (records.fine[j] == 1) 
            {
                puthz(300, y_offset, charges[j-2], 32, 30, 0x000000);
                y_offset += 50; // ÿ����������50����
            }
        }
    }
    draw_botton(250, 635, 350, 695, 0xFFFFFF, 0x000000);
    puthz_coverd(225, 652, "�ύ����", 4, 32, 30, 0x000000);
    draw_botton(660, 635, 760, 695, 0xFFFFFF, 0x000000);
    puthz_coverd(639, 652, "����������", 2, 32, 30, 0x000000);
    draw_botton(150, 550, 350, 610, 0xFFFFFF, 0xFF0000);
    puthz_coverd(180, 567, "��������", 4, 32, 30, 0x000000);
    draw_botton(650, 550, 850, 610, 0xFFFFFF, 0x00FF00);
    puthz_coverd(680, 567, "ά���ж�", 4, 32, 30, 0x000000);
    while (1) 
    {
        mouse_show(&mouse);
        if(mouse_press(150,550,350,610)==1)
        {
            if(is_query1==0)
            {
                deside=1;
                mouse_off(&mouse);
                delay(200);
                puthz_coverd(180, 567, "��������", 4, 32, 30,0xFF068);
                is_query1=1;
            }
            else
            {
                deside=-1;
                mouse_off(&mouse);
                delay(200);
                puthz_coverd(180, 567, "��������", 4, 32, 30,0xFF068);
                is_query1=0;
            }
        }//����
        if(mouse_press(650,550,850,610)==1)
        {
            if(is_query2==0)
            {
                deside=0;
                mouse_off(&mouse);
                delay(200);
                draw_botton(650, 550, 850, 610, 0xFF068, 0xFF33CC);
                puthz_coverd(680, 567, "ά���ж�", 4, 32, 30, 0x000000);
                mouse_show(&mouse);
            }
            else
            {
                deside=-1;
                mouse_off(&mouse);
                delay(200);
                draw_botton(650, 550, 850, 610, 0xFFFFFF, 0x00FF00);
                puthz_coverd(680, 567, "ά���ж�", 4, 32, 30, 0x000000);
                mouse_show(&mouse); 
                is_query2=0;
            }
        }//ά��ԭ��
        if(mouse_press(250, 635, 350, 695)==1&&deside!=-1)
        {
            if (deside==1)
            {
                records.if_fine = 0;
                records.if_against = 0;
                //д���ļ�
                fp= fopen("data.dat", "rb+");
                fseek(fp, current_pos, SEEK_SET);
                if (fwrite(&records, sizeof(USERS), 1, fp) != 1) 
                {
                    perror("д��ʧ��");
                }
                puthz_coverd(430, 700, "�ѳ���", 2, 32, 30, 0xFF0000);
                delay(1000);
                
                *page=5;
                fclose(fp);
                break;
            }
            if (deside==0)
            {
                records.if_against = 0;
                //д���ļ�
                fp= fopen("data.dat", "rb+");
                fseek(fp, current_pos, SEEK_SET);
                if (fwrite(&records, sizeof(USERS), 1, fp) != 1) 
                {
                    perror("д��ʧ��");
                }
                puthz_coverd(430, 700, "ά��ԭ��", 2, 32, 30, 0x00FF00);
                delay(1000);
                *page=5;
                fclose(fp);
                break;
            }  
        }
        if (mouse_press(660, 635, 760, 695) == 1) 
        {  // ���������水ť
            *page = 7;
            break;
        }
    }
}

void rules(int *page) 
{
    mouse_off(&mouse);
    Readbmp64k(0, 0, "bmp\\user1.bmp");
    puthz(350,50,"���пƼ���ѧ",48,50,0x9932CC);
    puthz(270,120,"������Υͣ��������",48,50,0x000000);
    rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
    bar1(60, 210, 964, 660, 0xFFFFFF);
    puthz(65, 220, "��һ����΢Υ��", 32, 30, 0x000000);
    puthz(110, 270, "�ڷ�ָ����ʱͣ���������ͣ����������ڣ���δӰ�콻ͨ���������ͨ�С�", 24, 25, 0x000000);
    puthz(80, 300, "ͣ��ʱ�����ֳ���ͣ��λ�߽磬��δ����������������������ͨ�У�ÿ�ο۶�", 24, 25, 0x000000);
    puthz(80, 330, "�֣������ʮԪ", 24, 25, 0x000000);
    puthz(65, 370, "������һ��Υ��", 32, 30, 0x000000);
    puthz(110, 420, "�ڽ�ֹͣ����־�����ߴ�ͣ������δ��ɽ�ͨӵ�¡�������ͨ����Ӧ��ͨ��ͣ", 24, 25, 0x000000);
    puthz(80, 450, "������δ�������������ÿ�ο���֣�������ʮԪ", 24, 25, 0x000000);
    puthz(65, 490, "����������Υ��", 32, 30, 0x000000);
    puthz(110, 530, "������ͨ����Ӧ��ͨ����ʱ��ͣ�������½�����Ԯ�����޷�ͨ�С���Υͣ���", 24, 25, 0x000000);
    puthz(80, 570, "У԰�ڽ�ͨ����ӵ�£�Ӱ�췶Χ�ϴ��ҳ���ʱ��ϳ���������ʮ���ӣ���Υ����", 24, 25, 0x000000);
    puthz(80, 600, "ÿ�ο�ʮ�֣�������ʮԪ", 24, 25, 0x000000);
    // ���Ʒ��ذ�ť����ɫ���� + ���еײ���
    draw_botton(300,660,450,730,0xFFFFFF,0x000000);
    puthz_coverd(293,670,"������һҳ",5 ,32,30,0x000000);
    draw_botton(580,660,730,730,0xFFFFFF,0x000000);
    puthz_coverd(593,670,"����������",2 ,32,30,0x000000);
    // ����������¼�
    while (1) {
        mouse_show(&mouse);
        if (mouse_press(300,660,450,730) == 1) 
        {
            *page = 10;  // ����Υ�´������
            break;
        }
        if (mouse_press(580,660,730,730) == 1) 
        {
            *page = 7;  // ���ع���Ա����
            break;
        }
    }
}

void history(int *page) 
{
    char* location[] = 
    {
        "���Ƹ�С", "ͼ���", "��е¥", "����ѧԺ", "������", 
        "�϶���", "�����ѧԺ", "����ѧԺ", "�вٳ�", "����������", 
        "����԰", "ѧ����������"
    };
    //Υͣ��ΪԤ��
    char *locations[20][4] = 
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
    FILE *fp = NULL;
    USERS records[20];
    int total = 0;
    int current_index = 0;
    int need_refresh = 1;
    // ��ȡ���м�¼
    fp = fopen("data.dat", "rb");
    if (fp) {
        while (total < 100 && fread(&records[total], sizeof(USERS), 1, fp) == 1) {
            total++;
        }
        fclose(fp);
    }
    // ��ʼ������
    mouse_off(&mouse);
    bar1(0, 0, 1024, 768, 0xFFFFFF);
    mouse_off(&mouse);
    Readbmp64k(0, 0, "bmp\\user1.bmp");
    rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
    // ���Ʋ�����ť
    puthz(50, 50, "��ʷΥ��ҳ", 48, 50, 0x000000);
    rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
    draw_botton(250,620,350,680,0xFFFFFF,0x000000);
    puthz_coverd(240,635,"��һҳ",4,32,30,0x000000);
    draw_botton(440,620,560,680,0xFFFFFF,0x000000);
    puthz_coverd(440,635,"������ҳ",4,32,30,0x000000);
    draw_botton(660,620,790,680,0xFFFFFF,0x000000);
    puthz_coverd(640,635,"����������",2,32,30,0x000000);

    // ���ҵ�һ�����������ļ�¼
    while (current_index < total && records[current_index].if_fine != 1) {
        current_index++;
    }

    // ��ѭ��
    while (1) {
        mouse_show(&mouse);
        if (need_refresh) {
            mouse_off(&mouse);
                rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
            if (current_index >= total) {
                puthz(330, 300, "�������һ����¼", 32, 40, 0x000000);
                delay(500);
                *page=7;
                break;
            } else
             {
                puthz(150, 180, "���ƺ���", 32, 40, 0x000000);
                prt_hz16_asc16_size(330, 180, 2, 2, records[current_index].carboard, 0x000000,"HZK\\hzk16");
                puthz(150, 230, "Υ�µص�", 32, 40, 0x000000);
                puthz(330, 230, location[records[current_index].location], 32, 40, 0x000000);
                puthz(150, 280, "Υ������", 32, 40, 0x000000);
                puthz(330, 280, locations[records[current_index].location][records[current_index].violation], 32, 40, 0x000000);
                puthz(150, 330, "�����۷�", 32, 40, 0x000000);
                put_asc16_number_size_coverd(330, 330, 2, 2, 1, records[current_index].fine[1], 0x000000);
                puthz(500, 330, "�������", 32, 40, 0x000000);
                put_asc16_number_size_coverd(650, 330, 2, 2, 1, records[current_index].fine[0], 0x000000);
                draw_botton(600, 405, 700, 455, 0xFFFFFF, 0x000000);
                puthz_coverd(590, 415, "���ж�", 2, 32, 30, 0x000000);
                if  ((records[current_index].location == 0 && records[current_index].violation == 0) ||  // ��������ͨ��
				                (records[current_index].location == 2 && records[current_index].violation == 2) ||  // ����˨ǰ
				                (records[current_index].location == 4 && records[current_index].violation == 2) ||  // Ӧ��ͨ��
				                (records[current_index].location == 9 && records[current_index].violation == 0) ||  // ��������ͨ��
				                (records[current_index].location == 11 && records[current_index].violation == 0)){  // ��������ͨ��
				                Readbmp64k(300, 400, "bmp\\3.bmp");
				                }
				                // �ڶ��ࣺ�����Υ��
				                if((records[current_index].location == 0 && records[current_index].violation == 3) ||  // У԰�����
				                (records[current_index].location == 1 && records[current_index].violation == 0) ||  // ͼ������
				                (records[current_index].location == 2 && records[current_index].violation == 0) ||  // ��е¥�����
				                (records[current_index].location == 3 && records[current_index].violation == 0) ||  // ����ѧԺ���
				                (records[current_index].location == 4 && records[current_index].violation == 0) ||  // ���������
				                (records[current_index].location == 5 && records[current_index].violation == 0)) { // �϶��ų����
				            
				                Readbmp64k(300, 400, "bmp\\5.bmp");
				                } 
				                // �����ࣺ���⳵λռ��
				                if ((records[current_index].location == 1 && records[current_index].violation == 2) ||  // �м��˳�λ
				                (records[current_index].location == 3 && records[current_index].violation == 2) ||  // ��ְ����λ
				                (records[current_index].location == 6 && records[current_index].violation == 2) ||  // ����Դ���λ
				                (records[current_index].location == 7 && records[current_index].violation == 2) ||  // �ÿͳ�λ
				                (records[current_index].location == 9 && records[current_index].violation == 1) )  // �������˳�λ
				                {
				                Readbmp64k(300, 400, "bmp\\1.bmp");
				                }
				                // �����ࣺ�̻�/���е�Υ��
				                if ((records[current_index].location == 0 && records[current_index].violation == 1) ||  // ռ�����е�
				                (records[current_index].location == 1 && records[current_index].violation == 3) ||  // �̻�����
				                (records[current_index].location == 3 && records[current_index].violation == 3) ||  // �̻�����
				                (records[current_index].location == 5 && records[current_index].violation == 2) ||  // ���е���
				                (records[current_index].location == 10 && records[current_index].violation == 1)) {  // �����̻���
				                Readbmp64k(300, 400, "bmp\\6.bmp");
				                }
				                // �����ࣺ��������Υ��
				                if((records[current_index].location == 6 && records[current_index].violation == 1) ||  // ѧԺ̨��ǰ
				                (records[current_index].location == 7 && records[current_index].violation == 1) ||  // ����·��
				                (records[current_index].location == 8 && records[current_index].violation == 1) ||  // �ܵ�������
				                (records[current_index].location == 9 && records[current_index].violation == 3) ||  // ҹ��Υͣ
				                (records[current_index].location == 11 && records[current_index].violation == 3)) {  // ҹ��Υͣ
				                Readbmp64k(300, 400, "bmp\\2.bmp");
				                }
				                // �����ࣺ����Υ��
				                else{
				                    Readbmp64k(300, 400, "bmp\\4.bmp");
				                }
				            }
				            
				            mouse_show(&mouse);
				            need_refresh = 0;
				        }
				
				        if (mouse_press(250,620,350,680) == 1) 
                        {
				            current_index++;
				            while (current_index < total && records[current_index].if_fine != 1) 
                            {
				                current_index++;
				            }
				            need_refresh = 1;
				            while(mouse_press(250,620,350,680) == 1);
				        }
				        
				        if (mouse_press(440,620,560,680) == 1) 
                        {
				            *page = 7;
				            break;
				        }
				        
				        if (mouse_press(660,620,790,680) == 1) 
                        {
				            *page = 5;
				            break;
				        }
				        
				        if (mouse_press(830,600,1000,660) == 1) 
                        {
				            *page = 5;
				            break;
				        }
				
				    }
				}
    
void rules1(int *page)
{
     mouse_off(&mouse);
     Readbmp64k(0, 0, "bmp\\user1.bmp");
     puthz(350,50,"���пƼ���ѧ",48,50,0x9932CC);
     puthz(270,120,"������Υͣ��������",48,50,0x000000);
     rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
     bar1(60, 210, 964, 660, 0xFFFFFF);
     puthz(65, 220, "��һ����΢Υ��", 32, 30, 0x000000);
     puthz(110, 270, "�ڷ�ָ����ʱͣ���������ͣ����������ڣ���δӰ�콻ͨ���������ͨ�С�", 24, 25, 0x000000);
     puthz(80, 300, "ͣ��ʱ�����ֳ���ͣ��λ�߽磬��δ����������������������ͨ�У�ÿ�ο۶�", 24, 25, 0x000000);
     puthz(80, 330, "�֣������ʮԪ", 24, 25, 0x000000);
     puthz(65, 370, "������һ��Υ��", 32, 30, 0x000000);
     puthz(110, 420, "�ڽ�ֹͣ����־�����ߴ�ͣ������δ��ɽ�ͨӵ�¡�������ͨ����Ӧ��ͨ��ͣ", 24, 25, 0x000000);
     puthz(80, 450, "������δ�������������ÿ�ο���֣�������ʮԪ", 24, 25, 0x000000);
     puthz(65, 490, "����������Υ��", 32, 30, 0x000000);
     puthz(110, 530, "������ͨ����Ӧ��ͨ����ʱ��ͣ�������½�����Ԯ�����޷�ͨ�С���Υͣ���", 24, 25, 0x000000);
     puthz(80, 570, "У԰�ڽ�ͨ����ӵ�£�Ӱ�췶Χ�ϴ��ҳ���ʱ��ϳ���������ʮ���ӣ���Υ����", 24, 25, 0x000000);
     puthz(80, 600, "ÿ�ο�ʮ�֣�������ʮԪ", 24, 25, 0x000000);
     // ���Ʒ��ذ�ť����ɫ���� + ���еײ���
     draw_botton(300,660,450,730,0xFFFFFF,0x000000);
     puthz_coverd(293,670,"������һҳ",5 ,32,30,0x000000);
     draw_botton(580,660,730,730,0xFFFFFF,0x000000);
     puthz_coverd(593,670,"����������",2 ,32,30,0x000000);
     // ����������¼�
     while (1) {
         mouse_show(&mouse);
         if (mouse_press(300,660,450,730) == 1)
          {
             *page = 7;  // ������һҳ
             break;
         }
         if (mouse_press(580,660,730,730) == 1)
          {
             *page = 7;  // ���ع���Ա����
 
             break;
         }
     }
 }