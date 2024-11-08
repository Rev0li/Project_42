#include "libft.h"
#include <stdio.h>
#include <string.h> // Pour comparaison avec la version standard de memset

void test_ft_memset()
{
    char buffer[10];
    int i = 0;

    // Utilisation de ft_memset pour remplir le tableau avec des 'A'
    ft_memset(buffer, 'A', sizeof(buffer));

    // Vérification du contenu du tableau avec une boucle `while`
    while (i < 10)
    {
        if (buffer[i] != 'A')
        {
            printf("Test échoué : buffer[%d] contient %c au lieu de 'A'\n", i, buffer[i]);
            return; // Fin du test en cas d'échec
        }
        i++;
    }

    printf("ft_memset Tests terminés \n");
}

int main()
{
    test_ft_memset();
    return 0;
}

