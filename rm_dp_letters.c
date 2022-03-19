#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeDuplicateLetters(char *s)
{
    int i, j, len=strlen(s);
    char *sss = (char *)calloc(1,sizeof(s));

    for (i = 0; i < len; i++)
        for (j = i+1; j < len; j++)
            if (s[i] == s[j]) strcat(sss,&s[i]);
    return sss;
}

int main()
{
    char *s = "bcabc";
    printf(removeDuplicateLetters(s));
    return (0);
}