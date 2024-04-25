#include <stdio.h>
#include <stdbool.h>

bool flag = false; // Global flag to track if any subset is found

// Function to print subsets with sum equal to targetSum
void PrintSubsetSum(int i, int n, int set[], int targetSum, int subset[], int subsetSize) {
    // Base case: If targetSum is reached (subset with desired sum found)
    if (targetSum == 0) {
        flag = true; // Set flag to true indicating a valid subset is found
        printf(" [ ");
        for (int j = 0; j < subsetSize; ++j) {
            printf("%d ", subset[j]);
        }
        printf("]\n");
        return;
    }

    // Base case: If all elements of set[] have been considered
    if (i == n)
        return;

    // Exclude current element and move to the next
    PrintSubsetSum(i + 1, n, set, targetSum, subset, subsetSize);

    // Include current element if it is less than or equal to targetSum
    if (set[i] <= targetSum) {
        subset[subsetSize] = set[i];
        PrintSubsetSum(i + 1, n, set, targetSum - set[i], subset, subsetSize + 1);
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[n];

    printf("Enter the elements of the set (non-negative integers): ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &set[i]);

    int targetSum;
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    int subset[n]; // Array to store subsets

    printf("Subsets with sum equal to %d:\n", targetSum);
    PrintSubsetSum(0, n, set, targetSum, subset, 0);

    // If no subset with the given sum is found, display message
    if (!flag)
        printf("There is no such subset.\n");

    return 0;
}
