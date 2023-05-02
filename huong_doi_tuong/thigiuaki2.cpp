#include<stdio.h>
#include<string.h>
typedef struct {
	char id[20];
	int dai,rong,cao;
	int loai;
}hang;
void nhap(hang &a)
{
	printf("\nid:");
	fflush(stdin);
	fgets(a.id,sizeof(a.id),stdin);
	a.id[(strlen(a.id)-1)]='\0';
	printf("\ndai:");
	scanf("%d",&a.dai);
	printf("\nrong:");
	scanf("%d",&a.rong);
	printf("\ncao");
	scanf("%d",&a.cao);
	do{
	printf("\nloai van chuyen:");
	scanf("%d",&a.loai);	
	}while(a.loai<0||a.loai>1);
	
}
void nhapdanhsach(hang a[],int x,int y)
{
	for(int i=x;i<y;i++)
	{
	nhap(a[i]);
	}
}
void 


int main()
{
	hang a[100];
	int key;
	int x=0,y=0;
	int n;
	int p;
	while(1)
	{
		printf("\n-------MENU-------");
		printf("\n1.nhap thong tin ");
		printf("\n2.chi tiet kien hang bi tu choi");
		printf("\n3.chi tiet kien hang hop le ");
		printf("\n4.tinh phis van chuyen");
		printf("\n5.thoat\n");
		printf("\nnhap vao lua chon : ");
		scanf("%d",&key);
		switch(key)
		{
			case 1:
				do{
				printf("nhap vao n:\n");
				scanf("%d",&n);
			     p=y+n;
				}while(p>100||p<1);
				x=y;
				y+=n;
				nhapdanhsach(a,x,y);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				printf("\nTHOAT!");
				return 0;
		}
	}
	
	
}
