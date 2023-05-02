#include<stdio.h>
void slg(int *a)
{
    for(int i=0;i<8;i++)
    {
        if(i<7){//neu nam trong danh sach mon 
            do{
                scanf("%d",&a[i]);
            }while(a[i]<0);//nhap lai cho den khi slg thoa man thi thoi 
        }
        else a[i]=-1;//neu ko nam trong danh sach mon 
    }
}
int main()
{
    long a=13;
    double b=20000;
    int c=1;
    long d=12;
    a+=((long)b*c);
    a+=d;
    printf("%ld",a);
}