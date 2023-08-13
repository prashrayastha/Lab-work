#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct bst {
	int data;
	struct bst* left;
    struct bst* right;
};
typedef struct bst node;
node root1;
node *root=NULL;
//root1.data=0;
//root1.left=NULL;
//root1.right=NULL;
//root =&root1;
node *newnode;
void insert (node* r,int key){
	if(r==NULL){
		newnode=(node*)malloc(sizeof(node));
        newnode->data=key;
		newnode->left=NULL;
		newnode->right=NULL;
		printf("node created!!");
		getch();
	}
	else if (key<=r->data){
		insert(r->left,key);
	}
	else if( key>=r->data){
		insert(r->right,key);
	}
}
/*void Delete(node *r,int key){
	node * temp;
	search(r,key);
	
}*/
void display( node *r){
	if(r!= NULL){
		display(r->left);
		printf("%d\t",r->data);
		display(r->right);
	}
}

int main(){
	int key,opt;
	do{
	system("cls");
	printf("menue\n1)\tInsert\n2)\tDisplay\n3)\tDelete\n4)\tSearch\n5)\tQuit\nEnter your choice:");
	scanf("%d",&opt);
	switch(opt){
	case 1:
		printf("enter the data to add:");
		scanf("%d",&key);
		insert(root,key);
		break;
	case 2:
	    display(root);
	    getch();
		break;
	case 3:
		printf("enter the data to delete:");
		scanf("%d",&key);
	    //Delete(root,key);
	    break;
	case 4:
		printf("enter the data to search:");
		scanf("%d",&key);
		//search(root,key);
		break;
		
	}
	
	}while(opt!=5);
}