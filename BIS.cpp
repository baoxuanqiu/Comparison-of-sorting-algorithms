#include<stdio.h>
#include<time.h>
extern bool test(int *r);
extern int g_r[];
extern int g_n;
extern int write_file2(char *str,int *arr,double time,bool test);
extern clock_t start,stop;
extern double duration;

//��Ϊ��������������������������ֵһһ���뵽�������У��γɶ�̬����������
void BinaryInsertSort(int R[],int n)
{
    int i,j,low,mid,high,temp;
    for(i=1;i<n;i++)
    {
        low=0;
        high=i-1;//��i��Ԫ�ص�ǰһ��Ԫ��Ϊhigh
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
        for(j=i-1;j>=high+1;j--)    //high+1���Ԫ�غ���
        {
            R[j+1]=R[j];
        }
        R[j+1]=temp;    //��Ԫ�ز��뵽ָ��λ��
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
    duration=(double)(stop-start);//��λ��ms
    bool b=test(a);
    write_file2("�۰����",a,duration,b);

}


