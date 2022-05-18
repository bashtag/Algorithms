#include <stdlib.h>
#include <string.h>

// Runtime: 0 ms, faster than 100.00% of C online submissions for Goal Parser Interpretation.
// Memory Usage: 5.7 MB, less than 44.20% of C online submissions for Goal Parser Interpretation.


char * interpret(char * command){
    char *result = (char *)calloc(strlen(command) + 1, sizeof(char));
    int j = 0;
    
    for (int i = 0; command[i]; i++)
    {
        if (command[i] == 'G') result[j++] = 'G';
        else if (command[i + 1] && command[i] == '(')
        {
            if (command[i + 1] == ')')
            {
                result[j++] = 'o';
                i++;
            }
            else if (command[i + 2] && command[i + 3] && command[i + 1] == 'a' &&
               command[i + 2] == 'l' && command[i + 3] == ')')
            {
                result[j++] = 'a';
                result[j++] = 'l';
                i += 3;
            }
        }
    }
    result[j] = '\0';
    return (result);
}