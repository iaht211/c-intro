#include<stdlib.h>
#include<stdio.h>
#include<string.h>
const int TOTAL_WORDS = 370100;
const int WORD_LEN = 30;
void standalizeWord(char *Word)
{
int i=0;
while(i<strlen(Word))
{
if(Word[i]=='\r' || Word[i]=='\n')
{
Word[i]='\0';
break;
}
else
i++;			
}
}
char **loadDict(char* filename, int* dict_size)
{
char **Words;
int i,total_size=0;;
char buff[50];
FILE *fPtr;
fPtr = fopen(filename, "r");
if(fPtr == NULL) {
      perror("Error in opening file");
      return(NULL);
   	}

// cap phat mang con tro
Words=(char**)malloc(sizeof(char*)*TOTAL_WORDS);

    i=0;
while(fscanf(fPtr,"%s",buff)!=NULL) {
standalizeWord(buff);		
Words[i] = (char*)malloc(sizeof(char)*(strlen(buff)+1));
strcpy(Words[i],buff);
puts(Words[i]);
total_size=total_size+strlen(buff)+1;
i++;
}
fclose(fPtr);
printf("Total Read: %d\n",i);
printf("Total size: %d\n",total_size);
*dict_size = i;
return Words;
}
 
void freeMem(char **pointer)
{
// giai phong bo nho
for(int i=0;i<TOTAL_WORDS; i++)
free(pointer[i]);	
 
free(pointer);
}
int checkWord(char *a)
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
char **Dict;
char lookupW[30];
int dict_size;
char filename[]="D:\\c\\bai_03.txt";
Dict = loadDict(filename, &dict_size);

printf("Tra cuu tu dien:\n");
while(1)
{
printf("Tu can tra: ");
fflush(stdin);
gets(lookupW);
if(strcmp(lookupW,"@")==0) break;
if(checkWord(lookupW))
printf("Tu nay dung!\n");
else
printf("Tu nay KHONG co trong tu dien!\n");
}

freeMem(Dict);
return 0;

}
