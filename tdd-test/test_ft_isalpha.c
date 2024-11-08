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


void test_ft_isalpha()
{
    print_table_header("Tests pour ft_isalpha");

    // Cas 1 : Caractères alphabétiques (A-Z, a-z)
    int c = 'A';
    int passed = 1;
    while (c <= 'Z')
    {
        if (ft_isalpha(c) != 1)
        {
            print_table_row("Caractère A-Z", "[ÉCHOUÉ]");
            passed = 0;
            break; // Arrêt au premier échec
        }
        c++;
    }
    c = 'a';
    while (c <= 'z')
    {
        if (ft_isalpha(c) != 1)
        {
            print_table_row("Caractère a-z", "[ÉCHOUÉ]");
            passed = 0;
            break;
        }
        c++;
    }
    if (passed)
        print_table_row("Caractères alphabétiques", "[SUCCÈS]");

    // Cas 2 : Caractères non alphabétiques (reste de la table ASCII)
    c = 0;
    passed = 1;
    while (c <= 127)
    {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) && ft_isalpha(c) != 0)
        {
            print_table_row("Non-alphabétiques", "[ÉCHOUÉ]");
            passed = 0;
            break;
        }
        c++;
    }
    if (passed)
        print_table_row("Non-alphabétiques", "[SUCCÈS]");

    print_table_footer();
}

int main()
{
    test_ft_isalpha();
    return 0;
}

