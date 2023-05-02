#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
    char ms[10];
    char ten[250];
    char hang[100];
    int slg;
}sp;
struct node{
    sp data;
    struct node* next;
};
typedef struct node *Node;
//ham tao Node
Node makeNode(sp a)
{
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->next=NULL;
    newNode->data=a;
    return newNode;
    
}
//ham chen vao vi tri duoc con tro p tro den
Node insertLast(Node *head,sp a){
     Node temp,p;//khai bao 2 node tam
     temp = makeNode(a);
     if(head == NULL)
     {
        head = temp;
     }
     else{
        p=head;
        while(p->next !=NULL) p=p->next;
        p->next=temp;
     }
     return head;
}
//ham xuat du lieu hien tai
void printfList(Node head)
{
    printf("\ndanh sach hien tai \n");
    for(Node p=head;p!=NULL;p=p->next)
    {
        printf("%10s%30s%10s%10d\n",p->data.ms,p->data.ten,p->data.hang,p->data.slg);
    }
    printf("\n------\n");

}
//ham tach du lieu 
