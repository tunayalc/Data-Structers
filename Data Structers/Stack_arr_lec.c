#include<stdio.h>  // Standard Input/Output library
#include<stdlib.h> // Standard library for memory allocation (malloc, free, etc.)

// Definition of the stack structure
struct s{
	int size;      // Total size of the stack (capacity)
	int top;       // Index of the top element in the stack
	int *arr;      // Pointer to the array that holds the stack elements
};
typedef struct s stack; // 'stack' is now an alias for 'struct s'

// Function to initialize a new stack
stack * init(){
	stack* s; // Declare a pointer to the stack
	s = (stack*)malloc(sizeof(stack)); // Allocate memory for the stack structure
	s -> size = 2; // Initial capacity of the stack is 2
	s -> top = 0; // Stack is initially empty, so top is set to 0
	s -> arr = (int*)malloc(sizeof(int) * 2); // Allocate memory for the array with 2 elements
	return s; // Return the pointer to the newly initialized stack
}

// Function to push (add) a new element to the stack
void push(stack * s, int num){
	// Check if the stack is full, resize if necessary
	if(s -> top == s -> size - 1){ 
		int *arr2 = (int*)malloc(sizeof(int) * s -> size * 2); // Create a new array with double the size
		int i;
		for(i = 0; i < s -> top; i++){ // Copy elements from the old array to the new array
			arr2[i] = s -> arr[i];
		}
		free(s -> arr); // Free the memory of the old array
		s -> arr = arr2; // Update the stack's array pointer to the new array
		s -> size *= 2; // Double the capacity of the stack
	}
	s -> arr[s -> top++] = num; // Add the new element and increase the top index
}

// Function to pop (remove) an element from the stack
int pop(stack *s){
	// If the stack is empty, print a message and return -1
	if(s -> top == 0){
		printf("Stack is empty\n"); 
		return -1; 
	}
	// Check if the stack size can be reduced to save memory
	if(s -> top <= s -> size / 4){ 
		int *arr2 = (int*)malloc(sizeof(int) * s -> size / 2); // Create a new array with half the current size
		int i;
		for(i = 0; i < s -> top; i++){ // Copy existing elements to the new array
			arr2[i] = s -> arr[i];
		}
		free(s -> arr); // Free the memory of the old array
		s -> arr = arr2; // Update the stack's array pointer to the new array
		s -> size /= 2; // Halve the capacity of the stack
	}
	return s -> arr[--s -> top]; // Decrease the top index and return the value of the popped element
}

// Function to print all elements of the stack
void printElements(stack *s){
	int i;
	printf("Size of stack is %d\n", s -> size); // Print the current size of the stack
	for(i = 0; i < s -> top; i++){ // Print each element in the stack
		printf("%d ", s -> arr[i]); 
	}
	printf("\n"); // Print a newline after all elements have been printed
}

int main(){
	stack * s = init(); // Initialize a new stack
	printElements(s); // Print the stack (it is empty at this point)
	
	// Test 1: Add 10 elements to the stack
	int i;
	for(i = 0; i < 10; i++){
		push(s, i * 3); // Push multiples of 3 to the stack
	}
	printElements(s); // Print the stack after adding 10 elements
	
	// Test 2: Pop 15 elements from the stack
	for(i = 0; i < 15; i++){
		printf("popped is %d\n", pop(s)); // Print the value of each popped element
	}
	printElements(s); // Print the stack after popping 15 elements
	
	// Test 3: Add 5 elements to the stack
	for(i = 0; i < 5; i++){
		push(s, i * 6); // Push multiples of 6 to the stack
	}
	printElements(s); // Print the stack after adding 5 elements
	
	return 0; // Return 0 to indicate successful program execution
}



