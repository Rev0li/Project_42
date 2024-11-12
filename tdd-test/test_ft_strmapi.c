#include "libft.h"
#include <stdio.h>
#include <string.h> // Pour comparer les résultats

// Exemple de fonction à appliquer avec ft_strmapi
char example_func(unsigned int index, char c)
{
    return (c + index); // Ajoute l'index au caractère
}

void test_ft_strmapi()
{
    char *result;
    char expected[50];

    printf("\n+------------------------------------------------+\n");
    printf("| Tests pour ft_strmapi                          |\n");
    printf("+----------------------+-------------------------+\n");
    printf("| Cas                  | Résultat                |\n");
    printf("+----------------------+-------------------------+\n");

    // Cas 1 : Application de la fonction de transformation
    result = ft_strmapi("abcd", example_func);
    snprintf(expected, sizeof(expected), "%s", "aceg"); // Chaque lettre est augmentée par son index
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "transform basic");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "transform basic", result ? result : "NULL");
    free(result);

    // Cas 2 : Chaîne vide
    result = ft_strmapi("", example_func);
    snprintf(expected, sizeof(expected), "%s", "");
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "empty string");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "empty string", result ? result : "NULL");
    free(result);

    // Cas 3 : Chaîne NULL
    result = ft_strmapi(NULL, example_func);
    if (result == NULL)
        printf("| %-20s | [SUCCÈS]                |\n", "NULL input");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "NULL input", result);

    printf("+----------------------+-------------------------+\n");
}

int main()
{
    test_ft_strmapi();
    return 0;
}

