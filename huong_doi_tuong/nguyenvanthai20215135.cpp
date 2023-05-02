#include<stdio.h>
#include<string.h>
typedef struct {
	char ma[20];
	float dai;
	float rong;
	float cao;
	float nang;
	int loai;
	int  maloi1=0;
	int maloi2=0;
	int  maloi3=0;

}hang;
 
void nhap(hang &a)
{
	
	
		printf("\nnhap ma :");
	fflush(stdin);	fgets(a.ma,sizeof(a.ma),stdin);
	a.ma[(strlen(a.ma)-1)]='\0';
	fflush(stdin);
	
	
	printf("nhap dai:");
	scanf("%f",&a.dai);
	printf("nhap rong :");
	scanf("%f",&a.rong);
	printf("nhap cao");
	scanf("%f",&a.cao);
	printf("nhap can nang :");
	scanf("%.2f",&a.nang);
	fflush(stdin);
	do{
		printf("loai van chuyen:");
		scanf("%d",&a.loai);
	}while(a.loai<0 || a.loai>1);
      if(a.cao<10&&a.dai<10&&a.rong<10)
      a.maloi1=1;
	 if(a.cao>150&&a.dai>150&&a.rong>150)
	 a.maloi2=2;
	 if(a.nang>30);
	 a.maloi3=3;
	 
}
void nhapdanhsach(hang a[],int n)
{
	
	for(int i=0;i<n;i++)
	{
		nhap(a[i]);
	}
	
}
void donloi(hang a[],int n)
{
	int found=0;
	printf("\n chi tiet kien hang bi tu choi");
	printf("\n===============================");
	printf("\n%10s \t %15s","ma kien","ly do tu choi");
	for(int i=0;i<n;i++)
	{
		if(a[i].maloi1==1)
		{
			printf("\n%10s \t %s",a[i].ma,"ER1");
			
			
		}
	else if(a[i].maloi2==2)
		{
			printf("\n%10s \t %s",a[i].ma,"ER2");
			
			
		}
	else if(a[i].maloi3==3)
		{
			printf("\n%10s \t %s",a[i].ma,"ER3");
			
		}
	if(a[i].maloi1==1||a[i].maloi2==2||a[i].maloi3==3)
		found++;
		
	}
	printf("\ntong so la %d",found);
	
}
void tinh_trong_luong(hang a[],int n)
{
	printf("\ntinh trong luong quy doi \n");
	for(int i=0;i<n;i++)
	{
		float nhanh = (a[i].dai * a[i].rong * a[i].cao)/6000;
		float thuong = (a[i].dai *a[i].rong* a[i].cao)/4000;
		if((a[i].dai+a[i].rong+a[i].cao)<80)
		{
			printf("so kg la : %f",a[i].nang);
		}
		else{
			if(a[i].loai ==1)
			printf("so kg la %f",nhanh);
			if(a[i].loai ==0)
			printf("so kg la %f",thuong);
		}
	}
}
int main()
{
	int n;
	int key;
	hang ds[100];
do{
		
	printf("nhap vao so hang :");
	scanf("%d",&n);
}while(n<1||n>100);
	
	printf("\n----------MENU----------\n");
	printf("\n1.nhap vao thong tin");
	printf("\n2.chi tiet don hang bi tu choi");
	printf("\n3.chi tiet din hang hop le ");
	printf("\n4.tinh toan van chuyen ");
	printf("\n5.thoat");
	while(true)
	{
		printf("\nnhap vao yeu cau:");
		scanf("%d",&key);
		switch(key)
		{
			case 1:
				nhapdanhsach(ds,n);
				break;
			case 2:
				donloi(ds,n);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
			    printf("\nthoat!");
			    return 0;
		}
	}
}
