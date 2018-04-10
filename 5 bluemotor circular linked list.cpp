
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
struct node{
	char name [19];
	int qty;
	int data;
	struct node *next;
};
node *head=NULL, *last=NULL;
int za=3;
struct node *start = NULL;
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_node(struct node *);

struct node *delete_beg(struct node *);
void deletedata();
int leng;
void init(){
	struct node * new_node;	
		
//	int	price1[3]={3122,15122,16122};
	int qty1[3]= {12,23,4};
	int data[3]={3,2,1};
	char * nama[]={"PE28","Gear","Pipe"};
//	char * Type[]={"X45","AAC","MAC"};
	for (int i =0;i<3;i++){
		new_node = (struct node *)malloc(sizeof(struct node));
		strcpy(new_node ->name,nama[i]);
		new_node -> qty =qty1[i];
		new_node->data=data[i];
		new_node ->next= start;
		start= new_node;
	}	
}
int limit(int n){
	return n;
}

int main (){

	
	  init();
	 
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
				start = display(start);
				break;
			case 2 : 
		start = insert_end(start);
				break;
			case 3:
				start = delete_node(start);
//		deletedata();
//		start = delete_after(start);
				break;
		}
	}while(option != 4);
	getchar();
	return 0;
}
void deletedata(){
	  struct node *myNode;
  myNode=start;

	  node *previous=NULL;
 
int value;
	printf("Insert Num");
	scanf("%d",&value); 
	int flag = 0;
    while(myNode->next!=NULL)
    {
        if(myNode->qty==value)
        {
        	
  flag = 1;
            break;
        }

        previous = myNode;
        myNode = myNode->next;
    }

    if(flag==0)
     printf("Key not found!\n");
 
}
struct node *delete_node(struct node *start){
	  struct node *ptr, *preptr;
      int val;
      printf("\n Enter the value of the node which has to be deleted : ");
      scanf("%d", &val);
      ptr = start;
      if(ptr -> data == val)
      {
        start = delete_beg(start);
        return start;
      }
      else
      {
        while(ptr -> data != val)
        {
          preptr = ptr;
          ptr = ptr -> next;
        }
        preptr -> next = ptr -> next;
		free(ptr);
        return start;
      }
}
  struct node *delete_beg(struct node *start)
  {
    struct node *ptr;
    ptr = start;
    start = start -> next;
    free(ptr);
    return start;
  }
struct node *insert_end(struct node *start)
{	
system("cls");
  struct node *ptr, *new_node;
  int num;
  char nama[12];
	za=za+1;
  printf("%d",za);
  int count;
  do{
	  printf("\n Input name Motorcycle's part [1.. 2o]: ");
	  scanf("%s", nama);
	  count = strlen(nama);
  }while (count<1 && count>=19);
  do{
  	printf("\n Input QTY Motorcycle's part [3.. 3o]' : ");
 	 scanf("%d", &num);
  }while(num>=29 || num<=3);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node -> qty = num;
  new_node -> data =za;
  strcpy(new_node->name,nama);
  ptr = start;
  while(ptr -> next != NULL)
  ptr = ptr -> next;
  ptr -> next = new_node;
  new_node -> next = NULL;
  return start;
}
struct node *display(struct node *start)
{
		system("cls");
  struct node *ptr;
  ptr=start;
  int i=1;
  while(ptr -> next !=NULL)
  {
    printf("%d. \t| %21s|%21d \n", ptr->data, ptr->name,ptr->qty);
    ptr = ptr -> next;
    
  }
	printf("%d. \t| %21s|%21d \n", ptr->data, ptr->name,ptr->qty);
	leng =i-1;
	printf("%d\n", leng);
	limit(leng);
  return start;
}
