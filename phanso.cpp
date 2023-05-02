#include<stdio.h>
#include<math.h>
typedef struct {
	int tuso;
	int mauso;
	
}ps;
int rutgon(ps *a)
{
	int ucln=0;
	int x=abs(a->tuso);
	int y=abs(a->mauso);
	if(x==0)
	{
		ucln=x+y;
		
	}
	else if(x!=y)
	{
		while(x != y){
				if(x > y)
				x-=y;
				if(y > x)
				y-=x;
				ucln = x;
		}
	}
	a->mauso/=ucln;
	a->tuso/=ucln;
}
void nhap(ps *a)
{
	printf("nhap tu so: ");
	scanf("%d",&a->tuso);
	do{
		printf("nhap mau so: ");
		
		scanf("%d",&a->mauso);
	}while(a->mauso==0);
	//doan code chuyen doi phan so co mau so am
	if(a->mauso<0)
	{
		a->tuso*=-1;
		a->mauso*=-1;
	}
}

void xuat(ps a)
{
	rutgon(&a);
	printf("phan so da nhap la %d/%d\n",a.tuso,a.mauso);
}



int main()
{
	ps a1;
	while(true)
	{
	
	nhap(&a1);
	xuat(a1);

}
}
