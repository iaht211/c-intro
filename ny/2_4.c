/* Truyền vào địa chỉ tham số gốc thông qua con trỏ
(mọi bản copy của địa chỉ đểu trỏ tới 1 vùng nhớ duy nhất của tham số gốc) */

#include <stdio.h>
void swap1(int a, int b) {
    int c=a;
    a=b;
    b=c;
    printf("Trong ham a=%d, b=%d\n", a, b);
}

void swap2(int *a, int *b) {
    int c=*a;
    *a=*b;
    *b=c;
    printf("Trong ham a=%d, b=%d\n", a, b);
}

int main() {
    int x=5, y=7;
    printf("Truoc goi ham x=%d, y=%d\n", x, y);
    //swap1(x, y);
    swap2(&x, &y);
    printf("Sau goi ham x=%d, y=%d\n", x, y);
    return 0;
}