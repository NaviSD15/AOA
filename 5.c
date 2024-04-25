#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], tp = 0;
    int i;
    float remainingCapacity = capacity;

    // Initialize the result vector x[] to store item selection (0 or 1)
    for (i = 0; i < n; i++)
        x[i] = 0.0;

    // Calculate the maximum profit by selecting items based on greedy approach (fractional knapsack)
    for (i = 0; i < n; i++) {
        if (weight[i] > remainingCapacity)
            break;
        
        x[i] = 1.0; // Select the whole item
        tp += profit[i]; // Add profit of the selected item to total profit
        remainingCapacity -= weight[i]; // Reduce the remaining capacity
    }

    // If there's remaining capacity, calculate the fraction of the last item to maximize profit
    if (i < n)
        x[i] = remainingCapacity / weight[i];
    
    tp += x[i] * profit[i]; // Add profit of the fractionally selected item to total profit

    // Output the result vector and maximum profit
    printf("\nThe result vector is:- ");
    for (i = 0; i < n; i++)
        printf("%f\t", x[i]);
    
    printf("\nMaximum profit is:- %f", tp);
}

int main() {
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;

    printf("\nEnter the number of objects: ");
    scanf("%d", &num);

    printf("\nEnter the weights of each object: ");
    for (i = 0; i < num; i++)
        scanf("%f", &weight[i]);

    printf("\nEnter the profits of each object: ");
    for (i = 0; i < num; i++)
        scanf("%f", &profit[i]);

    printf("\nEnter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    // Calculate profit-to-weight ratio for each item
    for (i = 0; i < num; i++)
        ratio[i] = profit[i] / weight[i];

    // Sort items based on the ratio in descending order (greedy approach)
    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap elements based on the ratio
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    // Call the knapsack function to find the maximum profit
    knapsack(num, weight, profit, capacity);

    return 0;
}
