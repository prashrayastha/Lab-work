#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct circularlinkedlist{
	int data;
	struct circularlinkedlist *next;
};
typedef struct circluarlinkedlist cll;

void insert();
void display();
void Delete();
cll *last;
cll *first;
first=last;
cll *newnode;
int size=0;

int main(){
	int opt;
	
	cll *c1;
	do{
	system ("CLS");
	printf("your options are :");
	printf("/n 1. /t INSERT/n 2. /t DELETE/n 3. DISPLAY/n 4. /t EXIT");
	scanf("%d",&opt);
	switch(opt){
		case 1:
			insert();
			size++;
			break;
		case 2:
		    Delete();
		    size--;
			break;
		case 3:
			display();
			break;			
	}
	}while(opt!=4);
	
}
void insert(){
	int position,i=1;
	cll *prevnode,*temp;
	newnode=(cll*)malloc(sizeof(cll));
	scanf("%d",&newnode->data);
	if(first == NULL){
		first=newnode;
		last=newnode;
		last->next=first;
	}
	
	
	else {
		printf("Enter position to insert new node [1-%d]: ",size+1);
		scanf("%d",&position);
		if(position >size+1 ||position<1){
			printf("INVALID POSITION");
		}
		else if(position<=size){
			temp=first;
			while(i<position){
				prevnode=temp;
				temp =temp->next;
				i++;
				}
				newnode->next=prevnode->next;
				prevnode->next=newnode;
		}
		else
		{
			last->next=newnode;
			last=newnode;
			last->next=first;
		}
		
	}
}