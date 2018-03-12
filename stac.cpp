/*
 * C program to implement stack. Stack is a LIFO data structure.
 * Stack operations: PUSH(insert operation), POP(Delete operation)
 * and Display stack.
 */
#include <stdio.h>
#define MAXSIZE 5
typedef struct
{
    int stk[MAXSIZE];
    int top;
    char name[19];
}mhs;
typedef struct stack STACK;
//STACK s;
mhs student[100];
 
void push(void);
int  pop(void);
void display(void);
 
 main ()
{
    int choice;
    int option = 1;
    student[0].top = -1;
 
    printf ("STACK OPERATION\n");
    while (option)
    {
        printf ("------------------------------------------\n");
        printf ("      1    -->    PUSH               \n");
        printf ("      2    -->    POP               \n");
        printf ("      3    -->    DISPLAY               \n");
        printf ("      4    -->    EXIT           \n");
        printf ("------------------------------------------\n");
 
        printf ("Enter your choice\n");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
        fflush (stdin);
        printf ("Do you want to continue(Type 0 or 1)?\n");
        scanf    ("%d", &option);
    }
}
/*  Function to add an element to the stack */
void push ()
{
    int num;
    if (student[0].top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        printf ("Enter the element to be pushed\n");
        scanf ("%d", &num);
        char nama [19];
 int top;
 top = student[0].top =  student[0].top + 1;
//gets(student[0].name);
	printf("nNPM = "); 
	scanf("%s", student[top].name);
	    
         student[0].stk[student[0].top] = num;
//           student[0].name[student[0].top] = na;
    }
    
}
/*  Function to delete an element from the stack */
int pop ()
{
    int num;
    if ( student[0].top == - 1)
    {
        printf ("Stack is Empty\n");
        return ( student[0].top);
    }
    else
    {
        num =  student[0].stk[ student[0].top];
        printf ("poped element is = %dn",  student[0].stk[ student[0].top]);
        student[0].top =  student[0].top - 1;
    }
    return(num);
}
/*  Function to display the status of the stack */
void display ()
{
    int i;
    if ( student[0].top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i =  student[0].top; i >= 0; i--)
        {
            printf ("%d %s\n",  student[0].stk[i], student[i].name);
        }
    }
    printf ("\n");
}
