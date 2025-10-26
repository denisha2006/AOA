#include <stdio.h>
#include <conio.h>

// Function to perform the fractional knapsack calculation
void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;   // x[] = fraction of each object taken, tp = total profit
    int i, j, u;

    u = capacity;   // remaining capacity of knapsack

    // Initially set fraction vector to 0
    for (i = 0; i < n; i++)
        x[i] = 0.0;

    // Take items one by one in sorted order
    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)   // if item cannot fully fit
            break;
        else
        {
            x[i] = 1.0;                  // take full item
            tp = tp + profit[i];         // add its profit
            u = u - weight[i];           // reduce capacity
        }
    }

    // Take fractional part of next item if knapsack not full
    if (i < n)
        x[i] = u / weight[i];

    // Add fractional profit
    tp = tp + (x[i] * profit[i]);

    // Print result vector (fractions of objects taken)
    printf("\nThe result vector is: ");
    for (i = 0; i < n; i++)
    {
        if (i == n - 1)
            printf("%f", x[i]);
        else
            printf("%f, ", x[i]);
    }

    // Print maximum profit
    printf("\nMaximum profit is: %f", tp);
}

int main()
{
    clrscr();   // clear screen (Turbo C)

    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;

    // Input number of objects
    printf("\nEnter the no. of objects: ");
    scanf("%d", &num);

    // Input weights and profits
    for (i = 0; i < num; i++)
    {
        printf("\nEnter the wts and profits of object %d: ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    // Input knapsack capacity
    printf("\nEnter the capacity of knapsack: ");
    scanf("%f", &capacity);

    // Calculate profit/weight ratio for each item
    for (i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort items in descending order of ratio (Greedy step)
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                // Swap ratio
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                // Swap weight
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                // Swap profit
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    // Call knapsack function
    knapsack(num, weight, profit, capacity);

    getch();   // wait for a key press (Turbo C)
    return 0;
}
