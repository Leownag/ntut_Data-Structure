int* buildArray(int* nums, int numsSize, int* returnSize) {
    // Assign memory space for the return array.
    int *arr = malloc(numsSize * sizeof(int));
    // Return array have the same length as the given array.
    *returnSize = numsSize;

    // Put nums array's nums[i] place value to retrun arr.
    for (int i = 0; i < numsSize; i++) {
        arr[i]          = nums[nums[i]];
    }
    return arr;
}

/*
BuildArray have some constant time operation and a for-loop run n(numsSize) times, time input array's lenth will affact this function's speed.
Time Complexity: O(n)
*/
