#include<stdio.h>
#include"main.h"//调用print函数 
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

//对X_Pole排序    
void in_order(char TOP,char array[]) 
 {  
    char i,j,temp,mark;  //mark用来判断是否已经完成排序 
    for(j=0;j<TOP-1;j++){
      mark=0;
      for(i=0;i<TOP-1-j;i++){
         if(a[array[i]]>a[array[i+1]]){
            temp=array[i];               
            array[i]=array[i+1];
            array[i+1]=temp;
            mark=1; //说明有错序，还得至少冒泡一次
          }
        else if(a[array[i]]==a[array[i+1]]){//针对有重复项的情况下 
						if(array[i]>array[i+1]){ //位置靠左的排前面 
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
 void insert_Index(char src,char des,char top) //把外部元素插入该数列的某位置；把向左移的下标插入原最长增序子数列SubIndex中 
{  char j;                                     //new_Index=最长递增子数列index+L_Pole之后形成的新的递增数列
   for(j=top+1;j>des;j--){  //top+1是因为插入后总长度要加1 
     SubIndex[j]=SubIndex[j-1];
   }
   SubIndex[des]=src;//L_Pole[k]; 
}
//-------------------------------------------------------------------
void MovL(char src,char des) //把数列中的一个元素拿出来放到该数列的其他位置（左移） 
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
void LadjustIndexa(char src,char des)//左移；将原始数组a[]所对应的下标移动，从而变相将a移动，并帮助计算出每步的移动距离L 
{
   char i;//  
	 src=src+revise[src];//修正src,指令要求的是指源数列中的a[src],故现在的a[x]非原来的a[x],所以x要修正 
	 des=des+revise[des];//修正des,
	 for(i=des;i<src;i++){
			revise[Indexa[i]]++;
	 }
	 revise[Indexa[src]]+=(des-src);
	 
	 MovL(src,des); //将Indexa移位
	 
} 

void RadjustIndexa(char src,char des)//通过更改a[]的下标的顺序来输出每一步移动后的a[]  
{
	 char i;
	 src=src+revise[src];//修正src,指令要求的是指源数列中的a[src],故现在的a[x]非原来的a[x],所以x要修正 
	 des=des+revise[des];//修正des,	
	 for(i=src+1;i<=des;i++){
			revise[Indexa[i]]--;
	 }
	 revise[Indexa[src]]+=(des-src);//revise[temp]+=(des-src);//
	 
	 MovR(src,des);//将Indexa移位 
	 
} 
void des_L_Pole(void)  //返回向左移的目的地下标,同时刷新SubIndex(调用insert_Index函数) ;times为调用该函数的次数，因为需要得到new_Index[],故在每一次的更新后，SubIndex[]长度增长1
 {
    char i,k,times=0;
         
    for(k=0;k<ll;k++){
        if(a[L_Pole[k]]<a[SubIndex[0]]){  //如果比最长子数列中的首项小
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
								 insert_Index(L_Pole[k],i+1,Current_MAX_L-1+times);//刷新SubIndex[] 
						      //printf("new_Index: ");
           				//PRINTa(Current_MAX_L-1+times+1,SubIndex);
           				times++;
           				break;
     					}
     				}
   			}
	  }
	     
 } 
void des_R_Pole(void)  //找到向→移的目的地下标 
 {
      char i,k;
      for(k=rr-1;k>=0;k--){
         if(a[R_Pole[k]]>a[SubIndex[Current_MAX_L-1+ll]]){//如果比最长子数列中的尾项大 
						printf("MOV %d -> %d ",a[R_Pole[k]],a[SubIndex[Current_MAX_L-1+ll]]);
						
						RadjustIndexa(R_Pole[k],SubIndex[Current_MAX_L-1+ll]);
				 }
         else{
            for(i=0;i<Current_MAX_L-1+ll;i++){  //*当左移全部以好后，用增加a[L_Pole[]]的新的a[SubIndex[]]来确定R_Pole的目的地，而不是之前用的最长递增子数列a[SubIndex[]]* 
              if(a[R_Pole[k]]>a[SubIndex[i]]&&a[R_Pole[k]]<=a[SubIndex[i+1]]){
								 printf("MOV %d -> %d ",a[R_Pole[k]],a[SubIndex[i]]);
								 
								 RadjustIndexa(R_Pole[k],SubIndex[i]);
                 break;
              }
            }
         }
      }
 }
  
/*void des_L(char k,char times)  //返回向左移的目的地下标,同时刷新SubIndex(调用insert_Index函数) ;times为调用该函数的次数，因为需要得到new_Index[],故在每一次的更新后，SubIndex[]长度增长1
 {                                                                                        
    char i,top;                                                                           
    top=Current_MAX_L-1+times;                                                            
    if(a[L_Pole[k]]<a[SubIndex[0]]){//如果是L_Pole[0]（最小值 ）                             
        //如果比最长子数列中的首项小                                                      
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
           insert_Index(L_Pole[k],i+1,top);//刷新SubIndex[]                                  
           printf("new_Index: ");                                                         
           PRINTa(top+1,SubIndex);                                                            
           //return SubIndex[i+1];//移至 SubIndex[i+1]的前面                                    
           break;                                                                         
         }                                                                                
       }                                                                                  
    }                                                                                     
 }                                                                                        
 void des_R(char k)  //找到向→移的目的地下标                                             
 {                                                                                        
    char i;                                                                               
      if(a[R_Pole[k]]>a[SubIndex[Current_MAX_L-1+ll]])//如果比最长子数列中的尾项大           
      printf("MOV %d -> %d\n",a[R_Pole[k]],a[SubIndex[Current_MAX_L-1+ll]]);                 
      //return SubIndex[Current_MAX_L-1];                                                    
    else{                                                                                 
       for(i=0;i<Current_MAX_L-1+ll;i++){  //*当左移全部以好后，用增加a[L_Pole[]]的新的a[SubIndex[]]来确定R_Pole的目的地，而不是之前用的最长递增子数列a[SubIndex[]]* 
         if(a[R_Pole[k]]>a[SubIndex[i]]&&a[R_Pole[k]]<=a[SubIndex[i+1]]){                       
                                                                                      
           printf("MOV %d -> %d\n",a[R_Pole[k]],a[SubIndex[i]]);                             
           //return SubIndex[i]; //移至SubIndex[i]的后面                                        
           break;                                                                         
         }                                                                           
       }                                                                           
   }                                                                                      
 }                                                                                        
void print_steps(void)//按照次序将X_Pole插入最长递增zi数列                                
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
      
