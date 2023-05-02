#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int sl=17;
const int size=30;
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
int check(char* a)
{
	int i=0;
	while(i<strlen(a))
	{
		if(a[i]>=65&&a[i]<=90)
		return 1;
	}
	return 0;
}
int main()
{
	FILE *f;
	char filename[]="D:\\c\\bai_03.txt";
	f=fopen(filename,"r");
	char **word;
	word=(char**)malloc(sizeof(char*)*sl);
	int i,n;
	char buff[30];
	i=0;
	while(fgets(buff,sl,f)!=NULL)
	{
		tu_chuan(buff);
		word[i]=(char*)malloc(sizeof(char)*(strlen(buff)+1));
		strcpy(word[i],buff);
		puts(word[i]);
		i++;
	}
    n=i;
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{
		if(check(word[i]))
		printf("%s ",word[i]);
	}

	fclose(f);
	
	free(word[i]);
	free(word);
	return 0;

}