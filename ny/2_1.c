/* Nhập vào họ tên 1 người, tách ra phần tên và in ra lời chào
“Joe Biden” --> Biden
“Elon” --> “Elon”
C1. Tìm dấu cách trống cuối và in ra các ký tự từ sau dấu cách trống
C2. Tách riêng phần tên khỏi họ tên (nếu muốn dùng tên nhiều lần )  */

#include <stdio.h>
#include <string.h>

int main() {
    char hoten[31];
    printf("Ho ten: ");
    gets(hoten);

    int pos=-1;
    for (pos=strlen(hoten); pos>=0; pos--) if (hoten[pos]==' ') break;

    //C1
    printf("Xin chao ");
    for (int i=pos+1; i<strlen(hoten); i++) putchar(hoten[i]);
    printf("\n");

    //C2
    char ten[31];
    int i;
    //cach 1: Copy tung ky tu sang bien ten
    for (i=pos+1; i<strlen(hoten); i++) ten[i-(pos+1)] = hoten[i];
    ten[i-(pos+1)] = '\0'; //bao hieu ket thuc xau
    printf("Xin chao %s\n", ten);
    //cach 2: dung strcpy
    strcpy(ten, hoten+pos+1); //strcpy(ten, &hoten[pos+1]);
    printf("Xin chao %s\n", ten);

    return 0;
}