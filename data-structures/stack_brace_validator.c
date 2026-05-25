#include <stdio.h>
int MAXSIZE = 6;
char stack[6];
int top = -1; 

char peek();
int isEmpty();
int isFull();
char pop();
void push(char inChar);


//Returns the top of the stack, if any.
char peek(){
	if(!isEmpty()){
		return stack[top];
	} else {
		printf("Error: Stack is empty.");
	}
}

//Checks to see if stack is empty.
int isEmpty()
{
	if (top == -1){
		return 1;
	} else{
		return 0;
	}
}

//Checks to see if stack is full. 
int isFull()
{
	if ((top+1) == MAXSIZE){
		return 1;
	} else {
		return 0;
	}

}

//Deletes whatever is at the top of the stack
char pop()
{
	char data;

	if(!isEmpty()){
		data = stack[top];
		top = top-1;
		return data;
	} else {
		printf("Error: Stack is Empty.\n");
	}
}

//Inserts data into top of stack
void push(char inChar)
{

	if(!isFull()){
		top = top + 1;
		stack[top] = inChar;
	} else {
		
	}
}

int main()
{	
	int isValid = 0;
	char str[6];
	printf("Robert Quintana, utt318\n");
	printf("Enter a 6 character string containing only { or } characters:\n");
	scanf("%s",str);
	

	for (int i = 0; i < 6; i++){
		if(str[i] == '{'){
			push(str[i]);
		} else if ((str[i] == '}') && !isEmpty()){
			pop();
		} else{
			printf("Invalid String.1\n");
			break;
		}
	}
	
	if(isEmpty()){
		printf("String is valid.\n");
	} else {
		printf("String is invalid.\n");
	}

	printf("Stack is full, last value entered: %c \n",str[5]);

	
	return 0;
}

