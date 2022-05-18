#include <stdbool.h>
#include <stdlib.h>

int comp(const void *l1, const void *l2)
{
    return (*((char *)l1) - *((char *)l2));
}

bool isAnagram(char * s, char * t){
    if (strlen(s) != strlen(t)) return (false);
    
    qsort(s, strlen(s), sizeof(char), comp);
    qsort(t, strlen(t), sizeof(char), comp);
    
    return (strcmp(s, t) == 0);
}