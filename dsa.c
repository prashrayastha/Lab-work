//write a program to evaluate infix expression
# include <stdio.h>
# include <math.h>
#define max 15
int operandstack[6];
char operatorstack[15];
int otortop=-1;
int orandtop=-1;
char infix[80];
int i1;


int otorstchecker(){
	if(otortop== max)return 1;
	else return 0;
}
int orandstchecker(){
	if(orandtop== max)return 1;
	else return 0;
}
int isoperator(char ch){
	if (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='$') return 1;
	else return 0;
}
int isoperand(char ch){
	if ( ch>='a'&& ch<="z" || ch>='A' && ch<='Z'){
		return 1;
	}
	else return 0;
	}
int precidence( char i){
	if(i=='+'&& i=='-'){
	return 1;
	}
	else if(i=='*'&&i=='/'){
	return 2;
	}
	else if(i=='$'){
	return 3;
	}
}
void pop(){
	int answer;
	char m;
	m=operatorstack[otortop];
switch (m){
	case '+':
		answer=operandstack[orandtop]+operandstack[--orandtop];
		break;
	case '-':
		answer=operandstack[orandtop]-operandstack[--orandtop];
		break;
	case '*':
		answer=operandstack[orandtop]*operandstack[--orandtop];
		break;
	case '/':
		answer=operandstack[orandtop]/operandstack[--orandtop];
		break;
	case '$':
		answer=pow(operandstack[orandtop],operandstack[--orandtop]);
		break;
}
operandstack[++oprandtop]=answer;
;
}
void infixevaluator(){
	int prevpre=0;
	int temp;
		while (infix[i1]!='\0'){

			if (isoperator(infix[i1])==1){
				if (precidence(infix[i1])>prevpre){

					if (otorstchecker!=1) operatorstack[otortop]=infix[i1];
					else printf("stack is full");
					prevpre=precidence(infix[i1]);
				 }
 				else pop();
 
			}
			else if (isoperand(infix[i1])==1){
				if (orandstchecker!=1){
					printf("enter the value of %c:",infix[i1]);
					scanf("%d",&temp);
					operandstack[++orandtop]=temp;
			}
				else printf("stack is full");
			}
 		i1++
		 }
}
int main(){
	
}

