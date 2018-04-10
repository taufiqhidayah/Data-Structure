#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
struct node{
	char name[29];
	char type[29];
	int qty;
	int price;
	struct node *next;
};
struct node *start = NULL;
struct node *display(struct node *start);
struct node *insert_beg(struct node *start);
void init();
int main(){
	init();
	int option;
	system("cls");
	char * menu[]= {"1. Item List", "2. Add<[PUSH] new Item","3. Exit"};
	do{
		printf("BLUE COMPUTER \n");
		printf("=============\n");
		for(int i= 0; i<=2;i++){
			printf("%s \n", menu[i]);
		}
		printf("Input your choice");
		scanf("%d",&option);
		switch(option){
			case 1:
				start=display(start);
				break;
			case 2 : 
			start =insert_beg(start);
				break;
			case 3:
				break;
		}
	}while(option != 4);
	getchar();
	return 0;
}
struct node *display (struct node *start){
	system("cls");
	struct node *ptr;
	ptr = start;
	printf("======================\n\n");
 	printf("NO\t| Name\t\t\t|Type\t\t\t\t|QTY\t\t|PRICE \n");
 	printf("--------------------------------------------------------------\n");
 	int i=1;
	while (ptr != NULL){
		printf("%d. \t| %21s|%21s \t\t|%d \t\t|  $. %d \n", i++, ptr->name,ptr->type,ptr->qty,ptr->price);
		ptr =ptr->next;
	}
	return start;
}
struct node *insert_beg(struct node *start){
	system("cls");
	struct node *ptr, *new_node;
	char nameUsr[12],nameDrs[12];
	int priceD,qtyD,a,b,c;
	do{
		printf("\n Inpur Name ");
		scanf("%s",nameUsr);	
		a = strlen(nameUsr);
	}while(a>=20 || a<=3 );
	do{		getchar();
			printf("\n Inpur Type [processor | graphic card | memory]");
			scanf("%[^\n]s",nameDrs);
			getchar();
	}while(strcmp("processor",nameDrs)!=0 && strcmp("graphic card",nameDrs )!=0 && strcmp("memory",nameDrs )!=0);

	do{
		printf("\n Inpur QTY ");
		scanf("%d",&priceD);
	}while(priceD>=999 && priceD<=50 );
	do{
		printf("\n Inpur  Price ");
		scanf("%d",&priceD);
	}while(priceD>=999 && priceD<=50 );
	do{
		printf("\n Inpur  Price ");
		scanf("%d",&qtyD);
	}while(qtyD>=999 && qtyD<=50 );
	new_node =(struct node *)malloc(sizeof(struct node));
	strcpy(new_node ->name,nameUsr);
	strcpy(new_node ->type,nameDrs);
	new_node -> qty = priceD;
	new_node -> price = qtyD;
	new_node ->  next= NULL;
    ptr = start;
    while(ptr -> next != NULL)
    ptr = ptr -> next;
    ptr -> next = new_node;
	return start;
}
void init(){
	struct node * new_node;	
		
	int	price1[3]={3122,15122,16122};
	int qty1[3]= {12,23,4};
	char * name[]={"ASUS","TOSHOBA","APPLE"};
	char * Type[]={"X45","AAC","MAC"};
	for (int i =0;i<3;i++){
		new_node = (struct node *)malloc(sizeof(struct node));
		strcpy(new_node ->name,name[i]);
		strcpy(new_node ->type,Type[i]);
		new_node ->price=price1[i];
		new_node -> qty =qty1[i];
		new_node ->next= start;
		start= new_node;
	}	
}
