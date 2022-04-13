#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * freqAlphabets(char * s){
    printf("strlen -> %d\n", strlen(s));
    char *result = (char *)calloc(strlen(s) + 1, sizeof(char));
    
    int j = 0;
    for (int i = 0; s[i]; i++, j++)
    {
        char letter = 0;
        printf("i = %d, j = %d\n", i, j);
        if (i < strlen(s) - 2 && s[i + 2] == '#')
        {
            letter += (s[i] - 48) * 10 + (s[i + 1] - 48);
            i += 2;
        }
        else
        {
            printf("%d\n", s[i]);
            letter += s[i] - 48;
        }
        printf("alo\n");
        result[j] = 'a' + letter - 1;
        printf("%c\n", result[j]);
    }
    result[j] = '\0';
    
    return (result);
}

int	main(void)
{
	char *str = freqAlphabets("1");

	printf("%s\n", str);
	free(str);
}