#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
name la ten file/thu muc
*/
struct TNode 
{ 
    char name[255]; 
struct TNode *firstChild, *nextSibling;
}; 
// tham so name chi doc --> khai bao la const
struct TNode *makeNewNode(const char *newName)
{
struct TNode *newNode = (struct TNode *)malloc(sizeof(struct TNode));
strcpy(newNode->name, newName);
newNode->firstChild = newNode->nextSibling = NULL;
return newNode;
}
 
/* them newnode la con cua root
root phai khac NULL
*/
void addNewChild(struct TNode *root, struct TNode *newNode)
{
if(root->firstChild==NULL)
{
root->firstChild = newNode;
}
else
{
struct TNode *preChild = root->firstChild;
while(preChild->nextSibling!=NULL)
preChild=preChild->nextSibling;
preChild->nextSibling = newNode;
}
}
 
struct TNode * createaTree()
{
struct TNode *root = makeNewNode("C:");
struct TNode *aNewChild = makeNewNode("Baitap1");
addNewChild(root,aNewChild);

aNewChild = makeNewNode("Baitap1.c");
addNewChild(root->firstChild,aNewChild);
aNewChild = makeNewNode("Baitap1.exe");
addNewChild(root->firstChild,aNewChild);
aNewChild = makeNewNode("input.txt");
addNewChild(root->firstChild,aNewChild);

aNewChild = makeNewNode("Baitap2");
addNewChild(root,aNewChild);
aNewChild = makeNewNode("Baitap2.c");
addNewChild(root->firstChild->nextSibling,aNewChild);

aNewChild = makeNewNode("Example.c");
addNewChild(root,aNewChild);
aNewChild = makeNewNode("Example.exe");
addNewChild(root,aNewChild);

aNewChild = makeNewNode("Code mau");
addNewChild(root,aNewChild);	
struct TNode *currentNode = root->firstChild->nextSibling->nextSibling->nextSibling->nextSibling;
aNewChild = makeNewNode("Chuong 1");
addNewChild(currentNode,aNewChild);
aNewChild = makeNewNode("Ex1.cpp");
addNewChild(currentNode->firstChild,aNewChild);
aNewChild = makeNewNode("Chuong 2");
addNewChild(currentNode,aNewChild);
return root;
}
 
/*ham xoa toan bo cay
phai gan root = NULL sau khi xoa*/
void removeTree2(struct TNode **root)
{
if(root==NULL) return;
struct TNode *child = (*root)->firstChild;
if(child==NULL) return;
while(child!=NULL)
{
    struct TNode *preChild = child;
    child=child->nextSibling;
    removeTree2(&preChild);
}
free(*root);
(*root)=NULL;	
}
 
/*ham xoa toan bo cay
phai gan root = NULL sau khi xoa
KHONG duoc dung sau khi da goi ham xoa*/
void removeTree(struct TNode *root)
{
if(root==NULL) return;
struct TNode *child = root->firstChild;
while(child!=NULL)
{
child = child->nextSibling;
removeTree(child);

}
free(root);	
}
/*Tim va tra ve nut chua ten nhu xau mau
Neu khong tim thay thi can tra ve NULL*/
struct TNode *findNode(struct TNode *root, const char *searchKey)
{
if(root==NULL) return NULL;

if(strcmp(root->name,searchKey)==0) return root;
 
struct TNode *child = root->firstChild;
struct TNode *retVal;
while(child!=NULL)
{
retVal = findNode(child, searchKey);
if(retVal!=NULL) return retVal;
child = child->nextSibling;
}
}
/*Ham in ra duogn dan tu nut goc toi nut hien tai
Ca 2 tu phai la nut co tren cay*/
void printPath(struct TNode *root, struct TNode *currentNode, char *path)
{
char currentPath[255]; 
if(root==currentNode)
{
strcpy(path,root->name); 
printf("%s\n",root->name);
}		
else
{
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
else
printPath(child,currentNode,path);
child = child->nextSibling;
}
}
}
 
 
void printCurrentDirectory(struct TNode *root, int currentLevel)
{
if(root==NULL) return;
 
if(currentLevel>0)
{
for(int i=0; i<currentLevel-1; i++) printf("   ");
printf("+->");
}

 
printf("%s\n",root->name);
struct TNode *child = root->firstChild;
while(child!=NULL)
{
printCurrentDirectory(child, currentLevel+1);
child = child->nextSibling;
}
}
 
int main()
{
struct TNode *root = createaTree();
printCurrentDirectory(root,0);


struct TNode *nNode = findNode(root,"Ex1.cpp");
if(nNode!=NULL){
printf("Ton tai file/thu muc co ten Ex1.cpp\n");
char pathName[200];
printPath(root,nNode,pathName);
}

else
printf("Ten da cho KHONG ton tai!");
removeTree2(&root);
//removeTree(root);
return 0;
}
