#include <stdio.h>
#include <conio.h>

// Function to perform Selection Sort
void selectionsort(int arr[], int n) 
{ 
    int i, j, si, temp;

    // Outer loop runs (n-1) times
    for (i = 0; i < n - 1; i++) 
    { 
        si = i;  // assume current index i is the smallest

        // Find the smallest element in the unsorted part
        for (j = i + 1; j < n; j++) 
        { 
            if (arr[j] < arr[si]) 
            { 
                si = j;  // update smallest index
            } 
        } 

        // Swap the smallest element with element at index i
        temp = arr[i]; 
        arr[i] = arr[si]; 
        arr[si] = temp; 
 
        // Print the smallest element chosen in this pass
        printf("Smallest element chosen: %d\n", arr[i]); 

        // Print array after each pass
        for (j = 0; j < n; j++) 
        { 
            printf("%d\t", arr[j]); 
        } 
        printf("\n"); 
    } 
} 

int main() 
{ 
    int n, i; 
    int arr[10]; 

    clrscr();   // clear screen (Turbo C)

    // Input size of array
    printf("Enter the number of elements in the array: "); 
    scanf("%d", &n); 

    // Input array elements
    printf("Enter the elements of the array:\n"); 
    for (i = 0; i < n; i++) 
    { 
        scanf("%d", &arr[i]); 
    } 

    // Call selection sort
    selectionsort(arr, n); 

    // Print final sorted array
    printf("\nSorted Array is:\n"); 
    for (i = 0; i < n; i++) 
    { 
        printf("%d\t", arr[i]); 
    } 

    getch();   // wait for key press before closing
    return 0; 
}
