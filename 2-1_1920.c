int* buildArray(int* nums, int numsSize, int* returnSize) {
    // Assign memory space for the return array.
    int *arr = malloc(numsSize * sizeof(int));
    int *arr[numsSize];
    // Return array have the same length as the given array.
    *returnSize = numsSize;

    // Get i place's value 
    for (int i = 0; i < numsSize; i++) {
        arr[i] = nums[nums[i]];
    }
    return arr;
}

