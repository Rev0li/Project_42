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
    printf("| %-40.40s | %-15s |\n", test_case, result);
}

void print_table_footer()
{
    printf("+------------------------------------------+-----------------+\n");
}

void test_ft_memchr()
{
    char data[] = "42Network";

    // Cas 1 : Caractère présent dans la chaîne
    char *result = ft_memchr(data, 'N', 9);
    if (result == &data[2])
        print_table_row("Caractère présent ('N')", "[SUCCÈS]");
    else
        print_table_row("Caractère présent ('N')", "[ÉCHOUÉ]");

    // Cas 2 : Caractère non présent
    result = ft_memchr(data, 'X', 9);
    if (result == NULL)
        print_table_row("Caractère non présent ('X')", "[SUCCÈS]");
    else
        print_table_row("Caractère non présent ('X')", "[ÉCHOUÉ]");

    // Cas 3 : Recherche du caractère nul '\0'
    result = ft_memchr(data, '\0', 10);
    if (result == &data[9])
        print_table_row("Recherche du caractère nul '\\0'", "[SUCCÈS]");
    else
        print_table_row("Recherche du caractère nul '\\0'", "[ÉCHOUÉ]");

    // Cas 4 : Taille 0 (aucune recherche)
    result = ft_memchr(data, '4', 0);
    if (result == NULL)
        print_table_row("Taille de recherche 0", "[SUCCÈS]");
    else
        print_table_row("Taille de recherche 0", "[ÉCHOUÉ]");
}

int main()
{
    print_table_header("Tests pour ft_memchr");
    test_ft_memchr();
    print_table_footer();
    return 0;
}

