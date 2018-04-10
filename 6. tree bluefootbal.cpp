#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include<string.h>
#include <stdlib.h>
struct Player{
//	char name[12];
	int number;
	struct Player *left;
	struct Player *right;
};

int main(){	
int option;
	do{		
		system("cls");
		char * menu[]={"View All Player","Add Player","Remove Player","Inorder  Postorder","Exit Remove ALl"};
		for(int i = 0; i<5;i++){
			printf("%d. %s \n", i+1, menu[i]);
		}
	
		scanf("%d",&option);
		
		switch(option){
			case 1: 
				
			break;
			case 2:
			break;
			case 3:
			break;
			case 4:
			break;
			
		}
		
	}while(option!=5);
	getchar();
	return  0;
	
}
