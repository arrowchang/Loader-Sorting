#include<stdio.h>
#include"Longest_sub_series.h"
#include"index_rest.h"
#include"m2.h"
#define length 100  
//����Ԥ���ռ䣨�������鳤��ʱ�ã� 
char LENGTH; //ʵ�����볤�� 
char a[length]={0};  //{9,8,2,7,6,3,5,4,1,0};//{7,3,1,8,2,6,5,0,4,9};//
//for Longest_sub_series.c
char SubIndex[length]={0};   //SubIndex of the longest incresing sub-series 
char Interim_Length=1;//���桰��ǰ�����������г��ȣ�һ���׶ε����ֵ����Current_MAX_L 
char Current_MAX_L=1; //'��ǰ��'�������������ֵ�����е����Ľ��������������г��� 
char Simplify=0;      //����Ϊ����"����ͣ�Ͳ�ǰ����µĽ�����ظ�����"
int  step=0;//��������������������貽�� 
//for rest_index.c 
char IndexRest[length]={0};
char R_Pole[length];  //��¼����������±� 
char L_Pole[length];  //��¼����������±� 
char rr=0,ll=0;       //�ֱ�����R_Pole��L_Pole 
//for insert.c
char Indexa[length];
char revise[length]={0};
int L=0;//�ƶ��г�֮�� 
int RunTimes=0;//  
//--------------------Record Information to print later--------                                    
char Record_a[length]={0};
void PRINTa(char top,char array[]);
void PRINT(char top,char array[]);
void initialization(void);
void RunAgain(void);
