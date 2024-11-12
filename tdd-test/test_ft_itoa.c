#include "libft.h"
#include <stdio.h>
#include <string.h> // For comparison

void test_ft_itoa()
{
    char *result;
    char expected[20]; // Sufficiently large buffer for expected results

    printf("\n+------------------------------------------------+\n");
    printf("| Tests pour ft_itoa                             |\n");
    printf("+----------------------+-------------------------+\n");
    printf("| Cas                  | Résultat                |\n");
    printf("+----------------------+-------------------------+\n");

    // Cas 1 : Conversion de zéro
    result = ft_itoa(0);
    snprintf(expected, sizeof(expected), "%d", 0);
    if (strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "0");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "0", result);
    free(result);

    // Cas 2 : Conversion d'un nombre positif
    result = ft_itoa(12345);
    snprintf(expected, sizeof(expected), "%d", 12345);
    if (strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "12345");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "12345", result);
    free(result);

    // Cas 3 : Conversion d'un nombre négatif
    result = ft_itoa(-12345);
    snprintf(expected, sizeof(expected), "%d", -12345);
    if (strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "-12345");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "-12345", result);
    free(result);

    // Cas 4 : Conversion d'un grand nombre positif
    result = ft_itoa(2147483647); // INT_MAX
    snprintf(expected, sizeof(expected), "%d", 2147483647);
    if (strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "2147483647");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "2147483647", result);
    free(result);

    // Cas 5 : Conversion d'un grand nombre négatif
    result = ft_itoa(-2147483648); // INT_MIN
    snprintf(expected, sizeof(expected), "%d", (int)-2147483648);
    if (strcmp(result, expected) == 0)
        printf("| %-20s | [SUCCÈS]                |\n", "-2147483648");
    else
        printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "-2147483648", result);
    free(result);

    printf("+----------------------+-------------------------+\n");
}

int main()
{
    test_ft_itoa();
    return 0;
}

