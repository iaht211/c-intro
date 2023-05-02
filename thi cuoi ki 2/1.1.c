#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//cau truc mon an hom nay 
struct mon{
    int stt;
    char name[255];
    int ton;
    double money;
};
typedef struct request {
    int ID ; // số thứ tự
    int order[8];
    long total; //tổng tiền
    struct request *next;
} Request;
//ham doc du lieu tu file 
struct mon *doc_file(const char *filename,int *n)
{
    FILE *f;
    f=fopen(filename,"r");
    int i=0;
    fscanf(f,"%d",n);
    struct mon *A = (struct mon*)malloc(sizeof(struct mon)*(*n));
    while(fscanf(f,"%d %s %d %lf",&A[i].stt,&A[i].name,&A[i].ton,&A[i].money)!=EOF)
    {
        i++;
    }
    fclose(f);
    return A;
}
void thuc_don(struct mon *A,int n)
{
    printf("\n%3s %15s %15s \t %8s ","ID","Ten mon","so luong mon","gia tien");
    for(int i=0;i<n;i++){
        if(A[i].ton>0)
        printf("\n%2d %15s %10d \t\t %.0lf ",A[i].stt,A[i].name,A[i].ton,A[i].money);
    }
}
//ham nhap vao cac mon order
void number_Order(int n,Request *a){
    
    for(int i=0;i<8;i++)
    {
        if(i<n){
            do{
                scanf("%d",&a->order[i]);
            }while(a->order[i]<0);
        }
        else a->order[i] = -1;
    }
}
//ham tinh tien 
void tinh_tien(struct mon *A,int n,Request *a)
{
    printf("\nnhap vao order : ");
    number_Order(n,a);
    double sum=0;
    for(int i=0;i<n;i++)
    {
        sum += ((double)A[i].money * (double)a->order[i]);
      //  printf("%.0lf %d = %lf   ",A[i].money,a->order[i]);
    }
    a->total = (long)sum;
    printf("\ntong tien la : %.0ld",a->total);
}
//tao node 
Request *makeNode(struct mon *A,int n){
    Request *a = (Request*)malloc(sizeof(Request));
    tinh_tien(A,n,a);
    for(int i=0;i<n;i++)
    {
        if(A[i].ton<a->order[i]) {
            printf("\nXin lỗi, nhà hàng không còn đủ suất ăn đáp ứng yêu cầu của quý khach .");
        return NULL;
        }
    }

    a->next = NULL;
    return a;
}
//ham them node vao dau danh sach 
void addNode(Request **head,Request *newNode)
{
    if(newNode==NULL) return;
    newNode->next = (*head);
    (*head) = newNode;
}
//ham in ra danh sach cac mon da order 
void printOrder(Request *head)
{
    printf("\ndanh sach cac mon da order thanh cong la : ");
    while(head!=NULL)
    {
        printf("\n");
        for(int i=0;i<8;i++)
        printf("%d \t",head->order[i]);

        head = head->next;
    }
}
//cap nhat lai danh sach con lai trong kho 
void cap_nhat(Request *head,struct mon *A,int n)
{
    if(head==NULL) return;
    Request *x=head;
   
        for(int i=0;i<n;i++)
        {
            A[i].ton -= head->order[i]; 
        }
     
   printf("\ndanh sach cac mon con lai trong kho la  : ");
        for(int i=0;i<n;i++)
        printf("%d \t",A[i].ton);
       
    
}
//ham in ra danh sach da order 
void thanh_toan(struct mon *A,Request *head,int n)
{
    int x=0;
    while(head!=NULL)
    {
        printf("\ndon hang so %d",x);
        printf("\n%15s %10s %10s","Món đã chọn"," Số lượng","Thành tiền");
        for(int i=0;i<n;i++)
        {
            printf("\n%10s \t %5d \t\t %.0lf",A[i].name,head->order[i],(double)head->order[i]*A[i].money);
        }
        printf("\ntong tien don la: %ld",head->total);
        x++;
        head=head->next;
    }
}
//ham giai phong bo nho 
void xoa(Request **head)
{
    Request *p;
    while((*head)!=NULL)
    {
        p=*head;
        (*head) = (*head)->next;
        free(p);
    }
    (*head)=NULL;
}
//ham tim mon an ua thich nhat
void likest(struct mon *A,int n,struct mon *tong)
{
    
    for(int i=0;i<n;i++)
    {
        tong[i].ton = tong[i].ton - A[i].ton;
    }
    struct mon like = tong[0];
    for(int i=0;i<n;i++)
    {
        if(tong[i].ton>like.ton) like = tong[i];
    }
    for(int i=0;i<n;i++){
        if(tong[i].ton==like.ton)
    printf("\nmon an duoc ua thich nhat la :%s duoc goi %d lan",like.name,like.ton);

    }
    
    
}
int main()
{
    int n;
    struct mon *danh_sach=doc_file("thucdontheongay.txt",&n);
    
    int key;
    Request *head = NULL,*newNode;
    do{
        printf("\n-------MENU--------");
        printf("\n1.doc file va in ra");
        printf("\n2.1 a) In ra tổng số tiền phải trả cho order");
        printf("\n2.2 b) Cập nhật số lượng tồn cho mỗi món ăn sau khi nhận order");
        printf("\n3. Thông tin tất cả order");
        printf("\n4. Món ăn ưa chuộng nhất");
        printf("\n5. Thoát.");
        printf("\nnhap vao lua chon : ");
        scanf("%d",&key);
        switch(key){
            case 1:
            thuc_don(danh_sach,n);
            break;
            case 21:
            Request a;
            tinh_tien(danh_sach,n,&a);
            break;
            case 22:
                newNode = makeNode(danh_sach,n);
                addNode(&head,newNode);
                printOrder(head);
                cap_nhat(head,danh_sach,n);
            break;
            case 3:
            thanh_toan(danh_sach,head,n);
            break;
            case 4:
            int x=0;
            struct mon *tong = doc_file("thucdontheongay.txt",&x) ;
            likest(danh_sach,n,tong);
            break;
            case 5:
            xoa(&head);
            return 0;
        }
    }while(1);
}