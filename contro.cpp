#include<stdio.h>
/*
doi voi con tro thi :
1,%#X la ki hieu dia chi cua o nho dau tien ma co tro tro toi hay dia chi vung nho bien con tro 
2,%p la ki hieu dia chi  cua bien con tro 
*/
int main()
{
    char c1,*pch;
    int a1,a2,*p2;
    float f1;
    double f2,*pdb;
    printf("dia chi o nho cap phat cho c1:%#X\n",&c1);
    printf("\ndia chi o nho cap phat cho c1: %#X",&c1);
    
    printf("\ndia chi o nhow cap phat cho a1:%#X",&a1);
    printf("\ndia chi o nhow cap phat cho a1:%p",&a1);
    printf("\ndia chi o nhow cap phat cho a2:%#X",&a2);

printf("\nkich thuoc vung nho cua c1:%d",sizeof(f2));
printf("\ndia chi vung nho cua pch: %#X",&pch);
printf("\ndia chi vung nho dau tien cua p2 :%#X",&p2);

}


