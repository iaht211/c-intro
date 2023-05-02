#include<stdio.h>
#include<string.h>

int comparename(char *hoten1,char *hoten2)
{
	int pos1;
	for(pos1=strlen(hoten1)-1;pos1>=0;pos1--)
	if(hoten1[pos1]==' ') break;
	int pos2;
	for(pos2=strlen(hoten2)-1;pos2>=0;pos2--)
	if(hoten2[pos2]==' ') break;
	return strcmp(hoten1+pos1+1,hoten2+pos2+1);
}
int main()
{
    char hoten1[31]="joe birden",hoten2[31]="elon mush";
    printf("%d\n",comparename(hoten1,hoten2));
	return 0;
}
