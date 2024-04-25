
#include<stdio.h>

void insertionsort(int arr[], int n) {
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = key;
    }
}

int main() {
    int arr[5]; // You need to specify the size of the array, for example, 5

    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting the array using insertion sort
    insertionsort(arr, n);

    // Displaying the sorted array
    printf("Sorted array by insertion sort :\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

         
         
   