#include"allfunc.h"
void second_deal_window(int *page)
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
        {"����ͣ�ڹ���ѧԺ���", "δ���涨ͣ��", "ռ��taffͣ��λ", "����ͣ���̻�����"},
        {"����ͣ�����������", "δ���涨ͣ��", "����ͣ��Ӧ��ͨ��", "����ͣ�ڹ���ͨ��"},
        {"����ͣ���϶��ų����", "δ���涨ͣ��", "����ͣ�����е���", "����ͣ�ڽ�ͣ����"},
        {"ռ��ʵ�����豸װж��", "ͣ��ѧԺ����̨��ǰ", "ռ������Դ�����λ", "��ռ����ר��ͣ����"},
        {"ͣ���������ͨ��", "��ѧԺ����·��Υͣ", "ռ�÷ÿͳ�λ", "������˨ǰΥ��ͣ��"},
        {"ͣ�����˶���Ӧ��ͨ��", "ռ���ܵ��ܱ߻�����", "�ڹ���ϯ�����ͣ��", "��ռ�ٳ���Χ�ǻ�������"},
        {"��������¥����ͨ��", "ռ����������ר�ó�λ", "���������г���ǰͣ��", "ҹ��Υͣ����ʱ��ͣ��"},
        {"ʻ��԰���̵�ͣ��", "ռ���ּ䲽�е�", "�ں��߹۾�ƽ̨Υͣ", "ͣ����԰����խ·��"},
        {"�ڻ��鳵����ڴ�ͣ��", "ͣ�������ľ����̻���","����������Ա����ͨ��","δ���涨ͣ��"}
    };
    FILE *fp ;
    int click = -1;
    long current_pos;
    USERS user;
    long file_size;
    char username[10];

    fp = fopen("data.dat", "rb+"); // �Զ�дģʽ���ļ�
    if(fp==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    {
        int j;
        USERS temp;
        int found_count =0;
        int record_count = 0;
        int file_size=0;
        fseek(fp, 0, SEEK_END);
        file_size = ftell(fp);
        record_count = file_size / sizeof(USERS);
        fseek(fp, 0, SEEK_SET);
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
            if (temp.if_fine==2)
             {  // ����if_fine==2�ļ�¼
                
                found_count++;
                break;
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
    }
    srand((unsigned)time(NULL)); 
    memset(&user, 0, sizeof(USERS));
    bar1(300, 400, 800, 600, 0xFFFFFF);
    fseek(fp, current_pos, SEEK_SET);
    fread(&user, sizeof(USERS), 1, fp);
    user.if_fine = 1;
    fseek(fp, current_pos, SEEK_SET);  // ��λ����ǰ��¼����ʼλ��
    fwrite(&user, sizeof(USERS), 1, fp);// д���޸ĺ������
    
    /*sprintf(buffer, "%p", fp);
    put_asc16_size(0, 100, 3, 3, buffer, 0x000000);*/
    // 2. �޸������Ա�ʾ�ڶ���Υ������
    user.location = rand() % 12;  // ��������µ�Υ�µص�
    user.violation = rand() % 4;  // ��������µ�Υ����Ϊ
    user.if_against = 0;          // ���Ϊ�ظ�Υ��
    user.if_fine = 1;             // ���ô���״̬
    // 3. ���޸ĺ������д���ļ�
    // �ر������ʾ
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
        char temp1[10];
        // ��λ���������ݿ�ʼ��������ȡ 80 �ֽڳ������ݣ�8�����ƣ�ÿ��10�ֽڣ�
        fseek(fp,60+current_pos, SEEK_SET);  // ����ǰ60�ֽ�,������ƺ�
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
                    char temp1[3];
                    temp1[0] = plateBuf[offset+col];
                    temp1[1] = plateBuf[offset+col+1];
                    temp1[2] = '\0';
                    puthz(x, y, temp1, 32, 30, 0x000000);
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
  
    // �ر��ļ�
    fclose(fp);
    //puthz(300, 180, v[current_index].carboard, 32, 40, 0x000000);
    puthz(150, 230, "Υͣ�ص�", 32, 40, 0x000000);
    puthz(330, 230, location[user.location], 32, 40, 0x000000);
    puthz(150, 280, "Υͣ��Ϊ", 32, 40, 0x000000);
    puthz(330, 280, locations[user.location][user.violation], 32, 40, 0x000000);
    //��Ϊ��Ӧ��Ƭ��ӡ
    //��һ�ࣺ�������Υ��
    if  ((user.location == 0 && user.violation == 0) ||  // ��������ͨ��
    (user.location == 2 && user.violation == 2) ||  // ����˨ǰ
    (user.location == 4 && user.violation == 2) ||  // Ӧ��ͨ��
    (user.location == 9 && user.violation == 0) ||  // ��������ͨ��
    (user.location == 11 && user.violation == 0)){  // ��������ͨ��
    Readbmp64k(300, 350, "bmp\\3.bmp");
    }
    // �ڶ��ࣺ�����Υ��
    if((user.location == 0 && user.violation == 3) ||  // У԰�����
    (user.location == 1 && user.violation == 0) ||  // ͼ������
    (user.location == 2 && user.violation == 0) ||  // ��е¥�����
    (user.location == 3 && user.violation == 0) ||  // ����ѧԺ���
    (user.location == 4 && user.violation == 0) ||  // ���������
    (user.location == 5 && user.violation == 0)) { // �϶��ų����
    Readbmp64k(300, 350, "bmp\\5.bmp");
    } 
    
    // �����ࣺ���⳵λռ��//(v[current_index].location == 11 && v[current_index]v.violation == 1))
    if ((user.location == 1 && user.violation == 2) ||  // �м��˳�λ
    (user.location == 3 && user.violation == 2) ||  // ��ְ����λ
    (user.location == 6 && user.violation == 2) ||  // ����Դ���λ
    (user.location == 7 && user.violation == 2) ||  // �ÿͳ�λ
    (user.location == 9 && user.violation == 1) )  // �������˳�λ
    {// �������˳�λ
    Readbmp64k(300, 350, "bmp\\1.bmp");
    }
    // �����ࣺ�̻�/���е�Υ�� (click=4)
    if ((user.location == 0 && user.violation == 1) ||  // ռ�����е�
    (user.location == 1 && user.violation == 3) ||  // �̻�����
    (user.location == 3 && user.violation == 3) ||  // �̻�����
    (user.location == 5 && user.violation == 2) ||  // ���е���
    (user.location == 10 && user.violation == 1)) {  // �����̻���
    Readbmp64k(300, 350, "bmp\\6.bmp");
    }
// �����ࣺ��������Υ�� (click=5)
    if((user.location == 6 && user.violation == 1) ||  // ѧԺ̨��ǰ
    (user.location == 7 && user.violation == 1) ||  // ����·��
    (user.location == 8 && user.violation == 1) ||  // �ܵ�������
    (user.location == 9 && user.violation == 3) ||  // ҹ��Υͣ
    (user.location == 11 && user.violation == 3)) {  // ҹ��Υͣ
    Readbmp64k(300, 350, "bmp\\2.bmp");
    }
    
    // �����ࣺ����Υ�� (click=6)
    else{
        Readbmp64k(300, 350, "bmp\\4.bmp");
    }
     // �۷�ѡ�ť
    bar1(220, 520, 350, 560, 0xFFD700);
    puthz(230, 520, "���ķ�", 32, 40, 0x000000);
    bar1(420, 520, 550, 560, 0xFFD700);
    puthz(430, 520, "�۰˷�", 32, 40, 0x000000);
    bar1(620, 520, 750, 560, 0xFFD700);
    puthz(630, 520, "��ʮ����", 32, 40, 0x000000);
    draw_botton(600, 405, 700, 455, 0xFFFFFF, 0x000000);
    puthz_coverd(590, 415, "�����϶�", 2, 32, 30, 0x000000);
    // ������ť
    draw_botton(250, 635, 350, 695, 0xFFFFFF, 0x000000);
    puthz_coverd(230, 652, "������ҳ", 4, 32, 30, 0x000000);
    draw_botton(440, 635, 560, 695, 0xFFFFFF, 0x000000);
    puthz_coverd(430, 652, "�ύ����", 4, 32, 30, 0x000000);
    draw_botton(660, 635, 760, 695, 0xFFFFFF, 0x000000);
    puthz_coverd(650, 652, "����鿴", 2, 32, 30, 0x000000);
    
    // ��ѭ��
    while (1) 
    {
        mouse_show(&mouse);
        
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
            puthz(230, 520, "���ķ�", 32, 40, 0x000000);
            click=4;
        }
        if(mouse_press(420, 520, 550, 560)==1)
        {
            bar1(420, 520, 550, 560, 0x32CD32);
            puthz(430, 520, "�۰˷�", 32, 40, 0x000000);
            click=8;
        }
        if(mouse_press(620, 520, 750, 560)==1)
        {
            bar1(620, 520, 750, 560, 0x32CD32);
            puthz(630, 520, "ʮ����", 32, 40, 0x000000);
            click=12;
        }
         if (mouse_press(440, 635, 560, 695) == 1 && click != -1) 
        {    
            // ���µ�ǰ��¼�Ĵ�����Ϣ
            user.if_fine = 1;
            user.fine[0] = click * 10;  // ������
            user.fine[1] = click;      // �۷�ֵ
            if (click == 0) 
            {
                user.if_fine = 0;  // ���ѡ�������϶���������������
            }

            // �����µĴ�����¼׷�ӵ��ļ�ĩβ
            
            if (fp== NULL) 
            {
                perror("�޷����ļ�����׷��д��");
               
                exit(0);
            }
            fp= fopen("data.dat", "rb+"); // �Զ�дģʽ���ļ�
            fseek(fp, 0, SEEK_END);  // ��λ����ǰ��¼
            if (fwrite(&user, sizeof(USERS), 1, fp) != 1)
             {
                perror("д��ʧ��");
                
                exit(0);
            }
            fflush(fp); // ˢ���ļ�������
            // ��ת����ʷ��¼ҳ��
            showTransferAnimation1();
            fclose(fp);
            *page=7;
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
    }
}
int watch_func1(USERS temp)
{
                char* location_output[12] = {0};
                char* violation_output[12][4] = {0};
                // ��ʾ��ѯ����
                bar1(35, 91, 500, 500, 0xFFFFFF);

                if(temp.if_fine==1||temp.if_fine==2) 
                {
                    prt_hz16_asc16_size(150, 100, 2, 2, temp.carboard, 0x000000, "HZK\\hzk16");
                        if(temp.if_fine==2)
                        {
                            puthz(300,150,"���Ѵ���", 32, 30, 0x000000);
                        }
                        puthz(35, 200, "Υ������", 32, 30, 0x000000);
                        puthz(35, 250, "Υ�µص�", 32, 30, 0x000000);
                        puthz(35, 300, "Υ��ʱ��", 32, 30, 0x000000);
                     
                        // ��ȡ location �� violation
                        // ���Υ��ʱ��
                        puthz(190, 300, temp.fine_time, 32, 30, 0x000000);

                        // ��� location �� violation �ķ�Χ
                        if (temp.location >= 0 && temp.location < 12 && temp.violation >= 0 && temp.violation < 4)
                        {
                            // ���� location �� violation ��ֵ�����Ӧ���ַ���
                            location_input(location_output, temp.location);
                            violation_input(violation_output, temp.location, temp.violation);

                            if (location_output[temp.location] != NULL)
                            {
                                puthz(190, 200, location_output[temp.location], 32, 30, 0x000000);
                                free(location_output[temp.location]);  // �ͷ��ڴ�
                            }

                            if (violation_output[temp.location][temp.violation] != NULL)
                            {
                                puthz(190, 250, violation_output[temp.location][temp.violation], 32, 30, 0x000000);
                                free(violation_output[temp.location][temp.violation]);  // �ͷ��ڴ�
                            }
                        }
                    
                        else
                        {
                            puthz(190, 200, "��Υ�¼�¼", 32, 30, 0x000000);
                            puthz(190, 250, "����Υ���ù������������Ӵ", 24, 25, 0x000000);
                        }
                    
                    return 1; // ���Ϊ��ѯ�����Ѵ�
                }
                
                else if(temp.if_fine==0)
                {
                    puthz(140, 160, "��Υ�¼�¼", 48, 50, 0x000000);
                    puthz(140, 250, "����Υ���ù������������Ӵ", 24, 25, 0x000000);
                    return 1; // ���Ϊ��ѯ�����Ѵ�
                }
                else
                {
                    puthz(190, 200, "��ȡΥ����Ϣʧ��", 32, 30, 0xFF068);
                    puthz(190, 250, "���������ļ�", 24, 25, 0xFF068);
                    return 1; // ���Ϊ��ѯ�����Ѵ�
                }
}
int watch_func2(USERS temp)
{
    
    bar1(35, 91, 500, 500, 0xFFFFFF);
    if(temp.if_fine==1||temp.if_fine==2) 
    {
        int col;
        int x;
        int baseX = 150;
        // ��ʼ�����ֻ꣬��ʼ��һ�Σ���֤���������ͬһ��
        x = baseX;
        for(col = 0; col < 10 && temp.carboard[ col] != '\0'; )
            {
                // ���Ϊ�����ַ���GBK�����£�����Ϊ˫�ֽ��жϣ�
                if((unsigned char)temp.carboard[ col] >= 0xA0)
                {
                    char temp2[3];
                    temp2[0] = temp.carboard[col];
                    temp2[1] = temp.carboard[col+1];
                    temp2[2] = '\0';
                    puthz(x, 100, temp2, 32, 30, 0x000000);
                    col += 2;
                    x += 32;
                }
                else  // Ӣ�Ļ�����Ϊ���ֽ�
                {
                    Put_Asc16_Size(x, 100, 3, 3, temp.carboard[col], 0x000000);
                    col++;
                    x += 30;
                }
            }
            if  ((temp.location == 0 && temp.violation == 0) ||  // ��������ͨ��
				                (temp.location == 2 && temp.violation == 2) ||  // ����˨ǰ
				                (temp.location == 4 &&temp.violation == 2) ||  // Ӧ��ͨ��
				                (temp.location == 9 && temp.violation == 0) ||  // ��������ͨ��
				                (temp.location == 11 && temp.violation == 0))
                                {  // ��������ͨ��
				                Readbmp64k(50, 150, "bmp\\31.bmp");
				                }
            else if((temp.location == 0 && temp.violation == 3) ||  // У԰�����
            (temp.location == 1 &&temp.violation == 0) ||  // ͼ������
            (temp.location == 2 && temp.violation == 0) ||  // ��е¥�����
            (temp.location == 3 && temp.violation == 0) ||  // ����ѧԺ���
            (temp.location == 4 && temp.violation == 0) ||  // ���������
            (temp.location == 5 &&temp.violation == 0)) 
            { // �϶��ų����
        
            Readbmp64k(50, 150,  "bmp\\51.bmp");
            } 
            else if ((temp.location == 1 && temp.violation == 2) ||  // �м��˳�λ
            (temp.location == 3 && temp.violation == 2) ||  // ��ְ����λ
            (temp.location == 6 && temp.violation == 2) ||  // ����Դ���λ
            (temp.location == 7 && temp.violation == 2) ||  // �ÿͳ�λ
            (temp.location == 9 && temp.violation == 1) )  // �������˳�λ
            {
            Readbmp64k(50, 150,  "bmp\\11.bmp");
            }
            else if ((temp.location == 0 && temp.violation == 1) ||  // ռ�����е�
            (temp.location == 1 && temp.violation == 3) ||  // �̻�����
            (temp.location == 3 && temp.violation == 3) ||  // �̻�����
            (temp.location == 5 && temp.violation == 2) ||  // ���е���
            (temp.location == 10 && temp.violation == 1)) 
            {  // �����̻���
            Readbmp64k(50, 150,  "bmp\\61.bmp");
            }
            else // �����ࣺ��������Υ��
            if((temp.location == 6 && temp.violation == 1) ||  // ѧԺ̨��ǰ
            (temp.location == 7 && temp.violation == 1) ||  // ����·��
            (temp.location == 8 && temp.violation == 1) ||  // �ܵ�������
            (temp.location == 9 && temp.violation == 3) ||  // ҹ��Υͣ
            (temp.location == 11 && temp.violation == 3)) 
            {  // ҹ��Υͣ
            Readbmp64k(50, 150,  "bmp\\21.bmp");
            }
            // �����ࣺ����Υ��
            else
            {
                Readbmp64k(50, 150, "bmp\\41.bmp");
            }
            return 1; // ���Ϊ��ѯ�����Ѵ�
        }
        else
        {
        puthz(140, 160, "��Υ�¼�¼", 48, 50, 0x000000);
        puthz(140, 250, "����Υ���ù������������Ӵ", 24, 25, 0x000000);
        return 1; // ���Ϊ��ѯ�����Ѵ�
        }
}
void put_car_picture(USERS temp)
{
    if(strcmp(temp.brand,"1")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "BMW730i(��ɫ)", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\bmw.bmp");
        }
        else if(strcmp(temp.brand,"2")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "Maybach", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\benz.bmp");
        }
        else if(strcmp(temp.brand,"3")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "Audi A8", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\audi.bmp");
        }
        else if(strcmp(temp.brand,"4")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "TOYOTA", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\toyota.bmp");
        }
        else if(strcmp(temp.brand,"5")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "MAGOTAN", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\vw.bmp");
        }
        else if(strcmp(temp.brand,"6")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "Ford-Focus", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\focus.bmp");
        }
        else if(strcmp(temp.brand,"7")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "����MINI", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\mini.bmp");
        }
        else if(strcmp(temp.brand,"8")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "ID.6(eletric)", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\ID.bmp");
        }
        else if(strcmp(temp.brand,"9")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "Tesla-Model3", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\tesla.bmp");
        }
        else if(strcmp(temp.brand,"b")==0)
        {
            prt_hz16_asc16_size(110, 380, 3, 3, "Dodge-Challenger", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\police.bmp");
        }
        else if(strcmp(temp.brand,"c")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "Scania", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\scania.bmp");
        }
        else if(strcmp(temp.brand,"0")==0)
        {
            prt_hz16_asc16_size(150, 380, 3, 3, "Audi-Q5L", 0x000000, "HZK\\hzk16");
            Readbmp64k(35, 450, "bmp\\audiQ5.bmp");
        }
}
 int deal_func1()
{
    int current_rating = 0; // ��ǰ����
    int i;
    int new_rating = 0;
    int update_needed = 0; // ����Ƿ���Ҫ���½���

    while (1)
    {
        mouse_show(&mouse);

        // ���������Ƶ��
        new_rating = 0;
        for(i = 0; i < 10; i++)
        {
            int boxX1 = 350 + i * (40 + 5);
            int boxY1 = 520;
            int boxX2 = boxX1 + 40;
            int boxY2 = boxY1 + 40;
            if(mouse_press(boxX1, boxY1, boxX2, boxY2) == 1)
            {
                new_rating = i + 1;
                // �����ӳ�ʱ��
                delay(100); 
                update_needed = 1;
                break;
            }
        }

        if(update_needed)
        {
            // ÿ������ʱ����������������������ֿ򹹳ɵ����򣩣�ȷ��֮ǰ��Ц��������
            int totalWidth = 10 * (45) - 5;
            bar1(350, 520, 350 + totalWidth, 520 + 40, 0xFFFFFF);
            for(i = 0; i < 10; i++)
            {
                int boxX1 = 350 + i * (45);
                int boxY1 = 520;
                int boxX2 = boxX1 + 40;
                int boxY2 = boxY1 + 40;
                // ���Ʋ���ɫ�ľ��α߿�
                bar2(boxX1, boxY1, boxX2, boxY2, 0x000000);
            }
            // ���µ�ǰ����Ϊ������
            current_rating = new_rating;
            mouse_off(&mouse);
            // �ػ�ӵ�һ�����ֿ򵽵�ǰ���ֿ��Ц��
            for(i = 0; i < current_rating; i++)
            {
                int boxX1 = 350 + i * (45);
                int centerX = boxX1 + 20;
                // ��������ֵ�жϲ������ֱ���
                if(current_rating < 4)
                {
                    bar1(230, 600, 920, 650, 0xFFFFFF);
                    draw_cry32(centerX - 16, 525);
                    puthz(240, 610, "��Ǹ�˴η���ʹ���е������⣬����������", 24,25,  0xFF068);
                    puthz(715, 610, "ǰ����������ҳ��", 24,25,  0xCD5C5C);
                    Line3(715,640,910,640,1,0xCD5C5C);
                }
                else if(current_rating >= 4 && current_rating <= 7)
                {
                    bar1(230, 600, 920, 650, 0xFFFFFF);
                    mouse_off(&mouse);
                    draw_neutral32(centerX - 16, 525);
                    // �����У����Ա��飬��Ӧ��л����
                    puthz(350, 610,  "��л���������ǵķ��񽫼�������", 24,25,  0xFF068);
                }
                else  // current_rating >= 8
                {
                    bar1(230, 600, 920, 650, 0xFFFFFF);
                    mouse_off(&mouse);
                    draw_smiley32(centerX - 16, 525);
                    // ���ָߣ�Ц������Ӧ��лȫ��֧��
                    puthz(350, 610, "��л����ȫ��֧�֣����ǽ��߳�Ϊ������", 24,25, 0xFF068);
                }
            }
            update_needed = 0;
        }

        if(mouse_press(715,610,910, 650)==1) 
        {
            mouse_off(&mouse);
            delay(100);
            // �������
            return 27;    // ��ת����������ҳ��
        }
        else if(mouse_press(420, 680, 540, 740)==1)
        {
            // ͬʱ�������ֱ���
            current_rating = 0;
            delay(100);
            break;
        }
        else if(mouse_press(70,525,190,658)==1||mouse_press(70, 210, 190, 340)==1||mouse_press(70, 360, 190, 515)==1)
        {
            mouse_off(&mouse);
            delay(100);
            break;
        }
    }
}
            