#include<stdio.h>
#include<time.h>
extern int g_n;
extern int g_r[];
extern bool test(int *r);
extern int write_file2(char *str,int *arr,double time,bool test);
extern clock_t start,stop;
extern double duration;

//�������ѽϴ�����ݼ��Ϸָ�����ɸ�С�飨�߼��Ϸ��飩��Ȼ���ÿһ��С��ֱ���в�������
//��ʱ���������������õ��������Ƚ�С��ÿһ��С�飩�������Ч�ʱȽϸ�
void Shell_sort(int *a, int len)
{
    int i;
    int j;
    int temp;
    int gap;  //����
    for (gap = len / 2; gap >= 1; gap /= 2) {  // ������ʼ��Ϊ���鳤�ȵ�һ�룬ÿ�α����󲽳�����
        for (i = 0 + gap; i < len; i += 1) {   //��ÿ�����������ʱ������һ����������ٽ�����һ��������������ÿ������в�������
            temp = a[i];  //����a[i]��ֵ
            j = i - gap;  //j��ʼ��Ϊi��ǰһ��Ԫ�أ���i���gap���ȣ�
            while (j >= 0 && a[j] > temp) {
                a[j + gap] = a[j];  //����a[i]ǰ�ұ�temp��ֵ���Ԫ������ƶ�һλ
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
    duration=(double)(stop-start);//��λ��ms
    bool b=test(a);
    write_file2("ϣ������",a,duration,b);
}
