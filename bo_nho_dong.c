#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int sl=21;
const int size=30;
//ham dieu chinh ki tu cuoi cung la '\0'
void tu_chuan(char *word)
{
    int i=0;
    while(i<strlen(word))
    {
        if(word[i]=='\r'||word[i]=='\n')
        {
            word[i]='\0';
            break;
        }
        else i++;
    }
}
//ham doc tu ra tu file
char **nhaptu(char *filename,int *so_tu)
{
    char **words;
    FILE *f;
    f=fopen(filename,"r");
    //cap phat so luong tu
    words=(char**)malloc(sizeof(char*)*sl);
    int i,n;
    char buff[size];
    i=0;
    while(fgets(buff,size,f)!=NULL)
    {
        tu_chuan(buff);
        words[i]=(char*)malloc(sizeof(char)*(strlen(buff)+1));
        strcpy(words[i], buff);
        puts(words[i]);
        i++;
    }
    *so_tu=i;
    fclose(f);
    
    printf("so luong tu :%d",*so_tu);
    return words;

}
//ham giai phong bo nho cap phat dong 
void freemem(char** pointer)
{
    int i;
    for(i=0;i<sl;i++)
    free(pointer[i]);
    free(pointer);
}
int check(char *word,char **words)
{
    //so sanh 2 tu
    for(int i=0;i<sl;i++)
    {
        if(strcmp(word,words[i])==0) 
        return 1;
    }
    return 0;

}
int main()
{
    char **words;
    int i,n;
    int so_tu;
    char filename[]="D:\\c\\b4.out";
    char lookw[size];
    words=nhaptu(filename,&so_tu);
    
    printf("\ntra cuu tu dien:\n");
    while(1)
    {
        printf("\nnhap vao tu can tra:");
        fflush(stdin);
        gets(lookw);
        if(strcmp(lookw,"@")==0) break;
        if(check(lookw,words))
        printf("\ntu nay dung");
        else 
        printf("\nko co tu nay trong tu dien");

    }
    freemem(words);
    return 0;
}