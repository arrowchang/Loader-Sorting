#include<stdio.h>
#define length 100
extern char LENGTH;
extern char a[];
 
void M2(void)
{  char i,j;
   int num=0;
   char sub_a[2];
   for(i=0;i<LENGTH-1;i++){         
      sub_a[0]=a[i];
      for(j=i+1;j<LENGTH;j++){  
         sub_a[1]=a[j];           //得到M2尾项 
         if(sub_a[0]>sub_a[1])
         num++;
      }
   }
  // printf("Inversion Number=%d\n",num);//可以不显示 
}             
