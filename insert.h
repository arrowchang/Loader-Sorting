void in_order(char TOP,char array[]); 
void insert_Index(char src,char des,char top); //把向左移的下标插入原最长增序子数列Index中 
void des_L_Pole(void);  //找到向左移的目的地下标,同时刷新Index(调用insert_Index函数) ;times为调用该函数的次数，因为需要得到new_Index[],故在每一次的更新后，Index[]长度增长1
void des_R_Pole(void);  //找到向→移的目的地下标 
void LadjustIndexa(char src,char des);//左移；将原始数组a[]所对应的下标移动，从而变相将a移动，并帮助计算出每步的移动距离L 
void RadjustIndexa(char src,char des);
void MovL(char src,char des) ;//把数列中的一个元素拿出来放到该数列的其他位置（左移） 
void MovR(char src,char des);
