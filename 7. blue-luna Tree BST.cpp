#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
struct node{
	char karakter[20];
	char job[31];
	int data,level;
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

		printf("\nBLUE-LUNA ONLINE \n");
		printf("---------------- \n");
		printf("1. View All Profile  \n");
		printf("2. Add new player \n");
		printf("3. Inorder, Postorder damage\n");
		printf("4. exit\n");
		printf(">>Input choice \n");
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
			gotoEnter();
			printf("\nPreorder :"); 	preorderTraversal(tree);
			printf("\nIn Order :"); 	inorderTraversal(tree);
			printf("\nPos Order :");	postorderTraversal(tree);
			break;
			default:
			break;


		}

	}while(option!=4);
}
int main(){
	menuUtama();
	return 0;
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
	int val,pil,name_lenght,levelkara;
	char kara[15];
	char karajob[15];
	do{
		printf("Input Charackter Name [3..2o]");
		scanf("%s",kara);
		name_lenght= strlen(kara);
	}while(name_lenght<=3 && name_lenght>=20);
	do{
		printf("Input Charackter Job [fighter/rogue/mage]");
		scanf("%s",karajob);

	}while (strcmp("fighter",karajob )!=0&&strcmp("rogue",karajob)!=0&&strcmp("mage",karajob)!=0);
	do{
		printf("Input Level Charackter [1..1o5]");
		scanf("%d",&levelkara);
	}while(levelkara<=1 && levelkara>=105);
	if(strcmp("fighter",karajob )!=0){
		
		srand(time(NULL));   // should only be called once
		int ran = rand()%49;
		val = ran + levelkara;
	
	}else if (strcmp("rogue",karajob)!=0){
		srand(time(NULL));   // should only be called once
		int ran = rand()%24;
		val = ran + levelkara;
	}else{
		srand(time(NULL));   // should only be called once
		int ran = rand()%74;
		val = ran + levelkara;
	}
	struct node *ptr, *nodeptr, *parentptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	strcpy(ptr->karakter,kara);
	strcpy(ptr->karakter,kara);
	strcpy(ptr->job,karajob);
	ptr->level = levelkara;
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	if(tree==NULL)
	{
		tree=ptr;
		tree->left=NULL;
		tree->right=NULL;
	}
	else
	{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL)
		{
			parentptr=nodeptr;
			if(val<nodeptr->data)
			nodeptr=nodeptr->left;
			else
			nodeptr = nodeptr->right;
		}
		if(val<parentptr->data)
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
	 if (tree == NULL){
		printf("Tree is no Charackter in the Tree");
	}else if(tree != NULL){
		printf("* %s \t\t |%s \t\t |lvl. %d \t\t|damage : %d \n", tree->karakter,tree->job,tree->level, tree->data);
		display(tree->left);
		display(tree->right);
	}
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
