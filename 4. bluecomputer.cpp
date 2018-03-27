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
 	printf("NO | Customer Name | Dress Name | Price\n");
 	printf("--------------------------------------------------------------\n");
 	int i=1;
	while (ptr != NULL){
		printf("%d. | %12s | %-12s |%d     | Rp. %d \n", i++, ptr->name,ptr->type,ptr->qty,ptr->price);
		ptr =ptr->next;
	}
	return start;
}
struct node *insert_beg(struct node *start){
	struct node *new_node;
	int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> ptr = num;
    new_node -> next = start;
	start = new_node;
    return start;
}
void init(){
	struct node * new_node;	
		
	int	price1[3]={3,15,16};
	int qty1[3]= {12,23,4};
	char * name[]={"martin","suci","diah"};
	char * nameDre[]={"Batik","Kain","Kaos"};
	for (int i =0;i<3;i++){
		new_node = (struct node *)malloc(sizeof(struct node));
		strcpy(new_node ->name,name[i]);
		strcpy(new_node ->type,nameDre[i]);
		new_node ->price=price1[i];
		new_node -> qty =qty1[i];
		new_node ->next= start;
		start= new_node;
	}	
}
