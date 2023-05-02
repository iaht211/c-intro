/* Nhập vào giá mở cửa và đóng cửa của 1 mã CK trong 30 ngày gần nhất
Hãy tính và in ra màn hình 
1.	Ngày biến động nhiều nhất (giá mở cửa và đóng cửa chênh nhau nhiều nhất)
2.	Tìm và in ra chuỗi ngày có giá mở cửa tăng dài nhất*/

#include <stdio.h>
#include <math.h>

int main() {
    double gia_mo[30], gia_dong[30];
    int i;
    printf("Nhap vao gia mo va dong cua ma CK trong 30 ngay: \n");

    for (i=0; i < 30; i++) {
        scanf("%lf", &gia_mo[i]);
        scanf("%lf", &gia_dong[i]);
    }
    
    //in ra de check
    printf("Gia CK trong 30 ngay: \n");
    for (i=0; i<30; i++)
        printf("Mo: %.2lf | Dong: %.2lf\n", gia_mo[i], gia_dong[i]);
    
    //tim ngay chenh lech nhieu nhat
    int ngay_lech_max = 0;
    double chech_lech_max = fabs(gia_mo[0] - gia_dong[0]);
    for (i=1; i<30; i++) {
        if (fabs(gia_mo[i] - gia_dong[i]) > chech_lech_max) {
            chech_lech_max = fabs(gia_mo[i] - gia_dong[i]);
            ngay_lech_max = i;
        }
    }
    printf("Ngay chenh lech nhieu nhat la %d\n", ngay_lech_max);
    printf("Gia mo: %.2lf | Gia dong: %.2lf = Chenh lech: %.2lf\n", gia_mo[ngay_lech_max], gia_dong[ngay_lech_max], fabs(gia_mo[ngay_lech_max] - gia_dong[ngay_lech_max]));

    //tim chuoi ngay co gia mo tang dai nhat
    int max_i = 0, max_len = 1, len, j;
    for (i=0; i<30; i++) {
        len = 1;
        for (j=i; j<30; j++) {
            if (gia_mo[j] < gia_mo[j+1]) len++;
            else break; //het doan tang tu i
        }
        if (len>max_len) {
            max_len = len;
            max_i = i;
            i = j; //cap nhat lai vi tri moi cua i
        }
    }

    printf("Chuoi ngay gia mo tang nhieu nhat: %d, tu ngay %d\n", max_len, max_i);
    for (i=max_i; i<max_i+max_len; i++) printf("%.2lf ", gia_mo[i]);
    printf("\n");

/* Mở rộng bài toán mã CK
1.	Tìm và in ra ngày có giá đóng cửa bị tụt/giảm nhiều nhất so với ngày liền trước (chỉ quan tâm tới giá đóng cửa)
2.	Tìm và in ra những ngày có giá đóng cửa cao hơn giá mở cửa trên 1%
<Giá đóng> - <giá mở>  > 1% * <giá mở>
3.	Tìm và in ra những ngày có giá đóng cửa dưới giá trung bình giá mở cửa của 30 ngày */

    return 0;
}