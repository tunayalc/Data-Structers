#include<stdio.h>  // Standard Input/Output library
#include<stdlib.h> // Standard library for general-purpose functions

// Bubble Sort: Repeatedly swaps adjacent elements if they are in the wrong order
void bubblesort(int arr[], int size) {
	int i, j;
	for(i = 0; i < size - 1; i++) {
		for(j = 0; j < size - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				// Swap arr[j] and arr[j+1]
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;		
			}
		}	
	}
}

// Insertion Sort: Places each element in its correct position relative to the previous elements
void insertionsort(int arr[], int size) {
	int key, i, j;
	for(i = 1; i < size; i++) {
		key = arr[i];
		j = i;
		while(j > 0 && arr[j - 1] > key) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
	}	
}

// Selection Sort: Repeatedly selects the smallest element and moves it to its correct position
void selectionsort(int arr[], int size) {
	int i, j, imin;
	for(i = 0; i < size - 1; i++) {
		imin = i;
		for(j = i + 1; j < size; j++) {
			if(arr[j] < arr[imin]) {
				imin = j;
			}
		}
		// Swap arr[i] with the minimum element found
		int temp = arr[i];
		arr[i] = arr[imin];
		arr[imin] = temp;
	}
}

// Quick Sort: Divides the array into two parts using a pivot and sorts them recursively
void quicksort(int arr[], int left, int right) {
	if(left >= right) {
		return;
	} else {
		int pvt = right; // Pivot element
		int current, marker;
		current = left - 1;
		marker = left - 1;
		while(current < right) {
			current++;
			if(arr[current] <= arr[pvt]) {
				marker++;
				if(current > marker) {
					// Swap arr[current] with arr[marker]
					int temp = arr[current];
					arr[current] = arr[marker];
					arr[marker] = temp;
				}
			}
		}
		quicksort(arr, left, marker - 1); // Sort left partition
		quicksort(arr, marker + 1, right); // Sort right partition		
	}
}

// Merge Sort: Divides the array into two halves and merges them after sorting
void mergesort(int arr[], int left, int right) {
	if(right > left) {
		int mid = (left + right) / 2; // Find the midpoint
		mergesort(arr, left, mid); // Sort the left half
		mergesort(arr, mid + 1, right); // Sort the right half
		merge(arr, left, right); // Merge the two sorted halves
	}
}

// Merge function for merge sort
void merge(int arr[], int left, int right) {
	int temparr[right - left + 1]; // Temporary array to store merged values
	int mid = (left + right) / 2;
	int l = left;
	int r = mid + 1;
	int i = 0;
	
	// Merge the two halves into temparr
	while(l <= mid && r <= right) {
		if(arr[r] < arr[l]) {
			temparr[i] = arr[r];
			r++;
		} else {
			temparr[i] = arr[l];
			l++;
		}
		i++;
	}
	
	// Copy the remaining elements from the left half
	while(l <= mid) {
		temparr[i] = arr[l];
		i++;
		l++;
	}
	
	// Copy the remaining elements from the right half
	while(r <= right) {
		temparr[i] = arr[r];
		i++;
		r++;
	}
	
	// Copy the merged elements back into the original array
	for(i = left; i <= right; i++) {
		arr[i] = temparr[i - left];
	}
}

// Print the elements of the array
void printArray(int arr[], int size) {
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int secim; // User's choice of sorting algorithm
    int boyut; // Size of the array

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &boyut);

    int arr[boyut]; // Declare an array of the specified size

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < boyut; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the sorting options to the user
    printf("Please choose a sorting algorithm:\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Merge Sort\n");
    scanf("%d", &secim);

    // Call the appropriate sorting function based on user's choice
    switch(secim) {
        case 1:
            selectionsort(arr, boyut); // Call selection sort
            printArray(arr, boyut); // Print the sorted array
            break;
        case 2:
            bubblesort(arr, boyut); // Call bubble sort
            printArray(arr, boyut); // Print the sorted array
            break;
        case 3:
            insertionsort(arr, boyut); // Call insertion sort
            printArray(arr, boyut); // Print the sorted array
            break;
        case 4:
            quicksort(arr, 0, boyut - 1); // Call quick sort
            printArray(arr, boyut); // Print the sorted array
            break;
        case 5:
            mergesort(arr, 0, boyut - 1); // Call merge sort
            printArray(arr, boyut); // Print the sorted array
            break;
        default:
            printf("Invalid choice\n"); // Print an error message if choice is invalid
    }

    return 0; // Return 0 to indicate successful program execution
}

