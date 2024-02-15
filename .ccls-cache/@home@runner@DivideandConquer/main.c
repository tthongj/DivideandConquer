#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int max(int a, int b, int c) {
    return (a > b) ? (a > c ? a : c) : (b > c ? b : c);
}

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubArraySum(int arr[], int low, int high) {
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    // Return the maximum of three possible cases:
    // Maximum subarray sum in the left half
    // Maximum subarray sum in the right half
    // Maximum subarray sum crossing the middle element
    return max(maxSubArraySum(arr, low, mid),
               maxSubArraySum(arr, mid + 1, high),
               maxCrossingSum(arr, low, mid, high));
}

int main() {
    int n = 10;
    int arr[n];

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 - 10;
        printf("%d ", arr[i]);
    }

    int maxSum = maxSubArraySum(arr, 0, n - 1);

    printf("\nMaximum sum of subarray is %d\n", maxSum);

    return 0;
}
