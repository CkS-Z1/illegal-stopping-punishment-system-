#include"allfunc.h"

// 定义界面状态枚举
typedef enum 
{
    STATE_INIT,
    STATE_UNPROCESSED_QUERY,
    STATE_PROCESSED_PAYMENT,
    STATE_PAID_FEEDBACK
} AppState;

// 封装界面恢复函数
void restoreMainUI(int savepicture1, int savepicyure2, int savepicture3) 
{
    LoadBMP(70, 210, 190, 340, savepicture1);
    LoadBMP(70, 360, 190, 515, savepicyure2);
    LoadBMP(70, 525, 190, 658, savepicture3);
    puthz(72, 280, "未处理", 32, 30, 0x000000);
    puthz(72, 400, "已处理", 32, 30, 0x000000);
    puthz(72, 440, "未缴款", 32, 30, 0x000000);
    puthz(72, 560, "已缴款", 32, 30, 0x000000);
}

// 封装违章信息显示函数
void showViolationInfo(USERS temp) 
{
    char* location_output[12] = {0};
    char* violation_output[12][4] = {0};
    char fine_str[10];
    char fine_str1[10];
    int i;

    sprintf(fine_str, "%d", temp.fine[0]);
    sprintf(fine_str1, "%d", temp.fine[1]);

    puthz(350, 250, temp.fine_time, 32, 30, 0x0010DD);
    prt_hz16_asc16_size(290, 450, 2, 2, fine_str1, 0x0010DD, "HZK\\hzk16");

    for (i = 0; fine_str[i] != '\0'; i++) 
    {
        char digit[2];
        digit[0] = fine_str[i];
        digit[1] = '\0';
        prt_hz16_asc16_size(700 + i * 20, 450, 2, 2, digit, 0x0010DD, "HZK\\hzk16");
    }

    if (temp.location >= 0 && temp.location < 12 && temp.violation >= 0 && temp.violation < 4) 
    {
        location_input(location_output, temp.location);
        violation_input(violation_output, temp.location, temp.violation);

        if (location_output[temp.location] != NULL) 
        {
            puthz(700, 250, location_output[temp.location], 32, 30, 0x0010DD);
            free(location_output[temp.location]);
        }

        if (violation_output[temp.location][temp.violation] != NULL) 
        {
            puthz(350, 350, violation_output[temp.location][temp.violation], 32, 30, 0x0010DD);
            free(violation_output[temp.location][temp.violation]);
        }
    } 
    else 
    {
        puthz(190, 200, "无违章记录", 32, 30, 0x000000);
        puthz(190, 250, "您是守法好公民，请继续加油哟", 24, 25, 0x000000);
    }
}
void showViolationInfo1(USERS temp) 
{
    char* location_output[12] = {0};
    

    puthz(350, 350, temp.fine_time, 32, 30, 0x0010DD);

    if (temp.location >= 0 && temp.location < 12 && temp.violation >= 0 && temp.violation < 4) 
    {
        location_input(location_output, temp.location);
        

        if (location_output[temp.location]!= NULL) 
        {
            puthz(700, 350, location_output[temp.location], 32, 30, 0x0010DD);
            free(location_output[temp.location]);
        }
    }
}

// 封装支付二维码处理函数
void handlePaymentQRCode(int *is_show, int savepicture2_1, const char *bmp_path) 
{
    mouse_off(&mouse);
    delay(200);
    LoadBMP(560, 270, 940, 650, savepicture2_1);
    Readbmp64k(560, 270, bmp_path);
    draw_botton(400, 560, 535, 610, 0xFFFFFF, 0x00FF);
    puthz(400, 570, "我已付款", 32, 35, 0x000000);
    *is_show = 1;
}

void deal_warning(int *page) 
{
    int savepicture1, savepicyure2, savepicture2_1, savepicture3 ;
    FILE *fp;
    USERS temp;
    int if_fine = -1;
    static int current_rating = 0;
    int if_deal = 0, text2 = 0, if_pay = 0;
    long current_pos = 0;
    AppState state = STATE_INIT;
    int is_query_show1_1 = 0;
    int is_query_show1_2 = 0;
    int i;
    char fine_str[10];

    if ((fp = fopen("data1.dat", "rb+")) == NULL) 
    {
        printf("error!\n");
        exit(0);
    }
    fseek(fp, 0, SEEK_END);
    current_pos = ftell(fp) - (long)sizeof(USERS);
    fseek(fp, current_pos, SEEK_SET);
    fread(&temp, sizeof(USERS), 1, fp);
    fclose(fp);

    mouse_off(&mouse);
    Readbmp64k(0, 0, "bmp\\user1.bmp");
    rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
    bar1(60, 210, 964, 660, 0xFFFFFF);
    puthz(400, 50, "违章处理", 48, 50, 0x000000);
    draw_confirmbotton(420, 680, "提交处理");

    savepicture1 = SaveBMP(70, 210, 190, 340);
    savepicyure2 = SaveBMP(70, 360, 190, 515);
    savepicture3 = SaveBMP(70, 525, 190, 658);
    
    savepicture2_1 = SaveBMP(560, 270, 700, 550);

    Line3(200, 210, 200, 660, 3, 0x000000);
    puthz(72, 280, "未处理", 32, 30, 0x000000);
    puthz(72, 400, "已处理", 32, 30, 0x000000);
    puthz(72, 440, "未缴款", 32, 30, 0x000000);
    puthz(72, 560, "已缴款", 32, 30, 0x000000);
    Line3(60, 350, 190, 350, 5, 0xBD32);
    Line3(60, 520, 190, 520, 5, 0xBD32);
    Circlefill(165, 265, 10, 0xFF000);

    while (1) 
    {
        mouse_show(&mouse);

        switch (state) 
        {
            case STATE_INIT:
                if (mouse_press(70, 210, 190, 350) == 1) 
                {
                    mouse_off(&mouse);
                    delay(200);
                    restoreMainUI(savepicture1, savepicyure2, savepicture3);
                    puthz(72, 280, "未处理", 32, 30, 0x0010DD);
                    Line3(75, 320, 170, 320, 1, 0x0010DD);
                    // 显示违章信息
                    puthz(220, 250, "违章时间", 32, 30, 0x000000);
                    puthz(570, 250, "违章地点", 32, 30, 0x000000);
                    puthz(220, 350, "违章行为", 32, 30, 0x000000);
                    puthz(570, 450, "罚款金额", 32, 30, 0x000000);
                    puthz(220, 450, "扣分", 32, 30, 0x000000);
                    puthz(215, 550, "如果对扣分处罚有疑问，请点击下方查看处罚细则按钮查看具体细则", 24, 25, 0xFF068);
                    draw_confirmbotton(280, 590, "提交处理");
                    draw_confirmbotton(650, 590, "查看处罚细则");
                    showViolationInfo(temp);
                    state = STATE_UNPROCESSED_QUERY;
                }
                break;
            case STATE_UNPROCESSED_QUERY:
                if (mouse_press(70, 210, 190, 350) == 1) 
                {
                    mouse_off(&mouse);
                    delay(200);
                    restoreMainUI(savepicture1,  savepicyure2, savepicture3);
                    bar1(205, 212, 960, 658, 0xFFFFFF);
                    state = STATE_INIT;
                } else if (mouse_press(280, 590, 400, 650) == 1) 
                {
                    puthz(350, 500, "处理成功，请前往缴款页面", 32, 30, 0xFF068);
                    if_deal = 1;
                    delay(2000);
                    Circlefill(165, 385, 10, 0xFF000);
                } else if (mouse_press(650, 590, 800, 650) == 1) 
                {
                    *page = 30;
                    bar1(345, 545, 750, 585, 0xFFFFFF);
                    puthz(380, 500, "正在前往处罚细则页面", 32, 30, 0xFF068);
                    delay(2000);
                    return;
                }
                break;
            case STATE_PROCESSED_PAYMENT:
                if (mouse_press(70, 360, 190, 515) == 1) 
                {
                    mouse_off(&mouse);
                    delay(200);
                    restoreMainUI(savepicture1,savepicyure2, savepicture3);
                    bar1(205, 212, 960, 658, 0xFFFFFF);
                    state = STATE_INIT;
                } else if (mouse_press(250, 520, 345, 570) == 1) 
                {
                    if (!is_query_show1_1) 
                    {
                        handlePaymentQRCode(&is_query_show1_1, savepicture2_1, "bmp\\zfb.bmp");
                    } 
                    else 
                    {
                        mouse_off(&mouse);
                        delay(200);
                        LoadBMP(560, 270, 940, 650, savepicture2_1);
                        is_query_show1_1 = 0;
                    }
                } else if (mouse_press(400, 560, 535, 610) == 1 && is_query_show1_1) 
                {
                    delay(200);
                    mouse_off(&mouse);
                    start_scan(670, 380, 830, 545, 15, 0xFFE4E1, 5);
                    puthz(400, 610, "付款成功", 32, 35, 0xFF068);
                    Circlefill(165, 545, 10, 0xFF000);
                    if_pay = 1;
                    state = STATE_PAID_FEEDBACK;
                } else if (mouse_press(250, 600, 345, 650) == 1) 
                {
                    if (!is_query_show1_2) 
                    {
                        handlePaymentQRCode(&is_query_show1_2, savepicture2_1, "bmp\\wx.bmp");
                        is_query_show1_1 = 0;
                    } else 
                    {
                        mouse_off(&mouse);
                        delay(200);
                        LoadBMP(560, 270, 940, 650, savepicture2_1);
                        is_query_show1_2 = 0;
                    }
                } 
                // 新增微信支付 “我已付款” 按钮处理逻辑
                else if (mouse_press(400, 560, 535, 610) == 1 && is_query_show1_2) 
                {
                    delay(200);
                    mouse_off(&mouse);
                    start_scan(670, 380, 830, 545, 15, 0xFFE4E1, 5);
                    puthz(400, 610, "付款成功", 32, 35, 0xFF068);
                    Circlefill(165, 545, 10, 0xFF000);
                    if_pay = 1;
                    state = STATE_PAID_FEEDBACK;
                }
                break;
            case STATE_PAID_FEEDBACK:
                if (mouse_press(70, 525, 190, 658) == 1) 
                {
                    if (if_pay != 1) 
                    {
                        int save_picture20 = SaveBMP(70, 675, 300, 768);
                        puthz(73, 680, "请先完成付款", 32, 30, 0xFF068);
                        delay(1000);
                        LoadBMP(70, 675, 300, 768, save_picture20);
                    } 
                    else 
                    {
                        // 显示反馈界面
                        mouse_off(&mouse);
                        delay(200);
                        restoreMainUI(savepicture1,savepicyure2, savepicture3);
                        bar1(205, 212, 960, 658, 0xFFFFFF);
                        puthz(72, 560, "已缴款", 32, 30, 0x0010DD);
                        Line3(75, 600, 170, 600, 1, 0x0010DD);
                        puthz(220, 250, "已处理违章", 32, 30, 0x000000);
                        puthz(220, 350, "违章时间", 32, 30, 0x000000);
                        puthz(570, 350, "违章地点", 32, 30, 0x000000);
                        showViolationInfo1(temp);
                        puthz(220, 450, "此次违章处理您的满意程度", 32, 30, 0x000000);
                        puthz(340, 560, "不满意", 32, 30, 0xFF068);
                        puthz(510, 560, "满意", 32, 30, 0x0010DD);
                        puthz(660, 560, "非常满意", 32, 30, 0x000000);
                        for (i = 0; i < 10; i++) 
                        {
                            int boxX1 = 350 + i * (40 + 5);
                            int boxY1 = 520;
                            int boxX2 = boxX1 + 40;
                            int boxY2 = boxY1 + 40;
                            bar2(boxX1, boxY1, boxX2, boxY2, 0x000000);
                        }
                        *page=deal_func1();
                        break;
                    }
                }
                else if ((mouse_press(420, 680, 540, 740) == 1) || text2 == 1) 
                {
                    puthz(270, 650, "处理成功，自动前往安全学习页面", 24, 30, 0xFF068);
                    delay(2000);
                    if_fine = 2;
                    if ((fp = fopen("data1.dat", "rb+")) == NULL) 
                    {
                        printf("error!\n");
                        exit(0);
                    }
                    fseek(fp, 36 + current_pos, SEEK_SET);
                    fwrite(&if_fine, sizeof(int), 1, fp);
                    fclose(fp);
                    *page = 31;
                    return;
                }
                break;
        }

        if (if_deal == 1 && mouse_press(70, 360, 190, 515) == 1) 
        {
            mouse_off(&mouse);
            delay(200);
            restoreMainUI(savepicture1,savepicyure2, savepicture3);
            bar1(205, 212, 960, 658, 0xFFFFFF);
            puthz(72, 400, "已处理", 32, 30, 0x0010DD);
            Line3(75, 440, 170, 440, 1, 0x0010DD);
            puthz(72, 440, "未缴款", 32, 30, 0x0010DD);
            Line3(75, 480, 170, 480, 1, 0x0010DD);
            puthz(220, 220, "华中科技大学校园违停管理系统", 48, 50, 0x000000);
            puthz(450, 270, "罚款缴纳", 48, 50, 0x000000);
            puthz(210, 330, "尊敬的用户，您好！", 32, 30, 0x000000);
            puthz(210, 370, "您共需缴纳罚款：", 32, 30, 0xFF068);
            RMB(220, 420, 2, 2, 0xFF068);
            sprintf(fine_str, "%d", temp.fine[0]);
            for (i = 0; fine_str[i] != '\0'; i++) {
                char digit[2];
                digit[0] = fine_str[i];
                digit[1] = '\0';
                prt_hz16_asc16_size(285 + i * 30, 410, 3, 3, digit, 0xFF06F, "HZK\\hzk16");
            }
            puthz(210, 470, "请选择付款方式", 24, 25, 0x0010DD);
            draw_botton(250, 520, 345, 570, 0xFFFFFF, 0x00FF);
            puthz(245, 530, "支付宝", 32, 35, 0x000000);
            draw_botton(250, 600, 345, 650, 0xFFFFFF, 0x00FF);
            puthz(255, 610, "微信", 32, 35, 0x000000);
            savepicture2_1 = SaveBMP(560, 270, 940, 650);
            state = STATE_PROCESSED_PAYMENT;
        }
        if(*page==27)
        {
            break;
        }
    }
}
void punish(int *page)
{
    mouse_off(&mouse);
    Readbmp64k(0, 0, "bmp\\user1.bmp");
    puthz(350,50,"华中科技大学",48,50,0x9932CC);
    puthz(270,120,"机动车违停处罚条例",48,50,0x000000);
    rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
    bar1(60, 210, 964, 660, 0xFFFFFF);
    draw_confirmbotton(420, 680, "返回上一级"); // 返回上一级
    /*（一）轻微违规
    在非指定临时停车区域短暂停车（五分钟内），未影响交通秩序和他人通行。停车时车身部分超出停车位边界，但未妨碍其他车辆和行人正常通行,每次扣二分,罚款20元
    (二）一般违规
    在禁止停车标志、标线处停车，但未造成交通拥堵。用消防通道、应急通道停车，但未引发紧急情况。每次扣五分，罚款30元
    （三）严重违规
    在消防通道、应急通道长时间停车，导致紧急救援车辆无法通行。因违停造成校园内交通严重拥堵，影响范围较大且持续时间较长（超过三十分钟）。严重违规：每次扣十分，罚款50元*/
    puthz(65, 220, "（一）轻微违规", 32, 30, 0x000000);
    puthz(110, 270, "在非指定临时停车区域短暂停车（五分钟内），未影响交通秩序和他人通行。", 24, 25, 0x000000);
    puthz(80, 300, "停车时车身部分超出停车位边界，但未妨碍其他车辆和行人正常通行，每次扣二", 24, 25, 0x000000);
    puthz(80, 330, "分，罚款二十元", 24, 25, 0x000000);
    puthz(65, 370, "（二）一般违规", 32, 30, 0x000000);
    puthz(110, 420, "在禁止停车标志、标线处停车，但未造成交通拥堵。用消防通道、应急通道停", 24, 25, 0x000000);
    puthz(80, 450, "车，但未引发紧急情况。每次扣五分，罚款三十元", 24, 25, 0x000000);
    puthz(65, 490, "（三）严重违规", 32, 30, 0x000000);
    puthz(110, 530, "在消防通道、应急通道长时间停车，导致紧急救援车辆无法通行。因违停造成", 24, 25, 0x000000);
    puthz(80, 570, "校园内交通严重拥堵，影响范围较大且持续时间较长（超过三十分钟）。违法者", 24, 25, 0x000000);
    puthz(80, 600, "每次扣十分，罚款五十元", 24, 25, 0x000000);
    while(1)
    {
        mouse_show(&mouse);
        if(mouse_press(420, 680, 540, 740)==1)
        {
            *page=29;
            break;
        }
    }
}
void safe_learning_deal(int *page)
{
    int is_query_open = 0; 
    // 标志变量，记录是否处于查询界面
    int save_picture16; // 保存原界面
    int save_picture17;

    Readbmp64k(0, 0, "bmp\\user1.bmp");   
    
    puthz(350, 50, "安全知识学习", 48, 50, 0x000000);
    puthz(250, 150, "华中科技大学机动车管理条例", 32, 40, 0x000000);
   
    rounded_bar(50, 200, 974, 750, 10, 0xBDBD, 0xFFFFFF, 0);
    bar1(60, 210, 964, 660, 0xFFFFFF);

    draw_confirmbotton(430, 680, "确认并退出"); // 返回上一级
    
    puthz(80, 250,"第一条",32,30,0x000000);
    puthz(110, 300,"校园主干道两侧、教学核心区、楼宇出入口、车辆和人员密集区通道等区域严",24,25,0x000000);
    puthz(75, 330,"禁停放机动车，已施划停车位的除外。车辆在停车位停放应遵守规范，停车入位，",24,25,0x000000);
    puthz(75, 360,"不得跨压停车线。",24,25,0x000000);
    puthz(80, 400,"第二条",32,30,0x000000);
    puthz(110, 440,"校园内机动车辆行驶应遵守交通规则，不得超速行驶，不得逆行，不得占用人",24,25,0x000000);
    puthz(75, 470,"行道行驶，不得在校园内鸣喇叭。",24,25,0x000000);
    puthz(80, 510,"第三条",32,30,0x000000);
    puthz(110, 550,"在校园内停放机动车，应依照物价部门核定的收费标准缴纳停放费用。",24,25,0x000000);

    bar2(258,626,288,656,0x000000);
    puthz(300,630,"我已知晓并同意以上条例且愿意遵循以上条例",24,25,0x000000);

    /*prt_hz24_asc32(25, 150,"校园主干道两侧、教学核心区、楼宇出入口、车辆和人员密集区通道等区域严禁停放机动车,已施划停车位的除外。车辆在停车位停放应遵守规范,停车入位,不得跨压停车线。", 0x000000, "HZK\\HZK24s");
    prt_hz24_asc32(25, 250,"校园内机动车辆行驶应遵守交通规则,不得超速行驶,不得逆行,不得占用人行道行驶,不得在校园内鸣喇叭。", 0x000000, "HZK\\HZK24s");
    prt_hz24_asc32(25, 350,"在校园内停放机动车,应依照物价部门核定的收费标准缴纳停放费用。", 0x000000, "HZK\\HZK24s");
    */
    
    while (1)
    {
        mouse_show(&mouse);
        
        if (mouse_press(430, 680, 550, 740) == 1)
        {
            if(is_query_open!=1)
            {
                mouse_off(&mouse);
                save_picture17 = SaveBMP(258, 586, 800, 650);//保存原界面,长为290，宽为220
                //Readbmp64k(450, 350, "bmp\\warning.bmp");效果不好，改为下面的
                puthz(300, 600, "请用户确认同意校园车辆安全管理条例", 24, 25, 0xFF068);
                delay(1000);
                LoadBMP(258, 586, 800, 650, save_picture17);
            }
            else
            {
                *page = 26;
                break;
            }
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
void search_history(int *page)
{
    
    char* location[] = 
    {
        "华科附小", "图书馆", "机械楼", "管理学院", "体育馆", 
        "南二门", "计算机学院", "船海学院", "中操场", "东二区宿舍", 
        "青年园", "学术交流中心"
    };
    //违停行为预存
    char *locations[20][4] = 
    {
            {"未按规定停车，堵塞消防通道", "车辆占用人行道", "车辆停在禁停区域", "车辆停在校园出入口"},
            {"车辆停在图书馆入口", "未按规定停车", "占用残疾人停车位", "车辆停在绿化带内"},
            {"车辆停在机械楼出入口", "未按规定停车", "车辆停在消防栓前", "车辆停在应急通道"},
            {"车辆停在管理学院入口", "未按规定停车", "占用taff停车位", "车辆停在绿化带内"},
            {"车辆停在体育馆入口", "未按规定停车", "车辆停在应急通道", "车辆停在观众通道"},
            {"车辆停在南二门出入口", "未按规定停车", "车辆停在人行道上", "车辆停在禁停区域"},
            {"占用实验室设备装卸区", "停在学院正门台阶前", "占用新能源车充电位", "挤占教授专用停车区"},
            {"停放在试验池通道", "在学院交叉路口违停", "占用访客车位", "在消防栓前违规停车"},
            {"停放在运动场应急通道", "占用跑道周边缓冲区", "在观众席出入口停车", "挤占操场外围非机动车道"},
            {"堵塞宿舍楼消防通道", "占用垃圾清运专用车位", "在宿舍自行车棚前停车", "夜间违停于临时禁停区"},
            {"驶入园区绿地停车", "占用林间步行道", "在湖边观景平台违停", "停放在园内狭窄路段"},
            {"在会议车辆入口处停车", "停放在中心景观绿化带","堵塞交流人员进出通道","未按规定停车"}
        };
        FILE *fp = NULL;
        USERS records[20];
        int total = 0;
        int current_index = 0;
        int need_refresh = 1;
        // 读取所有记录
        fp = fopen("data1.dat", "rb+");
        if (fp) 
        {
            while (total < 20 && fread(&records[total], sizeof(USERS), 1, fp) == 1) 
            {
                total++;
            }
            fclose(fp);
        }
        // 初始化界面
        mouse_off(&mouse);
        bar1(0, 0, 1024, 768, 0xFFFFFF);
        mouse_off(&mouse);
        Readbmp64k(0, 0, "bmp\\user1.bmp");
        rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
        // 绘制操作按钮
        puthz(50, 50, "历史违章页", 48, 50, 0x000000);
        rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
        draw_botton(250,620,350,680,0xFFFFFF,0x000000);
        puthz_coverd(240,635,"下一页",4,32,30,0x000000);
        draw_botton(440,620,560,680,0xFFFFFF,0x000000);
        puthz_coverd(440,635,"返回上页",4,32,30,0x000000);
        draw_botton(660,620,790,680,0xFFFFFF,0x000000);
        puthz_coverd(640,635,"返回主界面",2,32,30,0x000000);

      
        // 主循环
        while (1) 
        {
            mouse_show(&mouse);
            if (need_refresh) 
            {
                mouse_off(&mouse);
                    rounded_bar(100, 150, 924, 600, 20, 0xFFFFFF, 0x000000, 0);
                if (current_index >= total) 
                {
                    puthz(330, 300, "已是最后一个记录", 32, 40, 0x000000);
                    delay(500);
                    *page=26;
                    break;
                } 
                else
                {
                    puthz(150, 180, "车牌号码", 32, 40, 0x000000);
                    prt_hz16_asc16_size(330, 180, 2, 2, records[current_index].carboard, 0x000000,"HZK\\hzk16");
                    puthz(150, 230, "违章地点", 32, 40, 0x000000);
                    puthz(330, 230, location[records[current_index].location], 32, 40, 0x000000);
                    puthz(150, 280, "违章类型", 32, 40, 0x000000);
                    puthz(330, 280, locations[records[current_index].location][records[current_index].violation], 32, 40, 0x000000);
                    puthz(150, 330, "处罚扣分", 32, 40, 0x000000);
                    put_asc16_number_size_coverd(330, 330, 2, 2, 1, records[current_index].fine[1], 0x000000);
                    puthz(500, 330, "处罚金额", 32, 40, 0x000000);
                    put_asc16_number_size_coverd(650, 330, 2, 2, 1, records[current_index].fine[0], 0x000000);
                    draw_botton(600, 405, 700, 455, 0xFFFFFF, 0x000000);
                    puthz_coverd(590, 415, "已判定", 2, 32, 30, 0x000000);
                    if  ((records[current_index].location == 0 && records[current_index].violation == 0) ||  // 堵塞消防通道
				                (records[current_index].location == 2 && records[current_index].violation == 2) ||  // 消防栓前
				                (records[current_index].location == 4 && records[current_index].violation == 2) ||  // 应急通道
				                (records[current_index].location == 9 && records[current_index].violation == 0) ||  // 宿舍消防通道
				                (records[current_index].location == 11 && records[current_index].violation == 0))
                                {  // 宿舍消防通道
				                Readbmp64k(300, 400, "bmp\\3.bmp");
				                }
				                // 第二类：出入口违规
				                if((records[current_index].location == 0 && records[current_index].violation == 3) ||  // 校园出入口
				                (records[current_index].location == 1 && records[current_index].violation == 0) ||  // 图书馆入口
				                (records[current_index].location == 2 && records[current_index].violation == 0) ||  // 机械楼出入口
				                (records[current_index].location == 3 && records[current_index].violation == 0) ||  // 管理学院入口
				                (records[current_index].location == 4 && records[current_index].violation == 0) ||  // 体育馆入口
				                (records[current_index].location == 5 && records[current_index].violation == 0)) { // 南二门出入口
				            
				                Readbmp64k(300, 400, "bmp\\5.bmp");
				                } 
				                // 第三类：特殊车位占用
				                if ((records[current_index].location == 1 && records[current_index].violation == 2) ||  // 残疾人车位
				                (records[current_index].location == 3 && records[current_index].violation == 2) ||  // taff停车位
				                (records[current_index].location == 6 && records[current_index].violation == 2) ||  // 新能源充电位
				                (records[current_index].location == 7 && records[current_index].violation == 2) ||  // 访客车位
				                (records[current_index].location == 9 && records[current_index].violation == 1) )  // 垃圾清运车位
				                {
				                Readbmp64k(300, 400, "bmp\\1.bmp");
				                }
				                // 第四类：绿化/人行道违规
				                if ((records[current_index].location == 0 && records[current_index].violation == 1) ||  // 占用人行道
				                (records[current_index].location == 1 && records[current_index].violation == 3) ||  // 绿化带内
				                (records[current_index].location == 3 && records[current_index].violation == 3) ||  // 绿化带内
				                (records[current_index].location == 5 && records[current_index].violation == 2) ||  // 人行道上
				                (records[current_index].location == 10 && records[current_index].violation == 1)) {  // 景观绿化带
				                Readbmp64k(300, 400, "bmp\\6.bmp");
				                }
				                // 第五类：特殊区域违规
				                if((records[current_index].location == 6 && records[current_index].violation == 1) ||  // 学院台阶前
				                (records[current_index].location == 7 && records[current_index].violation == 1) ||  // 交叉路口
				                (records[current_index].location == 8 && records[current_index].violation == 1) ||  // 跑道缓冲区
				                (records[current_index].location == 9 && records[current_index].violation == 3) ||  // 夜间违停
				                (records[current_index].location == 11 && records[current_index].violation == 3)) {  // 夜间违停
				                Readbmp64k(300, 400, "bmp\\2.bmp");
				                }
				                // 第六类：其他违规
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
				            need_refresh = 1;
				            while(mouse_press(250,620,350,680) == 1);
				        }
				        
				        if (mouse_press(440,620,560,680) == 1) 
                        {
				            *page = 26;
				            break;
				        }
				        
				        if (mouse_press(660,620,790,680) == 1) 
                        {
				            *page = 26;
				            break;
				        }
				        
				        if (mouse_press(830,600,1000,660) == 1) 
                        {
				            *page = 26;
				            break;
				        }
				
				    }
				
}