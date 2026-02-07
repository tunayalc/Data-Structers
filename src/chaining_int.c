#include <stdio.h>  // Standard Input/Output library
#include <stdlib.h> // Standard library for memory allocation and general functions

// Definition of the node structure used for the linked list in each hash table bucket
struct node {
	int key;              // Key of the node (used to calculate the hash index)
	int value;            // Value associated with the key
	struct node* next;    // Pointer to the next node in the linked list (for collision handling)
};
typedef struct node node; // 'node' is now an alias for 'struct node'

// Definition of the hash table structure
struct hashtable {
	node *head[10]; // Array of pointers to the head of the linked list for each of the 10 hash table indices
};
typedef struct hashtable hashtable; // 'hashtable' is now an alias for 'struct hashtable'

// Hash function to calculate the index for a given key
int hash(int key) {
	return key % 10; // Modulus operator to ensure the index is within the range [0-9]
}

// Function to insert a key-value pair into the hash table
void insert(hashtable *ht, int key, int value) {
	int index = hash(key); // Calculate the index for the key using the hash function
	node *newnode = (node *)malloc(sizeof(node)); // Allocate memory for the new node
	newnode->key = key; // Store the key in the node
	newnode->value = value; // Store the value in the node
	newnode->next = NULL; // This node will be added to the end of the linked list, so next is set to NULL

	// If the bucket is empty, insert the new node as the first node in the linked list
	if(ht->head[index] == NULL) {
		ht->head[index] = newnode;
		return; // End the function since the node has been inserted
	}

	// If the bucket is not empty, add the new node to the end of the linked list
	node *temp = ht->head[index]; // Start from the first node in the linked list
	while(temp->next != NULL) { // Traverse to the last node in the linked list
		temp = temp->next;
	}
	temp->next = newnode; // Add the new node to the end of the linked list
}

// Function to print all key-value pairs in the hash table
void printhash(hashtable *ht) {
	for(int i = 0; i < 10; i++) { // Loop through each of the 10 indices of the hash table
		node *temp = ht->head[i]; // Get the head of the linked list at the current index
		if(temp == NULL) { // If the bucket is empty, print that it's empty
			printf("%d.index is empty\n", i);
		} else {
			while(temp != NULL) { // Traverse the linked list and print each key-value pair
				printf("%d.index key:%d ,value:%d\n", i, temp->key, temp->value);
				temp = temp->next; // Move to the next node
			}
		}
		printf("\n"); // Print a new line after each bucket's contents are displayed
	}
}

// Function to initialize the hash table
hashtable *init() {
	hashtable *ht = (hashtable *)malloc(sizeof(hashtable)); // Allocate memory for the hash table
	for(int i = 0; i < 10; i++) { // Initialize all indices of the hash table to NULL
		ht->head[i] = NULL;
	}
	return ht; // Return the pointer to the newly created hash table
}

int main(int argc, char *argv[]) {
	// Initialize the hash table
	hashtable *ht = init();
	
	// Insert key-value pairs into the hash table
	insert(ht, 64, 123);
	insert(ht, 89, 456);
	insert(ht, 42, 789);
	insert(ht, 30, 4263);
	insert(ht, 91, 2423);
	insert(ht, 23, 4334);
	
	// Print all the key-value pairs in the hash table
	printhash(ht);
	
	return 0; // Return 0 to indicate successful program execution
}

