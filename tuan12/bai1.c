#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<time.h>
#include<sys/time.h>
//ham sinh so ngau  nhien 
int getNextNumber()
{
    int a=rand();
    int b=rand();
    return a*1000+b;
}
//ham tinh thoi gian 
struct timeval timeSub(struct timeval b,struct timeval a)
{
    struct timeval result;
    result.tv_sec = a.tv_sec - b.tv_sec;
    result.tv_usec = a.tv_usec - b.tv_usec;
    if(result.tv_usec<0)
    {
        result.tv_usec=1000000 +result.tv_usec;
        result.tv_sec--;
    }
    return result;
}
//ham tao mang n phan tu 
//cac phan tu khong trung nhau

int *generateRandomArray(int size)
{
    struct timeval before,after,result;
    gettimeofday(&before,NULL);
    //khai bao mang dong 
    
    int *arr = (int *)malloc(size*sizeof(int));//khai bao mang dong 
    int check,nextnum,n=0;
    while(n<size)
    {
        nextnum = getNextNumber();
        check=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==nextnum)
            {
                check=1;
                break;
            }
        }
        if(check==0) 
       {
            arr[n]=nextnum;
            n++;
       }
    }
    gettimeofday(&after,NULL);//thoi gian sau khi co mang 
    result = timeSub(before,after);
    printf("\nthoi gian sinh mang la : %ld.%06ld",(long int)result.tv_sec,(long int)result.tv_usec);
    return arr;
}
//ham in ra cac phan tu trong mang
void printfArr(int *arr,int size)
{
    printf("\ncac phan tu co trong danh sach la \n");
    for(int i=0;i<size;i++)
    {
        printf("%9d, ",arr[i]);
        if((i+1)%10==0)
        printf("\n");
    }
}
//ham delay time 
void delay(int number_of_seconds)
{
    //doi sang mili giay
    int mili_seconds = 1000*number_of_seconds;
    //tgian bat dau 
    clock_t start_time = clock();
    //vong lap tgian 
    while(clock()<start_time+mili_seconds);
}
//ham tim kiem tuan tu 
void sequentialSearch(int *arr,int size)
{
    int searchKey = getNextNumber();
    for(int i=0;i<size;i++)
    {
        if(arr[i]==searchKey)
        {
            printf("found key %d at %d\n",searchKey,i);
            return;
        }
    }
  //  printf("could not find key %d\n",searchKey);
}
//ham tinh thoi gian cua viec tim kiem tuan tu n lan
void checkTimeSpend(int *arr,int size,int repeats)
{
    struct timeval before,after,result;
    gettimeofday(&before,NULL);
    for(int i=0;i<repeats;i++)
    {
        sequentialSearch(arr,size);
    }
    gettimeofday(&after,NULL);
    result = timeSub(before,after);
    printf("\ntgian tim kiem tuan tu %d lan la %ld.%06ld",repeats,(long int)result.tv_sec,(long int)result.tv_usec);
}
//ham sap xep mang 
void sapxep(int *a,int size)
{
    struct timeval before,after,result;
    gettimeofday(&before,NULL);
    int count=0;
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(a[j]<a[i])
            {
                count=a[i];
                a[i]=a[j];
                a[j]=count;
            }
        }
    }
    gettimeofday(&after,NULL);
    result = timeSub(before,after);
    printf("\nthoi gian sap xep mang tuan tu la :%ld.%06ld",(long int)result.tv_sec,(long int)result.tv_usec);

}
void selectionSort(int A[], int N){
// index tu1 -> N
struct timeval before,after,result;
    gettimeofday(&before,NULL);
for(int k = 1; k < N-1; k++){
int min = k;
for(int j = k+1; j < N; j++)
{if(A[min] > A[j]) 
min = j;
}
int tmp= A[min];
 A[min] = A[k];
 A[k] = tmp;
}
 gettimeofday(&after,NULL);
    result = timeSub(before,after);
    printf("\nthoi gian sap xep mang noi bot la :%ld.%06ld",(long int)result.tv_sec,(long int)result.tv_usec);
}
//tim kiem nhi phan 
struct Node {
    int data;
    struct Node *right,*left;
};
struct Node *makeNewNode(int data){
   struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->left = newNode->right = NULL;
   return newNode;
}
//them not
struct Node *addNode(struct Node *root,int data)
{
    if(root ==NULL) return makeNewNode(data);

    if(data < root->data)
    root->left = addNode(root->left,data);
    else
    root->right = addNode(root->right,data);
    return root;
}
//ham tao cay
struct Node *creatTree(int size)
{
    int num;
    //num = getNextNumber();
    struct Node *root=NULL ;
    int n=0;
    while(n<size)
    {
        num = getNextNumber();
        if(root==NULL)
        {
            root = makeNewNode(num);
            n++;
        }
        else{//neu khong phai la nut dau tien 
            addNode(root,num);
            n++;
        }
    }
    return root;
}
//tim kiem nhi phan 
struct Node *findNode(struct Node *root,int key)
{
    if(root==NULL||root->data==key) return root;
    struct Node *find = findNode(root->left,key);
    if(find!=NULL) return find;
    return findNode(root->right,key);
}
//in theo thu tu truoc 
void printfTree(struct Node *root)
{
    if(root==NULL) return;
    printf("%d ,",root->data);
    printfTree(root->left);
    printfTree(root->right);
}
//tim kiem cho den khi thay thi thoi 
void time_find(struct Node *root,int size,int repeat)
{
    struct timeval before,after,result;
    int n,check,key;
    int count=0;
    gettimeofday(&before,NULL);
    while(repeat>0){
        key = getNextNumber();
        if(findNode(root,key)!=NULL) break;
        repeat--;
    }
    gettimeofday(&after,NULL);
    result = timeSub(before,after);
    printf("\ntgian tim kiem nhi phan la %ld.06%ld",(long int)result.tv_sec,(long int)result.tv_usec);
}
int main()
{
    int repeat=5000;
    int *arr = generateRandomArray(20);
    printfArr(arr,20);
    sapxep(arr,20);
    selectionSort(arr,20);
    printf("\ncay nhi phan la :");
    struct Node *root = creatTree(20);
    printfTree(root);
    time_find(root,20,repeat);
    //thoi gian tim kiem tuan tu n la 
    checkTimeSpend(arr,20,repeat);
    return 0;
}