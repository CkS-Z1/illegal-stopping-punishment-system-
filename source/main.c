#include <allfunc.h>
void clear_all_data() 
    {
    // ��� userinfo.dat �ļ�
    FILE *fp = fopen("userinfo.dat", "wb");
    if (fp == NULL) {
        perror("�޷��� userinfo.dat �ļ�");
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    // ��� data.dat �ļ�
    fp = fopen("data.dat", "wb");
    if (fp == NULL) {
        perror("�޷��� data.dat �ļ�");
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    printf("������������ա�\n");
}

void main()
{      
    int page=0;
    int num=0;
    
    FILE *fp=NULL;   
    if((fp=fopen("data.dat","wb"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
      //һ����д�������ṹ�����飨д���¼��������д��2�����ɸ���ʵ�ʼ�¼���޸ģ�
   
    fclose(fp);

    SetSVGA64k();//����SVGA��ͼ����
    bar1(0,0,1400,1400,0xffffff);
    mouse_init();
    //��ʼ����� 
	while(1)   
	{
	        mouse_show(&mouse);
            switch (page)
            {
                case 0:
                welcome(&page);
                break;
                case 1:
                staff_login(&page);//draw_login_visiter_rigister(&page);
                break;
                case 2:
                user_login(&page,&num);
                break;
                case 3:
                draw_login_visiter_chepai(&page);
                break;
                case 4:
                rigister_login(&page);//draw_login_admin(&page);
                break;
                case 5:
                draw_map(&page);
                break;
                case 6:
                watcher(&page);
                break;

                case 7:
                handle(&page);
                break;

                case 8:
                charge_deal(&page);
                break;

                case 10:
                deal_window(&page);
                break;

                case 11:
                rules(&page);
                break;

                case 12:
                history(&page);
                break;

                case 13:
                rules1(&page);
                break;
                
                case 14:
                second_deal_window(&page);
                break;
                
                case 15:
                search_history(&page);
                break;

                case 26:
                user_function(&page);
                break;

                case 27:
                fun_against(&page);
                break;

                case 28:
                safe_learning(&page);
                break;

                case 29:
                deal_warning(&page);
                break;

                case 30:
                punish(&page);
                break;

                case 31:    
                safe_learning_deal(&page);
                break;

                
            }
	}
	CloseSVGA();//�ر�ͼ�ν��� 
}

    