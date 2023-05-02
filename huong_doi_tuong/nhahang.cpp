#include<stdio.h>
#include<string.h>
typedef struct {
	char name[30];
 char description[500];
	int rating;
	char address[100];
}mon;

void nhap(mon &a)
{

	printf("\nname :");
	fflush(stdin);fgets(a.name,sizeof(a.name),stdin);
    
	printf("description: ");
	fgets(a.description,sizeof(a.description),stdin);
	do{
			printf("rating :");
	scanf("%d",&a.rating); fflush(stdin);
	}while(a.rating<0&&a.rating>5);

	printf("address:");
	fgets(a.address,sizeof(a.address),stdin);
	
}
void nhapdanhsach(mon a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nnha hang %d",i+1);
		nhap(a[i]);
	}
}
 void xuatdanhsach(mon a[],int n)
 {
 		
 	for(int i=0;i<n;i++)
 	{
 		printf("\n\nnha hang %d ",i+1);
 		printf("\nname :%s",a[i].name);
 		printf("description: %s",a[i].description);
 		printf("rating :%d",a[i].rating);
 		printf("\naddress:%s",a[i].address);	 
    }
}
void timkiemtheoten(mon a[],int n, char ten[])
{
	int found=0;
	for(int i=0;i<n;i++)
	{
		if(strstr(a[i].name,ten))
		{
			
			a[found]=a[i];
			printf("nha hang can tim la \n");
		found++;
		}
	}
		xuatdanhsach(a,found);
}
void timkiemtheomota(mon a[],int n,char ten1[])
{
int found=0;
	for(int i=0;i<n;i++)
	{
		if(strstr(a[i].description,ten1))
		{
			
			a[found]=a[i];
            found++;
		}
	}
	printf("nha hang can tim la \n");
		xuatdanhsach(a,found);
}

int main()
{
	int key;
	mon ds[30];
	int n=0;
printf("\n-----------MENU-------------\n");
printf("1.nhap thong tin nha hang\n");
printf("2.in thong tin nha hang \n");
printf("3.tim kiem theo ten \n");
printf("4.tim kiem theo mo ta \n");
printf("5. sap xep theo ten\n");
printf("6.nhap them nha hang\n");
printf("0. thoat!\n");

	while(true)
{	
printf("\nnhap vao yeu cau:");
scanf("%d",&key);
switch(key)
{
	case 1:
		do{
		printf("nhap vao so luong cua hang:");
		scanf("%d",&n);
		}while(n<1);
		nhapdanhsach(ds,n);
		break;
	case 2:
		xuatdanhsach(ds,n);
		break;
	case 3:
		char ten[30];
		printf("\nnhap ten :");
		fflush(stdin);
		fgets(ten,sizeof(ten),stdin);
	
		timkiemtheoten(ds,n,ten);
	break;
	case 4:
	char ten1[30];
	printf("\nnhap vao ki tu:");
	fflush(stdin);
	gets(ten1);
	timkiemtheomota(ds,n,ten1);
	break;
	case 5:
		break;
	case 0:
		break;
}
}
	
}
