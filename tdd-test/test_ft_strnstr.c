#include "libft.h"

void print_table_header(const char *test_name)
{
    printf("\n+------------------------------------------------------------+\n");
    printf("| %-58s |\n", test_name);
    printf("+------------------------------------------+-----------------+\n");
    printf("| Cas                                      | Résultat        |\n");
    printf("+------------------------------------------+-----------------+\n");
}

void print_table_row(const char *test_case, const char *result)
{
    printf("| %-40s | %-15s |\n", test_case, result);
}

void print_table_footer()
{
    printf("+------------------------------------------+-----------------+\n");
}

void test_ft_strnstr()
{
    print_table_header("Tests pour ft_strnstr");

    // Cas 1 : Recherche d'une sous-chaîne présente
    const char haystack1[] = "Hello, World!";
    const char needle1[] = "World";
    char *result1 = ft_strnstr(haystack1, needle1, 13);
    if (result1 != NULL && strcmp(result1, "World!") == 0)
        print_table_row("Recherche sous-chaîne présente", "[SUCCÈS]");
    else
        print_table_row("Recherche sous-chaîne présente", "[ÉCHOUÉ]");

    // Cas 2 : Recherche d'une sous-chaîne absente
    const char needle2[] = "42";
    char *result2 = ft_strnstr(haystack1, needle2, 13);
    if (result2 == NULL)
        print_table_row("Recherche sous-chaîne absente", "[SUCCÈS]");
    else
        print_table_row("Recherche sous-chaîne absente", "[ÉCHOUÉ]");

    // Cas 3 : Recherche avec une longueur limitée plus petite que la sous-chaîne
    char *result3 = ft_strnstr(haystack1, needle1, 5);
    if (result3 == NULL)
        print_table_row("Recherche limitée trop courte", "[SUCCÈS]");
    else
        print_table_row("Recherche limitée trop courte", "[ÉCHOUÉ]");

    // Cas 4 : Recherche d'une chaîne vide (doit retourner haystack)
    char *result4 = ft_strnstr(haystack1, "", 13);
    if (result4 == haystack1)
        print_table_row("Recherche chaîne vide", "[SUCCÈS]");
    else
        print_table_row("Recherche chaîne vide", "[ÉCHOUÉ]");

    // Cas 5 : Recherche avec len = 0 (doit retourner NULL)
    char *result5 = ft_strnstr(haystack1, needle1, 0);
    if (result5 == NULL)
        print_table_row("Recherche avec len = 0", "[SUCCÈS]");
    else
        print_table_row("Recherche avec len = 0", "[ÉCHOUÉ]");

    print_table_footer();
}

int main()
{
    test_ft_strnstr();
    return 0;
}

