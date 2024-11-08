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
    printf("| %-41s | %-16s |\n", test_case, result);
}

void print_table_footer()
{
    printf("+------------------------------------------+-----------------+\n");
}

void test_ft_isprint()
{
    print_table_header("Tests pour ft_isprint");

    // Cas 1 : Caractères imprimables (de ' ' à '~')
    int c = ' ';
    int passed = 1;
    while (c <= '~')
    {
        if (ft_isprint(c) != 1)
        {
            print_table_row("Caractère imprimable", "[ÉCHOUÉ]");
            passed = 0;
            break; // Arrêt au premier échec
        }
        c++;
    }
    if (passed)
        print_table_row("Caractères imprimables", "[SUCCÈS]");

    // Cas 2 : Caractères non imprimables (0 à 31 et 127)
    c = 0;
    passed = 1;
    while (c <= 31)
    {
        if (ft_isprint(c) != 0)
        {
            print_table_row("Non imprimable (0-31)", "[ÉCHOUÉ]");
            passed = 0;
            break;
        }
        c++;
    }
    if (ft_isprint(127) != 0)
    {
        print_table_row("Non imprimable (127)", "[ÉCHOUÉ]");
        passed = 0;
    }
    if (passed)
        print_table_row("Caractères non imprimables", "[SUCCÈS]");

    print_table_footer();
}

int main()
{
    test_ft_isprint();
    return 0;
}

