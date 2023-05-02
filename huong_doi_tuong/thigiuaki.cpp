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
	printf("\nnhap classid:");
	scanf("%d",&a.classid);
	printf("\ncourse:");
	fflush(stdin);
    fgets(a.coursename,sizeof(a.coursename),stdin);
    a.coursename[(strlen(a.coursename)-1)]='\0';
	printf("\nroom:");
	fgets(a.room,sizeof(a.room),stdin);
	a.room[(strlen(a.room)-1)]='\0';
do{
	printf("\nday:");
	scanf("%d",&a.day);
}while(a.day<1||a.day>7);

	
	fflush(stdin);
	printf("\nslots:");
	fgets(a.slots,sizeof(a.slots),stdin);
	a.slots[(strlen(a.slots)-1)]='\0';	
}
void nhapdanhsach(lop x[],int b ,int a )
{
 for(int i=a;i<b;i++)
{
	nhap(x[i]);
}
}

void xuatdanhsach(lop a[],int n)
{
		printf("\n%10s \t %20s \t %15s \t %6s \t %10s ","ma lop","ten mon hoc","ten phong","thu","tiet hoc");
	for(int i=0;i<n;i++)
	{
		printf("\n%10d \t %20s \t %15s \t %6d \t %10s ",a[i].classid,a[i].coursename,a[i].room,a[i].day,a[i].slots);
	}

}

void sapxep(lop a[],int n)
{
	lop l;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].classid>a[j].classid)
			{
				l=a[i];
				a[i]=a[j];
				a[j]=l;
			}
		}
	}
}
void timkiem(lop a[],int n)
{
char ten[10];
int found=0;
lop mangtk[100];
printf("nhap ten can tim:");
fflush(stdin);
fgets(ten,sizeof(ten),stdin);
ten[(strlen(ten)-1)]='\0';
for(int i=0;i<n;i++)
{
	if(strstr(a[i].room,ten))
	{
	mangtk[found]=a[i];
	found++;	
	}
	else printf("\n phong ko ton tai");
	
}
xuatdanhsach(mangtk,found);
}
int main()
{
	int key;
	lop x[200];
		int a=0,b=0;
while(1){
	printf("\n_______MENU__________");
	printf("\n1.nhap vao hs");
	printf("\n2.xuat thong tin ");
	printf("\n3.sap xep");
	printf("\n4.tim kiem ");
	printf("\n5.");
	printf("\n6 exit.");
		printf("\nchon chuc nang :");
		scanf("%d",&key);
		switch(key)
		{
			case 1:
				int n;
				printf("\nnhap vao n=");
				scanf("%d",&n);
				a=b;
				b+=n;
				nhapdanhsach(x,b,a);
				break;
			case 2:
			
				xuatdanhsach(x,b);
				break;
			case 3:
				sapxep(x,b);
				break;
			case 4:
				timkiem(x,b);
				break;
			case 5:
				break;
			case 6:
				return 0;
		}	
}
}

