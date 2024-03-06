/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    // Assign memory space for the return array.
    int* arr = malloc(numsSize * sizeof(int));

    // Return array have the same length as the given array.
    *returnSize = numsSize;

    // A counter shows next element's position.
    int curr = 0;

    for (int i = 0; i < n; i++) {
        // Assign X number to arr array before moving both curr and start forward.
        arr[curr++] = nums[i];
        // Since Y number is second part in the nums array, i+n is our target index.
        // Assign Y number to arr array before moving both curr and start forward.
        arr[curr++] = nums[i + n];
    }

    return arr;
}

/*
Time Complexity: O(n)
*/
