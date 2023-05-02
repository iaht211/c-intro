#include<stdio.h>
#include<string.h>
typedef struct {
	int classid;
	char coursename[30];
	char room[10];
	int day;
	char slots[10];
}lop;

void nhap(lop &a)
{
	printf("nhap id:");
	scanf("%d",&a.classid);
	printf("nhap coursename:");
	fflush(stdin);
	fgets(a.coursename,sizeof(a.coursename),stdin);
	a.coursename[(strlen(a.coursename)-1)]='\0';
	printf("nhap room:");
	fgets(a.room,sizeof(a.room),stdin); fflush(stdin);
	a.room[(strlen(a.room)-1)]='\0';
	printf("nhap ngay:");
	scanf("%d",&a.day); fflush(stdin);
	printf("nhap slots: ");
	fgets(a.slots,sizeof(a.slots),stdin);
	a.slots[(strlen(a.slots)-1)]='\0';
	
}
void nhapdanhsach(lop a[],int n)
{
	printf("nhap vao lop thu %d\n",n+1);

		nhap(a[n]);
	
}
void xuatdanhsach(lop a[],int n)
{
	printf("\n%6s \t %15s \t %10s \t %5s \t %10s","ma lop","ten mon hoc","ten phong","thu", "tiet hoc");
	for(int i=0;i<n;i++)
	{
		printf("\n%6d \t %15s \t %10s \t %5d \t %10s",a[i].classid,a[i].coursename,a[i].room,a[i].day,a[i].slots);
	}
}
void sapxep(lop a[] , int n)
{
	lop tmp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].classid<a[j].classid)
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	printf("danh sach sau khi sap xep la\n");
	xuatdanhsach(a,n);
}
void timkiem(lop a[],int n,char ten[])
{
	int found=0;
	for(int i=0;i<n;i++)
	{
		if(strstr(a[i].room,ten))
		{
			a[found]=a[i];
			found++;
		}
	}
	if(found!=0)
	{
	printf("lop tim dc la :\n");
	xuatdanhsach(a,found);
	}
	if(found==0)
	printf("\nkhong ton tai phong %s trong danh sach\n",ten);
}
void xoatheoid(lop a[],int n,int id1 )
{
	int found=0;
	for(int i=0;i<n;i++)
	{
		
		if(a[i].classid==id1)
		{
			found=1;
			for(int j=i;j<n;j++)
			{
				a[j]=a[j+1];
			}
			n-=1;
		}
	}
	if(found ==0)
	printf("\nko ton tai lop co id :%d\n",id1);
	if(found==1)
	{
			printf("\ndanh sach sau khi xoa lop co id %d la \n",id1);
			xuatdanhsach(a,n);
	}

	
}


int main()
{
	int key;
	int n=0;
	lop ds[200];
	while(true)
	{
		printf("\n----------MENU-------------\n");
		printf("1.them lop hoc \n");
		printf("2.in lop hoc\n");
			printf("3.sap xep lop hoc theo ma lop tang dan\n");
		printf("4.tim kiem theo lop\n");
	printf("5.xoa theo id\n");
		printf("nhap vao key:");
		fflush(stdin);
		scanf("%d",&key);
		switch(key)
		{
			case 1:
				nhapdanhsach(ds,n);
				n++;
				break;
			case 2:
				xuatdanhsach(ds,n);
				break;
			case 3:
				sapxep(ds,n);
				break;
			case 4:
				char ten[10];
				printf("nhap vao phong can tim:");
				fflush(stdin);
				fgets(ten,sizeof(ten),stdin);
				ten[(strlen(ten)-1)]='\0';
				timkiem(ds,n,ten);
				break;
				case 5:
				int id1;
				printf("\nnhap vao id can xoa :");
				scanf("%d",&id1);fflush(stdin);
				xoatheoid(ds,n,id1);
				fflush(stdin);
			case 0:
				printf("\nthoat chuong trinh !");
				return 0;
		}
	}
	
	
}
