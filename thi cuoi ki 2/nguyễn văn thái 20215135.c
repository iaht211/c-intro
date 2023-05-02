#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tg{
    int  DD,MM,YYYY;
};
struct sach{
    char yeu_cau[20];
    char id[3];
    int nguoi;
    int ma;
   struct tg a;
    int tre;
    char tgian[20];
};
//ham doc file 
struct sach *docfile(const char *filename,int *n)
{
    FILE *f;
    f=fopen(filename,"r");
    if(f==NULL)
    {
        printf("\nloi mo file");
        fclose(f);
        return NULL;
    }
    fscanf(f,"%d",n);
    struct sach *A = (struct sach*)malloc(sizeof(struct sach)*(*n));
    int i=0;
    while(fscanf(f,"%s %d %d %s %s %d",&A[i].yeu_cau,&A[i].nguoi,&A[i].ma,&A[i].id,&A[i].tgian,&A[i].tre)!=EOF)
    {
        i++;
    }
    fclose(f);
    return A;
}
//ham in ra danh sach da doc duoc 
void printfArr(struct sach *A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\n%s %d %d %s %s %d",A[i].yeu_cau,A[i].nguoi,A[i].ma,A[i].id,A[i].tgian,A[i].tre);
    }
}
//ham loc danh sach 
struct sach *doc(struct sach *A,int *n)
{
    for(int i=0;i<(*n);i++)
    {
        if(A[i].nguoi<=A[i].tre)//neu ma tong nguoi bang tong tre con 
        {
            A[i]=A[i+1];
            (*n)--;
        }
    }
    printf("\ndanh sach sau khi loc la :");
    printfArr(A,*n);
    return A;
}

struct nNode{
    struct sach data;
    struct nNode *left,*right;
};
//ham tao node 
struct nNode* createNode(struct sach data)
{
    struct nNode *newNode = (struct nNode*)malloc(sizeof(struct nNode));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    return newNode;
}
//ham chen them phan tu 
struct nNode *insertNode(struct nNode *root,struct sach data)
{
    if(root == NULL) return createNode(data);
    if(strcmp(root->data.yeu_cau , data.yeu_cau)==-1)
    root->left = insertNode(root->left,data);
    else if(strcmp(root->data.yeu_cau,data.yeu_cau)==1)
    root->right = insertNode(root->right,data);
    else{
        root = createNode(data);
        return root;
    }
    return root;
}
struct nNode *createTree(struct sach *A,int n)
{
    struct nNode *root=NULL;
    for(int i=0;i<n;i++)
    {
        root = insertNode(root,A[i]);
    }
    return root;
}
//ham in cay 
void printTree(struct nNode *root)
{
    if(root==NULL) return;
    
    printf("\n%s %d %d %s %s %d",root->data.yeu_cau,root->data.nguoi,
    root->data.ma,root->data.id,root->data.tgian,root->data.tre);
    printTree(root->left);
    printTree(root->right);
}
//ham tim kiem thong tin 
struct nNode *findNode(struct nNode *root,char *key)
{
    if(root==NULL) return root;
    if(strcmp(root->data.yeu_cau,key)==0) return root;
    struct nNode *find = findNode(root->left,key);
    if(find!=NULL)
    return find;
    return findNode(root->right,key);
}
//ham giai phong mang dong 
void giaiphong(struct sach **A,int n)
{
    free(*A);
    A = NULL;
}
//ham in vao file 
void ghifile(struct nNode *root,int count)
{
    FILE *f = fopen("ghi.txt","w");
    fprintf(f,"%d",count);
   
    fclose(f);
}
void freeTree(struct nNode* r){
    if(r == NULL) return;
    freeTree(r->left);
    freeTree(r->right);
    free(r);
}

int main()
{
    int key;
    int count=0;
    do{
        printf("\n---------MENU---------");
        printf("\n1.doc file");
        printf("\n2.kiem tra so luong yeu cau hop le  ");
        printf("\n3.ttra cuu duoi ma yeu cau ");
        printf("\n4.thay doi yeu cau  ");
        printf("\n5.huy yeu cau ");
        printf("\n6ghi thong tin vao file ");
        printf("\n7.thong ke danh sach duoc ua thich nhat");
        printf("\n8.ngay khong hop le ");
        printf("\n9.ngay khong hop le");
        printf("\n10.thoat chuong trinh ");
        printf("\n11.giai phong bo nho cap phat dong");
        printf("\nnhap vao lua chon :");
        scanf("%d",&key);
        switch(key){
            case 1:
            int n=0;
            struct sach *A = docfile("booking_orders.txt",&n);
            printf("\nso phong lay ra tu file la :%d",n);
            printfArr(A,n);
            count = n;
            break;
            case 2:
             printf("\nso hop le lay ra tu file la :%d",n);
            A = doc(A,&n);
            printf("\nso phong hop le la %d",n);
            printf("\nso yeu cau khong hop le la %d",count-n);
            break;
            case 3:
            struct nNode *root=createTree(A,n);
            printTree(root);
            char x[20];
            printf("\nnhap vao ma yeu cau moun tim : ");
            fflush(stdin);
            gets(x);
           // x[strlen(x)-1] = '\0';
            printf("\ntim yeu cau %s",x);
            struct nNode *find = findNode(root,x);
            if(find==NULL)
            printf("\nNOT FOUND!");
            else printf("da tim duoc phong :\n%s %d %d %s %s %d",find->data.yeu_cau,find->data.nguoi,find->data.ma
            ,find->data.id,find->data.tgian,find->data.tre);
            break;
            case 4:

            break;
            case 5:
            char name[30];
            printf("\nnhap vao yeu cau muon huy");
            fflush(stdin);
            gets(name);
            
            break;
            case 6:
            ghifile(root,count);
            break;
            case 7:
            break;
            case 8:
            break;
            case 9:
            break;
            case 10:
            return 0;
            case 11:
            giaiphong(&A,count);
            freeTree(root);
            //sau khi giai phong thi khong goi den A nua
            break;

        }
    }while(1);
}