#include <stdio.h>
int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right =n - 1;

    while (left <= right) {
        int mid = (left+right)/ 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int key= 23;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, n, key);
    if (result != -1)
        printf("Element %d is present at index %d\n", key, result);
    else
        printf("Element %d is not present in the array\n", key);
    return 0;
}
