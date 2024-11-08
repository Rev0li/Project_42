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
    printf("| %-40.40s | %-16s |\n", test_case, result);
}

void print_table_footer()
{
    printf("+------------------------------------------+-----------------+\n");
}

void test_ft_bzero()
{
    print_table_header("Tests pour ft_bzero");

    // Cas 1 : Taille zéro (ne devrait rien changer)
    char buffer1[10] = "123456789";
    ft_bzero(buffer1, 0);
    if (memcmp(buffer1, "123456789", 10) != 0)
        print_table_row("Taille zéro", "[ÉCHOUÉ]");
    else
        print_table_row("Taille zéro", "[SUCCÈS]");

    // Cas 2 : Remplissage partiel
    char buffer2[10] = "abcdefghi";
    ft_bzero(buffer2, 5);
    int i = 0;
    int passed = 1;
    while (i < 5)
    {
        if (buffer2[i] != '\0')
        {
            passed = 0;
            break;
        }
        i++;
    }
    if (passed)
        print_table_row("Remplissage partiel", "[SUCCÈS]");
    else
        print_table_row("Remplissage partiel", "[ÉCHOUÉ]");

    // Cas 3 : Remplissage total
    char buffer3[10] = "abcdefgh";
    ft_bzero(buffer3, 10);
    i = 0;
    passed = 1;
    while (i < 10)
    {
        if (buffer3[i] != '\0')
        {
            passed = 0;
            break;
        }
        i++;
    }
    if (passed)
        print_table_row("Remplissage total", "[SUCCÈS]");
    else
        print_table_row("Remplissage total", "[ÉCHOUÉ]");

    print_table_footer();
}

int main()
{
    test_ft_bzero();
    return 0;
}

