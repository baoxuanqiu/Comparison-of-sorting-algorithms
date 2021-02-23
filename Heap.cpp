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

    //下面的for循环每一次调换一个元素时，都会从当前元素向下重新整一下元素（将小的元素换到下面）
    for (Tmp = A[i]; 2*i+1 < len; i = child){
        child = 2*i+1; //注意数组下标是从0开始的，所以左孩子的求发不是2*i
        if (child != len - 1 && A[child + 1] > A[child])
            ++child;                //找到最大的儿子节点
        if (Tmp < A[child])
            A[i] = A[child];
        else
            break;
    }
    A[i] = Tmp;
}

void HeapSort(int A[], int len)
{
    //构造堆
    for (int i = len / 2; i >= 0; --i)//因为N/2以后的节点都是子节点，从最下右边的“父节点”开始交换大的节点给父节点
        PercDown(A, i, len);

    for(int i=len-1;i>0;--i)
    {
        Swap(&A[0],&A[i]);  //将最大元素（根）与数组末尾元素交换，从而删除最大元素，重新构造堆
        PercDown(A, 0, i);//从倒数第二个节点开始，重新排序
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
    duration=(double)(stop-start);//单位是ms
    bool b=test(a);
    write_file2("堆排序",a,duration,b);
}



