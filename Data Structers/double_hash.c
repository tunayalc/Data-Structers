#include <stdio.h>   // Standard Input/Output library for printf and scanf
#include <conio.h>   // Console Input/Output library for getch() (used in Windows environment)
#include <stdlib.h>  // Standard library for general-purpose functions like exit()

#define TABLE_SIZE 10 // Size of the hash table (fixed to 10)

int h[TABLE_SIZE]; // Array to represent the hash table with a fixed size of 10

// Function to insert a key into the hash table using double hashing
void insert() {
    int key, index, i, hkey, hash2;
    
    // Get the key from the user
    printf("\nEnter a value to insert into the hash table: ");
    scanf("%d", &key);
    
    // First hash function (h1)
    hkey = key % TABLE_SIZE; 
    
    // Second hash function (h2) to resolve collisions
    hash2 = 7 - (key % 7); // Second hash function uses 7 as a secondary prime number
    
    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i * hash2) % TABLE_SIZE; // Double hashing formula
        if (h[index] == NULL) { // If the slot is empty, insert the key
            h[index] = key; // Insert the key into the calculated index
            break;
        }
    }
    if (i == TABLE_SIZE) // If the loop completes, the table is full, and the key couldn't be inserted
        printf("\nElement cannot be inserted\n");
}

// Function to search for a key in the hash table
void search() {
    int key, index, i, hkey, hash2;
    
    // Get the key to search from the user
    printf("\nEnter the key to search: ");
    scanf("%d", &key);
    
    // Calculate the index using double hashing
    hkey = key % TABLE_SIZE;
    hash2 = 7 - (key % 7);
    
    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i * hash2) % TABLE_SIZE; // Double hashing formula
        if (h[index] == key) { // If the key is found at the calculated index
            printf("Value is found at index %d", index);
            break;
        }
    }
    if (i == TABLE_SIZE) // If the key is not found after checking all slots
        printf("\nValue is not found\n");
}

// Function to display all the elements in the hash table
void display() {
    printf("\nElements in the hash table are:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("\nHash table [%d] = %d", i, h[i]); // Print each index and its corresponding value
    }
}

// Main function
void main() {
    int opt;
    
    // Menu-driven system for the hash table operations
    printf("DOUBLE HASHING\n");
    while (1) {
        printf("\nPress 1. Insert 2. Display 3. Search 4. Exit \n");
        scanf("%d", &opt);
        
        switch (opt) {
            case 1:
                insert(); // Call the insert function to add a key-value pair to the table
                break;
            case 2:
                display(); // Call the display function to print the hash table
                break;
            case 3:
                search(); // Call the search function to search for a key in the hash table
                break;
            case 4:
                exit(0); // Exit the program
        }
    }
}

