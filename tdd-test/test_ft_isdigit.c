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
    printf("| %-42s | %-16s |\n", test_case, result);
}

void print_table_footer()
{
    printf("+------------------------------------------+-----------------+\n");
}


void test_ft_isdigit()
{
    print_table_header("Tests pour ft_isdigit");

    // Cas 1 : Caractères numériques (de '0' à '9')
    int c = '0';
    int passed = 1;
    while (c <= '9')
    {
        if (ft_isdigit(c) != 1)
        {
            print_table_row("Caractère 0-9", "[ÉCHOUÉ]");
            passed = 0;
            break; // Arrêt au premier échec
        }
        c++;
    }
    if (passed)
        print_table_row("Caractères numériques", "[SUCCÈS]");

    // Cas 2 : Caractères non numériques (reste de la table ASCII)
    c = 0;
    passed = 1;
    while (c <= 127)
    {
        if ((c < '0' || c > '9') && ft_isdigit(c) != 0)
        {
            print_table_row("Non numériques", "[ÉCHOUÉ]");
            passed = 0;
            break;
        }
        c++;
    }
    if (passed)
        print_table_row("Caractères non numériques", "[SUCCÈS]");

    print_table_footer();
}

int main()
{
    test_ft_isdigit();
    return 0;
}

