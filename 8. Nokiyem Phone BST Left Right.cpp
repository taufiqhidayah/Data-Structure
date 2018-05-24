#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
int val;
struct node{
  int sncode,price;
  struct node *left;
  struct node *right;
};
struct node *deleteElement(struct node *);
void inOrder(struct node*);
void preOrder( struct node* );
struct node *add(struct node *);
void editVal(struct node *tree);
void postOrder(struct node*);
struct node *tree;
struct node *insertData(struct node *tree);

int main(){
  int pilih;
  do {
    char * menuUtamaa[] ={ "1. Add New Player", "2. Update Phone Price", "3.  inOrder, preOrder, postOrder","4. Exit"};
    printf("\nNOKIYEM CELLULAR PHONE\n");
    printf("\n=========================\n");
    
    for( int i =  0; i< 3; i++){
      printf("%s \n", menuUtamaa[i]);
    }
    scanf("%d",&pilih );
    getchar();
    if (pilih == 1) {
      system("cls");
      tree=insertData(tree);
    }else if(pilih == 2){
      system("cls");
      printf("Input Phone Code\n");
      scanf("%d", &val);
      editVal(tree);
    }else if(pilih == 3){
      system("cls");
      printf("\nPreorder :"); 	preOrder(tree);
      printf("\nIn Order :"); 	inOrder(tree);
      printf("\nPos Order :");	postOrder(tree);
    }
  }while(pilih !=4);
  return 0;
}

struct node *insertData(struct node *tree){
  system("cls");
  struct node *newnode,*nodeptr,*parentptr;
  int harga,kode;
  
  do{
    printf("Input Phone Code N[1-9][0-9][0-9][0-9] : N");
    scanf("%d",&kode);
  }while(kode<1000||kode>9999);
  
  do {
    printf("Input Phone Price[$50...$999]: ");
    scanf("%d",&harga);
  } while(harga<50 || harga>999);
  
  
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->sncode=kode;
  newnode->price=harga;
  newnode->left=NULL;
  newnode->right=NULL;
  
  if(tree==NULL){
    tree=newnode;
    tree->left=NULL;
    tree->right=NULL;
  }else{
    parentptr=NULL;
    nodeptr=tree;
    
    while(nodeptr!=NULL)
    {
      parentptr=nodeptr;
      if(kode<=tree->sncode){
        nodeptr=nodeptr->left;
      }else{
        nodeptr=nodeptr->right;
      }
    }
    if(kode<=tree->sncode){
      parentptr->left=newnode;
    }else{
      parentptr->right=newnode;
    }
  }
  return tree;
}

void inOrder(struct node* tree) {
  if(tree != NULL){
    inOrder(tree->left);
    printf("\n- N%d  [$ %d ]", tree->sncode, tree->price);
    inOrder(tree->right);
  }
}
void preOrder( struct node* tree ){
  if(tree != NULL){
    printf("\n- N%d  [$ %d ]", tree->sncode, tree->price);
    preOrder(tree->left);
    preOrder(tree->right);
  }
}
void postOrder(struct node * tree){
  if(tree != NULL){
    inOrder(tree->left);
    inOrder(tree->right);
    printf("\n- N%d  [$ %d ]", tree->sncode, tree->price);
  }
}
void editVal( struct node *tree){
  
  if(tree->sncode != val){
    editVal(tree->left);
    editVal(tree->right);
  }else if(tree->sncode == val){
    int hasil;
    printf("\n- N%d  [$ %d ]\n", tree->sncode, tree->price);
    printf("Inpur new phone price");
    scanf("%d", &hasil);
    tree->price=hasil;
  }
}
