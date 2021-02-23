#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
extern bool test(int *r);
extern int g_n;
extern int g_r[];
extern int write_file2(char *str,int *arr,double time,bool test);
extern clock_t start,stop;
extern double duration;

void _Merge(int *a,int begin1,int end1,int begin2,int end2){
    int *tmp=new int[g_n];
    int index=begin1;
    int i=begin1,j=begin2;
    while(i<=end1 && j<=end2){
        if(a[i]<=a[j])
            tmp[index++]=a[i++];//a[i]赋值给tmp[index]后，i再加一，index再加一
        else
            tmp[index++]=a[j++];
    }

    while(i<=end1)
        tmp[index++]=a[i++];
    while(j<=end2)
        tmp[index++]=a[j++];

    //将tmp+begin1开始的元素（即合并后的元素）复制到数组a+begin1开始的位置
    //sizeof(int)*(end2-begin1+1)为合并后的元素长度
    memcpy(a+begin1,tmp+begin1,sizeof(int)*(end2-begin1+1));
}


void MergeSort(int *a,int left,int right){
    if(left>=right)
        return;
    int mid=(left+right)/2;
    MergeSort(a,left,mid);
    MergeSort(a,mid+1,right);
    _Merge(a,left,mid,mid+1,right);
}

void Merge(){
    //start=clock();
    int *a=new int[g_n];
    for(int i=0;i<g_n;i++){
        a[i]=g_r[i];
    }
    start=clock();
    MergeSort(a,0,g_n-1);
    stop=clock();
    duration=(double)(stop-start);//单位是ms
    bool b=test(a);
    write_file2("归并排序",a,duration,b);
}
