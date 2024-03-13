int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* arr = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int curr = 0;
    for (int i = 0; i < numsSize; i++) {
        curr += nums[i];
        arr[i] = curr;
    }
    return arr;
}