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

void test_ft_memset()
{
    print_table_header("Tests pour ft_memset");

    // Cas 1 : Remplissage total avec 'A'
    char buffer[10];
    ft_memset(buffer, 'A', sizeof(buffer));
    int i = 0;
    int passed = 1;
    while (i < 10)
    {
        if (buffer[i] != 'A')
        {
            print_table_row("Remplissage total", "[ÉCHOUÉ]");
            passed = 0;
            break; // Arrêt au premier échec
        }
        i++;
    }
    if (passed)
        print_table_row("Remplissage total", "[SUCCÈS]");

    // Cas 2 : Remplissage partiel
    char buffer2[10] = {0};
    ft_memset(buffer2, 'B', 5);
    int j = 0;
    int passed2 = 1;
    while (j < 5)
    {
        if (buffer2[j] != 'B')
        {
            print_table_row("Remplissage partiel", "[ÉCHOUÉ]");
            passed2 = 0;
            break;
        }
        j++;
    }
    if (passed2)
        print_table_row("Remplissage partiel", "[SUCCÈS]");

    print_table_footer();
}

int main()
{
    test_ft_memset();
    return 0;
}

