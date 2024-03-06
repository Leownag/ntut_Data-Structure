#include <stdio.h>

bool threeConsecutiveOdds(int* arr, int arrSize) {
    // A counter shows count of consecutive odds.
    int counter = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {
            // If the current element is odd, add one to the counter variable.
            counter++;
            // If the counter is greater than or equal to 3, it means there are three consecutive odds in the array.
            // Break the for loop in this case.
            if (counter >= 3)
                break;
        } else {
            // If the current element is odd, reset the counter variable.
            counter = 0;
        }
    }

    // If the counter is greater than or equal to 3, it means there are three consecutive odds in the array.
    return counter >= 3;
}