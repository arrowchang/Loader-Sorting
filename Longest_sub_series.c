#include<stdio.h>
#include"main.h"  //PRINTa���� 
#define length 100
extern char LENGTH;  
extern char a[];
extern char SubIndex[];//SubIndex of the longest incresing sub-series 
extern char Interim_Length;//���桰��ǰ�����������г��ȣ�һ���׶ε����ֵ����Current_MAX_L 
extern char Current_MAX_L;//'��ǰ��'�������������ֵ�����е����Ľ����Ŀ�������г��� 
extern char Simplify; //����Ϊ����"����ͣ�Ͳ�ǰ����µĽ�����ظ�����"
extern int step;

void Value_assignment(char k,char src_index[length])
{ char i;
  for(i=0;i<k;i++){
    SubIndex[i]=src_index[i];
  }
}

void BodyOfLoop(int k,char ii[length])   
{  
  for(ii[k]=ii[k-1]+1;(ii[k]<LENGTH)&&(k+LENGTH-ii[k]>Current_MAX_L);ii[k]++){    //��ǰ�������г��ȼ���ʣ����ĸ���������ڵ�ǰ��������еĳ��� 
     //PRINTa(k,ii);
     //step++;
     if(a[ii[k]]>=a[ii[k-1]]){   //sub_a[k]>sub_a[k-1]
        Interim_Length++;   //���г���+1������Щ����������ǵݼ����У� 
        if(ii[k]==(LENGTH-1)&&Current_MAX_L<Interim_Length){//����Ѿ����뵽�������һ���ô�������ν�����˳��÷�֧��&&Current_MAX_L����ֵ 
           Value_assignment(k+1,ii);
           //printf("����� T=%d,Interim_Length=%d,������� ",Current_MAX_L,Interim_Length);
           //printf("1) ");PRINTa(k,SubIndex); 
           //if(Current_MAX_L<Interim_Length)
					 Current_MAX_L=Interim_Length;
           Interim_Length--;
        }       
     }
     else { 
        if(Interim_Length>Current_MAX_L&&Simplify<Interim_Length){ //��¼��ԭ��¼���Ľ��&&���ظ���¼����ֹͣ��ǰ�Ľ�� 
          Value_assignment(k,ii);
           Simplify=Interim_Length;
           //printf("Current_MAX_L=%d,Interim_Length=%d,��ǰ������� ",Current_MAX_L,Interim_Length);
          // printf("2) "); PRINTa(k-1,SubIndex);
        }
        continue;//���ٶ���һ��֧�������� 
     } 
                           
     if(ii[k]+1<LENGTH){ 
        BodyOfLoop(k+1,ii);
        
        if(Current_MAX_L<Interim_Length) 
        Current_MAX_L=Interim_Length;
        Interim_Length--;//ʵ������û�����߼� 
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
   /*if(Current_MAX_L==1){//������������a[]�ǵݼ����� 
     printf("[ԭʼ����Ϊ�ݼ�����]\n");
		 SubIndex[0]=0; //�ɷ��ڳ�ʼ���н��и�ֵ0 
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
