#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct hs {
    char name[30];
    int ms;
};
int size=0;
//ham tao node 
struct hs makeNode(char *name,int ms)
{
    struct hs new;
    strcpy(new.name,name);
    new.ms = ms;
    return new;
}
//ham tim kiem 
int check(struct hs *arr,int ma,int size)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i].ms==ma)
        return 1;
    }
    return 0;
    
}
//ham doc du lieu tu file
struct hs* createARR(const char *filename)
{
    FILE *f;
    f=fopen(filename,"r");
    char a[5];//de nhap vao cai stt va kiem tra ket thuc file
    char name[30];
    int ma;
    /*
    fscanf(f,"%s",a);
    fgets(name,sizeof(name),f);
    fscanf(f,"%d",&ma);
    printf("%s  %d",name,ma);
    */
    struct hs *ARR = (struct hs *)malloc(10*sizeof(struct hs));
    struct hs count;
    while(1)
    {
//fscanf(f,"%d",&stt);
    fscanf(f,"%s",a);
    if(strcmp(a,"---")==0)
    {
        fclose(f);
        return ARR;
    }

    //nhap thong tin tiep
    fflush(stdin);
    fgets(name,sizeof(name),f);
    fflush(stdin);
    fscanf(f,"%d",&ma);

    count = makeNode(name,ma);
   
    if(check(ARR,ma,size)==0)
    {
        ARR[size] = count;
        size++;
    }
    }
}
//ham in ra danh sach
void printfArr(struct hs *arr,int size)
{
    printf("%d\n",size);
    for(int i=0;i<size;i++)
    {
        printf("%d . %s %d\n",i+1,arr[i].name,arr[i].ms);
    }

}
int main()
{
    struct hs *arr = createARR("bai2.txt");
    printfArr(arr,size);

    return 0;
}