#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left,*right;
};
//ham tao node moi 
struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//ham them node vao cay
struct Node *insertNode(struct Node *root,int key)
{
    if(root == NULL) return createNode(key);
    if(key<root->data)
    root->left = insertNode(root->left,key);
    else
    root->right = insertNode(root->right,key);
    return root;
}
//ham in cay theo thu tu giua 
void preorder(struct Node *root)
{
    if(root==NULL) return;
    preorder(root->left);
    printf("%d ,",root->data);
    preorder(root->right);
}
//ham doc du lieu tu cay 
struct Node *createTree(const char *filename)
{
    FILE *f;
    f=fopen(filename,"r");
    if(f==NULL)
    {
        printf("khong mo duoc file!");
        return NULL;
    }
    int a;
    struct Node *root=NULL;
    while(!EOF)
    {
        fscanf(f,"%d",&a);
        root = insertNode(root,a);
    }
    fclose(f);
    return root;
}

int main()
{
    struct Node* root = createTree("nhap2.txt");
    preorder(root);
    return 0;
}