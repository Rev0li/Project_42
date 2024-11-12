#include "libft.h"
#include <stdio.h>
#include <string.h> // Pour comparer les résultats

void check_split_result(char **result, char **expected, const char *description)
{
    int i = 0;
    int success = 1;

    if (!result && !expected)
    {
        printf("| %-20s | [SUCCÈS]                |\n", description);
        return;
    }

    if (!result || !expected)
    {
        printf("| %-20s | [ÉCHOUÉ] Résultat: NULL  |\n", description);
        return;
    }

    while (expected[i])
    {
        if (!result[i] || strcmp(result[i], expected[i]) != 0)
        {
            success = 0;
            break;
        }
        i++;
    }

    if (success && !result[i]) // Vérification que les deux tableaux sont terminés
        printf("| %-20s | [SUCCÈS]                |\n", description);
    else
    {
        printf("| %-20s | [ÉCHOUÉ] Résultat: ", description);
        i = 0;
        while (result && result[i])
        {
            printf("\"%s\" ", result[i]);
            free(result[i]);
            i++;
        }
        printf("|\n");
    }
    free(result);
}

void test_ft_split()
{
    char **result;
    char *expected1[] = {"hello", "world", "42", NULL};
    char *expected2[] = {"42", "school", NULL};
    char *expected3[] = {"hello", NULL};
    char *expected4[] = {NULL};
    char *expected5[] = {"hello", NULL};
    char *expected6[] = {NULL};

    printf("\n+------------------------------------------------+\n");
    printf("| Tests pour ft_split                            |\n");
    printf("+----------------------+-------------------------+\n");
    printf("| Cas                  | Résultat                |\n");
    printf("+----------------------+-------------------------+\n");

    // Cas 1 : Division par un espace
    result = ft_split("hello world 42", ' ');
    check_split_result(result, expected1, "split spaces");

    // Cas 2 : Division par un tiret avec délimiteurs consécutifs
    result = ft_split("42---school", '-');
    check_split_result(result, expected2, "split -");

    // Cas 3 : Division d'une chaîne avec délimiteurs au début et à la fin
    result = ft_split("--hello--", '-');
    check_split_result(result, expected3, "split edge -");

    // Cas 4 : Chaîne vide
    result = ft_split("", ' ');
    check_split_result(result, expected4, "split empty string");

    // Cas 5 : Aucun délimiteur présent
    result = ft_split("hello", '-');
    check_split_result(result, expected5, "no delimiters");

    // Cas 6 : Délimiteur seul
    result = ft_split("---", '-');
    check_split_result(result, expected6, "delimiter only -");

    printf("+----------------------+-------------------------+\n");
}

int main()
{
    test_ft_split();
    return 0;
}

