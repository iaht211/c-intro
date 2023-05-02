/* Con trỏ */

#include <stdio.h>

int main() {
    char c1, *pCh;
    int a1, a2, *pint, *p2;
    float f1;
    double f2, x1, *pdb;
    printf("Địa chỉ ô nhớ cấp phát cho c1: %#X\n", &c1);
    printf("Địa chỉ ô nhớ cấp phát cho a1: %#X\n", &a1);
    printf("Địa chỉ ô nhớ cấp phát cho a2: %#X\n", &a2);
    printf("Kích thước vùng nhớ của c1: %d\n", sizeof(c1));
    printf("Kích thước vùng nhớ của a1: %d\n", sizeof(a1));
    printf("Kích thước vùng nhớ của a2: %d\n", sizeof(a2));
    c1 = 'C';
    printf("Giá trị của biến c1: %d\n", c1);

    printf("Địa chỉ vùng nhớ của pCh: %#X\n", &pCh);
    printf("Địa chỉ vùng nhớ của pint: %#X\n", &pint);
    printf("Địa chỉ vùng nhớ của p2: %#X\n", &p2);
    printf("Địa chỉ vùng nhớ của pdb: %#X\n", &pdb);
    printf("Kích thước của biến pCh: %d\n", sizeof(pCh));
    printf("Kích thước của biến pint: %d\n", sizeof(pint));
    printf("Kích thước của biến p2: %d\n", sizeof(p2));
    printf("Kích thước của biến pdb: %d\n", sizeof(pdb));
    pint = &a1;
    a1 = 5;
    printf("Địa chỉ vùng nhớ của a1: %#X\n", &a1);
    printf("Địa chỉ vùng nhớ mà pint đang trỏ tới: %#X\n", pint);
    printf("Giá trị vùng nhớ mà pint đang trỏ tới: %d\n", *pint);
    *pint = 1234;
    printf("a1 = %d\n", a1);
    return 0;
}