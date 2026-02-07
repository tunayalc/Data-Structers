#include<stdio.h>  // Standard Input/Output library
#include<stdlib.h> // Standard library for memory allocation (malloc, free, etc.)

// Definition of the node structure
struct n{
	struct n * next; // Pointer to the next node in the stack
	int value;       // Value stored in the node
};
typedef struct n node; // 'node' is now an alias for 'struct n'

// Function to push (add) a new element to the end of the stack
node * push(node * r, int num){
	node * newNode = (node *)malloc(sizeof(node)); // Allocate memory for a new node
	newNode -> value = num; // Assign the given value to the new node
	newNode -> next = NULL; // Since this node will be at the end, its next is set to NULL
	if(r == NULL) // If the stack is empty, return the new node as the new root
		return newNode;
		
	node * iter = r; // Start from the root of the stack
	while(iter -> next != NULL) // Traverse to the last node in the stack
		iter = iter -> next;
	
	iter -> next = newNode; // Link the last node to the new node
	return r; // Return the updated root of the stack
}

// Function to print all elements of the stack
void printStack(node * r){
	while(r != NULL){ // Traverse the stack and print each node's value
		printf("%d ", r -> value); // Print the value of the current node
		r = r -> next; // Move to the next node
	}
	printf("\n"); // Print a newline after all elements have been printed
}

// Function to pop (remove) the last element from the stack
int pop(node * r){
	 while(r == NULL){ // If the stack is empty, print a message and return -1
	 	printf("Stack is empty"); 
	 	return -1; 
	 }
	 if(r -> next == NULL){ // If there is only one node in the stack (only the root)
	 	int data = r -> value; // Store the value of the root node
	 	free(r); // Free the memory of the root node
	 	return data; // Return the value of the removed node
	 }
	 node * iter = r; // Start from the root of the stack
	 while(iter -> next -> next != NULL){ // Traverse to the second-last node
	 	iter = iter -> next; // Move to the next node
	 }
	 int rvalue = iter -> next -> value; // Store the value of the last node
	 node * temp = iter -> next; // Temporary pointer to the last node
	 iter -> next = NULL; // Detach the last node from the stack
	 free(temp); // Free the memory of the last node
	 return rvalue; // Return the value of the removed node
}

int main(){
	node * r; // Declare the root of the stack
	r = NULL; // Initialize the stack as empty
	r = push(r, 5); // Push 5 onto the stack
	r = push(r, 6); // Push 6 onto the stack
	r = push(r, 17); // Push 17 onto the stack
	printStack(r); // Print the contents of the stack
	
	printf("\n%d was popped.\n", pop(r)); // Pop the last element and print its value
	printStack(r); // Print the contents of the stack after the pop
	
	r = push(r, 28); // Push 28 onto the stack
	r = push(r, 65); // Push 65 onto the stack
	printStack(r); // Print the contents of the stack
	
	return 0; // Return 0 to indicate successful program execution
}

