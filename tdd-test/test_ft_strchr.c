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

void test_ft_strchr()
{
    print_table_header("Tests pour ft_strchr");

    // Cas 1 : Caractère présent au début
    const char *str1 = "Hello, world!";
    if (ft_strchr(str1, 'H') == strchr(str1, 'H'))
        print_table_row("Caractère présent au début", "[SUCCÈS]");
    else
        print_table_row("Caractère présent au début", "[ÉCHOUÉ]");

    // Cas 2 : Caractère présent au milieu
    if (ft_strchr(str1, 'o') == strchr(str1, 'o'))
        print_table_row("Caractère présent au milieu", "[SUCCÈS]");
    else
        print_table_row("Caractère présent au milieu", "[ÉCHOUÉ]");

    // Cas 3 : Caractère présent à la fin
    if (ft_strchr(str1, '!') == strchr(str1, '!'))
        print_table_row("Caractère présent à la fin", "[SUCCÈS]");
    else
        print_table_row("Caractère présent à la fin", "[ÉCHOUÉ]");

    // Cas 4 : Caractère non présent
    if (ft_strchr(str1, 'x') == strchr(str1, 'x'))
        print_table_row("Caractère non présent", "[SUCCÈS]");
    else
        print_table_row("Caractère non présent", "[ÉCHOUÉ]");

    // Cas 5 : Caractère nul '\0'
    if (ft_strchr(str1, '\0') == strchr(str1, '\0'))
        print_table_row("Caractère nul '\\0'", "[SUCCÈS]");
    else
        print_table_row("Caractère nul '\\0'", "[ÉCHOUÉ]");

    // Cas 6 : Chaîne vide
    const char *empty_str = "";
    if (ft_strchr(empty_str, 'a') == strchr(empty_str, 'a'))
        print_table_row("Chaîne vide", "[SUCCÈS]");
    else
        print_table_row("Chaîne vide", "[ÉCHOUÉ]");

    print_table_footer();
}

int main()
{
    test_ft_strchr();
    return 0;
}

