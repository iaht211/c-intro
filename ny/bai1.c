#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <tree_c.h>
#include <traversal.h>
#include <ctype.h>

void capitalize (char *str) {
    int length = strlen(str);
    for (int i = 0; i < length;i++) {
        if (str[i] >= 'a'&& str[i] <= 'z') {
            str[i]+='A'-'a';
        }
    }
}

int main(int argc, char **argv) {
    if (argc > 3) {
        printf("Too many arguments.\nExiting.\n");
        exit(1);
    }
    if (argc < 3) {
        printf("Too few arguments.\nExiting.\n");
        exit(1);
    }

    tree_t tree = NULL;
    char a[100][100];
    char filein[100];
    char fileout[100];

    strcpy(filein, argv[1]);
    strcpy(fileout, argv[2]);
    FILE *fin=fopen(filein,"r");
    FILE *fout=fopen(fileout,"w");
    
    if (fin==NULL) {
        printf("Error opening file input.\n");
        exit(1);
    }
    if (fout==NULL) {
        printf("Error opening file output.\n");
        fclose(fin);
        exit(1);
    }
    int size = 0;
    char temp;
    int point=0;
    while (!feof(fin)){
        temp = fgetc(fin);
        if (isalnum(temp)) {
            a[size][point]=temp;
            point++;
        }
        else {
            a[size][point]='\0';
            size++;
            point=0;
        }   
    }
    for (int i=0; i<size; i++) {
        capitalize(a[i]);
        InsertandCount(a[i],&tree);
    }
    f_inorderprint(tree,fout);
    fclose(fin);
    fclose(fout);
    makeNullTree(tree);
}