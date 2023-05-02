#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct QNode{
  int i,j;
  struct QNode *next;
};
void intiQueue(struct QNode **front,struct QNode **rear,int *size)
{
  *size=0;
  *front=NULL;
  *rear=NULL;
}
struct QNode *makeNewNode(int x,int y)
{
  struct QNode *newNode=(struct QNode*)malloc(sizeof(struct QNode));
  newNode->i=x;
  newNode->j=y;
  newNode->next=NULL;
  return newNode;
}
void eQueue(int x,int y,struct QNode **front,struct QNode **rear,int *size)
{
  struct QNode *newNode =makeNewNode(x,y);
  if(*size==0)//hang doi dang rong
  {
    *front = newNode;
    *rear = newNode;
    *size=1;
  }
  else//hang doi khac rong-->them vao cuoi
  {
    (*rear)->next=newNode;
    *rear = newNode;
    (*size)++;
  }
}
struct QNode *dQueue(struct QNode **front,struct QNode **rear,int *size)
{
  if(*size==0)//hang doi rong 
  return NULL;
  struct QNode*retVal = *front;
  if(*size==0)//hang doi chi co 1 phan tu 
  {
    *rear = NULL;
    *front = NULL;
    *size = 0;
    return retVal;
  }
  else //xoa phan t u dau
  {
    *front=(*front)->next;
    (*size)--;
    return retVal;
  }
}
int main()
{
  struct QNode *front,*rear,*curE;
  int qSize=0;
  intiQueue(&front,&rear,&qSize);
  eQueue(1,1,&front, &rear, &qSize);
  //eQueue(1,2,&front, &rear, &qSize);
eQueue(2,1,&front, &rear, &qSize);
eQueue(3,1,&front, &rear, &qSize);
for(int i=0;i<3;i++)
{
curE = dQueue(&front, &rear, &qSize);
printf("%d:%d\n",curE->i,curE->j);
}
return 0;

}