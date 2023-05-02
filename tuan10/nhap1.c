#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct TNode {
    char name[255];
    struct TNode *firstChild,*nextSibling;
};
//ham tao node moi 
struct TNode *makeNode(const char *name)
{
    struct TNode *newNode = (struct TNode *)malloc(sizeof(struct TNode ));
    strcpy(newNode->name,name);
    newNode->firstChild = newNode->nextSibling = NULL;
    return newNode;
}
//ham them node moi vao cay
void addNewNode(struct TNode *root,struct TNode *newNode)
{
    if(root==NULL) return;
    if(root->firstChild==NULL) 
    root->firstChild=newNode;

    else{
        struct TNode *preChild = root->firstChild;

        while(preChild->nextSibling!=NULL)
        preChild=preChild->nextSibling;

        preChild->nextSibling = newNode;
    }
}
//ham tao cay 
struct TNode *creatTree()
{
    struct TNode *root = makeNode("C:");

    struct TNode *child = makeNode("Baitap1");
    addNewNode(root,child);
    child = makeNode("Baitap1.c");
    addNewNode(root->firstChild,child);
    child = makeNode("Baitap1.exe");
    addNewNode(root->firstChild,child);
    child = makeNode("input.txt");
    addNewNode(root->firstChild,child);

    child = makeNode("Baitap2");
    addNewNode(root,child);
    child = makeNode("Baitap2.c");
    addNewNode(root->firstChild->nextSibling,child);

    child = makeNode("Example.c");
    addNewNode(root,child);

    child = makeNode("Example.exe");
    addNewNode(root,child);

    child = makeNode("Code mau");
    addNewNode(root,child);
    struct TNode *preChild = root->firstChild->nextSibling->nextSibling->nextSibling->nextSibling;
    child = makeNode("Chuong 1");
    addNewNode(preChild,child);
    child = makeNode("Ex1.cpp");
    addNewNode(preChild->firstChild,child);
    child = makeNode("Chuong 2");
    addNewNode(preChild,child);


    return root;
}
void printfTree(struct TNode *root,int currentLevel)
{
    if(root==NULL) return;
    if(currentLevel>0)
    {
        for(int i=0;i<currentLevel-1;i++) printf("   ");
        printf("+->");
    }
    printf("%s\n",root->name);
    struct TNode *child = root->firstChild;
    while(child!=NULL)
    {
        printfTree(child,currentLevel+1);
        child = child->nextSibling;
    }
}
//ham giai phong ca cay
//cach 1 su dung con tro cap 1
void removeTree(struct TNode *root)
{
    struct TNode *child = root->firstChild;
    while(child!=NULL)
    {
        struct TNode *preChild = child;
        child=child->nextSibling;
        removeTree(preChild);
       
    }
    free(root);
}
//tim kiem 
struct TNode *searchKey(struct TNode *root,char *key)
{
    if(root==NULL) return NULL;
    if(strcmp(root->name,key)==0) return root;
    struct TNode *child = root->firstChild;
    struct TNode *preVal = NULL;
    while(child!=NULL)
    {
        preVal = searchKey(child,key);
        if(preVal!=NULL) return preVal;
        child=child->nextSibling;
    }
}
//in duong dan den la tim duoc
void printfPath(struct TNode *root,struct TNode *currentNode,char *path)
{
    char currentPath[255];
    if(root==currentNode)
    {
        strcat(path,root->name);
        printf("%s\n",path);
    }
    else{
        if(strlen(path)>0) 
        strcat(path,"\\");
        strcat(path,root->name);
        strcpy(currentPath,path);
        struct TNode *child = root->firstChild;
        while(child!=NULL)
        {
            strcpy(path,currentPath);
            if(child==currentNode)
            {
                strcat(path,"\\");
                strcat(path,child->name); 
                printf("%s\n",path);
            }
            else{
                printfPath(child,currentNode,path);
            }
            child = child->nextSibling;
        }
    }
}
int main()
{
    struct TNode *root = creatTree();
    printfTree(root,0);
   struct TNode *nNode = searchKey(root,"Ex1.cpp");
if(nNode!=NULL){
printf("Ton tai file/thu muc co ten %s\n",nNode->name);
char pathName[200];
printfPath(root,nNode,pathName);
}

else
printf("Ten da cho KHONG ton tai!");
removeTree(root);
//removeTree(root);
return 0;
    
}
