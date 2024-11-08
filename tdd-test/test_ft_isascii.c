#include "libft.h"
#include <stdio.h>

void test_ft_isascii()
{
    int c;

    // Boucle pour tester tous les caractères de 0 à 127 (doit retourner 1)
    c = 0;
    while (c <= 127)
    {
        if (ft_isascii(c) != 1)
            printf("Test échoué pour le caractère ASCII %c (code ASCII %d)\n", c, c);
        c++;
    }

    // Tests pour des valeurs en dehors de la plage ASCII (doit retourner 0)
    if (ft_isascii(-1) != 0)
        printf("Test échoué pour le caractère non-ASCII (code ASCII -1)\n");
    if (ft_isascii(128) != 0)
        printf("Test échoué pour le caractère non-ASCII (code ASCII 128)\n");

    printf("ft_isascii Tests terminés(\n");
}

int main()
{
    test_ft_isascii();
    return 0;
}

