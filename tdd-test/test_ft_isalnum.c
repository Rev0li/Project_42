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


void test_ft_isalnum()
{
    print_table_header("Tests pour ft_isalnum");

    // Cas 1 : Caractères alphanumériques (A-Z, a-z, 0-9)
    int c = 'A';
    int passed = 1;
    while (c <= 'Z')
    {
        if (ft_isalnum(c) != 1)
        {
            print_table_row("Caractère A-Z", "[ÉCHOUÉ]");
            passed = 0;
            break; // Arrêt à la première erreur
        }
        c++;
    }
    c = 'a';
    while (c <= 'z')
    {
        if (ft_isalnum(c) != 1)
        {
            print_table_row("Caractère a-z", "[ÉCHOUÉ]");
            passed = 0;
            break;
        }
        c++;
    }
    c = '0';
    while (c <= '9')
    {
        if (ft_isalnum(c) != 1)
        {
            print_table_row("Caractère 0-9", "[ÉCHOUÉ]");
            passed = 0;
            break;
        }
        c++;
    }
    if (passed)
        print_table_row("Alphanumériques", "[SUCCÈS]");

    // Cas 2 : Caractères non alphanumériques (reste de la table ASCII)
    c = 0;
    passed = 1;
    while (c <= 127)
    {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) && ft_isalnum(c) != 0)
        {
            print_table_row("Non-alphanumériques", "[ÉCHOUÉ]");
            passed = 0;
            break;
        }
        c++;
    }
    if (passed)
        print_table_row("Non-alphanumériques", "[SUCCÈS]");

    print_table_footer();
}

int main()
{
    test_ft_isalnum();
    return 0;
}

