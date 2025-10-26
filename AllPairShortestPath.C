#include <stdio.h>
#include<conio.h>
#define nV 4
#define INF 999
void printMatrix(int matrix[][nV]);
void floydWarshall(int graph[][nV])
{
    int matrix[nV][nV], i, j, k;
    for (i = 0; i < nV; i++)
	for (j = 0; j < nV; j++)
	    matrix[i][j] = graph[i][j];
    for (k = 0; k < nV; k++)
    {
	for (i = 0; i < nV; i++)
	{
	    for (j = 0; j < nV; j++)
	    {
		if (matrix[i][k] + matrix[k][j] < matrix[i][j])
		    matrix[i][j] = matrix[i][k] + matrix[k][j];
	    }
	}
	printf("After including vertex: %d \n", k + 1);
	printMatrix(matrix);
    }
}
void printMatrix(int matrix[][nV])
{
    for (int i = 0; i < nV; i++)
    {
	for (int j = 0; j < nV; j++)
	{
	    if (matrix[i][j] == INF)
		printf("%4s", "INF");
	    else
		printf("%4d", matrix[i][j]);
	}
	printf("\n");
    }
}
int main()
{
clrscr();
    int graph[nV][nV];
    int i, j, n;
    printf("\nEnter the number of vertices of adj matrix: ");

    scanf("%d", &n);
    printf("\nEnter the elements of cost adjacency matrix\n");
    for (i = 0; i < n; i++)
    {
	for (j = 0; j < n; j++)
	{
	    scanf("%d", &graph[i][j]);
	}
    }
    floydWarshall(graph);
    getch();
    return 0;
}
