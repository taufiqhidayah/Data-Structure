#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include<string.h>
#include <stdlib.h>
struct node{
  char name[15];
  int data;
  struct node *left;
  struct node *right;
};

struct node *tree;
struct node *insertElement(struct node *);
void display(struct node *);
void traversal(struct node *);
void inorderTraversal(struct node *);
void preorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *deleteElement(struct node *);

void enter();
void gotoEnter();
void menuUtama(){
	int option;
  do{	
    
    printf("\n ******MAIN MENU******* \n");
    printf("\n 1. View All Player");
    printf("\n 2. Add Player");
    printf("\n 3. Remove Player");
    printf("\n 4. Traversal");
    printf("\n 5. Exit Remove ALl");
    scanf("%d",&option);
    
    switch(option){
      case 1: 
      gotoEnter();
      display(tree);
      break;
      gotoEnter();
      case 2:tree = insertElement(tree);
      break;
      case 3:
      tree = deleteElement(tree);
      break;
      case 4:  
      gotoEnter();
      printf("\nPreorder :"); 	preorderTraversal(tree);
      printf("\nIn Order :"); 	inorderTraversal(tree);
      printf("\nPos Order :");	postorderTraversal(tree);
      break;
      case 5:
      
      break;
    }
    
  }while(option!=5);	
}
int main(){	

	menuUtama();
  return  0;
  
}
void gotoEnter(){
	for (int i=1; i<=29;i++){
		printf("\n");
	}
}
void enter(){
  getchar();
  while(getchar() != '\n'){
    main();
  }
}
struct node *insertElement(struct node *tree){
	system("cls");
  int val,pil,name_lenght;
  char nama[15];
  do{
    printf("Input Player Name [3..2o]");
    scanf("%s",nama);
    name_lenght= strlen(nama);
  }while(name_lenght<=3 && name_lenght>=20);
  do{
    
    printf("Input Player Name [3..2o]");
    scanf("%d",&val);
    
  }while(val<=1 && val>=99);
  struct node *ptr, *nodeptr, *parentptr;
  ptr = (struct node*)malloc(sizeof(struct node));
  strcpy(ptr->name,nama);
  ptr->data = val;
  ptr->left = NULL;
  ptr->right = NULL;
  if(tree==NULL){
    tree=ptr;
    tree->left=NULL;
    tree->right=NULL;
  }
  else{
    parentptr=NULL;
    nodeptr=tree;
    while(nodeptr!=NULL){
      printf("Press 1 for Left and 2 for Right");
      scanf("%d",&pil);
      parentptr=nodeptr;
      
      if(pil==1)
      nodeptr=nodeptr->left;
      else if(pil==2)
      nodeptr = nodeptr->right;
    }
    if(pil==1)
    parentptr->left = ptr;
    else
    parentptr->right = ptr;
  }
  
  printf("add Player success ");
 
  enter();
   system("cls");
  return tree;
  
}
void display(struct node *tree){

  if(tree != NULL){
    printf("- %s <%d>\n",tree->name, tree->data);
    display(tree->left);
    display(tree->right);
  }
}

struct node *deleteElement(struct node *tree){
  
  return tree;
}
void preorderTraversal(struct node *tree){
  if(tree != NULL){
    printf("%d ", tree->data);
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
  }
}
void inorderTraversal(struct node *tree){
  if(tree != NULL){
    inorderTraversal(tree->left);
    printf("%d ", tree->data);
    inorderTraversal(tree->right);
  }
}
void postorderTraversal(struct node *tree){
  
  if(tree != NULL){
    postorderTraversal(tree->left);
    postorderTraversal(tree->right);
    printf("%d ", tree->data);
  }
}
