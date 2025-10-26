#include <stdio.h>
#include <conio.h>

#define nV 4     // number of vertices (fixed as 4 here)
#define INF 999  // representation of infinity (no direct edge)

// Function to print the distance matrix
void printMatrix(int matrix[][nV]);

// Function to implement Floyd–Warshall Algorithm
void floydWarshall(int graph[][nV])
{
    int matrix[nV][nV], i, j, k;

    // Step 1: Copy graph into matrix (initial distance matrix)
    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            matrix[i][j] = graph[i][j];

    // Step 2: Update distances by considering each vertex as an intermediate
    for (k = 0; k < nV; k++)  // intermediate vertex
    {
        for (i = 0; i < nV; i++)  // source vertex
        {
            for (j = 0; j < nV; j++)  // destination vertex
            {
                // If the path through vertex k is shorter, update the distance
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }

        // Print matrix after including each intermediate vertex
        printf("After including vertex: %d \n", k + 1);
        printMatrix(matrix);
    }
}

// Function to print the current distance matrix
void printMatrix(int matrix[][nV])
{
    int i, j;
    for (i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");   // no path
            else
                printf("%4d", matrix[i][j]);  // print distance
        }
        printf("\n");
    }
}

int main()
{
    clrscr();  // clear screen (Turbo C)

    int graph[nV][nV];  // adjacency matrix
    int i, j, n;

    printf("\nEnter the number of vertices of adj matrix: ");
    scanf("%d", &n);

    printf("\nEnter the elements of cost adjacency matrix\n");
    printf("(Enter %d for INF if no direct edge)\n", INF);

    // Input adjacency matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Run Floyd–Warshall algorithm
    floydWarshall(graph);

    getch();  // wait for key press
    return 0;
}
