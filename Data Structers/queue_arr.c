#include<stdio.h>  // Standard Input/Output library
#include<stdlib.h> // Standard library for memory allocation (malloc, free, etc.)

// Definition of the queue structure
struct q{
	int head;     // Index of the first element in the queue
	int tail;     // Index of the last element in the queue
	int size;     // Current size (capacity) of the queue
	int *arr;     // Pointer to the array that holds the queue elements
};
typedef struct q queue; // 'queue' is now an alias for 'struct q'

// Function to initialize a new queue
queue * init(){
	queue * q; // Create a pointer to the queue structure
	q = (queue*)malloc(sizeof(queue)); // Allocate memory for the queue
	q -> head = 0; // Head starts at index 0
	q -> tail = 0; // Tail starts at index 0
	q -> size = 2; // Initial capacity of the queue is 2
	q -> arr = (int*)malloc(sizeof(int) * 2); // Allocate memory for the array with 2 elements
	return q; // Return the pointer to the newly initialized queue
}

// Function to shift the queue elements to the front if head is not at index 0
queue * fix(queue *q){
	if(q -> head == 0){ // If head is already at index 0, no need to shift
		return q;
	}
	int i;
	for(i = 0; i < q -> size; i++){ // Shift all elements to the front of the array
		q -> arr[i] = q -> arr[i + q->head];
	}
	q -> tail = q -> tail - q -> head; // Update tail index after shifting
	q -> head = 0; // Reset head to 0
	return q; // Return the updated queue
}

// Function to enqueue (add) an element to the end of the queue
void enque(queue *q, int num){
	// If the queue is full, increase its size
	if(q -> tail >= q -> size - 1){
		int *arr2 = (int*)malloc(sizeof(int) * q->size * 2); // Create a new array with double the size
		q = fix(q); // Shift the elements to the front to avoid unnecessary space
		for(int i = 0; i < q -> tail; i++){ // Copy elements to the new array
			arr2[i] = q -> arr[i];
		}
		free(q->arr); // Free the old array's memory
		q -> arr = arr2; // Update the queue's array pointer to the new array
		q -> size *= 2; // Double the capacity of the queue
	}
	q -> arr[q->tail++] = num; // Add the new element to the end of the queue
}

// Function to print all elements in the queue
void printElements(queue *q){
	q = fix(q); // Shift elements to the front if necessary
	printf("Size of queue is %d\n", q -> size); // Print the size (capacity) of the queue
	for(int i = q->head; i < q -> tail; i++){ // Print each element from head to tail
		printf("%d ", q -> arr[i]); 
	}
	printf("\n"); // Print a newline after all elements have been printed
}

// Function to dequeue (remove) an element from the front of the queue
int deque(queue *q){
	// If the queue is empty, print a message and return -1
	if(q -> tail == q -> head){
		printf("Queue is empty\n");
		return -1;
	}
	
	// If the queue has too much unused space, reduce its size
	if(q -> tail - q -> head <= q -> size / 4){
		int *arr2 = (int*)malloc(sizeof(int) * q -> size / 2); // Create a new array with half the size
		for(int i = 0; i < q -> tail - q -> head; i++){ // Copy elements to the new array
			arr2[i] = q -> arr[i + q -> head];
		}
		q -> tail = q -> tail - q -> head; // Update tail index after shifting
		q -> head = 0; // Reset head to 0
		free(q -> arr); // Free the old array's memory
		q -> arr = arr2; // Update the queue's array pointer to the new array
		q -> size /= 2; // Halve the capacity of the queue
	}
	return q -> arr[q -> head++]; // Return the dequeued value and move head forward
}

int main(){
	// Initialize a new queue
	queue *q = init();
	
	// Attempt to dequeue from an empty queue
	printf("Dequeued %d\n", deque(q));
	printElements(q); // Print the elements of the queue (should be empty)
	
	// Enqueue 10 elements (0, 10, 20, ..., 90) into the queue
	for(int i = 0; i < 10; i++){
		enque(q, i * 10);		
	}
	printElements(q); // Print the elements of the queue
	
	// Dequeue 15 elements from the queue (more than the number of elements available)
	for(int i = 0; i < 15; i++){
		printf("Dequeued %d\n", deque(q));		
	}
	printElements(q); // Print the elements of the queue (should be empty)
	
	// Enqueue 30 elements (0, 10, 20, ..., 290) into the queue
	for(int i = 0; i < 30; i++){
		enque(q, i * 10);		
	}
	printElements(q); // Print the elements of the queue
	
	// Dequeue 26 elements from the queue
	for(int i = 0; i < 26; i++){
		printf("Dequeued %d\n", deque(q));		
	}
	printElements(q); // Print the elements of the queue
	
	return 0; // Return 0 to indicate successful program execution
}

