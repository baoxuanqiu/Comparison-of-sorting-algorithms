#include<stdio.h>
#include<stdlib.h>

extern int g_n;
extern int g_r[];

int write_file1(){
    FILE *fd=fopen("c:\\codeblocks\\���������㷨�ıȽ�\\���������㷨�ıȽ�.txt","awb");
    if(fd==NULL){
        printf("�ļ���ʧ�ܣ�");
        exit(1);
    }
    fprintf(fd,"\n%s\t\t","ԭ�����");
    fprintf(fd,"%d\n",g_r[0]);
    for(int j=1;j<g_n;j++){
        fprintf(fd,"\t\t%d\n",g_r[j]);
    }
    fprintf(fd,"%s\n","-------------------------------------------------------------------------------------------------------------");
    fprintf(fd,"%s\t\t","�����㷨");
    fprintf(fd,"%s\t\t","�����������");
    fprintf(fd,"%s\t\t","�����㷨����ʱ��");
    fprintf(fd,"%s\n","��������");
    fprintf(fd,"%s\n","-------------------------------------------------------------------------------------------------------------");
    fclose(fd);
        return 0;
}

int write_file2(char *str,int *arr,double time,bool test){
    FILE *fd=fopen("c:\\codeblocks\\���������㷨�ıȽ�\\���������㷨�ıȽ�.txt","awb");
    if(fd==NULL){
        printf("�ļ���ʧ�ܣ�");
        exit(1);
    }
    fprintf(fd,"%s\t\t",str);
    fprintf(fd,"%d\t\t\t",arr[0]);
    fprintf(fd,"%lf%s\t\t",time,"ms");
    fprintf(fd,"%s\n",test==true?"True":"False");
    for(int j=1;j<g_n;j++){
        fprintf(fd,"\t\t%d\n",arr[j]);
    }
    fprintf(fd,"%s\n","-------------------------------------------------------------------------------------------------------------");
    fclose(fd);
        return 0;
}
