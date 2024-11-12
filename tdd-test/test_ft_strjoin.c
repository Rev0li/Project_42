#include "libft.h"
#include <stdio.h>
#include <string.h> // Pour comparer les résultats

void test_ft_strjoin()
{
    char *result;
    char expected[50];

    printf("\n+------------------------------------------------+\n");
    printf("| Tests pour ft_strjoin                          |\n");
    printf("+----------------------+-------------------------+\n");
    printf("| Cas                  | Résultat                |\n");
    printf("+----------------------+-------------------------+\n");

    // Cas 1 : Concaténation normale
    result = ft_strjoin("hello", "world");
    snprintf(expected, sizeof(expected), "%s", "helloworld");
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "helloworld");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "helloworld", result ? result : "NULL");
    free(result);

    // Cas 2 : Chaîne vide et chaîne non vide
    result = ft_strjoin("", "world");
    snprintf(expected, sizeof(expected), "%s", "world");
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "world");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "world", result ? result : "NULL");
    free(result);

    result = ft_strjoin("hello", "");
    snprintf(expected, sizeof(expected), "%s", "hello");
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "hello");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "hello", result ? result : "NULL");
    free(result);

    // Cas 3 : Deux chaînes vides
    result = ft_strjoin("", "");
    snprintf(expected, sizeof(expected), "%s", "");
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "empty");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "empty", result ? result : "NULL");
    free(result);

    // Cas 4 : s1 est NULL
    result = ft_strjoin(NULL, "world");
    snprintf(expected, sizeof(expected), "%s", "world"); // Modifier selon le comportement souhaité
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "NULL + world");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "NULL + world", result ? result : "NULL");
    free(result);

    // Cas 5 : s2 est NULL
    result = ft_strjoin("hello", NULL);
    snprintf(expected, sizeof(expected), "%s", "hello"); // Modifier selon le comportement souhaité
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "hello + NULL");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "hello + NULL", result ? result : "NULL");
    free(result);

    // Cas 6 : s1 et s2 sont NULL
    result = ft_strjoin(NULL, NULL);
    if (!result)
        printf("| %-20s | [SUCCÈS]                |\n", "NULL + NULL");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "NULL + NULL", result);
    free(result);

    printf("+----------------------+-------------------------+\n");
}

int main()
{
    test_ft_strjoin();
    return 0;
}

