#include<stdio.h>
#include<string.h>//su dung cho ham memcpy
#include<time.h>
#include<stdlib.h>
#include<sys/time.h>//ham tinh thoi gian 
//ham tinh tgian 
struct timeval timeSpend(struct timeval b,struct timeval a)
{
    struct timeval result;
    result.tv_sec = a.tv_sec - b.tv_sec;
    result.tv_usec = a.tv_usec - b.tv_usec;
    if(result.tv_usec<0)
    {
        result.tv_sec--;
        result.tv_usec = 1000000 + result.tv_usec;
    }
    return result;
}
//ham sinh so ngau nhien 
int *generateArr(int size)
{
    srand(time(NULL));
    int *Arr = (int *)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++)
    {
        Arr[i] = rand();
    }
    return Arr;
}
//ham tao copy cua ham ban dau 
int *cloneArr(int *A,int size)
{
    int *copiedArr = (int *)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++)
    {
        copiedArr[i] = A[i];
    }
    return copiedArr;
}
//ham in mang ra 
void printArr(int *A,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%7d",A[i]);
        if((i+1)%10==0) printf("\n");
    }
}
//ham doi cho 
void swap(int *a,int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
//ham bubblesort
struct timeval bubblesort(int *input,int size)
{
    struct timeval b,a,re;
    gettimeofday(&b,NULL);
    for(int i=size;i>1;i--)
    {
        for(int j=1;j<i;j++)
        {
            if(input[j-1]>input[j]) swap(&input[j-1],&input[j]);
        }
    }
    gettimeofday(&a,NULL);
    re = timeSpend(b,a);
    return re;
    
}
//sap xep lua chon 
struct timeval  selectionsort(int *input,int size)
{
        struct timeval b,a,re;
        gettimeofday(&b,NULL);
    for(int i=size;i>1;i--)
    {
        int Max = 0;
        for(int j=1;j<i;j++)
        if(input[j]>input[Max]) Max = j;
        swap(&input[i-1],&input[Max]);
    }
    gettimeofday(&a,NULL);
    re = timeSpend(b,a);
    return re;
}
//sap xep chen tren mang 
void insertionSort(int *input,int size)
{
    for(int i=1;i<size;i++)
    {
        int key = input[i];
        int j=i-1;
        while(j>=0&&input[j]>key)
        {
            input[j+1] = input[j];
            j--;
        }
        input[j+1] = key;
    }
}

int main()
{
    int *A,size;
    size=10;
    struct timeval result;
    A = generateArr(size);
    printf("mang ban dau la :\n");
    //printArr(A,size);
    //bubblesort
    int *copiedArr = cloneArr(A,size);
    result = bubblesort(copiedArr,size);
    printf("\ntgian %ld.%.5ld",result.tv_sec,result.tv_usec);
    printf("\nham ban dau sau khi bubblesort la :\n");
   // printArr(copiedArr,size);
    //selectionsort
    free(copiedArr);
    copiedArr = cloneArr(A,size);
    result = selectionsort(copiedArr,size);
    printf("\nham sau khi selectionsort la :\n");
    printf("\ntgian %ld.%.5ld",result.tv_sec,result.tv_usec);

    //printArr(copiedArr,size);
    //selectionsort
    insertionSort(copiedArr,size);
    printArr(copiedArr,size);

    return 0;
}
