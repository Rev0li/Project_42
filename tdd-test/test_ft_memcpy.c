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

void test_ft_memcpy()
{
    print_table_header("Tests pour ft_memcpy");

    // Cas 1 : Test basique
    char src[] = "Hello, World!";
    char dest[20] = {0};
    ft_memcpy(dest, src, 13);
    if (strcmp(dest, src) == 0)
        print_table_row("Test basique (chaine)", "[SUCCÈS]");
    else
        print_table_row("Test basique (chaine)", "[ÉCHOUÉ]");

    // Cas 2 : Copie de 0 octets
    char dest_zero[20] = {0};
    ft_memcpy(dest_zero, src, 0); // Should perform no copying
    if (dest_zero[0] == '\0')
        print_table_row("Test 0 octets", "[SUCCÈS]");
    else
        print_table_row("Test 0 octets", "[ÉCHOUÉ]");

    // Cas 3 : Tableau d'entiers
    int src_int[] = {1, 2, 3, 4, 5};
    int dest_int[5] = {0};
    ft_memcpy(dest_int, src_int, 5 * sizeof(int));
    int i = 0;
    int success = 1;
    while (i < 5)
    {
        if (dest_int[i] != src_int[i])
        {
            success = 0;
            break;
        }
        i++;
    }
    if (success)
        print_table_row("Tableau d'int", "[SUCCÈS]");
    else
        print_table_row("Tableau d'int", "[ÉCHOUÉ]");

    print_table_footer();
}

int main()
{
    test_ft_memcpy();
    return 0;
}

