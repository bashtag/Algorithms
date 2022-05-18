// Runtime: 89 ms, faster than 80.02% of C online submissions for Move Zeroes.
// Memory Usage: 15.1 MB, less than 53.94% of C online submissions for Move Zeroes.

void moveZeroes(int* nums, int numsSize){
    int j = 0;
    int zero_counter = 0;
    
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0) nums[j++] = nums[i];
        else zero_counter++;
    }
    
    for (int i = numsSize - zero_counter; i < numsSize; i++)
    {
        if (nums[i] != 0) nums[i] = 0;
    }
}