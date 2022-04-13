#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Runtime: 4 ms, faster than 38.83% of C online submissions for Find the Difference.
// Memory Usage: 5.9 MB, less than 5.19% of C online submissions for Find the Difference.

bool charComp(void *a, void *b)
{
    return *(char *)a > *(char *)b;
}

char findTheDifference(char * s, char * t){
    int i;
    
    qsort(s, strlen(s), sizeof(char), charComp);
    qsort(t, strlen(t), sizeof(char), charComp);
    for (i = 0; s[i]; i++)
        if (s[i] != t[i]) break;
    
    return t[i];
}