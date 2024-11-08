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

void test_ft_toupper()
{
    print_table_header("Tests pour ft_toupper");

    // Cas 1 : Lettre minuscule
    char lower = 'a';
    char result = ft_toupper(lower);
    if (result == 'A')
        print_table_row("Conversion de 'a' en 'A'", "[SUCCÈS]");
    else
        print_table_row("Conversion de 'a' en 'A'", "[ÉCHOUÉ]");

    // Cas 2 : Lettre majuscule (pas de conversion)
    char upper = 'A';
    result = ft_toupper(upper);
    if (result == 'A')
        print_table_row("Pas de conversion pour 'A'", "[SUCCÈS]");
    else
        print_table_row("Pas de conversion pour 'A'", "[ÉCHOUÉ]");

    // Cas 3 : Chiffre (pas de conversion)
    char digit = '1';
    result = ft_toupper(digit);
    if (result == '1')
        print_table_row("Pas de conversion pour '1'", "[SUCCÈS]");
    else
        print_table_row("Pas de conversion pour '1'", "[ÉCHOUÉ]");

    // Cas 4 : Symbole (pas de conversion)
    char symbol = '#';
    result = ft_toupper(symbol);
    if (result == '#')
        print_table_row("Pas de conversion pour '#'", "[SUCCÈS]");
    else
        print_table_row("Pas de conversion pour '#'", "[ÉCHOUÉ]");

    // Cas 5 : Lettre minuscule limite ('z')
    char lower_limit = 'z';
    result = ft_toupper(lower_limit);
    if (result == 'Z')
        print_table_row("Conversion de 'z' en 'Z'", "[SUCCÈS]");
    else
        print_table_row("Conversion de 'z' en 'Z'", "[ÉCHOUÉ]");

    print_table_footer();
}

int main()
{
    test_ft_toupper();
    return 0;
}

