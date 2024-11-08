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
    printf("| %-40s | %-16s |\n", test_case, result);
}

void print_table_footer()
{
    printf("+------------------------------------------+-----------------+\n");
}

void test_ft_isascii()
{
    print_table_header("Tests pour ft_isascii");

    // Cas 1 : Caractères dans la plage ASCII (0 à 127)
    int c = 0;
    int passed = 1;
    while (c <= 127)
    {
        if (ft_isascii(c) != 1)
        {
            print_table_row("Plage ASCII (0-127)", "[ÉCHOUÉ]");
            passed = 0;
            break;
        }
        c++;
    }
    if (passed)
        print_table_row("Plage ASCII (0-127)", "[SUCCÈS]");

    // Cas 2 : Valeurs en dehors de la plage ASCII
    passed = 1;
    if (ft_isascii(-1) != 0)
    {
        print_table_row("Valeur -1", "[ÉCHOUÉ]");
        passed = 0;
    }
    if (ft_isascii(128) != 0)
    {
        print_table_row("Valeur 128", "[ÉCHOUÉ]");
        passed = 0;
    }
    if (passed)
        print_table_row("Hors plage ASCII", "[SUCCÈS]");

    print_table_footer();
}

int main()
{
    test_ft_isascii();
    return 0;
}

