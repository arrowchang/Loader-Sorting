#include"i_sort.h"
int main(void)
{ 	
    printf(" Author:ArrowChang------------------------------yanjingchang@gmail.com\n");
    printf(" ------------------------------Copyright Reserved---------------------------\n");
    printf(" INSTRUCTION OF DUMMY ORDER:                                              \n");
    printf("               MOV 1<-2 [3];          Move '1' Leftward To The Left Side  \n");
    printf("                                      Of '2'(Jump over '3' Elements).     \n");
    printf("               MOV 2->1 [4];          Move '2' Rightward To The Right Side\n");
    printf("                                      Of '1'(Jump over '4' Elements).     \n");
    printf("               [ N=5;L=6 ] ;          '5'Elements Have Been Moved;        \n");
    printf("                                      Jump Over'6'Elements In Total.      \n"); 
    printf("                                                                            \n"); 
    printf(" ----------------------------------Version 4.3---------------------5/12/2012\n");
    while(1){
        RunAgain(); 
        initialization();
        printf("OriginalArray:\n");
        PRINT(LENGTH,a);
        
        M2();
        Loop();
        rest_mess();
        /*//可以不在界面显示。 
        printf("The Longest Increasing Sub-Sequence :\n");
        PRINTa(Current_MAX_L-1,SubIndex);
        printf("The Rest:\n ");
        PRINTa(LENGTH-Current_MAX_L-1,IndexRest);
        */
        printf("Sorting Steps:\n");
        in_order(rr,R_Pole);
        in_order(ll,L_Pole);
        /*
        printf("R_Pole:   "); //正确顺序
        PRINTa(rr-1,R_Pole);
        printf("L_Pole:   "); //正确顺序
        PRINTa(ll-1,L_Pole);
        */
        des_L_Pole();
        des_R_Pole();
        
        printf("Result:\n");
        printf("       ");
        PRINT(LENGTH,Record_a);
        
        printf("[   N= %d;",LENGTH-Current_MAX_L);
        printf("L= %d   ]\n",L);
        printf("------------------------------------------------------------------[%d]----\n",RunTimes++);

    }
    system("pause");
    return 0;  
}
//-----------------------------------------------------------------------------
void PRINTa(char top,char array[]){
    char i;
    for(i=0;i<top+1;i++){
       printf("%d ",a[array[i]]);
    }
    printf("\n");
}
//-----------------------------------------------------------------------------
void PRINT(char top,char array[]){
  char i;
  for(i=0;i<top;i++){
    printf("%d ",array[i]);
  }
  printf("\n");
}
//-----------------------------------------------------------------------------
void initialization(void){
    char i=0;
    printf("Please input an array(array[i]<128 && Length<100)：\n");//数据类型为char型，数组长度<100 
    
    do{  
        scanf("%d",&a[i]);
        i++;
    }
    while(getchar()!='\n');   //如果输入不为换行，继续输入（但数据总长度<100） 
    LENGTH=i;
    
    for(i=0;i<LENGTH;i++){
        Indexa[i]=i;
        Record_a[i]=a[i];//Initial Record_a[]
    }	
}
//-----------------------------------------------------------------------------
void RunAgain(void){  //serving for the initialization of the next array input 
    Interim_Length=1;//=initial
    Current_MAX_L=1;
    Simplify=0;
    step=0;
    rr=0;
    ll=0;
    L=0;
    
    char i;
    for(i=0;i<length;i++){
    	revise[i]=0;
    } //the initial value of revise[i] must be zero.
    for(i=0;i<length;i++){  //[new add]
    	IndexRest[i]=0;
    	SubIndex[i]=0;
    	Record_a[i]=0;
    } 
}
