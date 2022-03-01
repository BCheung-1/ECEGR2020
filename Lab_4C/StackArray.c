#include <stdio.h>
#include <stdlib.h>

// Data structure to represent a stack
typedef struct Stack
{
    float items;
	struct Stack* next;
} Stack;
 
Stack* headNode = NULL;
// Utility function to initialize the stack
Stack* newStack(float cap)
{
    Stack *newNode = (Stack*)malloc(sizeof(Stack));
	if( newNode != NULL){

		newNode -> items = cap;
		newNode->next = NULL;
	}
    return newNode;
}
 
// Utility function to return the size of the stack
int size() {
    Stack *newNode = headNode;
	int i = 0;
	while(newNode != NULL){
		i++;
		newNode = newNode-> next;
	}
	return i;
}
 
// Utility function to check if the stack is empty or not
int isEmpty() {
    return headNode == NULL;
}
 
// Utility function to check if the stack is full or not
int isFull() {
    return (malloc(sizeof(Stack)) == NULL);
}
 
// Utility function to add an element `x` to the stack
int push(float x)
{
    // check if the stack is already full. Then inserting an element would
    // lead to stack overflow
    if (isFull())
    {
        printf("Stack Full!\n");
        return -1;
    }
	
	Stack* newNode = newStack(x);
	
    printf("Inserting %f\n", x);
	if(headNode == NULL){
		headNode = newNode;
		return 0;
	}
    // add an element and increment the top's index
    newNode -> next = headNode;
	headNode = newNode;
    return 0;
}
 
// Utility function to pop a top element from the stack
int pop()
{
    // check for stack underflow
    if (isEmpty())
    {
        printf("Stack Empty!\n");
        return -1;
    }
 
    // remove element decrement stack size by 1
    printf("Removing %f\n", headNode-> items);
	Stack* temp = headNode;
	headNode = headNode->next;
	free(temp);
    return 0;
}
 
// Utility function to peek at top element from the stack
int peek(float* x)
{
    // check for stack underflow
    if (isEmpty())
    {
        printf("Stack Empty!\n");
        return -1;
    }
 
    // return top of stack value
    *x = headNode->items;
    return 0;
}
 
int main()
{
    // create a stack of capacity 5
    float value;
 
    push(1.0);
    push(2.0);
    push(3.0);
 
    printf("The stack size is %d\n", size());

    peek(&value);
    printf("Top val on stack is %f\n", value);

    pop();
    pop();
    pop();
 
    if (isEmpty()) {
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }
 
    return 0;
}
