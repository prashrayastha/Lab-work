#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct circularlinkedlist{
	int data;
	struct circularlinkedlist *next;
};
//typedef struct circluarlinkedlist struct circularlinkedlist;

void insert();
void display();
void Delete();
struct circularlinkedlist *last=NULL;
struct circularlinkedlist *first=NULL;
struct circularlinkedlist *newnode=NULL;
int size=0;

int main(){
	int opt;
	
	struct circularlinkedlist *c1;
	do{
	system ("CLS");
	printf("your options are :");
	printf("\n 1. \t INSERT\n 2. \t DELETE\n 3. \t DISPLAY\n 4. \t EXIT");
	printf("\n Enter your option:");
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
	int position,i=1,a;
	struct circularlinkedlist *prevnode,*temp;
	newnode=(struct circularlinkedlist*)malloc(sizeof (struct circularlinkedlist));
	printf("Enter the data to add:");
	scanf("%d",&a);
	newnode->data=a;
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
void display(){
	if(size ==0){
		printf ("list does not exist.");
	}
	else{
		struct circularlinkedlist *temp;
		temp = first;
		do{
			printf("%d\t",temp->data);
		
			temp=temp->next;
		}while(temp!=first);
		getch();
	}
}
void Delete(){
	struct circularlinkedlist *temp,*prev;
	temp = first;

	if(size==0){
		printf("list does not exist.");
	}
	else{
		int position,i=0;
		printf("enter the positon of data to delete(1-%d):",size);
		scanf("%d",&position);
		if(position>= size){
			while(temp->next!=first){
				prev=temp;
				temp=temp->next;
			}
			prev->next=last->next;
			printf("%d\n",last->data);
			free(last);
			last=prev;
		}	
		else if (position <= 1){
			printf("%d\n",first->data);
			free(first);
			first=temp->next;
			}
		else{
			while(i<= position){
				prev=temp;
				temp=temp->next;
				i++;
			}
			printf("%d\n",temp->data);
			prev->next=temp->next;
			
			;
		}
	}
	getch();
}
