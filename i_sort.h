#include<stdio.h>
#include"Longest_sub_series.h"
#include"index_rest.h"
#include"m2.h"
#define length 100  
//程序预留空间（定义数组长度时用） 
char LENGTH; //实际输入长度 
char a[length]={0};  //{9,8,2,7,6,3,5,4,1,0};//{7,3,1,8,2,6,5,0,4,9};//
//for Longest_sub_series.c
char SubIndex[length]={0};   //SubIndex of the longest incresing sub-series 
char Interim_Length=1;//储存“当前”递增子数列长度，一定阶段的最大值赋给Current_MAX_L 
char Current_MAX_L=1; //'当前的'递增子数列最大值；运行到最后的结果是最长增序子数列长度 
char Simplify=0;      //作用为避免"长度停滞不前情况下的结果被重复处理"
int  step=0;//计算找最长增序子数列所需步骤 
//for rest_index.c 
char IndexRest[length]={0};
char R_Pole[length];  //记录向左移项的下标 
char L_Pole[length];  //记录向右移项的下标 
char rr=0,ll=0;       //分别用于R_Pole和L_Pole 
//for insert.c
char Indexa[length];
char revise[length]={0};
int L=0;//移动行程之和 
int RunTimes=0;//  
//--------------------Record Information to print later--------                                    
char Record_a[length]={0};
void PRINTa(char top,char array[]);
void PRINT(char top,char array[]);
void initialization(void);
void RunAgain(void);
