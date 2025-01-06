// clang twosum.c -o bin/twosumc

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

int* twoSumHash(int* nums, int numsSize, int target, int* returnSize) {
    // I love C but aye aye aye
    // I will come back and do this another time
    return NULL;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int x = 0; x < numsSize; x++)
    {
        for (int y = x + 1; y < numsSize; y++)
        {
            if ((nums[x] + nums[y]) == target)
            {
                int* result = malloc(sizeof(int) * 2);
                result[0] = x;
                result[1] = y;
                *returnSize = 2; // stores the length of the return array
                return result;
            }
        }
    }
    
    *returnSize = 0; // set to 0 because there is no array to return
    return NULL;
}

// a helper function that creates an array, and calls the two sum function
void twoSumHelper(int target, int size, ...) {
    va_list args;
    va_start(args, size);

    int* nums = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        nums[i] = va_arg(args, int);
    }

    int* result = twoSum(nums, size, target, NULL);
    printf("%d %d equal %d\n", result[0], result[1], target);
    free(result);
    result = NULL;
    
    free(nums);
    nums = NULL;
    va_end(args);
}

int main() {

    twoSumHelper(9, 4, 2, 7, 11, 15);
    twoSumHelper(6, 3, 3, 2, 4);
    twoSumHelper(6, 2, 3, 3);

    return 0;
}