#include "libft.h"
#include <stdio.h>

void test_ft_isalpha()
{
    int c = 0;
    
    // Boucle pour parcourir tous les caractères de 0 à 127
    while (c <= 127)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            if (ft_isalpha(c) != 1)
                printf("Test échoué pour le caractère %c (code ASCII %d)\n", c, c);
        }
        else
        {
            if (ft_isalpha(c) != 0)
                printf("Test échoué pour le caractère non alphabétique %c (code ASCII %d)\n", c, c);
        }
        c++;
    }
    printf("isalpha Tests terminés\n");
}

int main()
{
    test_ft_isalpha();
    return 0;
}

