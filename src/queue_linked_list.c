#include<stdio.h>  // Standard Input/Output library
#include<stdlib.h> // Standard library for memory allocation (malloc, free, etc.)

// Node structure for the queue
struct n{
	int data;         // Value stored in the node
	struct n * next;  // Pointer to the next node in the queue
};
typedef struct n node; // 'node' is now an alias for 'struct n'

// Function to enqueue (add) a new element to the queue
node * enque(node * r, int num){
	// Create a new node and allocate memory for it
	node * newNode = (node*)malloc(sizeof(node));
	newNode -> next = NULL; // This will be the last node, so next is NULL
	newNode -> data = num;  // Store the given value in the node
	
	// If the queue is empty, the new node becomes the first (root) node
	if(r == NULL) 
		return newNode;
	
	// If the queue is not empty, traverse to the last node
	node * iter = r; 
	while(iter -> next != NULL){ 
		iter = iter -> next; 
	}
	iter -> next = newNode; // Link the new node to the end of the queue
	return r; // Return the updated queue
}

// Function to dequeue (remove) an element from the front of the queue
node * deque(node * r){
	// If the queue is empty, print a message and return NULL
	if(r == NULL){
		printf("Queue is empty\n");
		return NULL;	
	}
	
	// If the queue has only one node, remove it and return NULL
	if(r -> next == NULL){
		int data = r -> data; // Store the data of the node to print it later
		free(r); // Free the memory of the node
		printf("Dequeued %d\n", data); // Print the dequeued value
		return NULL; // Return NULL since the queue is now empty
	}
	
	// Remove the first node and shift the root to the next node
	node * temp = r; 
	int data = temp -> data; // Store the data of the node to print it later
	r = r -> next; // Move the root to the next node
	free(temp); // Free the memory of the removed node
	printf("Dequeued %d\n", data); // Print the dequeued value
	return r; // Return the updated queue
}

// Function to print all elements in the queue
void printElements(node * r){
	while(r != NULL){ // Traverse the queue
		printf("%d ", r -> data); // Print each element
		r = r -> next; // Move to the next node
	}
	printf("\n"); // Print a newline after printing all elements
}

int main(){
	node * r; // Pointer to the root of the queue
	r = NULL; // Initialize the queue as empty

	// Attempt to dequeue from an empty queue
	r = deque(r);
	
	// Enqueue 5 elements (0, 1, 2, 3, 4) into the queue
	int i;
	for(i = 0; i < 5; i++){
		r = enque(r, i * 1);		
	}
	printElements(r); // Print the elements of the queue
	
	// Dequeue 2 elements from the queue
	for(i = 0; i < 2; i++){
		r = deque(r);		
	}
	printElements(r); // Print the elements of the queue
	
	// Enqueue 4 new elements (0, 3, 6, 9) into the queue
	for(i = 0; i < 4; i++){
		r = enque(r, i * 3);		
	}
	printElements(r); // Print the elements of the queue
	
	// Attempt to dequeue 10 elements, even if the queue has fewer than 10 elements
	for(i = 0; i < 10; i++){
		r = deque(r);		
	}
	printElements(r); // Print the elements of the queue (should be empty)
}

