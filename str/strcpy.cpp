#include<stdio.h>
#include<string.h>
void copy(char a[],char b[])
{
//copy tu a sang b
size_t x=strlen(a);
size_t y=strlen(b);
	for(int i=0;i<x;i++)
	b[i]=a[i];
b[x]='\0';
}
int main()
{
char a[20];
char b[20];
printf("nhap 2 chuoi :");
fgets(a,sizeof(a),stdin);
copy(a,b);
printf("chuoi b la :%s",b);

}
