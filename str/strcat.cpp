#include<stdio.h>
#include<string.h>
void xoa(char a[])
{
	int x=strlen(a);
	if(a[x-1]=='\n')
	a[x-1]='\0';
}
void ghep(char a[],char b[])
{
	size_t x=strlen(a);
	size_t y=strlen(b);
	size_t z =sizeof(a);
	if(x+y+1>z)
	printf("loi ko du bo nho!\n");
	else
	{
		for(int i=x;i<x+y;i++)
		a[i]=b[i-y];
	}
}
int main()
{
char a[30];
char b[10];
int x;
scanf("%d",&x);
getchar();
printf("nhap vao 2 chuoi:\n");
fgets(a,sizeof(a),stdin);
xoa(a);
fgets(b,sizeof(b),stdin);
xoa(b);
//printf("ghep 2 chuoi vao : %s\n",strcat(a,b));
//ghep chuoi b vao chuoi a 
printf("a: %s\n",a);
printf("b: %s \n",b);
ghep(a,b);
printf("ghep 2 chuoi %s",a);

}
