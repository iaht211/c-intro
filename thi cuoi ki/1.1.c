#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct mon{
    int stt;
    char name[255];
    int ton;
    double money;
};
typedef struct request{
    int ID ; // số thứ tự
    int order[8];
    double total; //tổng tiền
    struct request *next;
}Request;
int n;
struct mon *docFile(const char *filename){
   
    FILE *f;
    f=fopen(filename,"r");
    struct mon *A = (struct mon *)malloc(sizeof(struct mon)*8);

    fscanf(f,"%d",&n);
    int i=0;
    while(fscanf(f,"%d %s %d %ld\n",&A[i].stt,&A[i].name,&A[i].ton,&A[i].money)!=EOF){
        i++;
    }
    fclose(f);
    return A;
}
void printArr(struct mon *A,int size)
{
    printf("\nDanh sach mon an :\n");
    printf("%3s\t%15s\t%10s%6s\n","ID","ten mon","so luong mon ","gia tien");
    for(int i=0;i<size;i++)
    {
        if(A[i].ton>0)
        printf("%3d\t%15s\t%10d%10ld\n",A[i].stt,A[i].name,A[i].ton,A[i].money);
    }
}
//ham nhap vao so mon an ma khach lay
void slg(Request *a)
{
    
    for(int i=0;i<8;i++)
    {
        if(i<n){//neu nam trong danh sach mon 
            do{
                scanf("%d",(&a->order[i]));
            }while(((a)->order[i])<0);//nhap lai cho den khi slg thoa man thi thoi 
        }
        else ((a)->order[i])=-1;//neu ko nam trong danh sach mon 
    }
}
//tinh tien khach phai tra khi order 


void totalMoney(struct mon *A)
{
    Request a;
    slg(&a);
    double sum=0;
    for(int i=0;i<n;i++)
    {
        printf("%d %ld %lf",a.order[i],A[i].money,sum);
        sum += ((double)a.order[i] * A[i].money);
    }

    printf("\ntong tien cho don la : %lf",sum);
}


int main()
{
    struct mon *A;
    int key;
    do{
        printf("\n1.doc va hien thi file");
        printf("\n2.Nhận Order");
        printf("\n2.1) In ra tổng số tiền phải trả cho order");
        printf("\n2.2) Cập nhật số lượng tồn cho mỗi món ăn sau khi nhận order");
        printf("\n3. Thông tin tất cả order");
        printf("\n4. Món ăn ưa chuộng nhất");
        printf("\n5. Thoát.");
        printf("\nnhap vao lua chon :");
        scanf("%d",&key);
        switch(key){
            case 1:
            A = docFile("1.1.txt");
            printArr(A,n);
            break;
            case 21:
            totalMoney(A);
            break;
            case 22:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            return 0;
        }
    }while(1);
}