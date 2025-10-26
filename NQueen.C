#include <stdio.h>
#include <conio.h>
#include <math.h>

int board[20], count = 0;

int place(int row, int column);
void queen(int row, int n);
void print(int n);

void main()
{
    int n;
    clrscr();

    printf(" - N Queens Problem Using Backtracking -");
    printf("\n\nEnter number of Queens: ");
    scanf("%d", &n);

    queen(1, n);   // start placing queens from row 1

    if (count == 0)
        printf("\nNo solution found!");
    
    getch();
}

void queen(int row, int n)
{
    int column;
    for (column = 1; column <= n; column++)
    {
        if (place(row, column))
        {
            board[row] = column; // place queen
            if (row == n)       // if last row reached
                print(n);
            else
                queen(row + 1, n); // go to next row
        }
    }
}

int place(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; i++)
    {
        // check column conflict
        if (board[i] == column)
            return 0;

        // check diagonal conflict
        if (abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1; // safe position
}

void print(int n)
{
    int i, j;
    count++;
    printf("\n\nSolution %d:\n\n", count);

    // print column numbers
    for (i = 1; i <= n; i++)
        printf("\t%d", i);

    // print chess board
    for (i = 1; i <= n; i++)
    {
        printf("\n\n%d", i);
        for (j = 1; j <= n; j++)
        {
            if (board[i] == j)
                printf("\tQ"); // queen placed
            else
                printf("\t-"); // empty cell
        }
    }
}
