#include "libft.h"
#include <stdio.h>

void test_ft_isprint()
{
    int c;

    // Boucle pour tester tous les caractères de 0 à 127 
    c = 0;
    while (c <= 127)
    {
        if ((c >= ' ' && c <= '~') && ft_isprint(c) != 1)
            printf("Test échoué pour le caractère imprimable %c (code ASCII %d)\n", c, c);
        else if ((c < ' ' || c > '~') && ft_isprint(c) != 0)
            printf("Test échoué pour le caractère non imprimable (code ASCII %d)\n", c);
        c++;
    }

    printf("Tests terminés pour ft_isprint.\n");
}

int main()
{
    test_ft_isprint();
    return 0;
}

