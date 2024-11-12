#include "libft.h"
#include <stdio.h>
#include <string.h> // Pour comparer les résultats

void test_ft_strtrim()
{
    char *result;
    char expected[50];

    printf("\n+------------------------------------------------+\n");
    printf("| Tests pour ft_strtrim                          |\n");
    printf("+----------------------+-------------------------+\n");
    printf("| Cas                  | Résultat                |\n");
    printf("+----------------------+-------------------------+\n");

    // Cas 1 : Suppression d'espaces en début et fin
    result = ft_strtrim("   hello   ", " ");
    snprintf(expected, sizeof(expected), "%s", "hello");
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "trimmed spaces");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "trimmed spaces", result ? result : "NULL");
    free(result);

    // Cas 2 : Suppression de caractères spéciaux
    result = ft_strtrim("**42isAwesome**", "*");
    snprintf(expected, sizeof(expected), "%s", "42isAwesome");
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "trimmed *");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "trimmed *", result ? result : "NULL");
    free(result);

    // Cas 3 : Chaîne vide
    result = ft_strtrim("", " ");
    snprintf(expected, sizeof(expected), "%s", "");
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "empty string");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "empty string", result ? result : "NULL");
    free(result);

    // Cas 4 : Ensemble de caractères vide
    result = ft_strtrim("hello", "");
    snprintf(expected, sizeof(expected), "%s", "hello");
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "empty set");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "empty set", result ? result : "NULL");
    free(result);

    // Cas 5 : Tous les caractères doivent être supprimés
    result = ft_strtrim("xxxx", "x");
    snprintf(expected, sizeof(expected), "%s", "");
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "all trimmed");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "all trimmed", result ? result : "NULL");
    free(result);

    // Cas 6 : Suppression des caractères uniquement au début et à la fin
    result = ft_strtrim("$$$hello$$$", "$");
    snprintf(expected, sizeof(expected), "%s", "hello");
    if (result && strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "trimmed $");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "trimmed $", result ? result : "NULL");
    free(result);

    printf("+----------------------+-------------------------+\n");
}

int main()
{
    test_ft_strtrim();
    return 0;
}

