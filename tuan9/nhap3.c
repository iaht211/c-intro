#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next,*prev;
};
struct Node *h=NULL;//con tro chay 
//tao node moi
struct Node *makeNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
//them vao cuoi danh sach 
void insertLast(struct Node **head,int data)
{
    struct Node *newNode = makeNode(data);
    if((*head)==NULL){//neu list rong
        (*head) = newNode;
    }
    else{//neu khong rong thi them vao cuoi
       struct Node *p=(*head);
        while(p->next!=NULL)
        p=p->next;
        p->next=newNode;
        newNode->prev=p;
    }
    h=newNode;
}
void insertAfter(struct Node **head)
{
    int data;
    printf("nhap vao data\n");
    scanf("%d",&data);
    struct Node *newNode=makeNode(data);
    h->next=newNode;
    newNode->prev=h;
    struct Node *a=h;
    h=newNode;
    newNode=a;
    //gia phong sau h
    a=a->next;
    struct Node *b=a;
    while(b!=NULL)
    {
        free(a);
        b=b->next;
    }
}
void printfList(struct Node *head)
{
    
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
        if(head==h->next)
        break;
    }
    printf("\n");
}
void tien(struct Node **head)
{
    //neu mang ko co phan tu hoac dang o cuoi
    //them vao 
    int data;
    if((*head)==NULL||(h->next)==NULL)
    {
    printf("nhap vao url:");
    scanf("%d",&data);
    struct Node *newNode=makeNode(data);
    insertLast(head,data);
    }
    else{//neu dang o giua mang 
       printf("0.di tiep \n1.mo url moi\n");
       int count=0;
       scanf("%d",&count);
       if(count==0)
        h=h->next;
        else{
            insertAfter(head);
        }
    }
}
//ham lui
void back(struct Node *head)
{
    struct Node *p=head;
    if(h==NULL) return;
    if(h==head)//neu ma chi co 1 phan tu
    {
        printf("\ntrang chu ");
        h=NULL;
        return;
    }
    else{
        h=h->prev;
    }
}
int main()
{
    int key;
   struct Node *head=NULL;
    while(1)
    {
        printf("1.tien\n");
        printf("2.lui\n");
        scanf("%d",&key);
        switch(key)
        {
            case 1:
            tien(&head);
            printfList(head);
            break;
            case 2:
            back(head);
            printfList(head);
            break;
        }
    }
    return 0;
}