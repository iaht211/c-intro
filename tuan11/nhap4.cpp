#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
};
Node *findNode(Node *root,int key)
{
	if(root==NULL||root->data==key) return root;
	Node *find = findNode(root->left,key);
	if(find!=NULL) return find;
	return findNode(root->right,key);
}
void addNode(Node *root,Node *newNode,int type)
{
	if(type==1)
	root->right = newNode;
	if(type==-1)
	root->left = newNode;
}
Node *makeNode(int data)
{
	Node *newNode = new Node ;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
Node *createTree(const char *filename){
	FILE *f;
	f=fopen(filename ,"r");
	Node *root=NULL,*left,*right,*anode;
	int rootKey,rightKey,leftKey;
	do
	{
		fscanf(f,"%d",&rootKey);
		if(rootKey==-2)
		{
			fclose(f);
			return root;
		}
		if(root==NULL){
			root = makeNode(rootKey);
			anode = root;
		}
		else{
			anode = findNode(root,rootKey);
		}
		fscanf(f,"%d %d",&leftKey,&rightKey);
		if(leftKey!=-1){
			left = makeNode(leftKey);
			addNode(anode,left,-1);
		}
		if(rightKey!=-1)
		{
			right = makeNode(rightKey);
			addNode(anode,right,1);
		}
	}while(1);
}
void inorder(Node *root)
{
	if(root==NULL) return;
	cout<<root->data<<", ";
	inorder(root->left);
	inorder(root->right);
}

int main()
{
    Node *root = createTree("nhap1.txt");
    inorder(root);
}