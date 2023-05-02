/* Cho danh sách họ tên sinh viên trong lớp (lớp tối đa 45 sinh viên)
Hãy viết chương trình nhập vào họ tên các thành viên trong lớp
Sắp xếp và in ra danh sách theo thứ tự TÊN được sắp theo ABC
VD. Nguyen Van Hung, Le Thi Anh, Tran Quang Dung thì thứ tự sau khi sắp sẽ là
Le Thi Anh --> Tran Quang Dung --> Nguyen Van Hung

Gợi ý:
•	Dùng mảng xâu ký tự dạng DS[45][31];
•	Nhập vào từng họ tên dùng lệnh gets(DS[i])
•	So sánh
    	Tách ra tên và so sánh dùng hàm strcmp()
    	Nên viết thành hàm so sánh
    	So sánh trực tiếp tên mà KHÔNG cần copy ra biến riêng? */

#include <stdio.h>
#include <string.h>

int compareName(char *hoten1, char *hoten2) {
    int pos1;
    for (pos1=strlen(hoten1)-1; pos1>=0; pos1--) {
        if (hoten1[pos1]==' ') break;
    }

    int pos2;
    for (pos2=strlen(hoten2)-1; pos2>=0; pos2--) {
        if (hoten2[pos2]==' ') break;
    }

    return strcmp(hoten1+pos1+1, hoten2+pos2+1);
}

int main() {
    char hoten1[31]="Joe Biden", hoten2[31]="Elon Musk";
    printf("%d\n", compareName(hoten1, hoten2));
    return 0;
}

//Sắp xếp danh sách
void sapxep(char DS[45][31], int n) {
    char tmp[31];
    for (int i=n; i>1; i--) {
        for (int j=1; j<i; j++) {
            if (strcmp(DS[j-1], DS[j])>0) {
                strcpy(tmp, DS[j-1]);
                strcpy(DS[j-1],DS[j]);
                strcpy(DS[j], tmp);
            }
        }
    }
}