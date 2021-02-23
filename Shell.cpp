#include<stdio.h>
#include<time.h>
extern int g_n;
extern int g_r[];
extern bool test(int *r);
extern int write_file2(char *str,int *arr,double time,bool test);
extern clock_t start,stop;
extern double duration;

//首先它把较大的数据集合分割成若干个小组（逻辑上分组），然后对每一个小组分别进行插入排序
//此时，插入排序所作用的数据量比较小（每一个小组），插入的效率比较高
void Shell_sort(int *a, int len)
{
    int i;
    int j;
    int temp;
    int gap;  //步长
    for (gap = len / 2; gap >= 1; gap /= 2) {  // 步长初始化为数组长度的一半，每次遍历后步长减半
        for (i = 0 + gap; i < len; i += 1) {   //对每个组插入排序时，不是一个组排序后再进行另一个，而是轮流对每个组进行插入排序
            temp = a[i];  //备份a[i]的值
            j = i - gap;  //j初始化为i的前一个元素（与i相差gap长度）
            while (j >= 0 && a[j] > temp) {
                a[j + gap] = a[j];  //将在a[i]前且比temp的值大的元素向后移动一位
                j -= gap;
            }
            a[j + gap] = temp;
        }
    }
}

void Shell(){
    int *a=new int[g_n];
    for(int i=0;i<g_n;i++){
        a[i]=g_r[i];
    }
    start=clock();
    Shell_sort(a,g_n);
    stop=clock();
    duration=(double)(stop-start);//单位是ms
    bool b=test(a);
    write_file2("希尔排序",a,duration,b);
}
