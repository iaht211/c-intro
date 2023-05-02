#include<stdio.h>
#include<string.h>
//ham dem ki tu co trong day
//strlen ko dem \0 nhg se dem ki tu \n o cuoi dong neu nhap vao tu ban phim
//con neu la a[30]="..." thi se ko co \n o cuoi nen strlen se dem dung 
//chu y char a[] thi a bat dau tu a[0]
int dem(char a[])
{
	int count=0;
	while(a[count]!='\0')
	{
		count++;
	}
	return count;
}
void xoa(char a[])
{
	int count=0;
	if(a[strlen(a)-1]=='\n')
	a[strlen(a)-1]='\0';
}
int main()
{
	char name[30];
	printf("nhap vao te tu ban phim:");
	fgets(name,sizeof(name),stdin);
	xoa(name);
	printf("ten la :%s\n",name);
	printf("so ki tu khi dem  bang strlen la %d\n",strlen(name));
	printf("so ki tu dem bang ham dem la :%d",dem(name));
	char a[30]="a";
	printf("\n so ki tu trong a la :%d",strlen(a));
}
