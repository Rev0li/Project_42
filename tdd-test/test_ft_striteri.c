#include "libft.h"
#include <stdio.h>
#include <string.h> // Pour comparer les résultats

// Exemple de fonction à appliquer : met chaque caractère en majuscule
void to_uppercase(unsigned int index, char *c)
{
	(void)index;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

// Exemple de fonction à appliquer : ajoute l'index à chaque caractère (in-place)
void add_index(unsigned int index, char *c)
{
	*c += index;
}

void test_ft_striteri()
{
	char str1[] = "hello";
	char str2[] = "abcd";
	char str3[] = ""; // Chaîne vide

	printf("\n+------------------------------------------------+\n");
	printf("| Tests pour ft_striteri                         |\n");
	printf("+----------------------+-------------------------+\n");
	printf("| Cas                  | Résultat                |\n");
	printf("+----------------------+-------------------------+\n");

	// Cas 1 : Conversion en majuscules
	ft_striteri(str1, to_uppercase);
	if (strcmp(str1, "HELLO") == 0)
		printf("| %-20s | [SUCCÈS]                |\n", "to_uppercase");
	else
		printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "to_uppercase", str1);

	// Cas 2 : Ajout de l'index
	ft_striteri(str2, add_index);
	if (strcmp(str2, "aceg") == 0)
		printf("| %-20s | [SUCCÈS]                |\n", "add_index");
	else
		printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "add_index", str2);

	// Cas 3 : Chaîne vide
	ft_striteri(str3, to_uppercase);
	if (strcmp(str3, "") == 0)
		printf("| %-20s | [SUCCÈS]                |\n", "empty string");
	else
		printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "empty string", str3);

	printf("+----------------------+-------------------------+\n");
}

int main()
{
	test_ft_striteri();
	return 0;
}

