#ifndef _ALLFUNC_H_
#define _ALLFUNC_H_

#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<bios.h>
#include<string.h>
#include<dos.h>
#include<math.h>
#include<time.h>

#include"hz.h"
#include"ghz.h"
#include"lgfunc.h"
#include"login.h"
#include"map.h"
#include"mouse.h"
#include"SVGA.h"
#include"mcdraw.h"
#include"adraw.h"
#include"lgfunc.h"
#include"userfunc.h"
#include"licence.h"
#include"data.h"
#include"database.h"
#include"welcome.h"
#include "BMP.h"
#include"func1.h"

#define NUM0 0x5230
#define NUM1 0x4f31
#define NUM2 0x5032
#define NUM3 0x5133
#define NUM4 0x4134
#define NUM5 0x4c35
#define NUM6 0x4d36
#define NUM7 0x4737
#define NUM8 0x4838
#define NUM9 0x4939
#define F2 0x3c00
#define F3 0x3d00
#define F4 0x3e00
#define F5 0x3f00
#define F6 0x4000
#define F7 0x4100
#define F8 0x4200
#define F9 0x4300
#define F10 0x4400
#define F1 0x3b00
#define ENTER 0x1c0d
#define BACK 0x0e08
#define ESC 0x011b
#define UP 0x4800
#define DOWN 0x5000
#define RIGHT 0x4d00
#define LEFT 0x4b00
#define ONE 0x0231
#define TWO 0x0332
#define THREE 0x0433
#define FOUR 0x0534
#define FIVE 0x0635
#define SIX 0x0736
#define SEVEN 0x0837
#define EIGHT 0x0938
#define NINE 0x0a39
#define ZERO 0x0b30
extern MOUSE mouse;//声明全局变量，本项目工程共用同一个鼠标结构
//故每个（需要鼠标的）文件都应包含

#endif
