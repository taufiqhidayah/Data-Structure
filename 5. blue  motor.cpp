
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
struct node{
	char name [19];
	int qty;
	char key[12];
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;


bool isEmpty() {
   return head == NULL;
}

//insert link at the first location
void insertFirst(char const * keya, int data) {
	
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	strcpy(link->key,keya);
//   link->key = key;
   link->data = data;
	
   if (isEmpty()) {
      head = link;
      head->next = head;
   } else {
      //point it to old first node
      link->next = head;
		
      //point first to new first node
      head = link;
   }    
}

//display the list
void printList() {
	system("cls");
   struct node *ptr = head;
   printf("\n[ ");
	
   //start from the beginning
   if(head != NULL) {
	
      while(ptr->next != ptr) {     
         printf("(%s,%d) ",ptr->key,ptr->data);
         ptr = ptr->next;
      }
   }
	
   printf(" ]");
}

int main (){

	   insertFirst("as",20);
	   insertFirst("sasa",30);
//	   insertFirst(4,1);
//	   insertFirst(5,40);
//	   insertFirst(6,56); 
	int option;
	system("cls");
	char * menu[]= {"1. View Order List", "2. Add New Order ","3. Take Order","4. Exit"};
	do{
		printf("BLUE Motorcycle Parts \n");
		printf("=============\n");
		for(int i= 0; i<=3;i++){
			printf("%s \n", menu[i]);
		}
		printf("Input your choice");
		scanf("%d",&option);
		switch(option){
			case 1:
				 printList();
				break;
			case 2 : 
			insertFirst("asa",10);
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
ptr=start;
if (ptr == NULL){
	printf("kosong");
}else{
while(ptr -> next !=start)
{
printf("\t %d", ptr -> qty);
ptr = ptr -> next;
}
printf("\t %d", ptr -> qty);

}

	system("pause");
	main();
return start;

}
