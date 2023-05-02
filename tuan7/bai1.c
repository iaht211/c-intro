#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
    char ms[10];
    char ten[250];
    char hang[100];
    int slg;
}sp;
struct linklist{
    sp data;
    struct linklist* next;
};
typedef struct linklist *Node;
//ham tao node 
Node makeNode(sp a)
{
    Node newNode=(Node)malloc(sizeof(struct linklist));
    newNode->next=NULL;
    newNode->data=a;
    return newNode;
}
 //ham chen vao vi tri duoc con tro p tro den 
 Node insertLast(Node head, sp value){
    Node temp,p;// Khai báo 2 Node tạm temp và p
    temp = makeNode(value);//Gọi hàm createNode để khởi tạo Node temp có next trỏ tới NULL và giá trị là value
    if(head == NULL){
        head = temp;     //Nếu linked list đang trống thì Node temp là head luôn
    }
    else{
        p  = head;// Khởi tạo p trỏ tới head
        while(p->next != NULL){
            p = p->next;//Duyệt danh sách liên kết đến cuối. Node cuối là Node có next = NULL
        }
        p->next = temp;//Gán next của thằng cuối = temp. Khi đó temp sẽ là thằng cuối(temp->next = NULL mà)
    }
    return head;
}
 //ham xuat du lieu hien tai
 void printfList(Node head)
 {
    //int count =0;
    printf("\ndanh sach hien tai\n");
    //printf("\n%10s%30s%10s%10s","stt");
    for(Node p=head;p!=NULL;p=p->next)
    {
        printf("%10s%30s%10s%10d\n",p->data.ms,p->data.ten,p->data.hang,p->data.slg);
    }
    printf("\n----------\n");

 }
 //ham tach du lieu tu tap tin
 sp tach(char *line)
 {
    sp a;
    const char delimiter[] = "-";
    char *tmp;
    tmp = strtok(line,delimiter);
    if(tmp == NULL)
    {
        printf("Du lieu khong dung dinh dang: %s", line);
        exit(EXIT_FAILURE);
    }
    strcpy(a.ms,tmp);
    int count=0;
    for(;;count++)
    {
        tmp = strtok(NULL,delimiter);
        if(tmp==NULL) break;
        if(count==0) strcpy(a.ten,tmp);
        else if(count==1) strcpy(a.hang,tmp);
        else if(count==2) a.slg=atoi(tmp);
        else {
             printf("Du lieu khong dung dinh dang: %s", line);
            exit(EXIT_FAILURE);
        }
    }
     return a;
 }
 //ham doc du lieu tu t ap tin
 Node readData(Node head,char *filename)
 {
    FILE *file=fopen(filename,"r");
    if(!file){
         printf("Co loi khi mo file : %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char line[500];
    while(fgets(line,sizeof(line),file)){
        sp a=tach(line);
        head=insertLast(head,a);
    }
    fclose(file);
    return head;
 }
 //nhap vao 1 san pham
 sp nhap(){
    sp a;
    printf("\nnhap vao san pham :");
    fflush(stdin);
    gets(a.ms);
    gets(a.ten);
    gets(a.hang);
    fflush(stdin);
    scanf("%d",&a.slg);
    return a;
 }
 Node timkiem(Node head,char *ms){
    if(head == NULL) return NULL;
    if(strcmp(head->data.ms,ms)==0) return head;
    return timkiem(head->next,ms);
 }

 Node bo_sung(Node head){
    sp a;
    a=nhap();
    Node p=timkiem(head,a.ms);
    if(p==NULL)
    insertLast(head,a);
    else {
        p->data.slg+=a.slg;
    }
   // printfList(head);
    return head;

 }
 //xuat kho
 void xoa(Node *head,Node p){
    if((*head)==NULL) return;
    if((*head)==p)
    {
        p=*head;
        *head = (*head)->next;
        free(p);
    }
    else {
        Node pre = *head;
        while(pre->next!=p) pre = pre->next;
        pre->next = p->next;
        free(p);
    }

 }

 Node xuatkho(Node *head)
 {
    sp a;
    printf("\nnhap vao so luong de xuat\n");
    fflush(stdin);
    gets(a.ms);
    scanf("%d",&a.slg);
    Node p=timkiem(*head,a.ms);
    if(p==NULL) {
        printf("\nkhong tim thay ma hang ");
        //return NULL;
    }
    else{
        if(p->data.slg>a.slg)
        p->data.slg-=a.slg;
        else if(p->data.slg<a.slg)
        {
            printf("\n khong du de xuat");
        }
        else{
              xoa(head,p);
        }
    }
    return *head;
 }
 void ktra(Node head)
 {
    sp a;
    fflush(stdin);
    gets(a.ms);
    Node p=timkiem(head,a.ms);
    //p->next=NULL;
    if(p==NULL) {
        printf("\nkhong tim thay ma hang hoac da bn het ");
        return ;
    }
    else{
        if(p->data.slg>0)
        printf("%10s%30s%10s%10d\n",p->data.ms,p->data.ten,p->data.hang,p->data.slg);
        else {
            printf("\nhet hang ");
            //xoa(head,p);
            //printfList(*head);
        }
    }
 }
 /*void xoa(Node *head){
    Node p=(*head);
    while(p!=NULL){
        if(p->data.slg==0) break;
        p=p->next;
    }
    if((*head)==NULL) return;
    if((*head)==p)
    {
        p=*head;
        *head = (*head)->next;
        free(p);
    }
    else {
        Node pre = *head;
        while(pre->next!=p) pre = pre->next;
        pre->next = p->next;
        free(p);
    }
    
 }*/
 void xoa_hang(Node *head)
 {
    Node p=(*head);
    int count=0;
    while(p!=NULL)
    {
        if((p->data.slg)<=0) 
        {
            xoa(head,p);
           count++;
            break;
        }
        p=p->next;
    }
    if(count==0) return;
     xoa_hang(head);
 }
void printfList1(Node *head)
 {
     xoa_hang(head);
    int count =0;
    printf("\ndanh sach hien tai\n");
    printf("\n%10s%30s%20s\t%10s","stt","ten san pham","hang san xuat","so luong trong kho");
    for(Node p=(*head);p!=NULL;p=p->next)
    { 
        count++;
        printf("\n%10d%30s%20s\t%10d",count,p->data.ten,p->data.hang,p->data.slg);
    }
    printf("\n----------\n");

 }
 void ghiFile(Node head)
 {
    FILE *f=fopen("D:\\c\\tuan7\\b1out.txt","w");
    for(Node p=(head);p!=NULL;p=p->next)
    { 
        fprintf(f,"%s\n%s\n%s\n%d\n",p->data.ms,p->data.ten,p->data.hang,p->data.slg);
    }
    fclose(f);

 }
 int main()
 {
    Node head = NULL;
    head = readData(head,"D:\\c\\tuan7\\b1.txt");
    printfList(head);
    int key;
    while(1){
        printf("\n----------\n");
        printf("\n1.bo sung san pham");
        printf("\n2.xuat kho");
        printf("\n3.kiem tra san pham ");
        printf("\n4.in ra san pham ");
        printf("\n5.ghi danh sach vao file");
        printf("\nnhap vao yeu cau ");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            xoa_hang(&head);
            head=bo_sung(head);
            printfList(head);
            break;
        case 2:
            head=xuatkho(&head);
            printfList(head);
            break;
        case 3:
            ktra(head);
            break;
        case 4:
            printfList1(&head);
            break;
        case 5:
        ghiFile(head);
            break;
        }
    }
 }
