#include <stdlib.h>
#include <string.h>

// Runtime: 0 ms, faster than 100.0% of C online submissions
// Memory Usage: 5.7 MB, less than 62.26% of C online submissions

char * mergeAlternately(char * word1, char * word2){
    char *result = (char *)calloc(strlen(word1) + strlen(word2) + 1, sizeof(char));
    int i, j = 0;
    
    for (i = 0; word1[i] && word2[i]; i++)
    {
        if (word1[i]) result[j++] = word1[i];
        if (word2[i]) result[j++] = word2[i];
    }
    
    if (!word1[i])
        while (word2[i])
            result[j++] = word2[i++];
    
    else if (!word2[i])
        while (word1[i])
            result[j++] = word1[i++];
    
    
    return (result);
}