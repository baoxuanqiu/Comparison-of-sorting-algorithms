#include<stdio.h>
#include<time.h>
extern int g_n;
extern int g_r[];
extern bool test(int *r);
extern int write_file2(char *str,int *arr,double time,bool test);
extern clock_t start,stop;
extern double duration;
typedef int ElementType;

void Swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void PercDown(int  A[], int i, int len)
{
    int child;
    ElementType Tmp;

    //�����forѭ��ÿһ�ε���һ��Ԫ��ʱ������ӵ�ǰԪ������������һ��Ԫ�أ���С��Ԫ�ػ������棩
    for (Tmp = A[i]; 2*i+1 < len; i = child){
        child = 2*i+1; //ע�������±��Ǵ�0��ʼ�ģ��������ӵ��󷢲���2*i
        if (child != len - 1 && A[child + 1] > A[child])
            ++child;                //�ҵ����Ķ��ӽڵ�
        if (Tmp < A[child])
            A[i] = A[child];
        else
            break;
    }
    A[i] = Tmp;
}

void HeapSort(int A[], int len)
{
    //�����
    for (int i = len / 2; i >= 0; --i)//��ΪN/2�Ժ�Ľڵ㶼���ӽڵ㣬�������ұߵġ����ڵ㡱��ʼ������Ľڵ�����ڵ�
        PercDown(A, i, len);

    for(int i=len-1;i>0;--i)
    {
        Swap(&A[0],&A[i]);  //�����Ԫ�أ�����������ĩβԪ�ؽ������Ӷ�ɾ�����Ԫ�أ����¹����
        PercDown(A, 0, i);//�ӵ����ڶ����ڵ㿪ʼ����������
    }
}

void Heap(){
    int *a=new int[g_n];
    for(int i=0;i<g_n;i++){
        a[i]=g_r[i];
    }
    start=clock();
    HeapSort(a,g_n);
    stop=clock();
    duration=(double)(stop-start);//��λ��ms
    bool b=test(a);
    write_file2("������",a,duration,b);
}



