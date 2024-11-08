#include "libft.h"
#include <stdio.h>
#include <string.h>

void test_ft_strlen()
{
    // Cas de la chaîne vide
    if (ft_strlen("") != 0)
        printf("Test échoué : longueur de chaîne vide devrait être 0\n");

    // Cas d'une chaîne avec un seul caractère
    if (ft_strlen("a") != 1)
        printf("Test échoué : longueur de 'a' devrait être 1\n");

    // Cas d'une chaîne avec plusieurs caractères
    if (ft_strlen("Hello") != 5)
        printf("Test échoué : longueur de 'Hello' devrait être 5\n");

    // Cas d'une chaîne avec des espaces
    if (ft_strlen("Hello World") != 11)
        printf("Test échoué : longueur de 'Hello World' devrait être 11\n");

    // Cas d'une chaîne avec des caractères spéciaux
    if (ft_strlen("Hello\n") != 6)
        printf("Test échoué : longueur de 'Hello\\n' devrait être 6\n");

    printf("ft_strlen Tests terminés\n");
}

void test_ft_strlen_advanced()
{
    // 1. Test avec une boucle pour des chaînes de longueurs variables
    char small_buffer[101];
    for (int i = 1; i <= 100; i++)
    {
        memset(small_buffer, 'A', i); // Remplit le buffer avec 'A'
        small_buffer[i] = '\0';       // Ajoute le caractère nul
        if (ft_strlen(small_buffer) != i)
            printf("Test échoué : longueur attendue %d, obtenue %d\n", i, ft_strlen(small_buffer));
    }

    // 2. Test avec des caractères spéciaux
    if (ft_strlen("Hello World\n") != 12)
        printf("Test échoué pour 'Hello World\\n'\n");

    if (ft_strlen("\tTab\t") != 5)
        printf("Test échoué pour '\\tTab\\t'\n");

    // 3. Stress test avec une chaîne très longue
    char large_buffer[1001]; // Augmentation de la taille du buffer pour 1000 caractères + caractère nul
    memset(large_buffer, 'A', 1000); // Crée une chaîne de 1000 caractères 'A'
    large_buffer[1000] = '\0';
    if (ft_strlen(large_buffer) != 1000)
        printf("Test échoué pour une chaîne de 1000 caractères\n");

    printf("ft_strlen Tests avancés terminés\n");
}
int main()
{
	test_ft_strlen_advanced();
	test_ft_strlen();
    return 0;
}

