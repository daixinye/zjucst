#include <stdio.h>
#include <string.h>
#define MAXLINE 80
void encrypt(char *s);
int main(void)
{
    char line[MAXLINE];

    gets(line);
    encrypt(line);
    printf("%s\n", line);
    return 0;
}

void encrypt(char *s)
{
    int i = 0;
    char *str = s;
    while (*str)
    {
        if (s[i] == 'z')
        {
            s[i] = 'a';
        }
        else
        {
            s[i]++;
        }
        str++;
        i++;
    }
}