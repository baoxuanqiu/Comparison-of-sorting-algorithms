#include<stdio.h>
#include<time.h>
extern int g_n;
extern int g_r[];
extern bool test(int *r);
extern int write_file2(char *str,int *arr,double time,bool test);
extern clock_t start,stop;
extern double duration;

void Swap(int arr[],int low,int high){
    int temp;
    temp=arr[low];
    arr[low]=arr[high];
    arr[high]=temp;
}

int Partition(int array[],int low,int high){
    int base=array[low];
    while(low<high){
        while(low<high && array[high]>=base){
            high--;
        }
        Swap(array,low,high);
        while(low<high && array[low]<=base){
            low++;
        }
        Swap(array,low,high);
    }
    array[low]=base;
    return low;
}

void QuickSort(int array[],int low,int high){
    if(low<high){
        int base=Partition(array,low,high);
        QuickSort(array,low,base-1);
        QuickSort(array,base+1,high);
    }
}

void Quick(){
    int *a=new int[g_n];
    for(int i=0;i<g_n;i++){
        a[i]=g_r[i];
    }
    start=clock();
    QuickSort(a,0,g_n-1);
    stop=clock();
    duration=(double)(stop-start);//单位是ms
    bool b=test(a);
    write_file2("快速排序",a,duration,b);
}
