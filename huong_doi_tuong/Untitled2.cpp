#include<stdio.h>
void nhap(int a[],int n)
{
int i;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
}
void xuat(int a[], int n){
    for(int i=0;i<n;i++){
        printf("%5d",a[i]);
    }
}
 
//Ham sap xep thu nhat su dung bien trung gian
void SortUp(int a[], int n){
    int Mid;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++){
            if(a[j]<a[i]){
                Mid=a[i];
                a[i]=a[j];
                a[j]=Mid;
            }
        }
    printf("\nMang sau khi sap xep:\n");
    xuat(a,n);
}
int main(){
    int a[100];
    int n;
    nhap(a,n);
    SortUp(a,n);
    xuat(a,n);
    return 0;
}

