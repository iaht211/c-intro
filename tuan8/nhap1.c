#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAX_LEN = 20;
struct DNode
{
char songname[255];
char singer[255];
int duration; //seconds
struct DNode *next, *prev;
};
 
// tao nut moi voi cac thong tin duoc cung cap
// cac con tro tam thoi gan la NULL
struct DNode *makeNode(char *songname, char *singer, int dur)
{
struct DNode *newNode = (struct DNode*)malloc(sizeof(struct DNode));
strcpy(newNode->songname,songname);
strcpy(newNode->singer,singer);
newNode->duration = dur;
newNode->next = NULL;
newNode->prev=NULL;
return newNode;
}
 
// them vao dau tien
// them newnode vao truoc tien cua danh sach da tro boi head
void insertFirst(struct DNode **head, struct DNode* newNode)
{
if(*head==NULL) // danh sach ban dau rong
{
*head=newNode;
}
else //danh sach khac rong
{
(*head)->prev = newNode;
newNode->next = *head;
}	
}
 
// them vao sau phan tu dang trong boi con tro *p
// danh sach se phai khac NULL
// *p chac chan khac NULL
void insertAfter(struct DNode *p, struct DNode* newNode)
{
    if((p->next)==NULL)
    {
        newNode->next=p->next;
        newNode->prev=p;
        p->next=newNode;

    }else{
        newNode->next=p->next;
    newNode->prev=p;
    (p->next)->prev=newNode;
    p->next=newNode;
    }
    
}
 
// them phan tu moi vao cuoi cung danh sach dang tro boi head
// Danh sach co the rong --> can check
void insertLast(struct DNode **head, struct DNode* newNode)
{
if(*head==NULL) // danh sach ban dau rong
{
*head=newNode;
}
else// danh sach khac rong --> tim den phan tu cuoi
{
struct DNode *p = *head;
while(p->next!=NULL) // tim phan tu cuoi day
p=p->next;

// them newnode vao cuoi
p->next = newNode;
newNode->prev = p;
}
}
 
// in ra playlist hien tai
// moi bai hat 1 dong dang
// 1. ABC 3:40
// 2. AVB  04:05
void printPlayList(struct DNode *head)
{
int idx =0;
printf("Danh sach bai hat hien tai:\n");
while(head!=NULL)
{
idx++;
printf("%d. %30s %30s %02d:%02d\n",idx,head->songname,head->singer, 
          head->duration/60, head->duration%60);
head = head->next;
}
printf("Tong cong %d bai hat\n",idx);
}
 
// in ra playlist hien tai
// moi bai hat 1 dong dang
// 1. ABC 3:40
// 2. AVB  04:05
// ten toi da 30 ky tu, qua thi thay bang dau ...
void printPlayList_V2(struct DNode *head)
{
int idx =0;
char sname[MAX_LEN], singer[MAX_LEN];
printf("Danh sach bai hat hien tai:\n");
while(head!=NULL)
{
idx++;
strncpy(sname,head->songname,MAX_LEN-1);
if(strlen(head->songname)>=MAX_LEN)
{
sname[strlen(sname)-3]='.';
sname[strlen(sname)-2]='.';
sname[strlen(sname)-1]='.';
}
strncpy(singer,head->singer,MAX_LEN-1);
if(strlen(head->singer)>=MAX_LEN)
{
singer[strlen(singer)-3]='.';
singer[strlen(singer)-2]='.';
singer[strlen(singer)-1]='.';
}

printf("%d. %30s %30s %02d:%02d\n",idx,sname,singer, 
          head->duration/60, head->duration%60);
head = head->next;
}
printf("Tong cong %d bai hat\n",idx);
}
 
// nap danh sach cac bai hat vao tu file
struct DNode *loadPlayList(char* filename)
{

}
 
// ghi danh sach hien tai ra file
void savePlayListToFile(char* filename, struct DNode *head)
{
    FILE *f=fopen(filename,"w");
    while(head!=NULL)
    {
        fprintf(f,"%s\n%s\n%d\n",head->songname,head->singer, 
          head->duration);
          head=head->next;
    }
    fclose(f);
}
 
// tim kiem bai hat trong playlist va tra ve 
// con tro toi bai hat neu no co trong playlist
// nguoc lai tra ve NULL
// chi can tim kiem 1 phan cua ten
struct DNode *searchSongName(struct DNode *head, char *sName)
{
   while(head!=NULL)
   {
    if(strstr(head->songname,sName))
    return head;
    head=head->next;
   }
   return NULL;
}
 
// tim kiem va in ra tat cac cac bai hat cua ca si
void listAllSongBySinger(struct DNode *head, char *singerName)
{
    while(head!=NULL)
    {
        if(strcmp(singerName,head->singer)==0)
        printf("\n%s\n",head->songname);
        head=head->next;
    }
}
 
// dua bai hat dang tro boi con tro P len dau danh sach
// neu danh sach co 1 bai hat thi ko lam gi ca
void adjustToTopPlaylist(struct DNode **head, struct DNode *p)
{
    //struct DNode *c=p->prev,*d=p->next;
   // if((*head)->prev==NULL)
   // return;
   if(p->next==NULL)
   {
     p->prev->next = NULL;
        p->next=(*head);
        p->prev=NULL;
        (*head)=p;
   }
    else{
       p->prev->next = p->next;
        p->next->prev = p->prev;
        p->next=(*head);
        p->prev=NULL;
        (*head)=p;
    }
}
 
// dua bai hat dang tro boi con tro P ve cuoi danh sach
// neu danh sach co 1 bai hat thi ko lam gi ca
void adjustToEndPlaylist(struct DNode **head, struct DNode *p)
{
    struct DNode *pre=(*head);
   if(p->next==NULL) return NULL;// neu p = last thi ko doi
   if(p=pre){
    (*head)=p->next;
    p->prev=(*head);
    while(pre->next!=NULL) pre=pre->next;
    pre->next=p;
    p->prev=pre;
   }
   else{
    while(pre->next!=NULL) pre=pre->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    pre->next=p;
    p->prev=pre;
   }
}
 
 
// Xoa bai hat dang tro boi con tro p trong danh sach
// co the la dau, giua/cuoi danh sach
void removeSong(struct DNode **head, struct DNode *p)
{

}
 
// tra ve bai hat tiep theo ngay sau bai hat tro boi p
// neu p la cuoi danh sach thi tra ve NULL
struct DNode *getNextSong(struct DNode *head, struct DNode *p)
{
    if((p->next)==NULL)
    return NULL;
    else{
        return p->next;
    }

}
 
// tra ve bai hat tiep theo ngay truoc bai hat tro boi p
// neu p la dau danh sach thi tra ve NULL
struct DNode *getPrevSong(struct DNode *head, struct DNode *p)
{

}
int main()
{
struct DNode *curList = NULL, *newNode;
newNode = makeNode("Vegas","Doja Cat",183);
insertFirst(&curList,newNode);
newNode = makeNode("Hello","Lionel Richie",247);
insertLast(&curList,newNode);
newNode = makeNode("Con La Brisa (From \"Black Panther:...\"","Black Panther: Wakanda Forever - Music From and",167);
insertLast(&curList,newNode);
newNode = makeNode("afaf","Lionel Richie",247);
insertLast(&curList,newNode);
struct DNode *p=NULL;
newNode = makeNode("gaggag","kadfd",347);
char sName[250];
printf("\nnhap vao song name:");
gets(sName);
p=searchSongName(curList,sName);
//insertAfter(p,newNode);
//adjustToTopPlaylist(&curList,p);
adjustToEndPlaylist(&curList,p);
printPlayList_V2(curList);
//tim kiem va in ra ten bai hat cua ca si 
char singername[50];
fflush(stdin);
printf("\nnhap vao ten ca si :");
gets(singername);
listAllSongBySinger(curList,singername);
printPlayList_V2(curList);
//ham in ra phan tu ngay sau con tro duoc tro den
/*char nextsong[50];
fflush(stdin);
printf("\nnhap vao ten :");
gets(nextsong);
struct DNode *ns;
ns=searchSongName(curList,nextsong);*/


char filesave[]="D:\\c\\tuan8\\bai1-out.txt";
savePlayListToFile(filesave,curList);
return 0;
}
