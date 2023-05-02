#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node *left,*right;
};
//ham tao node moi 
struct Node *makeNewNode(int a)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = a;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//ham them node moi 
void addNode(struct Node *root,struct Node *newNode ,int type)
{
    if(type==-1)
    root->left = newNode;
    if(type==1)
    root->right = newNode;
}
//ham tim kiem 
struct Node *findNode(struct Node *root,int key)
{
    if(root==NULL||root->data==key) return root;
    struct Node *find = findNode(root->left,key);
    if(find!=NULL) return find;
    return findNode(root->right,key);
}
struct Node *findKey(struct Node *root,int key)
{
    if(root==NULL||root->data==key) return root;
    struct Node *find = findKey(root->left,key);
    if(find!=NULL) return find;
    return findKey(root->right,key);
}
//ham tao cay
struct Node *createTree(const char *filename)
{
    FILE *f;
    f=fopen(filename,"r");
    struct Node *root = NULL,*right,*left,*anode;
    int rootKey,rightKey,leftKey;
    do{
        fscanf(f,"%d",&rootKey);
        if(rootKey==-2)
        {
            fclose(f);
            return root;
        }
        if(root==NULL)
        {
            root = makeNewNode(rootKey);
            anode = root;
        }
        else{
            anode = findNode(root,rootKey);
        }
        fscanf(f,"%d %d",&leftKey,&rightKey);
        if(leftKey!=-1) {
            left = makeNewNode(leftKey);
            addNode(anode,left,-1);
        }
        if(rightKey!=-1)
        {
            right = makeNewNode(rightKey);
            addNode(anode,right,1);
        }
    }while(1);
}
//ham in duyet theo thu tu truoc
void preTravel(struct Node *root)
{
    if(root==NULL) return;
    printf("%d, ",root->data);
    preTravel(root->left);
    preTravel(root->right);
}
//ham duyet theo thu tu sau 
void  Postorder(struct Node *root)
{
    if(root==NULL) return;
     Postorder(root->left);
     Postorder(root->right);
    printf("%d, ",root->data);
}
//ham tach ra
void tach(struct Node *root,int a[],int *i)
{
    if(root==NULL) return;
    a[*i] = root->data;
    (*i)++;
    tach(root->left,a,i);
    tach(root->right,a,i);
}
//ham sap xep
void selectionSort(int A[], int N){
    // index tu1 -> N
    for(int k = 0; k < N-1; k++){
        int min = k;
        for(int j = k+1; j < N; j++)
        {
            if(A[min] > A[j]) 
            min = j;
        }
        int tmp= A[min]; 
        A[min] = A[k]; 
        A[k] = tmp;
        }
    }
    //ham nhet lai vao cay theo thu tu giua
void stick(struct Node *root,int a[],int *i)
{
    if(root==NULL)
    return;

    stick(root->left,a,i);
    root->data = a[*i];
   // printf("%d ,",root->data);
    (*i)++;
    stick(root->right,a,i);
}
int main()
{
    struct Node *root = createTree("nhap1.txt");
    preTravel(root);

   
printf("\n");
    int a[20],n=0;
    tach(root,a,&n);
    selectionSort(a,n);
    for(int i=0;i<n;i++)
    printf("%d ,",a[i]);
    printf("\n");

    int i=0;
    stick(root,a,&i);
    preTravel(root);


}
