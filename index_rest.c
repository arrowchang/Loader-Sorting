#include<stdio.h>

extern char LENGTH;
extern char a[];
extern char IndexRest[];
extern char SubIndex[];
extern char Current_MAX_L; 
extern char R_Pole[];
extern char L_Pole[];
extern char rr,ll;
				 
void Pole_Separation(char src,char side)//side��ԭ������λ��a[IndexRest[i]����/�ҷ����� 
{
   if(a[src]>side){
      R_Pole[rr]=src;
      rr++;
    }
    else {
      L_Pole[ll]=src;
      ll++;
    } 
}
void rest_mess(void) //����ԭ����ʣ�����������ͬʱ�������и�����ƶ����������жϲ����� 
{   
    char i,j,num=0,delta;
    if(SubIndex[0]!=0){ //�����������������a[]���������Ϊ�±�0�� 
      for(i=0;i<SubIndex[0];i++){
         IndexRest[i]=i;
         Pole_Separation(IndexRest[i],a[SubIndex[0]]);
      }
      num=SubIndex[0];
    }
    
    if(SubIndex[Current_MAX_L-1]!=LENGTH-1){ //������������β���a[]��β�����Ϊ�±�LENGTH-1�� 
      for(i=SubIndex[Current_MAX_L-1]+1;i<LENGTH;i++){
         IndexRest[num]=i;
         Pole_Separation(IndexRest[num],a[SubIndex[Current_MAX_L-1]]);
         num++;
      }
    } 
    
    if(num<LENGTH-Current_MAX_L){
       for(i=0;i<Current_MAX_L-1;i++){
         delta=SubIndex[i+1]-SubIndex[i]; 
         for(j=0;j<delta-1;j++){
           IndexRest[num]=SubIndex[i]+1+j;
           Pole_Separation(IndexRest[num],a[SubIndex[i]]);
           num++;
         } 
         if(num>=LENGTH-Current_MAX_L) 
         break;
       }
   }
}
