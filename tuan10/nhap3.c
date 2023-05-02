#include <stdio.h>
#include <stdlib.h>
struct TNode
{
	char label;
	struct TNode *firstChild, *nextSibling;
};

struct TNode *makeNode(char label)
{
	struct TNode* newNode = (struct TNode*)malloc(sizeof(struct TNode));
	newNode->firstChild=NULL;
	newNode->nextSibling=NULL;
	newNode->label = label;
	return newNode;
}

// root KHONG phai la NULL
void addNewChild(struct TNode *root, struct TNode *nNode)
{
	if(root->firstChild==NULL)
		root->firstChild= nNode;
	else // them con moi vao cuoi cung danh sach con
	{
		struct TNode *p =  root->firstChild;
		// di chuyen den thang con nho nhat
		while(p->nextSibling!=NULL)
			p= p->nextSibling;
		// them nut moi la con moi nhat
		p->nextSibling = nNode;
		
	}
}

struct TNode * createTree()
{
	struct TNode *root = makeNode('B');

	struct TNode *newNode;
	newNode = makeNode('C');
	addNewChild(root,newNode);
	newNode = makeNode('D');
	addNewChild(root,newNode);
	newNode = makeNode('G');
	addNewChild(root,newNode);
	
	// them con cho nut G
	struct TNode *nodeG = root->firstChild->nextSibling->nextSibling;
	newNode = makeNode('E');
	addNewChild(nodeG,newNode);
	newNode = makeNode('F');
	addNewChild(nodeG,newNode);
	
	// them con cho nut F
	struct TNode *nodeF =  nodeG->firstChild->nextSibling;
	newNode = makeNode('A');
	addNewChild(nodeF,newNode);
	newNode = makeNode('H');
	addNewChild(nodeF,newNode);
	newNode = makeNode('I');
	addNewChild(nodeF,newNode);
	return root;
}

void preOrderTravel(struct TNode *root)
{
	if(root==NULL) return;
	printf("%c, ", root->label);
	struct TNode *p =  root->firstChild;
	
	while(p!=NULL)
	{
		preOrderTravel(p);
		p= p->nextSibling;
	}
}

void postOrderTravel(struct TNode *root)
{
	if(root==NULL) return;
	
	struct TNode *p =  root->firstChild;
	
	while(p!=NULL)
	{
		postOrderTravel(p);
		p= p->nextSibling;
	}
	printf("%c, ", root->label);
}

// tim chieu cao cua root
// chieu cao cua nut la la 0
int calHeight(struct TNode *root)
{
	// cay rong
	if(NULL==root) return -1;
	// goc la nut la
	if(NULL==root->firstChild) return 0;
	
	// tim MAX chieu cao cac cay con
	struct TNode *p =  root->firstChild;
	int maxChildHeight=calHeight(p);
	int height;	
	while(p!=NULL)
	{
		height = calHeight(p);
		if(maxChildHeight<height)maxChildHeight=height;
		p= p->nextSibling;
	}
	return 1+ maxChildHeight;
}

int main()
{
	struct TNode *root=createTree();
	printf("Duyet truoc: ");
	preOrderTravel(root);
	printf("\n");
	printf("Duyet sau: ");
	postOrderTravel(root);
	printf("\nChieu cao cay: %d", calHeight(root));
	
	// in ra chieu cao 1 so nut khac
	struct TNode *p = root->firstChild->nextSibling->nextSibling;
	printf("\nChieu cao nut %c: %d",p->label, calHeight(p));
	return 0;
}