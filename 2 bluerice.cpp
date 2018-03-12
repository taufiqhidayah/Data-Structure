#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 5
struct Beras {
	char name[19];
  	int stock[MAXSIZE];
	int top;
};
typedef struct Beras STACK;
STACK s;
 
//struct Beras Products[10];
//Beras sa;

char riceType[98];

int sellRice();
void enter(int x);
void getMenu();
void stockRice();

void initCake();
void insertRice();

int main (){
	
  initCake();
  getMenu();	
  return 0;
}

void insertRice(){
  	 int num;
    if (s.top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
    	char namea[12];
		
//		while (strcmp (name,"long")  == 0  && strcmp (name,"medium")  == 0  && strcmp (name,"short")  == 0  ){
//			printf("Input Rice type [ long / medium / short ]");
//			scanf("%s"s.name);
//		}
        printf ("Enter the element to be pushed\n");
        scanf ("%d", &num);
        printf("Input Rice type [ long / medium / short ]");
		scanf("%s", s.name);
        s.top = s.top + 1;
        s.stock[s.top] = num;
    
    }
 
//  scanf("%s", riceType);
//  while(strcmp (riceType,"long")  != 0 || strcmp (riceType,"medium" ) != 0 ||strcmp(riceType, "short" ) != 0 ){
//    printf("Input Rice type [ long / medium / short ]");
//    scanf("%s", riceType);	
//  }

     system("pause");
  getMenu();	

    return;
}
void initCake(){
	
//  strcpy(Products[0].name,"Blueberry Cake");
  s.stock[0]=10;
//  strcpy(Products[1].name,"Chocochip Cake");
  s.stock[1]=5;
//  strcpy(Products[2].name,"Mayoinase Cake");
 s.stock[2]=12;
//  strcpy(Products[3].name,"Strowberry ShortCake");
 s.stock[3]=7;
}
void enter(int x){
  for(int i=0; i<x;i++){
    printf("\n");
  }
}
void getMenu(){
  
  printf("Blue Rice Stock \n");	
  
  char * menu[] ={"Option :", "1. Stock Rice Sack", "2. Sell Rice","3. Exit"};
  stockRice();
  for(int i =0; i< 4; i++ ){
    printf("%s \n",menu[i]);
  }
  int pilihan;
  scanf("%d", &pilihan);
  if (pilihan == 1 ) insertRice();
  if (pilihan == 2) sellRice();
  
}
void stockRice(){
//  printf("--------------------------------------------------------------\n");
//  
//  if (sa.stock == -1 ){
//    printf ("Stack is empty\n");
//    return;
//  }
//  else {
//    for (int i =  0; i <= 8; i++){
//      
//      if(i == 0){
//        printf("%d. : %29s | %-12d |", i, Products[0].name, Products[0].stock);
//        printf("top\n");
//      }
//      
//      printf("%d. : %29s | %-12d | \n", i+1, Products[i+1].name, Products[i+1].stock);
//    }
//    printf("--------------------------------------------------------------\n");
//    
//  }
int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%d %s \n", s.stock[i], s.name[i]);
        }
    }
    printf ("\n");
}

int sellRice(){
    int num;
    if (s.top == - 1)
    {
        printf ("Stack is Empty\n");
        return (s.top);
    }
    else
    {
        num = s.stock[s.top];
        printf ("poped element is = %dn", s.stock[s.top]);
        s.top = s.top - 1;
    }
  system("pause");
  getMenu();	

  return(num);

}
