#include<stdio.h>
#include<string.h>
void viethoa(char a[])
{
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>=97&&a[i]<=122)
		a[i]=a[i]-32;
	}
}
void vietthuong(char a[])
{
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>=65&&a[i]<=90)
		a[i]=a[i]+32;
	}
}
int main()
{
	char a[30];
	printf("nhap vao chuoi a :");
	fgets(a,sizeof(a),stdin);
	printf("chuoi cua nhap :%s\n",a);
	viethoa(a);
	//strupr(a);
	printf("chuyen sang chuoi viet hoa la :%s\n",a);
//	strlwr(a);
vietthuong(a);
	printf("chuyen sang chuoi viet thuong la %s",a);
}
