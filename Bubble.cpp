#include<stdio.h>
#include<time.h>
extern bool test(int *r);
extern int g_n;
extern int g_r[];
extern int write_file2(char *str,int *arr,double time,bool test);
extern clock_t start,stop;
extern double duration;

//��ͷ��β����,�����������бȽ�,�������(���)����β��(���)
void Bubble_sort(int *a,int len){
    for(int i=0;i<len;i++)
	{
        for(int j=0;j<len-i-1;j++)
            if(a[j]>a[j+1]){
                int w=a[j];
                a[j]=a[j+1];
                a[j+1]=w;
            }
    }
}

void Bubble(){
    int *a=new int[g_n];
    for(int i=0;i<g_n;i++){
        a[i]=g_r[i];
    }
    start=clock();
    Bubble_sort(a,g_n);
    stop=clock();
    duration=(double)(stop-start);//��λ��ms
    bool b=test(a);
    write_file2("ð������",a,duration,b);
}
