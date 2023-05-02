#include<stdio.h>
void swap(int *a,int *b)
{
int tmp=*a;
*a=*b;
*b=tmp;
printf("ham sau hki hoan vi a=%d,b=%d\n",*a,*b);
}
int main()
{
int a,b;
scanf("%d%d",&a,&b);
printf("ham trc khi hoan doi a=%d b=%d\n",a,b);
printf("dia chi a=%p b=%p\n",&a,&b);
swap(&a,&b);
printf("a=%p\tb=%p",&a,&b);
}
