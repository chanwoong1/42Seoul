#include <stdio.h>

int main()
{
    char *str = "Hello";
    int i = 0;

    while (i < 5)
    {
        // printf("i : %d, str[%d] : %c\n", i, i, str[i]);
        printf("*str : %s, str : %c\n", str, str[0]);
        i++;
        str++;
    }
}