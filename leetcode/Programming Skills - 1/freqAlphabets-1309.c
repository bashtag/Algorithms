#include <stdlib.h>

char * freqAlphabets(char * s){
    char *result = (char *)calloc(strlen(s) + 1, sizeof(char));
    char letter;
    
    int j = 0;
    for (int i = 0; s[i]; i++, j++)
    {
        letter = 0;
        if (i + 2 < strlen(s) && s[i + 2] == '#')
        {
            letter += (s[i] - 48) * 10 + (s[i + 1] - 48);
            i += 2;
        }
        else
        {
            letter += s[i] - 48;
        }
        result[j] = 'a' + letter - 1;
    }
    result[j] = '\0';
    
    return (result);
}