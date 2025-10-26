#include <stdio.h>
#include <string.h>
#include <conio.h>

// Function to search for the pattern in the text
void search(char* pat, char* txt) {
    int M = strlen(pat);  // Length of pattern
    int N = strlen(txt);  // Length of text

    // Loop through text up to the point where pattern can fit
    for (int i = 0; i <= N - M; i++) {
        int j;

        // Check each character of pattern against substring of text
        for (j = 0; j < M; j++) {
            if (txt[i + j] != pat[j]) {
                break;   // Mismatch → stop checking further
            }
        }

        // If pattern fully matched (all M characters checked)
        if (j == M) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    clrscr();   // Clear screen (Turbo C)

    char txt1[20];  // Array to hold text string
    char pat1[15];  // Array to hold pattern string

    // Input text string
    printf("Enter the text string : ");
    scanf("%s", txt1);

    // Input pattern string
    printf("\nEnter the pattern string : ");
    scanf("%s", pat1);

    // Display results
    printf("\nSolution :\n");
    search(pat1, txt1);   // Call function to search

    getch();   // Wait for key press before closing
    return 0;
}
