#include<stdio.h>  // Standard Input/Output library for printf and scanf
#include<conio.h>  // Console Input/Output library for getch() (used in Windows environment)

int a[10]; // Array to represent the hash table with a fixed size of 10
int size;  // Size of the hash table, entered by the user

// Hash function to calculate the index for a given element
int hashfunction(int e) {
    int key;
    key = e % size; // Calculate the index using modulo operation
    return key; // Return the index where the element will be stored
}

void main() {
    int i, j, element;
    
    // Get the size of the hash table from the user
    printf("Enter the size of hash table: ");
    scanf("%d", &size);
    
    // Insert elements into the hash table
    for (i = 0; i < size; i++) {
        printf("Enter element to insert: ");
        scanf("%d", &element);
        
        // Calculate the index for the element using the hash function
        j = hashfunction(element);
        
        // Insert the element at the calculated index
        a[j] = element;
    }
    
    // Print all the values stored in the hash table
    printf("Values in the hash table:\n");
    for (i = 0; i < size; i++) {
        printf("%d\n", a[i]);
    }
    
    getch(); // Wait for a key press before closing the console (used in Windows environment)
}

