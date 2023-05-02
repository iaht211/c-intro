#include<stdio.h>
#include<string.h>
int cmp(char a[],char b[])
{
	int kq=0;
	size_t x=strlen(a);
	size_t y=strlen(b);
	size_t min= x<y?x:y;
	for(int i=0;i<min;i++)
	{
		kq=a[i]-b[i];
		if(kq!=0)
		break;
	}
	return kq;
}
int main()
{
	char a[30];
	char b[30];
	printf("nhap vao 2 chuoi:\n");
	fgets(a,sizeof(a),stdin);
	fgets(b,sizeof(b),stdin);
	printf("so sanh 2 chuoi a b la:%d\n",cmp(a,b));
	printf("so sanh a b :%d",strcmp(a,b));
}
