#include <stdlib.h>

int    comp(const void *n1, const void *n2)
{
    int counter1 = 0, counter2 = 0;
    int buff1 = *((int *)n1);
    int buff2 = *((int *)n2);
    
    while (buff1)
    {
        if (buff1 & 1) counter1++;
        buff1 >>= 1;
    }
    
    while (buff2)
    {
        if (buff2 & 1) counter2++;
        buff2 >>= 1;
    }
    
    if (counter1 == counter2)
        return (*((int *)n1) - *((int *)n2));
    return (counter1 - counter2);    
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize){
    qsort(arr, arrSize, sizeof(int), comp);
    
    *returnSize = arrSize;
    
    return (arr);
}