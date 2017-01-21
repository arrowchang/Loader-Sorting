#include<stdio.h>

extern char LENGTH;
extern char a[];
extern char IndexRest[];
extern char SubIndex[];
extern char Current_MAX_L; 
extern char R_Pole[];
extern char L_Pole[];
extern char rr,ll;
				 
void Pole_Separation(char src,char side)//side在原数据中位于a[IndexRest[i]的左方/右方都可 
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
void rest_mess(void) //生成原数列剩余乱序数组的同时，对其中各项的移动方向作出判断并归类 
{   
    char i,j,num=0,delta;
    if(SubIndex[0]!=0){ //如果最长递增数列首项不是a[]的首项（即不为下标0） 
      for(i=0;i<SubIndex[0];i++){
         IndexRest[i]=i;
         Pole_Separation(IndexRest[i],a[SubIndex[0]]);
      }
      num=SubIndex[0];
    }
    
    if(SubIndex[Current_MAX_L-1]!=LENGTH-1){ //如果最长递增数列尾项不是a[]的尾项（即不为下标LENGTH-1） 
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
