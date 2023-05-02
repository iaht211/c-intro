/* Nhập nhiều giá trị từ bàn phím?
•	Dùng vòng lặp
•	Trong vòng lặp chỉ có scanf, KHÔNG thêm printf
•	Dữ liệu được chuẩn bị từ file text
•	Dữ liệu cách nhau ít nhất bởi 1 dấu cách trống hoặc ENTER */

/* demo nhap nhieu gia tri tu ban phim */
#include <stdio.h>

int main() {
    double A[30];
    int i;
    //printf("Nhap vao 30 gia tri: ");
    //for (int i=0; i<30; i++) scanf("%lf", &A[i]);

    FILE *f;
    f = fopen("text.txt", "r");
    while (!feof(f)) 
    for (i=0; i<30; i++) fscanf(f, "%lf", &A[i]);

    printf("Gia tri vua nhap: \n");
    for (i=0; i<30; i++) printf("%.2lf ", A[i]);

    fclose(f);
    return 0;
}