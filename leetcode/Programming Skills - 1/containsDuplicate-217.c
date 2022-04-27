#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100000
#define HASH_SIZE 1000000000

struct Node {
    int val;
    struct Node *next;
};

bool    isVisited(int num, struct Node **visited, int *visitedSize)
{
    for (int i = 0; i < *visitedSize; i++)
    {
        if (num == visited[i]->val)
            return (true);
    }
    
    visited[*visitedSize] = (struct Node *)calloc(1, sizeof(struct Node));
    visited[(*visitedSize)++]->val = num;
    
    return (false);
}

bool containsDuplicate(int* nums, int numsSize){
    if (numsSize > 10000)
    {
        int *hashMap = (int *)calloc(HASH_SIZE, sizeof(int));
        int *hashMapNegative = (int *)calloc(HASH_SIZE, sizeof(int));

        for (int i = 0; i < numsSize; i++)
        {
            if (nums[i] >= 0) hashMap[nums[i]]++;
            if (nums[i] < 0) hashMapNegative[(-nums[i])]++;
        }

        for (int i = 0; i < numsSize; i++)
        {
            if (nums[i] >= 0 && hashMap[nums[i]] > 1) return (true);
            if (nums[i] < 0 && hashMapNegative[(-nums[i])] > 1) return (true);
        }
    }
    else
    {
        struct Node **visited = (struct Node **)calloc(MAX_SIZE, sizeof(struct Node *));
        int *visitedSize = (int *)calloc(1, sizeof(int));

        *visitedSize = 0;
        for (int i = 0; i < numsSize; i++)
            if (isVisited(nums[i], visited, visitedSize))
                return (true);
    }
    
    return (false);
}