#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void sapxep(char DS[5][31],int n)
{
    char tmp[31];
    for(int i=n;i>1;i--)
    for(int j=1;j<i;j++)
    if(compareName( (DS[j-1]) , (DS[j]) ) > 0)
    {
        strcpy(tmp,DS[j-1]);
        strcpy(DS[j-1],DS[j]);
        strcpy(DS[j],tmp);
    }
}
int compareName(char hoten1[], char hoten2[])
{
int pos1;
for(pos1=strlen(hoten1)-1; pos1>=0; pos1--)
if(hoten1[pos1]==' ') break;
int pos2;
for(pos2=strlen(hoten2)-1; pos2>=0; pos2--)
if(hoten2[pos2]==' ') break;
return strcmp(hoten1+pos1+1, hoten2+pos2+1);
}



int main()
{
    char DS[5][31];
    FILE *f;
    char filename[]="D:\\c\\tuan2\\b1.txt ";
    f=fopen(filename,"r");
    int i;
    
    if(f==NULL)
    {
        perror("ko mo file thanh cong ");
        return -1;
    }

    i=0;
    while(fgets(DS[i],31,f)!=NULL)
    {
        puts(DS[i]);
        i++;
    }
    int n;
    n=i;
    sapxep(DS,n);

    printf("\nday sau khi sap xep:\n");
    for(i=0;i<n;i++)
    {
        puts(DS[i]);
    }
    fclose(f);
    return 0;

}
