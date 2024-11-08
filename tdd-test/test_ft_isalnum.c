#include "libft.h"
#include <stdio.h>

void test_ft_isalnum()
{
    int c;

    c = 0;
    while (c <= 127)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            if (ft_isalnum(c) != 1)
                printf("Erreur : ft_isalnum a échoué pour le caractère alphanumérique %c (code ASCII %d)\n", c, c);
        }
        else
        {
            if (ft_isalnum(c) != 0)
                printf("Erreur : ft_isalnum a échoué pour le caractère non alphanumérique %c (code ASCII %d)\n", c, c);
        }
        c++;
    }
    printf("ft_isalnum Tests terminés\n");
}

int main()
{
    test_ft_isalnum();
    return 0;
}

