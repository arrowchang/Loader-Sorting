#include<stdio.h>
#include"main.h"//����print���� 
extern char LENGTH; 
extern char a[];
extern char SubIndex[];
extern char Current_MAX_L;
extern char L_Pole[];
extern char R_Pole[];
extern char rr;
extern char ll;
extern char Indexa[];
extern char revise[];
extern int L;
extern char Record_a[];

//��X_Pole����    
void in_order(char TOP,char array[]) 
 {  
    char i,j,temp,mark;  //mark�����ж��Ƿ��Ѿ�������� 
    for(j=0;j<TOP-1;j++){
      mark=0;
      for(i=0;i<TOP-1-j;i++){
         if(a[array[i]]>a[array[i+1]]){
            temp=array[i];               
            array[i]=array[i+1];
            array[i+1]=temp;
            mark=1; //˵���д��򣬻�������ð��һ��
          }
        else if(a[array[i]]==a[array[i+1]]){//������ظ��������� 
						if(array[i]>array[i+1]){ //λ�ÿ������ǰ�� 
							temp=array[i];               
              array[i]=array[i+1];
              array[i+1]=temp;
              mark=1;
						}
					} 
				
      }
      if(mark==0) break;
    }
 }
//------------------------------------------------------------ 
 void insert_Index(char src,char des,char top) //���ⲿԪ�ز�������е�ĳλ�ã��������Ƶ��±����ԭ�����������SubIndex�� 
{  char j;                                     //new_Index=�����������index+L_Pole֮���γɵ��µĵ�������
   for(j=top+1;j>des;j--){  //top+1����Ϊ������ܳ���Ҫ��1 
     SubIndex[j]=SubIndex[j-1];
   }
   SubIndex[des]=src;//L_Pole[k]; 
}
//-------------------------------------------------------------------
void MovL(char src,char des) //�������е�һ��Ԫ���ó����ŵ������е�����λ�ã����ƣ� 
{   
   char i,temp;
	 temp=Indexa[src];                                   // BUG!
	 for(i=src;i>des;i--){
	   Indexa[i]=Indexa[i-1];//temp_a[i]=revise[i];//temp_a[i+revise[i]]=a[i];
	 }
	 Indexa[des]=temp;
	 
	 L+=(src-des);
	 printf("[%d] :   ",src-des); 
//	 PRINTa(LENGTH-1,Indexa);  
//	 printf("                         *");
	 for(i=0;i<LENGTH;i++){
			if(i==src){
				printf("<%d> ",Record_a[i]);
				}
				else if(i==des){
					printf("{%d} ",Record_a[i]);
					} else
					printf("%d ",Record_a[i]);
	 }
	 printf("\n");
	 
	 for(i=0;i<LENGTH;i++){       //Record a[] to print later
			Record_a[i]=a[Indexa[i]];
		}
}
void MovR(char src,char des)
{
   char i,temp;
   temp=Indexa[src];                                   // BUG!
	 for(i=src;i<des;i++){
	   Indexa[i]=Indexa[i+1];//temp_a[i]=revise[i];//temp_a[i+revise[i]]=a[i];
	 }
	 Indexa[des]=temp;
	 
	 L+=(des-src);
	 printf("[%d] :   ",des-src);
	// PRINTa(LENGTH-1,Indexa);
	// printf("                         ");
	 for(i=0;i<LENGTH;i++){
			if(i==src){
				printf("<%d> ",Record_a[i]);
				}
				else if(i==des){
					printf("{%d} ",Record_a[i]);
					} else
					printf("%d ",Record_a[i]);
	 }
	printf("\n"); 
	
	 for(i=0;i<LENGTH;i++){       //Record a[] to print later
			Record_a[i]=a[Indexa[i]];
		}
}
void LadjustIndexa(char src,char des)//���ƣ���ԭʼ����a[]����Ӧ���±��ƶ����Ӷ����ཫa�ƶ��������������ÿ�����ƶ�����L 
{
   char i;//  
	 src=src+revise[src];//����src,ָ��Ҫ�����ָԴ�����е�a[src],�����ڵ�a[x]��ԭ����a[x],����xҪ���� 
	 des=des+revise[des];//����des,
	 for(i=des;i<src;i++){
			revise[Indexa[i]]++;
	 }
	 revise[Indexa[src]]+=(des-src);
	 
	 MovL(src,des); //��Indexa��λ
	 
} 

void RadjustIndexa(char src,char des)//ͨ������a[]���±��˳�������ÿһ���ƶ����a[]  
{
	 char i;
	 src=src+revise[src];//����src,ָ��Ҫ�����ָԴ�����е�a[src],�����ڵ�a[x]��ԭ����a[x],����xҪ���� 
	 des=des+revise[des];//����des,	
	 for(i=src+1;i<=des;i++){
			revise[Indexa[i]]--;
	 }
	 revise[Indexa[src]]+=(des-src);//revise[temp]+=(des-src);//
	 
	 MovR(src,des);//��Indexa��λ 
	 
} 
void des_L_Pole(void)  //���������Ƶ�Ŀ�ĵ��±�,ͬʱˢ��SubIndex(����insert_Index����) ;timesΪ���øú����Ĵ�������Ϊ��Ҫ�õ�new_Index[],����ÿһ�εĸ��º�SubIndex[]��������1
 {
    char i,k,times=0;
         
    for(k=0;k<ll;k++){
        if(a[L_Pole[k]]<a[SubIndex[0]]){  //�������������е�����С
					 printf("MOV %d <- %d ",a[L_Pole[k]],a[SubIndex[0]]); //
					 
					 LadjustIndexa(L_Pole[k],SubIndex[0]);
					 insert_Index(L_Pole[0],0,Current_MAX_L-1+times);
              //printf("new_Index: ");
              //PRINTa(Current_MAX_L-1+times+1,SubIndex);
           times++;
        }
        else{
           for(i=0;i<Current_MAX_L-1+times;i++){
         			if(a[L_Pole[k]]>=a[SubIndex[i]]&&a[L_Pole[k]]<a[SubIndex[i+1]]){
								 printf("MOV %d <- %d ",a[L_Pole[k]],a[SubIndex[i+1]]);
									
								 LadjustIndexa(L_Pole[k],SubIndex[i+1]);
								 insert_Index(L_Pole[k],i+1,Current_MAX_L-1+times);//ˢ��SubIndex[] 
						      //printf("new_Index: ");
           				//PRINTa(Current_MAX_L-1+times+1,SubIndex);
           				times++;
           				break;
     					}
     				}
   			}
	  }
	     
 } 
void des_R_Pole(void)  //�ҵ�����Ƶ�Ŀ�ĵ��±� 
 {
      char i,k;
      for(k=rr-1;k>=0;k--){
         if(a[R_Pole[k]]>a[SubIndex[Current_MAX_L-1+ll]]){//�������������е�β��� 
						printf("MOV %d -> %d ",a[R_Pole[k]],a[SubIndex[Current_MAX_L-1+ll]]);
						
						RadjustIndexa(R_Pole[k],SubIndex[Current_MAX_L-1+ll]);
				 }
         else{
            for(i=0;i<Current_MAX_L-1+ll;i++){  //*������ȫ���Ժú�������a[L_Pole[]]���µ�a[SubIndex[]]��ȷ��R_Pole��Ŀ�ĵأ�������֮ǰ�õ������������a[SubIndex[]]* 
              if(a[R_Pole[k]]>a[SubIndex[i]]&&a[R_Pole[k]]<=a[SubIndex[i+1]]){
								 printf("MOV %d -> %d ",a[R_Pole[k]],a[SubIndex[i]]);
								 
								 RadjustIndexa(R_Pole[k],SubIndex[i]);
                 break;
              }
            }
         }
      }
 }
  
/*void des_L(char k,char times)  //���������Ƶ�Ŀ�ĵ��±�,ͬʱˢ��SubIndex(����insert_Index����) ;timesΪ���øú����Ĵ�������Ϊ��Ҫ�õ�new_Index[],����ÿһ�εĸ��º�SubIndex[]��������1
 {                                                                                        
    char i,top;                                                                           
    top=Current_MAX_L-1+times;                                                            
    if(a[L_Pole[k]]<a[SubIndex[0]]){//�����L_Pole[0]����Сֵ ��                             
        //�������������е�����С                                                      
        printf("MOV %d <- %d\n",a[L_Pole[0]],a[SubIndex[0]]); //                             
        insert_Index(L_Pole[0],0,top);                                                    
        printf("new_Index: ");                                                            
        PRINTa(top+1,SubIndex);                                                               
        //return SubIndex[0];                                                                
    }                                                                                     
    else{                                                                                 
       for(i=0;i<top;i++){                                                                
         if(a[L_Pole[k]]>=a[SubIndex[i]]&&a[L_Pole[k]]<a[SubIndex[i+1]]){                       
           printf("MOV %d <- %d\n",a[L_Pole[k]],a[SubIndex[i+1]]); //                        
           insert_Index(L_Pole[k],i+1,top);//ˢ��SubIndex[]                                  
           printf("new_Index: ");                                                         
           PRINTa(top+1,SubIndex);                                                            
           //return SubIndex[i+1];//���� SubIndex[i+1]��ǰ��                                    
           break;                                                                         
         }                                                                                
       }                                                                                  
    }                                                                                     
 }                                                                                        
 void des_R(char k)  //�ҵ�����Ƶ�Ŀ�ĵ��±�                                             
 {                                                                                        
    char i;                                                                               
      if(a[R_Pole[k]]>a[SubIndex[Current_MAX_L-1+ll]])//�������������е�β���           
      printf("MOV %d -> %d\n",a[R_Pole[k]],a[SubIndex[Current_MAX_L-1+ll]]);                 
      //return SubIndex[Current_MAX_L-1];                                                    
    else{                                                                                 
       for(i=0;i<Current_MAX_L-1+ll;i++){  //*������ȫ���Ժú�������a[L_Pole[]]���µ�a[SubIndex[]]��ȷ��R_Pole��Ŀ�ĵأ�������֮ǰ�õ������������a[SubIndex[]]* 
         if(a[R_Pole[k]]>a[SubIndex[i]]&&a[R_Pole[k]]<=a[SubIndex[i+1]]){                       
                                                                                      
           printf("MOV %d -> %d\n",a[R_Pole[k]],a[SubIndex[i]]);                             
           //return SubIndex[i]; //����SubIndex[i]�ĺ���                                        
           break;                                                                         
         }                                                                           
       }                                                                           
   }                                                                                      
 }                                                                                        
void print_steps(void)//���մ���X_Pole���������zi����                                
{   char i;                                                                           
    for(i=0;i<ll;i++){                                                                    
      des_L(i,i);                                                                         
    }                                                                                     
    for(i=rr-1;i>=0;i--){                                                                 
      des_R(i);                                                                           
    }                                                                                     
}                                                                                         
*/ 
 /*
*/ 
      
