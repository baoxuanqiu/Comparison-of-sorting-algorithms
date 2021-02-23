#include<stdio.h>
#include<time.h>
extern bool test(int *r);
extern int g_r[];
extern int g_n;
extern int write_file2(char *str,int *arr,double time,bool test);
extern clock_t start,stop;
extern double duration;

//分为有序区和无序区，将无序区的值一一插入到有序区中，形成动态的有序序列
void BinaryInsertSort(int R[],int n)
{
    int i,j,low,mid,high,temp;
    for(i=1;i<n;i++)
    {
        low=0;
        high=i-1;//第i个元素的前一个元素为high
        temp=R[i];
        while(low<=high)
        {
            mid=(low+high)/2;
            if(R[mid]>temp)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        for(j=i-1;j>=high+1;j--)    //high+1后的元素后移
        {
            R[j+1]=R[j];
        }
        R[j+1]=temp;    //将元素插入到指定位置
    }
}

void BIS()
{
    int *a=new int[g_n];
    for(int i=0;i<g_n;i++){
        a[i]=g_r[i];
    }
    start=clock();
    BinaryInsertSort(a,g_n);
    stop=clock();
    duration=(double)(stop-start);//单位是ms
    bool b=test(a);
    write_file2("折半插入",a,duration,b);

}


