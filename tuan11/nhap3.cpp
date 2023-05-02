#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>

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
//duyet cay  theo muc 
void PrintfLevelOrder(Node *root)
{
    if(root==NULL) return;
    queue<Node*>hang_doi;
    hang_doi.push(root);
    while(!hang_doi.empty()){
        Node *current = hang_doi.front();
        cout<<current->data<<", ";
        hang_doi.pop();
        if(current->left!=NULL)
        {
            hang_doi.push(current->left);
        }
        if(current->right!=NULL)
        hang_doi.push(current->right);
    }
}
//duyet la cua cay o ngoai cung
void la_cay(Node *root)
{
    if(root==NULL) return;
    queue<Node*>hang_doi;
    hang_doi.push(root);
    while(!hang_doi.empty()){
        Node *current = hang_doi.front();
        if(current->right==NULL&&current->left==NULL)
        cout<<current->data<<" ,";
        //cout<<current->data<<", ";
        hang_doi.pop();
        if(current->left!=NULL)
        {
            hang_doi.push(current->left);
        }
        if(current->right!=NULL)
        hang_doi.push(current->right);
        
    }
}
//duyet la o muc nong nhat 
void nong_nhat(Node *root)
{
    if(root==NULL) return;
    cout<<root->left->data<<", ";
    cout<<root->right->data;
}
//duyet la o muc sau nhat 
/*
1.tao 1 hang doi 
2.tao de quy di chuyen sao cho level = muc muon duyet 
ham(root->left,level+1)
ham(root->right,level+1)
if(level==muc) return root;
*/
//ham di chuyen
int x=0;

void move(Node *root,int level,int muc)
{
   
    if(root==NULL) return;
    if(muc==level) cout<<root->data<<", ";
    move(root->left,level,muc+1); 
    move(root->right,level,muc+1);
}
void random_muc(Node *root,int level)
{
  //  move(root,level,0);
  //  for(int i=0;i<x;i++)
    //cout<<b[i]<<" ,";
}
int main()
{
    struct Node *root = createTree("nhap1.txt");
    printf("duyet cay theo thu tu truoc \n");
    preTravel(root);
    //duyet cay theo muc 
     printf("\nduyet cay theo muc \n");
    PrintfLevelOrder(root);
   //duyet la o ngoai dia 
   printf("\ntat ca la o ngoai dia\n");
   la_cay(root);
   //duyet la o muc nong nhat chi can xuat ra con cua root
   printf("\nla o muc nong nhat :");
   nong_nhat(root);
//la o muc sau nhat
cout<<"\nla o muc sau nhat la : ";
move(root,4,0);
//sap xep 
    printf("\n");
    int a[20],n=0;
    tach(root,a,&n);
    selectionSort(a,n);
    
    printf("\ncay nhi phan giu nguyen hinh dang\n");

    int i=0;
    stick(root,a,&i);
    preTravel(root);
   
    
    return 0;
}
