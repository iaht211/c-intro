#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct data_s{
    int DD, MM, YYY;
    int hh, mm, ss;
    char number[12];
    int type;
} data_t;

typedef struct node_s {
    
    data_t data;
    struct node_s *left, *right;
} node_t;

typedef node_t *tree_t;

int n = 0;
int countNode = 0, position = 0;
//cap phat bo nho dong
data_t* park ;


//them 10 phan tu ( neu can ) !
// park = (data_t*)realloc(park, 10* sizeof(data_t));

//===============================BST=======================
tree_t treeInit(){
  return NULL;
}

tree_t makeTreeNode(data_t item)
{
    node_t* temp = (node_t*)malloc(sizeof(node_t*));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

tree_t Search(char x[], tree_t Root) {
    if (Root == NULL)
        return NULL;           // not found
    else if (strcmp(Root->data.number, x)==0) /* found x */
        return Root;
    else if (strcmp(Root->data.number, x)<0)
        // continue searching in the right sub tree
        return Search(x, Root->right);
    else {
        // continue searching in the left sub tree
        return Search(x, Root->left);
    }
}

void Insertnode_t(data_t x, tree_t *pRoot) {
    if (*pRoot == NULL) {
        /* Create a new node for key x */
        *pRoot = (node_t *)malloc(sizeof(node_t));
        (*pRoot)->data = x;
        (*pRoot)->left = NULL;
        (*pRoot)->right = NULL;
    }else if (strcmp ( x.number , (*pRoot)->data.number ) < 0)
    Insertnode_t(x, &((*pRoot)->left));
    else if ((x.number , (*pRoot)->data.number) > 0 )
    Insertnode_t(x, &((*pRoot)->right));
}

char* DeleteMin(tree_t *Root) {
    char key[12];
    char *k = key;
    if ((*Root)->left == NULL) {
        strcpy(key,(*Root)->data.number);
        (*Root) = (*Root)->right;
        return k;
    } else
    return DeleteMin(&(*Root)->left);
}

void Deletenode_t(char x[], tree_t *Root) {
    if (*Root != NULL)
    if (strcmp(x , (*Root)->data.number) < 0 )
        Deletenode_t(x, &(*Root)->left);
    else if (strcmp(x, (*Root)->data.number) > 0 )
        Deletenode_t(x, &(*Root)->right);
    else if (((*Root)->left == NULL) && ((*Root)->right == NULL))
        *Root = NULL;
    else if ((*Root)->left == NULL)
        *Root = (*Root)->right;
    else if ((*Root)->right == NULL)
        *Root = (*Root)->left;
    else 
        strcpy((*Root)->data.number,DeleteMin(&(*Root)->right)); 
}

void printInorder(tree_t tree)
{
    if (tree == NULL)
        return;
 
    /* first recur on left child */
    printInorder(tree->left);
 
    /* then print the data of node */
    printf("%s  %d-%d-%d %02d:%02d:%02d\n",tree->data.number,tree->data.YYY,tree->data.MM,tree->data.DD,tree->data.hh,tree->data.mm,tree->data.ss);

 
    /* now recur on right child */
    printInorder(tree->right);
}

void f_printInorder(tree_t tree, FILE* f)
{
    if (tree == NULL)
        return;
 
    /* first recur on left child */
    f_printInorder(tree->left,f);
 
    /* then print the data of node */
    fprintf(f,"%s  %d-%d-%d %02d:%02d:%02d\n",tree->data.number,tree->data.YYY,tree->data.MM,tree->data.DD,tree->data.hh,tree->data.mm,tree->data.ss);

 
    /* now recur on right child */
    f_printInorder(tree->right,f);
}

void freetree(tree_t tree) {
  if (tree != NULL) {
    freetree(tree->left);
    freetree(tree->right);
    free((void *)tree);
  }
}
//=========================================================

tree_t query(tree_t root, int l, int r){
   
    for (int i = l ; i < r ; i++ )
      if(park[i].type == 1){
        Insertnode_t(park[i], &root);
        countNode++;
      }
      else{
        Deletenode_t(park[i].number, &root);
        countNode--;
      }
     
    return root;  
}

void showLog(){
 for(int i = 0 ; i < n ; i++)
    printf("%d-%d-%d %02d:%02d:%02d %s %d\n",park[i].YYY,park[i].MM,park[i].DD,park[i].hh,park[i].mm,park[i].ss,park[i].number,park[i].type);
}

int task1(){
  FILE* f = fopen("log_input.txt","r");
  if(f==NULL){ 
    printf("ERORR: Can't open file !\n"); 
    fclose(f);
    return 1;
  }
  data_t newData;
  while(!feof(f)){
    fscanf(f, "%d-%d-%d",&newData.YYY,&newData.MM,&newData.DD);
    fscanf(f, "%d:%d:%d",&newData.hh,&newData.mm,&newData.ss);
    fscanf(f, "%s",newData.number);
    fscanf(f, "%d",&newData.type);
    park[n++] = newData;
  }
  position = n; //Vi tri du lieu cuoi cung nhap tu file log_input.txt
  fclose(f);
  printf("Du lieu da nhap:\n");
  showLog();
  return 0;
}

void task2(int year, int month, int day){

  int in = 0, out = 0 ;
  for (int i = 0 ; i < n ; i++) 
    if(park[i].YYY==year && park[i].MM==month && park[i].DD==day){
      if( park[i].type == 0) out++;
      else if(park[i].type == 1) in++;
    }
  printf("Date %d-%d-%d Total %d, In %d, out %d\n",year,month,day,in+out,in,out);
}

void task3(tree_t root){
  printf("Tong so xe hien co: %d\n", countNode);
  printf("%s%18s\n","Bien so","Thoi gian gui");
  printInorder(root);
}

void printTime(data_t *data){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  data->YYY = tm.tm_year + 1900;
  data->MM = tm.tm_mon + 1;
  data->DD = tm.tm_mday;
  data->hh = tm.tm_hour;
  data->mm = tm.tm_min;
  data->ss = tm.tm_sec;
  printf("Hien tai la: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1,tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void task4(tree_t root){

  char input_Number[12];
  printf("Nhap bien so xe:\n");
  scanf("%s",input_Number);

  node_t* check = Search(input_Number,root);
  if( check != NULL ){ 
    printf("!!!ERORR!!!\n");
  }
  else{
    data_t newData;
    newData.type = 1;
    strcpy(newData.number, input_Number);
    printTime(&newData);
    park[n++] = newData;
  }
  
}

void task5(tree_t root){

  char input_Number[12];
  printf("Nhap bien so xe:\n");
  scanf("%s",input_Number);

  node_t* check = Search(input_Number,root);
  if( check == NULL ){ 
    printf("!!!ERORR!!!\n");
  }
  else{
    data_t newData;
    newData.type = 0;
    strcpy(newData.number, input_Number);
    printTime(&newData);
    park[n++] = newData;
  }

}

void task6(){
  showLog();
}

int task7(tree_t root){
  FILE* f = fopen("log_present.txt","w");
  if(f==NULL){
    printf("ERROR: can't open file !\n");
    return 1;
  }
  f_printInorder(root, f);
  fclose(f);
  return 0;
}

int task8(){
  FILE* f = fopen("change_log.txt","w");
  if(f==NULL){
    printf("ERROR: can't open file !\n");
    return 1;
  }
  for(int i = position ; i < n ; i++)
    fprintf(f,"%d-%d-%d %02d:%02d:%02d %s %d\n",park[i].YYY,park[i].MM,park[i].DD,park[i].hh,park[i].mm,park[i].ss,park[i].number,park[i].type);
  fclose(f);
  return 0;
}

void task9(){
  
  data_t In;
  data_t Out;
  printf("Nhap gio vao: <YYY-MM-DD> <hh:mm:ss>\n"); 
  scanf("%d-%d-%d %d:%d:%d",&In.YYY,&In.MM,&In.DD,&In.hh,&In.mm,&In.ss);
  printf("Nhap gio ra: <YYY-MM-DD> <hh:mm:ss>\n");   
  //co the thay bang viec lay thoi gian hien tai
  scanf("%d-%d-%d %d:%d:%d",&Out.YYY,&Out.MM,&Out.DD,&Out.hh,&Out.mm,&Out.ss);

  // Tính số giây trôi qua từ đầu vào một đến đầu vào hai
  struct tm time1 = {0};
  time1.tm_year = In.YYY - 1900;
  time1.tm_mon = In.MM - 1;
  time1.tm_mday = In.DD;
  time1.tm_hour = In.hh;
  time1.tm_min = In.mm;
  time1.tm_sec = In.ss;
  time_t timestamp1 = mktime(&time1);

  struct tm time2 = {0};
  time2.tm_year = Out.YYY - 1900;
  time2.tm_mon = Out.MM - 1;
  time2.tm_mday = Out.DD;
  time2.tm_hour = Out.hh;
  time2.tm_min = Out.mm;
  time2.tm_sec = Out.ss;
  time_t timestamp2 = mktime(&time2);

  //diffInDays: So dem troi qua:
  double diffInSeconds = difftime(timestamp2, timestamp1);
  int diffInDays = (int) (diffInSeconds / (60 * 60 * 24));
  
  int fee = (Out.hh >= 18) ? diffInDays*10000 + 8000 : diffInDays*10000 + 5000; 
  printf("===>>>>Phi can tra la: %d\n",fee);
}

void task10(){
  char input_Number[12];
  int check = 0;
  printf("Nhao bien so xe: \n");
  scanf("%s",input_Number);
  for(int i = 0 ; i < n ; i++) if(strcmp(input_Number, park[i].number)==0)
  {
    printf("%d-%d-%d %02d:%02d:%02d %s %d\n",park[i].YYY,park[i].MM,park[i].DD,park[i].hh,park[i].mm,park[i].ss,park[i].number,park[i].type);
    check = 1;
  }
  if(!check) printf("Xe khong gui tai bai xe !\n");
}

int main(){

  park = (data_t*)malloc(1000*sizeof(data_t));
  if(park==NULL){ 
    printf("ERORR: can't dynamically allocate memory!!!");
    return 1;
  }

  tree_t tree = treeInit();

  int key;
  while(1){

    printf("==============================\n");
    printf("1. Doc du lieu tu file log.\n");
    printf("2. Tra cuu so luong xe gui/lay theo ngay trong qua khu.\n");
    printf("3. Thong tin cac xe trong bai hien tai.\n");
    printf("4. Gui xe moi.\n");
    printf("5. Tra xe.\n");
    printf("6. Cap nhat log (in ra log).\n");
    printf("7. Luu danh sach xe dang co trong bai ra file \" log_present.txt\".\n");
    printf("8. Luu nhung log moi ra file \"change_log.txt\".\n");
    printf("9. Tinh tien gui xe.\n");
    printf("10. Tra cuu lich su gui xe\n");
    printf("11. Thoat.\n");
    printf("==============================\n");

    printf(">>>>Nhap lua chon:\n");
    scanf("%d",&key);

    if(key==1) { 
      task1();
      tree=query(tree,0,n);
    }
    else if(key==2) {
      int year, month, day;
      printf("Nhap ngay muon kierm tra: <YYY-MM-DD>\n");
      scanf("%d-%d-%d",&year,&month,&day);
      task2(year,month,day);
    } 
    else if(key==3){
      task3(tree);
    }
    else if(key==4){
      int tmp = n;
      task4(tree);
      tree=query(tree,tmp,n);
    }
    else if(key==5){
      int tmp = n;
      task5(tree);
      tree=query(tree,tmp,n);
    }
    else  if(key==6){
      task6();
    }
    else if(key==7){
      task7(tree);
    }
    else if(key==8){
      task8();
    }
    else if(key==9){
      task9();
    }
    else if(key==10){
      task10();
    }
    else  if(key==11){
      freetree(tree);
      free(park);
      return 0;
    }
  }

}