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

void test_ft_calloc()
{
    print_table_header("Tests pour ft_calloc");

    // Cas 1 : Allouer mémoire pour 5 entiers
    int *arr = (int *)ft_calloc(5, sizeof(int));
    int success = 1;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] != 0)
        {
            success = 0;
            break;
        }
    }
    if (success)
        print_table_row("Allouer mémoire pour 5 entiers (zéro)", "[SUCCÈS]");
    else
        print_table_row("Allouer mémoire pour 5 entiers (zéro)", "[ÉCHOUÉ]");
    free(arr);

    // Cas 2 : Allouer mémoire pour 0 éléments
    char *empty_alloc = (char *)ft_calloc(0, sizeof(char));
    if (empty_alloc != NULL)
        print_table_row("Allouer mémoire pour 0 éléments", "[SUCCÈS]");
    else
        print_table_row("Allouer mémoire pour 0 éléments", "[ÉCHOUÉ]");
    free(empty_alloc);

    print_table_footer();
}
int main()
{
    test_ft_calloc();
    return 0;
}

