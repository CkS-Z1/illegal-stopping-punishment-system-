#include <allfunc.h>


// ����ƽ�������ԣ����飬32x32��С������Ϊ�Ȼ�ɫ
void draw_neutral32(int x, int y)
{
    // ��������
    Circlefill(x+16, y+16, 16, 0xFD00);
    // �����۾�
    Circlefill(x+11, y+12, 3, 0x000000);
    Circlefill(x+21, y+12, 3, 0x000000);
    // ��������ֱ�����
    Line_Thick(x+10, y+24, x+22, y+24, 1, 0x000000);
}

// ���ƿ������飬32x32��С������Ϊ�Ȼ�ɫ
void draw_cry32(int x, int y)
{
    int j;
    // ��������
    Circlefill(x+16, y+16, 16, 0xFD00);
    // �����۾�
    Circlefill(x+11, y+12, 3, 0x000000);
    Circlefill(x+21, y+12, 3, 0x000000);
    // �����´�����ͣ��Գʰ�����
    Line_Thick(x+10, y+26, x+22, y+26, 1, 0x000000);
    // �������᣺�����ۺ������·ֱ���ƶ��СԲ
    for(j = 0; j < 4; j++)  // �ɸ�����Ҫ����ѭ������
    {
        Circlefill(x+11, y+16 + j*2, 2, 0xCD5C5C);  // �����µ��ӳ�����
        Circlefill(x+21, y+16 + j*2, 2, 0xCD5C5C);  // �����µ��ӳ�����
    }
}

void draw_smiley32(int x, int y)
{
    // ���������������� (x+16, y+16)���뾶Ϊ16���Ȼ�ɫ������ 0xFD00 Ϊ�Ȼ�ɫ��
    Circlefill(x + 16, y + 16, 16, 0xFD00);
    
    // ����ߴ������ԭ 24��24 ʱ���۾����������ƫ�� (-4, -3) �� (4, -3)���뾶 2��
    // 32��32 ʱ����������Լ 1.33�������۾�ƫ��ԼΪ (-5, -4) �� (5, -4)���۾��뾶��Ϊ 3
    Circlefill(x + 16 - 5, y + 16 - 4, 3, 0x0000);  // ���ۣ����� (11,12)
    Circlefill(x + 16 + 5, y + 16 - 4, 3, 0x0000);  // ���ۣ����� (21,12)
    
    // ����Ц��
    // ԭ 24��24 ʱ��Ц��������������� (12,12) Ϊ��(-5,3) -> (-2,6) -> (2,6) -> (5,3)��
    // ���Ա������� 1.33 �õ�������������꣺(-7,4) -> (-3,8) -> (3,8) -> (7,4)
    // ������������ (16,16) �õ��������꣺
    // P1: (16-7, 16+4) = (9,20)
    // P2: (16-3, 16+8) = (13,24)
    // P3: (16+3, 16+8) = (19,24)
    // P4: (16+7, 16+4) = (23,20)
    Line_Thick(x + 9,  y + 20, x + 13, y + 24, 1, 0x0000);
    Line_Thick(x + 13, y + 24, x + 19, y + 24, 1, 0x0000);
    Line_Thick(x + 19, y + 24, x + 23, y + 20, 1, 0x0000);
}

// ���������� 24x24 Ц������������Ȼ�ɫ������ɫ�ۺ�Ц��
void draw_smiley24(int x, int y)
{
    // �����沿�����Բ���뾶Ϊ12��ֱ��24��
    // ��ɫѡ�óȻ�ɫ���� 0xFD00 ��ʾ��5:6:5 ģʽ�� R=31, G��40, B=0��
    Circlefill(x + 12, y + 12, 12, 0xFD00);
    
    // �������ۣ�СԲ���뾶Ϊ2��λ���沿��������
    Circlefill(x + 8, y + 9, 2, 0x0000);
    
    // ��������
    Circlefill(x + 16, y + 9, 2, 0x0000);
    
    // ����Ц����΢Ц��
    // ����3���߶����ӽ��ƻ��Σ��� (x+7, y+15) -> (x+10, y+18) -> (x+14, y+18) -> (x+17, y+15)
    Line_Thick(x + 7,  y + 15, x + 10, y + 18, 1, 0x0000);
    Line_Thick(x + 10, y + 18, x + 14, y + 18, 1, 0x0000);
    Line_Thick(x + 14, y + 18, x + 17, y + 15, 1, 0x0000);
}



/* BC31�����Ը���˵����
   1. ���б�������ǰ��
   2. ʹ�ô�ͳforѭ���﷨
   3. ��ɫ��������unsigned short */
void DrawRMB32(int x0, int y0, int color)
{
    int y, i, d, x;        /* ѭ������ǰ������ */
    int ypos;              /* ��������м��� */
    unsigned page_offset;  /* �Դ��ҳƫ���� */

    

    /* ���ƴ�ֱ���ɣ����У� */
    for (y = 0; y < 32; y++) {
        /* �Դ��ҳ���㣨BC31ר���ڴ�ģ�ͣ� */
        page_offset = ((unsigned)(y0 + y) << 10) + x0 + 16;
        _AX = FP_SEG((void far*)page_offset);
        _DX = FP_OFF((void far*)page_offset);
        asm mov dx,ax  /* �Դ��ҳ���� */
        asm mov ax,0x4F05
        asm xor bx,bx
        asm int 0x10

        Putpixel64k(x0 + 16, y0 + y, color);
    }

    /* ��������ˮƽ��� */
    for (i = 0; i < 3; i++) {
        ypos = 8 + i*8;

        /* ����˻��� */
        for (x = 8; x < 25; x++) {
            Putpixel64k(x0 + x, y0 + ypos, color);
        }

        /* ����װ��б�� */
        if (i == 0) {
            for (d = 0; d < 5; d++) {
                Putpixel64k(x0 + 16-d, y0 + ypos-d, color);
                Putpixel64k(x0 + 16+d, y0 + ypos-d, color);
            }
        }

        /* �ײ�װ��б�� */
        if (i == 2) {
            for (d = 0; d < 5; d++) {
                Putpixel64k(x0 + 16-d, y0 + ypos+d, color);
                Putpixel64k(x0 + 16+d, y0 + ypos+d, color);
            }
        }
    }

    /* ǿ���м佻������ */
    for (y = 14; y < 19; y++) {
        for (x = 14; x < 19; x++) {
            Putpixel64k(x0 + x, y0 + y, color);
        }
    }
}//�����Թ�
/* �����Ĺ�ѡ��ǻ��ƺ��� */
void DrawCheckmark(int x, int y, int size, int color)
{
    /* ����˵����
       x,y    - ���ĵ�����
       size   - ��ǳߴ磨�����α߳���
       color  - ������ɫ */

    /* Ĭ�ϳߴ紦�� */
    /* �������ƫ���� */
    int offset = size/2;            // �뾶
    int line_width = size/15 + 1;    // ��̬�߿���С1���أ�
    /* ����·��������� */
    // ��ʼ�㣺���Ϸ�1/4��
    int start_x = x - offset*3/4;
    int start_y = y - offset/4;
    // �м�ת�۵㣺����ƫ���·�
    int mid_x = x - offset/5;
    int mid_y = y + offset/6;  
    // �����㣺���·�1/4��
    int end_x = x + offset*3/4;
    int end_y = y - offset*3/4;
	/* Ĭ�ϳߴ紦�� */
	if(size <= 0) size = 30;  
	/* ��������ʽ���� */
    Line_Thick(start_x, start_y, mid_x, mid_y, line_width, color);  // ���ϵ��м�
    Line_Thick(mid_x, mid_y, end_x, end_y, line_width, color);      // �м䵽����
    
}

//������Ż�
void DrawCheckmarkAA(int x, int y, int size, int color)
{
    // ʹ�����β�ͬ͸���ȵĻ�����ǿ�Ӿ�Ч��
    DrawCheckmark(x, y, size, color & 0xFFE0); // ���ͺ�ɫ����
    DrawCheckmark(x+1, y+1, size-2, color);    // ƫ�ƻ���
}
//��ֱ�������
void AutoScaleCheckmark(int x, int y, int color)
{
    // ���ݵ�ǰ�ֱ����Զ�����
    int cur_mode = GetSVGA();
    int scale_factor = (cur_mode == 0x117) ? 2 : 1;
    DrawCheckmark(x, y, 30*scale_factor, color);
}


/*//��ɨ����(���Ͻ����꣬�߳����ߺ���ɫ)
void draw_scanline(int x,int y,int l,int n,int color)
{
    register int i; // ʹ�üĴ�����������ѭ��
    for(i=0;i<n;i++)
    {
        Line1(x,y+i,x+l,y+i,color);
        color=color-10; // ������ɫ����Ч��
    }
}*/

//ɨ�����(���꣬�ߺ���ɫ���ٶ��ӳ�)
/*void start_scan(int x1,int y1,int x2,int y2,int n,int color,int speeddelay)
{
    register int i; // ʹ�üĴ�����������ѭ��
    int temp=color;
    void *buffer=NULL;
    
    /* ��ȷ���㻺������С */
    /*int width = x2 - x1 + 1;
    int height = n + 3;  // ������ȫ����
    size_t buffer_size = width * height * sizeof(unsigned int);
    
    /* Ԥ����̶�ֵ */
    /*int scan_length = x2 - x1;
    int total_lines = y2 - y1 - n - 1;
    
    buffer=(unsigned int*)malloc(buffer_size);
    if(!buffer) return; // ����ڴ������
    
    /* ɾ����Ч��ɫ�ж� */
    /*Get_image(x1,y1-1,x2,y1+n+1,buffer);
    draw_scanline(x1,y1,scan_length,n,color);
    
    for(i=1;i<total_lines;i++)
    {
        Put_image(x1,y1+i-2,x2+2,y1+i+n,buffer);       // �Ż�ͼ��ָ���Χ
        Get_image(x1,y1+i-1,x2+2,y1+i+n+1,buffer);     // �Ż�ͼ�񱣴淶Χ
        draw_scanline(x1,y1+i,scan_length,n,color--);// �����߳��������
        
        /* �ӳ�����ѭ��ĩβ������� */
       /* delay(speeddelay);
    }
    
    /* �Ż�����ͼ��ָ� */
    /*Put_image(x1,y1+total_lines-1,x2+2,y1+total_lines+n,buffer);
    free(buffer);
}
*/

//��ɨ����(���Ͻ����꣬�߳����ߺ���ɫ)
void draw_scanline(int x,int y,int l,int n,int color)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        Line1(x,y+i,x+l,y+i,color);
        color=color-3;
    }
}

//ɨ�����(���꣬�ߺ���ɫ���ٶ��ӳ�)
void start_scan(int x1,int y1,int x2,int y2,int n,int color,int speeddelay)
{
    int i=0;
    int temp=color;
    void *buffer=NULL;
    buffer=(unsigned int*)malloc(29000);
    if(temp-20==color)
    {
        color=temp;
    }
    Get_image(x1,y1-1,x2,y1+n+1,buffer);
    draw_scanline(x1,y1,x2-x1,n,color);
    for(i=1;i<y2-y1-n-1;i++)
    {
        Put_image(x1,y1+(i-1)-1,x2,y1+(i-1)+n+1,buffer);
        Get_image(x1,y1+i-1,x2,y1+i+n+1,buffer);
        draw_scanline(x1,y1+i,x2-x1-1,n,color--);
        delay(speeddelay);
    }
    Put_image(x1,y1+y2-y1-n-3,x2,y1+y2-y1-n-1+n,buffer);
    free(buffer);
    buffer=NULL;
}

//����Բ�Ǿ��ΰ�ť(color1����ɫ��color2�߿�ɫ,state��1Ϊ���0Ϊ��ͨ)
void rounded_bar(int x1, int y1, int x2, int y2, int r ,int color1, int color2,int state)
{
	if(state==1)
	{
		color1=0xFFAAAA;
		color2=0x00FF00;
	}

	Circlefill(x1+r,y1+r,r+1,color2);
	Circlefill(x2-r,y1+r,r+1,color2);
	Circlefill(x1+r,y2-r,r+1,color2);
	Circlefill(x2-r,y2-r,r+1,color2);
	Line_Thick(x1,y1+r+1,x1,y2-r-1,1,color2 );
	Line_Thick(x2,y1+r+1,x2,y2-r-1,1,color2 );
	Line_Thick(x1+r+1,y1,x2-r-1,y1,1,color2 );
	Line_Thick(x1+r+1,y2,x2-r-1,y2,1,color2 );

	Circlefill(x1+r,y1+r,r,color1);
	Circlefill(x2-r,y1+r,r,color1);
	Circlefill(x1+r,y2-r,r,color1);
	Circlefill(x2-r,y2-r,r,color1);
	bar1(x1+r,y1,x2-r,y2,color1);
	bar1(x1,y1+r,x2,y2-r,color1);
}


//��������
void draw_botton(int x1 ,int y1,int x2,int y2,int Cowercolor,int Bordercolor)
{
	Cirbar(x1,y1,x2,y2, Bordercolor);
	Cirbar(x1,y1+2,x2,y2-2, Cowercolor);
}


//������ͨ������
void draw_commoninput(int x1,int y1,char *s)
{
	Line_Thick(x1, y1, x1 + 380, y1, 1, 0xBD32 );
	prt_hz16_size(x1 + 16, y1 - 46, 2, 2, s, 0xBD32, "HZK\\HZK16s");
}

//����ȷ�ϰ�ť
void draw_confirmbotton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+150, y1+55, 0xFFFFFF, 0x00FF);
	puthz(x1+12,y1+15,s, 24,25, 0x000000);
}


//������ѡ��ť(x,yΪ�������꣬state��1Ϊ���0Ϊ��ͨ,2Ϊ����,-1Ϊ����,3Ϊ���,4Ϊ�յ�)
void draw_checkbutton(int x,int y,int state)
{
	bar1(x-16,y-16,x+16,y+16,0x000000);
	if(state==0)
	{
		bar1(x-15,y-15,x+15,y+15,0xFFFFFF);	
	}
	if(state==2)
	{
		bar1(x-15,y-15,x+15,y+15,0xFFAA);
	}
	if(state==1)
	{
		bar1(x-15,y-15,x+15,y+15,0xBBBB);
    	Line_Thick(x - 14, y - 2, x - 9, y - 2, 2, 0xFF0000);
		Line_Thick(x - 9, y - 2, x, y + 8, 2, 0xFF0000);
		Line_Thick(x + 12, y - 12, x, y + 8, 2, 0xFF0000);
	}
	if(state==-1)
	{
		bar1(x-15,y-15,x+15,y+15,0xFF19);
		Circlefill(x,y,13,0xFFAAAA);
		Circlefill(x,y,11,0xFF19);
		Line_Thick(x-14,y+11,x+11,y-14,1,0xFFFFFF);
		Line_Thick(x-11,y+14,x+14,y-11,1,0xFFFFFF);
		Line_Thick(x-14,y+14,x+14,y-14,2,0x000000);
	}
	if(state==3)
	{
		bar1(x-15,y-15,x+15,y+15,0xBDBD);
		puthz(x-1,y-1,"��",16,16,0xBB23);
		bar1(x-12,y+13,x-1,y+14,0x000000);
		bar1(x-7,y-12,x-6,y+13,0x000000);
		bar1(x-6,y-11,x+9,y-1,0xBBBF);
	}
	if(state==4)
	{
		bar1(x-15,y-15,x+15,y+15,0x7397F0);
		puthz(x-1,y-1,"��",16,16,0xBB23);
		bar1(x-12,y+13,x-1,y+14,0x000000);
		bar1(x-7,y-12,x-6,y+13,0x000000);
		bar1(x-6,y-11,x+9,y-1,0xFFAAAA);
	}
}


//��������
void Line_Thick_color(int x1, int y1, int x2, int y2, int radius,unsigned int color)
{
	int	dx, dy;			/*ֱ��x��y�����ֵ*/
	int dx2, dy2;		/*�ӿ������ٶȵ��м�ֵ*/
	int xinc, yinc;		/*�ж�x��y���ӷ���ķ���ֵ*/
	int d, dxy;			/*���߱���*/
	
	/*���������ֵ���м����*/
	dx = abs(x2 - x1);
	dx2 = dx << 1;
	dy = abs(y2 - y1);
	dy2 = dy << 1;
	
	/*�ж�ֱ��x�������ӷ���*/
	if (x2 > x1)
	{
		xinc = 1;
	}
	
	/*�������ֱ��*/
	else if (x2 == x1)
	{
		/*y��������*/
		if (y1 > y2)
		{
			dx = y1;
			y1 = y2;
			y2 = dx;
		}
		
		/*����ֱ��*/
		for (dx = y1; dx <= y2; dx++)
		{
			Circlefill(x1, dx, radius, color);
			color+=1;
		}
		
		return;
	}
	
	else
	{
		xinc = -1;
	}
	
	/*�ж�ֱ��y�������ӷ���*/
	if (y2 > y1)
	{
		yinc = 1;
	}
	
	/*�����ˮƽ��*/
	else if (y2 == y1)
	{
		Line3(x1, y1, x2, y1,radius, color);	
		color+=1;
		return;
	}
	
	else
	{
		yinc = -1;
	}
	
	/*******************************
	��������Bresenham�㷨����ֱ�ߡ�
	���㷨�ǵõ����ϵĳ���Ŀ����㷨��
	����ϸ����ȥ��
	*******************************/
	Circlefill(x1, y1, radius, color);
	color+=1;
	if (dx >= dy)
	{
		d = dy2 - dx;
		dxy = dy2 - dx2;
		
		while (dx--)
		{
			if (d <= 0)
			{
				d += dy2;
			}
			
			else
			{
				d += dxy;
				y1 += yinc;
			}
			
			x1 += xinc;
			Circlefill(x1, y1, radius, color);
			color+=1;
		}
	}
	
	else
	{
		d = dx2 - dy;
		dxy = dx2 - dy2;
		
		while (dy--)
		{
			if (d <= 0)
			{
				d += dx2;
			}
			
			else
			{
				d += dxy;
				x1 += xinc;
			}
			
			y1 += yinc;
			Circlefill(x1, y1, radius, color);
			color+=1;
		}
	}
}


