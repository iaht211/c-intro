#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct DNode{
    char songname[255];
    char singer[255];
    int time;
    struct DNode *next,*prev;
};
struct DNode *makeNode(char *songname,char *singer,int time)
{
    struct DNode *newNode = (struct DNode*)malloc(sizeof(struct DNode));
    strcpy(newNode->songname,songname);
    strcpy(newNode->singer,singer);
    newNode->time=time;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
};
void printfList(struct DNode *head)
{
    int count=0;
    printf("\ndanh sach bai hat hien tai la :\n");

    while(head!=NULL){
        count++;
        printf("%d. %20s %20s\t%02d:%02d\n",count,head->songname,
        head->singer,head->time/60,head->time%60);
        head=head->next;
    }
    printf("\ndanh sach hien co %d bai hat ",count);

}
//ham them bai hat vao dau cuoi
//tham  bai hat vao dau
void insertFist(struct DNode **head,struct DNode *newNode)
{
    if((*head)==NULL)
    (*head)=newNode;
    else{
        newNode->next=(*head);
        (*head)->prev=newNode;
        (*head)=newNode;
    }
}
//ham them vao cuoi
void insertLast(struct DNode **head,struct DNode *newNode)
{
    struct DNode *p=(*head);
    while(p->next!=NULL)
    {
        p=p->next;
    }
    newNode->prev=p;
    p->next=newNode;
}
//ham tim kiem bai hat bang ten 
struct DNode *searchName(struct DNode *head,char *name)
{
     while(head!=NULL){
        if(strstr(head->songname,name))
        return head;
        head=head->next;
     }
     return NULL;   
}
//ham tra va bai hat o truoc 
void topSong(struct DNode *head,struct DNode *p)
{
    if(p->prev==NULL) return;
    else{
        printf(" %20s %20s\t%02d:%02d\n",p->prev->songname,
        p->prev->singer,p->prev->time/60,p->prev->time%60);
    }
}
void truocsong(struct DNode *head)
{
    char name[200];
    fflush(stdin);
    printf("\nnhap vao ten :");
    gets(name);
    struct DNode *p=searchName(head,name);
    if(p->prev==NULL)
    return;
    else{
         printf(" %20s %20s\t%02d:%02d\n",p->prev->songname,
        p->prev->singer,p->prev->time/60,p->prev->time%60);
    }
    
}
//ham tra ve bai hat ow sau
struct DNode *prevSong(struct DNode *head)
{
    char name[200];
    printf("nhap vao ten :");
    fflush(stdin);
    gets(name);
    struct DNode *p=searchName(head,name);

    if(p->next==NULL)
    return NULL;
    else 
     printf(" %20s %20s\t%02d:%02d\n",p->next->songname,
        p->next->singer,p->next->time/60,p->next->time%60);

}
//doi thu tu bai hat 
void changeTop(struct DNode **head,struct DNode *p)
{
    if(p==NULL)
    return;
    if(p->next==NULL)
    {
        p->prev->next=NULL;
         p->next=(*head);
        (*head) = p;
        p->prev=NULL;
    }
    else {
        p->prev->next=p->next;
        p->next->prev=p->prev;
        p->next=(*head);
        (*head) = p;
        p->prev=NULL;
    } 
    
}
void changeLast(struct DNode **head,struct DNode *p)
{
    struct DNode *k=(*head);
    while(k->next!=NULL) k=k->next;
    if(p->next==NULL) return;
    if(p->prev==NULL)
    {
        (*head)=p->next;
        k->next=p;
        p->next=NULL;
    }
    else{
        p->next->prev=p->prev;
        p->prev->next=p->next;
        k->next=p;
        p->prev=k;
        p->next=NULL;
    }
}
int main()
{
    struct DNode *head=NULL,*newNode;
    newNode=makeNode("vcl dfau","kenvil",123);
    head=newNode;
    //them vao dau 
    newNode=makeNode("jgafga","sfgha",255);
    insertFist(&head,newNode);
    newNode=makeNode("akjfk","dkjgka",484);
    insertLast(&head,newNode);
    printfList(head);
    //tra ve bai hat o truoc
    struct DNode *p;

    printf("\nbai hat o truoc");
    truocsong(head);
    printf("\nbai hat o sau ");
    prevSong(head);
    //doi thu tu bai hat
   
    char name[200];
    printf("nhap vao ten bai hat muon doi cho");
    gets(name);
    p=searchName(head,name);
    changeLast(&head,p);
    printfList(head);

}