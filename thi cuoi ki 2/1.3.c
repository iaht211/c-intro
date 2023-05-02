#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct time{
    int nam,thang,ngay,gio,phut,giay;
};
struct Node{
    int loai;
  //  int nam,thang,ngay,gio,phut,giay;
    char bien[15];
    struct time tgian;
};
//ham tao node moi 
/*struct Node *creatNode(struct time tgian,char *name,int loai)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->tgian = tgian;
    strcpy(newNode->bien,name);
    newNode->loai = loai;
    return newNode;
}*/
//ham doc du lieu tu file
int dem_dong(const char *filename)
{
    int n=0;
    FILE *f;
    f=fopen(filename,"r");
    char a[255];
    if(f==NULL) {
        printf("\nloi mo file");
        fclose(f);
        return 0;
    }
    while(fgets(a,sizeof(a),f)!=NULL)
    {
        n++;
    }
    fclose(f);
    return n;

}
struct Node *readfile(char *filename,int n)
{
    FILE *f;
    f=fopen(filename,"r");
    struct Node *A = (struct Node*)malloc(sizeof(struct Node)*n);
    int i=0;
    //neu mo file loi 
    if(f==NULL){
        fclose(f);
        printf("\ndoc file khong thanh cong ");
        return NULL;
    }

    while(fscanf(f,"%d-%d-%d %d:%d:%d %s %d",
    &A[i].tgian.nam,&A[i].tgian.thang,&A[i].tgian.ngay,&A[i].tgian.gio,
    &A[i].tgian.phut,&A[i].tgian.giay,&A[i].bien,&A[i].loai)!=EOF){
        i++;
    }
   
    fclose(f);
    return A;
}
//ham in ra thong tin gui nhan xe trong 1 ngay 
void printxe(struct Node *A,int n)
{
    struct time a;
    printf("\nnhap vao ngay (vd 2022-11-22)");
    scanf("%d-%d-%d",&a.nam,&a.thang,&a.ngay);
    int count=0;
    int vao=0,ra=0;
    for(int i=0;i<n;i++){
        
        if(A[i].tgian.nam==a.nam&&A[i].tgian.thang==a.thang&&A[i].tgian.ngay==a.ngay)
        {
            /*
            printf("\n%d-%d-%d %d:%d:%d %s %d",
            A[i].tgian.nam,A[i].tgian.thang,A[i].tgian.ngay,A[i].tgian.gio,
            A[i].tgian.phut,A[i].tgian.giay,A[i].bien,A[i].loai);
            */
           if(A[i].loai==1) vao++;
           if(A[i].loai==0) ra++;
           count++;
        }
    }
    if(vao==0&&ra==0)
    printf("\nngay do khong co xe gui,lay ");
    printf("\ntong xe :%d\tvao:%d\tra:%d",count,vao,ra);

}
//tao cay nhi phan tim kiem voi khoa la bien so xe 
struct nNode{
    struct Node data;
    struct nNode* left,*right;
};
//ham tao nNode moi cho cay 
struct nNode* createNode(struct Node data)
{
    struct nNode *newNode = (struct nNode*)malloc(sizeof(struct nNode));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    return newNode;
}
//ham chen them node moi neu nhu node co ton tai thi cap nhat 
struct nNode *insertNode(struct nNode *root,struct Node data)
{
    if(root == NULL) return createNode(data);
    if(strcmp(root->data.bien,data.bien)==-1)
    root->left = insertNode(root->left,data);
    else if(strcmp(root->data.bien,data.bien)==1)
    root->right = insertNode(root->right,data);
    else{
        root = createNode(data);
        return root;
    }
    return root;
}
//ham tao cay nhi phan voi khoa la bien so xe 
struct nNode *createTree(struct Node *A,int n)
{
    struct nNode *root=NULL;
    for(int i=0;i<n;i++)
    {
        root = insertNode(root,A[i]);
    }
    return root;
}
//ham in ra cay duyet theo thu tu truoc in ra xe dang gui theo file 
void printTree(struct nNode *root)
{
    if(root==NULL) return;
    if(root->data.loai==1)
    printf("%d-%d-%d %d:%d:%d \t %s\n",root->data.tgian.nam,root->data.tgian.thang,root->data.tgian.ngay,
    root->data.tgian.gio,root->data.tgian.phut,root->data.tgian.giay,root->data.bien);
    printTree(root->left);
    printTree(root->right);
}
//ham tim node tren cay 
struct nNode *findNode(struct nNode *root,struct Node a)
{
    if(root==NULL) return root;
    if(strcmp(root->data.bien,a.bien)==0) return root;
    struct nNode *find = findNode(root->left,a);
    if(find!=NULL)
    return find;
    return findNode(root->right,a);
}
//ham them xe vao danh sach 

struct nNode *addxe(struct nNode *root,struct Node a)
{
    struct nNode *n = findNode(root,a);
    if(n==NULL){
        printf("\nthem xe moi vao danh sach");
    root = insertNode(root,a);
    }
    else{
        if(n->data.loai==1)
    printf("\nloi do da co xe o trong bai");
    else{
        printf("cap nhat lai xe ");
        n->data = a;
    }
    }
    return root;
    
}
int main()
{
    int key;
    do{
        
        printf("\n====================Menu================");
        printf("\nVui long chon 1 trong cac chuc nang sau\n");
        printf("[1] Doc du lieu tu file log\n");
        printf("[2] Tra cuu so luong xe gui/lay theo ngay trong qua khu\n");
        printf("[3] Thong tin cac xe trong bai hien tai\n");
        printf("[4] Gui them xe moi\n");
        printf("[5] Tra xe\n");
        printf("[6] Cap nhap log du lieu\n");
        printf("[7] Luu danh sach xe dang co trong bai ra file\n");
        printf("\n[8].thoat chuong trinh va giai phong bo nho ");
        printf("\nnhap vao lua chon : ");
        scanf("%d",&key);
    switch(key){
        case 1:
            int n=dem_dong("log_input.txt");
            struct Node *A = readfile("log_input.txt",n);
            
        break;
        case 2:
        printxe(A,n);
        break;
        case 3:
        struct nNode *root = createTree(A,n);
        printTree(root);
        break;
        case 4:
        printf("\nnhap vao xe muon them ");
        struct Node x;
        fflush(stdin);
        gets(x.bien);
        x.loai=1;
        root = addxe(root,x);
        break;
        case 5:
        break;
        case 6:
        break;
        case 7:
        break;
        case 8:
        return 0;

    }
    }while(1);

}
