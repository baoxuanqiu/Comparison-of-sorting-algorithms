#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

extern void BIS();
extern void Shell();
extern void Bubble();
extern void Quick();
extern void Heap();
extern void Merge();
extern int write_file1();
int g_n;
int g_r[10000];
clock_t start,stop;
double duration;

bool test(int *r){
    bool flag=true;
    for(int i=0;i<g_n-1;i++){
        if(r[i]>r[i+1]){
            flag=false;
            break;
        }
    }
    return flag;
}

int main()
{
    srand(time(NULL));
    printf("ÇëÊäÈëÄãÒªÅÅĞòµÄÊıÖµµÄÊıÁ¿");
    scanf("%d",&g_n);
    for(int i=0;i<g_n;i++){
        int x=rand();
        int y=rand();
        int z=x*y;
        while(z<20000){
            x=rand();
            y=rand();
            z=x*y;
        }
        g_r[i]=z;
    }
    write_file1();
    BIS();//ÕÛ°ë²åÈëÅÅĞò
    Shell();//Ï£¶ûÅÅĞò
    Bubble();//Ã°ÅİÅÅĞò
    Quick();//¿ìËÙÅÅĞò
    Heap();//¶ÑÅÅĞò
    Merge();//¹é²¢ÅÅĞò
    return 0;
}
