#include<stdio.h>
#include"main.h"  //PRINTa函数 
#define length 100
extern char LENGTH;  
extern char a[];
extern char SubIndex[];//SubIndex of the longest incresing sub-series 
extern char Interim_Length;//储存“当前”递增子数列长度，一定阶段的最大值赋给Current_MAX_L 
extern char Current_MAX_L;//'当前的'递增子数列最大值；运行到最后的结果是目的子数列长度 
extern char Simplify; //作用为避免"长度停滞不前情况下的结果被重复处理"
extern int step;

void Value_assignment(char k,char src_index[length])
{ char i;
  for(i=0;i<k;i++){
    SubIndex[i]=src_index[i];
  }
}

void BodyOfLoop(int k,char ii[length])   
{  
  for(ii[k]=ii[k-1]+1;(ii[k]<LENGTH)&&(k+LENGTH-ii[k]>Current_MAX_L);ii[k]++){    //当前增序数列长度加上剩余项的个数如果大于当前最长增序数列的长度 
     //PRINTa(k,ii);
     //step++;
     if(a[ii[k]]>=a[ii[k-1]]){   //sub_a[k]>sub_a[k-1]
        Interim_Length++;   //数列长度+1（从这些数列中找最长非递减数列） 
        if(ii[k]==(LENGTH-1)&&Current_MAX_L<Interim_Length){//如果已经深入到数列最后一项（那么保留本次结果后退出该分支）&&Current_MAX_L赋新值 
           Value_assignment(k+1,ii);
           //printf("上面的 T=%d,Interim_Length=%d,最长数列是 ",Current_MAX_L,Interim_Length);
           //printf("1) ");PRINTa(k,SubIndex); 
           //if(Current_MAX_L<Interim_Length)
					 Current_MAX_L=Interim_Length;
           Interim_Length--;
        }       
     }
     else { 
        if(Interim_Length>Current_MAX_L&&Simplify<Interim_Length){ //记录比原纪录长的结果&&不重复记录长度停止不前的结果 
          Value_assignment(k,ii);
           Simplify=Interim_Length;
           //printf("Current_MAX_L=%d,Interim_Length=%d,当前最长数列是 ",Current_MAX_L,Interim_Length);
          // printf("2) "); PRINTa(k-1,SubIndex);
        }
        continue;//不再对这一分支进行搜索 
     } 
                           
     if(ii[k]+1<LENGTH){ 
        BodyOfLoop(k+1,ii);
        
        if(Current_MAX_L<Interim_Length) 
        Current_MAX_L=Interim_Length;
        Interim_Length--;//实验结果，没深入逻辑 
     } 
  }
}
//---------------------   
void Loop(void)
{  
   int i;
   char ii[length];//char ii[length];
   for(i=0;i<LENGTH-1;i++){        
      ii[0]=i;
      BodyOfLoop(1,ii);
   }
   /*if(Current_MAX_L==1){//特殊情况，如果a[]是递减数列 
     printf("[原始数列为递减数列]\n");
		 SubIndex[0]=0; //可放在初始化中进行赋值0 
	 }
	 */
}              
/*int main(void)
{
  Loop();
  //printf("step=%d\n",step);
  PRINTa(Current_MAX_L-1,SubIndex);
  system("pause");
  return 0;
}    
*/
