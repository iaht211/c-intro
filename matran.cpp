#include<stdio.h>
void nhap(int a[100][100],int &n,int &m )
{
	printf("nhap vao n m:\n");
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void xuat(int a[100][100],int n,int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		printf("%d",a[i][j]);
		printf("\n");
	}
}
void  timkiem(int a[100][100],int n,int m)
{
	int giatri;
	printf("\nnhap vao gia tri can tim");
	scanf("%d",&giatri);
	int count=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==giatri)
			count++;
		}
	}
	printf("\nco %d gia tri can tim ",count);
}

void tbc(int a[100][100],int n,int m)
{
	double tb=0;
	int tong=0;
for(int i=0;i<m;i++)
{
	for(int j=0;j<n;j++)
	{
		tong+=a[i][j];
	}
}
	tb=(double)tong/(n*m);
	printf("\ntrung bing la :%lf",tb);
}
int dk(int n)
{
    if(n==0)
    return 0;
    else if(n%5==0)
    return 1;	
}
void tim(int a[100][100],int n,int m)
{
	int tong=0;
	int count=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dk(a[i][j])==1)
			{
				tong+=a[i][j];
				count++;
			}
			
		}
	}
	double trungbinh=0;
	trungbinh=(double)tong/count;
	printf("\ntrung binh cong la :%lf",trungbinh);
}
void maxmin(int a[100][100],int n,int m)
{
	int max=a[0][0];
	int min=a[0][0];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
	    {
	     if(a[i][j]>max)
		 max=a[i][j];
		 if(a[i][j]<min)
		 min=a[i][j];	
		}
	}
	printf("\nmax la : %d\nmin la :%d",max,min);
	
}
void maxdong(int a[100][100],int n,int m)
{
	
}

int main()
{
	int a[100][100];
	int n,m;
	nhap(a,n,m);
	xuat(a,n,m);
//	timkiem(a,n,m);
 //   tbc(a,n,m);
   // tim(a,n,m);
  // maxmin(a,n,m);
	
}
