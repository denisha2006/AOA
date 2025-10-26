#include <stdio.h>
#include <conio.h>

#define MAX 10     // Maximum number of vertices
#define INF 99999  // Representation of infinity

// Function to find the vertex with minimum distance that is not visited yet
int minDist(int dist[MAX], int s[MAX], int n) 
{
    int min = INF, min_index = -1;
    int i;

    // Check all vertices
    for (i = 1; i <= n; i++) 
    {
        // If vertex not visited and has smaller distance
        if (s[i] == 0 && dist[i] < min) 
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index; // Return index of minimum distance vertex
}

// Dijkstra’s Algorithm
void dijkstra(int v, int cost[MAX][MAX], int dist[MAX], int n) 
{
    int s[MAX]; // visited set
    int i, w, num, u;

    // Step 1: Initialize
    for (i = 1; i <= n; i++) 
    {
        s[i] = 0;              // Mark all vertices as unvisited
        dist[i] = cost[v][i];  // Distance from source to each vertex
    }

    s[v] = 1;     // Mark source as visited
    dist[v] = 0;  // Distance to itself is 0

    // Step 2: Repeat for (n-1) vertices
    for (num = 2; num <= n; num++) 
    {
        u = minDist(dist, s, n); // Pick unvisited vertex with smallest dist
        s[u] = 1;                // Mark it as visited

        // Step 3: Update distances of neighbors
        for (w = 1; w <= n; w++) 
        {
            if (s[w] == 0 && dist[w] > dist[u] + cost[u][w]) 
            {
                dist[w] = dist[u] + cost[u][w]; // Relaxation step
            }
        }

        // Print after each iteration
        printf("\nAfter Iteration %d:\n", num - 1);
        for (i = 1; i <= n; i++) 
        {
            printf("s[%d] = %d, dist[%d] = %d\n", i, s[i], i, dist[i]);
        }
    }
}

int main() 
{
    int cost[MAX][MAX], dist[MAX];
    int n, source;
    int i, j;

    clrscr(); // Clear screen (Turbo C)

    // Input number of vertices
    printf("Enter Number of vertices: ");
    scanf("%d", &n);

    // Input adjacency cost matrix
    printf("Enter cost Adjacency Matrix:\n");
    printf("(Use %d for no direct edge)\n", INF);
    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= n; j++) 
        {
            scanf("%d", &cost[i][j]);
        }
    }

    // Input source vertex
    printf("Enter the Source Vertex: ");
    scanf("%d", &source);

    // Run Dijkstra
    dijkstra(source, cost, dist, n);

    // Print final shortest distances
    printf("\nShortest Distance from Source %d:\n", source);
    for (i = 1; i <= n; i++) 
    {
        printf("To %d = %d\n", i, dist[i]);
    }

    getch(); // Wait for key press before closing
    return 0;
}
