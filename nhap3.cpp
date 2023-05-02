#include <stdio.h>
#include<string.h>
int check(char a[])
{
	int i=0;
	
		if(a[0]>=65&&a[0]<=90)
		return 1;
	
	return 0;
}
int main ()
{
   FILE *fp;
   int c;
   int n = 0;
  char a[30];
  
   fp = fopen("D:\\c\\bai5.txt","r");
   if(fp == NULL) 
   {
      perror("Xay ra loi khi mo baitapc.txt !!!");
      return(-1);
   }
   do
   {
      fscanf(fp,"%s",a);
      if( feof(fp) )
      {
         break ;
      }
      if(check(a))
      printf("%s ,", a);

   }while(1);

   fclose(fp);
   return(0);
}