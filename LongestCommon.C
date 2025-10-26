#include <stdio.h>
#include <string.h>
#include <conio.h>

int i, j, m, n, LCS_table[20][20];  // DP table
char b[20][20];                     // Not used but kept for reference

// Function to compute LCS
void lcsAlgo(char S1[], char S2[]) 
{
    m = strlen(S1); // length of first string
    n = strlen(S2); // length of second string

    // Step 1: Initialize DP table (first row and first column = 0)
    for (i = 0; i <= m; i++) 
        LCS_table[i][0] = 0;
    for (i = 0; i <= n; i++) 
        LCS_table[0][i] = 0;

    // Step 2: Fill DP table using recurrence relation
    for (i = 1; i <= m; i++) 
    {
        for (j = 1; j <= n; j++) 
        {
            if (S1[i - 1] == S2[j - 1]) 
            {
                // If characters match, take diagonal + 1
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            } 
            else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) 
            {
                // If not match, take maximum of top or left
                LCS_table[i][j] = LCS_table[i - 1][j];
            } 
            else 
            {
                LCS_table[i][j] = LCS_table[i][j - 1];
            }
        }
    }

    // Step 3: Reconstruct LCS string from DP table
    int index = LCS_table[m][n];   // length of LCS
    char lcsStr[index + 1];        // store result
    lcsStr[index] = '\0';          // null-terminate string

    int x = m, y = n;
    while (x > 0 && y > 0) 
    {
        if (S1[x - 1] == S2[y - 1]) 
        {
            lcsStr[index - 1] = S1[x - 1]; // put character in result
            x--;
            y--;
            index--;
        } 
        else if (LCS_table[x - 1][y] > LCS_table[x][y - 1]) 
        {
            x--; // move up
        } 
        else 
        {
            y--; // move left
        }
    }

    // Step 4: Print results
    printf("S1 : %s \nS2 : %s \n", S1, S2);
    printf("LCS: %s\n", lcsStr);
    printf("The length of LCS = %d\n", strlen(lcsStr));
}

int main() 
{
    char S1[20] = "CBDA", S2[20] = "ACADB";

    clrscr();   // clear screen (Turbo C)

    // Run LCS algorithm
    lcsAlgo(S1, S2);

    // Print DP table for verification
    printf("\nDP Table (LCS_table):\n");
    for (i = 0; i < 10; i++) 
    {
        for (j = 0; j < 10; j++) 
        {
            printf("%d ", LCS_table[i][j]);
        }
        printf("\n");
    }

    getch();    // wait for key press before closing
    return 0;
}
