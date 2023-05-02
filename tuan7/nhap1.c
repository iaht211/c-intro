#include<stdio.h>
#include<stdlib.h>
struct Node{
    double data;
    struct Node *next;
};
//ham tao node moi 
struct Node *makeNode(double value)
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node ));
    newNode->next=NULL;
    newNode->data=value;
    return newNode;
}
//ham them phan tu vao dau danh sach
void insertFist(struct Node **head,double value)
{
    struct Node *newNode=makeNode(value);
    newNode->next=(*head);
    (*head)=newNode;
}

struct Node *insertFist1(struct Node *head,double value)
{
    struct Node *newNode=makeNode(value);
    newNode->next=head;
    head=newNode;
    return head;
}
//ham in ra danh sach 
void printfList(struct Node *head)
{
    printf("\ndanh sach :");
    while(head!=NULL)
    {
        printf("%.2lf,",head->data);
        head=head->next;
    }
    printf("\n");
}
//ham in danh sach nguoc
void printfList_rev(struct Node *head)
{
    if(head==NULL) return;
    if(head!=NULL) printfList_rev(head->next);
    printf("%.2lf,",head->data);
}
//dem so phan tu trong danh sahch 
void countNodes(struct Node *head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    printf("\nso phan tu co trong danh sach la :%d",count);
}
//tim phan tu co khoa k trong danh sach 
struct Node *searchNode(struct Node *head,double value)
{
    
    while(head!=NULL)
    {
        if(head->data==value)
        {
            return head;
        }
        head=head->next;
    }
    return NULL;
}
//them phan tu moi vao sau phan tu co con tro p
void insertAfter(struct Node *p,double value)
{
    struct Node *newNode=makeNode(value);
    newNode->next=p->next;
    p->next=newNode;
}
//them pahn tu vao cuoi danh sach
void insertLast(struct Node *head,double value)
{
    struct Node *newNode=makeNode(value);
   while(head->next!=NULL)
   head=head->next;
   head->next=newNode;  
}
//xoa phan tu co khoa k
void moveNode(struct Node **head,double value)
{
     struct Node *p=(*head);
    if((*head)->data==value)
    {
        
        (*head)=(*head)->next;
        free(p);
    }else //xoa cuoi va giua
    {
        //tim phan tu

        while(p->data!=value)
        p=p->next;
        struct Node *pre=(*head);
        while(pre->next!=p)
        pre=pre->next;
        pre->next=p->next;
        free(p);
    }
}
int main()
{
    struct Node *head=NULL;
    head=makeNode(12);
    insertFist(&head,15);
    head=insertFist1(head,13);
    printfList(head);
    printf("\n in thoe danh sach nguoc : ");
    printfList_rev(head);
    countNodes(head);
    struct Node *p;
    p=searchNode(head,15);
    insertAfter(p,14);
    printfList(head);
    insertLast(head,19);
    printfList(head);
    moveNode(&head,15);
    printfList(head);




}