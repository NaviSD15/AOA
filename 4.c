#include <stdio.h>

// Binary Search function to find the index of a key in a sorted array
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the key is present at the middle element
        if (arr[mid] == key)
            return mid;

        // If the key is greater, ignore the left half
        if (arr[mid] < key)
            left = mid + 1;
        // If the key is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // Key not found in the array
    return -1;
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; // Declare an array of size 'n'

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Input array elements
    }

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key); // Input the key to search for

    // Perform binary search on the sorted array
    int index = binarySearch(arr, 0, n - 1, key);

    if (index != -1)
        printf("Key %d found at index %d.\n", key, index);
    else
        printf("Key %d not found in the array.\n", key);

    return 0;
}
