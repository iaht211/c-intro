#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
double data;
struct Node *next;
};
 
struct Node *makeNode(double value)
{
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
return newNode;
}
// ham them nut vao dau danh sach
void insertFirst(struct Node **head, double value)
{
struct Node *newNode = makeNode(value);
newNode->next = *head;
*head = newNode;
}
// ham them nut vao dau danh sach
struct Node * insertFirst2(struct Node *head, double value)
{
struct Node *newNode = makeNode(value);
newNode->next = head;
head = newNode;
return head;
}
// ham in danh sach
void printList(struct Node *head)
{
printf("Danh sach cac phan tu:\n");
while(head!=NULL)
{
printf("%.2lf,",head->data);
head = head->next;
}
printf("\n");
}
 
// in danh sach theo thu tu nguoc
void printList_rev(struct Node *head)
{
if(head==NULL) return;
printList_rev(head->next);
printf("%.2lf,",head->data);
}
// ham dem so phan tu trong danh sach
int countNodes(struct Node *head)
{
int count=0;
while(head!=NULL)
{
count++;
head = head->next;
}
return count;
}
// tim phan tu co khoa K trong danh sach
struct Node * searchKey(struct Node *head, double k)
{
while(head!=NULL)
{
if(head->data==k) return head;
head = head->next;
}
return NULL;
}
 
struct Node * searchKey_Rec(struct Node *head, double k)
{
if(head == NULL) return NULL;
if(head->data==k) return head;
return searchKey_Rec(head->next, k);
}
 
// ham chen phan tu moi vao sau vi tri duoc tro boi con tro p
// p phai khac NULL
void insertAfter(struct Node *p, double value)
{
struct Node *newNode = makeNode(value);
newNode->next = p->next;
p->next = newNode;
}
 
// chen phan tu vao cuoi danh sach
// head phai khac NULL
void insertLast(struct Node *head, double value)
{
while(head->next!=NULL)head=head->next;
insertAfter(head,value);
}
 
void insertLast_Rec(struct Node *head, double value)
{
if(head->next!=NULL)insertLast_Rec(head->next,value);
else insertAfter(head,value);
}
 
// ham xoa phan tu gia tri k trong danh sach
// xoa dau hoac xoa giua/cuoi
void removeKey(struct Node **head, double k)
{
if((*head)==NULL) return;
struct Node *p; // con tro toi phan tu can xoa
// neu khoa can xoa nam dung phan tu dau
if((*head)->data==k)
{
p = *head;
*head = (*head)->next;
free(p);
}
else // xoa giua/cuoi
{
// tim phan tu can xoa
p = *head;
while(p!=NULL)
{
if(p->data==k) break;
p=p->next;
}
// khoa can xoa KHONG ton tai trong danh sach
if(p==NULL) return;
// tim vi tri truoc vi tri can xoa
struct Node *pre = *head;
while(pre->next!=p) pre = pre->next;

// ngat p khoi danh sach
pre->next = p->next;
free(p);
}
}
void destroyList(struct Node **head)
{
struct Node *p;
while((*head)!=NULL)
{
p=*head;
*head = (*head)->next;
free(p);
}
*head = NULL;
}
int main()
{
struct Node *head = NULL;
insertFirst(&head, 12.5);
head = insertFirst2(head,17.6);
insertFirst(&head, 2.5);
struct Node *p = searchKey(head, 17.6);
if(p!=NULL)insertAfter(p, 22.2);
insertLast(head,11.11);
insertLast_Rec(head,12.12);
printList(head);
printf("Danh sach hien co %d phan tu\n",countNodes(head));
printf("In danh sach theo thu tu nguoc\n");
printList_rev(head);
printf("\n");
printf("\nXoa 2.5\n");
removeKey(&head, 2.5);
printList(head);
printf("Danh sach hien co %d phan tu\n",countNodes(head));
printf("\nXoa 12.12\n");
removeKey(&head, 12.12);
printList(head);
printf("Danh sach hien co %d phan tu\n",countNodes(head));

printf("\nXoa toan bo danh sach\n");
destroyList(&head);
printList(head);
printf("Danh sach hien co %d phan tu\n",countNodes(head));
return 0;

}
