#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 5
typedef struct{
  char name[19];
  int stk[MAXSIZE];
  int top;
}beras;
typedef struct stack STACK;
beras rice[100];

char riceType[98];

int sellRice();
void enter(int x);
void getMenu();
void stockRice();

void initCake();
void insertRice();
int main (){
  //  initCake();
  rice[0].top = -1;
  getMenu();	
  return 0;
}

void insertRice(){

  int num;
  if (rice[0].top == (MAXSIZE - 1))
  {
    printf ("Stack is Full\n");
    return;
  }
  else
  {
    
    char nama [19];
    int top;
    top = rice[0].top =  rice[0].top + 1;
    //gets(rice[0].name);
    printf("Input Rice type [ long / medium / short ]");
    scanf("%s", rice[top].name);
    while (strcmp (rice[top].name,"long")  != 0  && strcmp (rice[top].name,"medium")  != 0  && strcmp (rice[top].name,"short")  != 0  ){
      printf("Input Rice type [ long / medium / short ]");
      scanf("%s",rice[top].name);
    }
    printf ("Input weight of the rice sack [10.. 100 kg<s> ] :\n");
    scanf ("%d", &num);
    while(num>= 100 || num<=10){
      printf ("Input weight of the rice sack [10.. 100 kg<s> ] :\n");
      scanf ("%d", &num);
    }
    rice[0].stk[rice[0].top] = num;
  }
  system("pause");
  getMenu();	
  
}
void initCake(){
  // strcpy(rice[0].name ,"Kaka")	;
  // rice[0].stk[0]=12;
}
void enter(int x){
  for(int i=0; i<x;i++){
    printf("\n");
  }
}
void getMenu(){
  	system("cls");
  printf("Blue Rice Stock \n");	
  
  char * menu[] ={"Option :", "1. Stock Rice Sack", "2. Sell Rice","3. Exit"};
  stockRice();
  for(int i =0; i< 4; i++ ){
    printf("%s \n",menu[i]);
  }
  int pilihan;
  printf(">>choose");
  scanf("%d", &pilihan);
  if (pilihan == 1 ) insertRice();
  if (pilihan == 2) sellRice();
  
}
void stockRice(){

  int i;
  if ( rice[0].top == -1)
  {
    printf ("Stack is empty\n");
    
    return;
  }
  else
  {
    printf ("\n The status of the stack is \n");
    if ( rice[0].top == rice[0].top){
      printf ("[%s grain | %d kg<s>] ",  rice[rice[0].top].name, rice[0].stk[rice[0].top] );
      printf("=> top\n");
    }
    for (i =  rice[0].top; i >= 1; i--)
    {
      printf ("[%s grain | %d kg<s>]\n",  rice[i-1].name, rice[0].stk[i-1] );
      
    }
  }
  printf ("\n");
}
int sellRice(){

  int num;
  if ( rice[0].top == - 1)
  {
    printf ("Stack is Empty\n");
   
    system("pause");	 
    getMenu();
    
  }
  else
  {
    num =  rice[0].stk[ rice[0].top];
    printf ("poped element is = %dn",  rice[0].stk[ rice[0].top]);
    rice[0].top =  rice[0].top - 1;
  }
  system("pause");
  getMenu();	
  return(num);
  
}
