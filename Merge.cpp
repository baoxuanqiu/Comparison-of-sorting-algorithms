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
            tmp[index++]=a[i++];//a[i]��ֵ��tmp[index]��i�ټ�һ��index�ټ�һ
        else
            tmp[index++]=a[j++];
    }

    while(i<=end1)
        tmp[index++]=a[i++];
    while(j<=end2)
        tmp[index++]=a[j++];

    //��tmp+begin1��ʼ��Ԫ�أ����ϲ����Ԫ�أ����Ƶ�����a+begin1��ʼ��λ��
    //sizeof(int)*(end2-begin1+1)Ϊ�ϲ����Ԫ�س���
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
    duration=(double)(stop-start);//��λ��ms
    bool b=test(a);
    write_file2("�鲢����",a,duration,b);
}
