#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 5
struct Queue{
	int front,rear;
	int queue[max];
};
typedef struct Queue Q;

Q q;
int fullchecker(){
	if (q.rear==max-1) 
		return 1;
	else 
		return 0;
}
int emptychecker(){
	if(q.rear<q.front)
		 return 1;
	else
		 return 0;
}
void enqueue(int a){
if (fullchecker()==1){
	printf("Queue is full");
	getch();
	return ;
}
else {
	q.queue[++q.rear]=a;
	printf("Item is added.");
	getch();
	}
}
void dequeue(){
	int a;
	if (emptychecker()==1){
		printf("Queue is empty.");
		getch();
		return ;
	}
	else{
	printf("The dequqed item is %d",q.queue[q.front]);
	for (a=q.front+1;a<=q.rear;a++){
		q.queue[a-1]=q.queue[a];
	}
	q.rear--;
	getch();	
	}
}
void display(){
	int i;
	if(q.rear<q.front){
		printf("queue is empty");
		getch();
		return;
	}
	printf("element on queue are:");
	for (i=q.front;i<=q.rear;i++){
		printf("%d\t",q.queue[i]);
	}
}
int main(){
	int item,ch,exi=0;
	q.rear=-1;
	q.front=0;

	do{
		system("CLS");
			printf("menue\n1\tEnqueue\n2.\tDequeue\n3.\tDisplay\n4.\tExit\nEnter your choice:");
			scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the item to be enqueued:");
				scanf("%d",&item);	
				enqueue(item);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				getch();
				break;
			case 4:	
				exi=1;
				break;	
		}
	}while(exi!=1);

	return 0;
}