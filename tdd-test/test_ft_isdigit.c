#include "libft.h"
#include <stdio.h>

void test_ft_isdigit()
{
    int c = 0;
    
    // Boucle pour parcourir tous les caractères de 0 à 127
    while (c <= 127)
    {
        if (c >= '0' && c <= '9')
        {
            if (ft_isdigit(c) != 1)
                printf("Test échoué pour le caractère %c (code ASCII %d)\n", c, c);
        }
        else
        {
            if (ft_isdigit(c) != 0)
                printf("Test échoué pour le caractère non numerique %c (code ASCII %d)\n", c, c);
        }
        c++;
    }
    printf("Tests terminés (isdigit) pour toute la table ASCII.\n");
}

int main()
{
    test_ft_isdigit();
    return 0;
}

