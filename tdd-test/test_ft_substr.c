#include "libft.h"
#include <stdio.h>
#include <string.h> // For comparison

void test_ft_substr()
{
		char *result;
		char expected[20];

		printf("\n+------------------------------------------------+\n");
		printf("| Tests pour ft_substr                            |\n");
		printf("+----------------------+-------------------------+\n");
		printf("| Cas                  | Résultat                |\n");
		printf("+----------------------+-------------------------+\n");

		// Cas 1 : de 0 a 5
		result = ft_substr("hello world", 0, 5);
		snprintf(expected, sizeof(expected), "%s", "hello");
		if (result && strcmp(result, expected) == 0)
				printf("| %-20s | [SUCCÈS]                |\n", "hello");
		else
				printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "hello", result);
		free(result);

		// Cas 2 : len est a 0
		result = ft_substr("hello world", 0, 0);
		snprintf(expected, sizeof(expected), "%s", "");
		if (result && strcmp(result, expected) == 0)
				printf("| %-20s | [SUCCÈS]                |\n", "empty");
		else
				printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "empty", result ? result : "NULL");
		free(result);

		// Cas 3 : de 6 a 11
		result = ft_substr("hello world", 6, 5);
		snprintf(expected, sizeof(expected), "%s", "world");
		if (result && strcmp(result, expected) == 0)
				printf("| %-20s | [SUCCÈS]                |\n", "world");
		else
				printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "world", result ? result : "NULL");
		free(result);

		//Cas 4 : start est sup a la longueur de source
		result = ft_substr("hello", 10, 5);
		snprintf(expected, sizeof(expected), "%s", "");
		if (result && strcmp(result, expected) == 0)
				printf("| %-20s | [SUCCÈS]                |\n", "empty");
		else
				printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "empty", result ? result : "NULL");
		free(result);

		//Cas 5 : chaine vide 
		result = ft_substr("", 0, 5);
		snprintf(expected, sizeof(expected), "%s", "");
		if (result && strcmp(result, expected) == 0)
				printf("| %-20s | [SUCCÈS]                |\n", "empty");
		else
				printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "empty", result ? result : "NULL");
		free(result);

		// Cas 6 : len depasse la source
		result = ft_substr("hello", 1, 10);
		snprintf(expected, sizeof(expected), "%s", "ello");
		if (result && strcmp(result, expected) == 0)
				printf("| %-20s | [SUCCÈS]                |\n", "ello");
		else
				printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "ello", result ? result : "NULL");
		free(result);

		// Cas 7 : NULL en string d entree
		result = ft_substr(NULL, 0, 5);
if (!result)
    printf("| %-20s | [SUCCÈS]                |\n", "NULL input");
else
    printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "NULL input", result);
free(result);

		printf("+----------------------+-------------------------+\n");
}

int main()
{
		test_ft_substr();
		return 0;
}

