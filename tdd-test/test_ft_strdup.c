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

void test_ft_strdup()
{
    print_table_header("Tests pour ft_strdup");

    // Cas 1 : Chaîne non vide
    const char *str1 = "Hello World";
    char *dup1 = ft_strdup(str1);
    if (strcmp(dup1, str1) == 0)
        print_table_row("Dupliquer chaîne non vide", "[SUCCÈS]");
    else
        print_table_row("Dupliquer chaîne non vide", "[ÉCHOUÉ]");
    free(dup1);

    // Cas 2 : Chaîne vide
    const char *str2 = "";
    char *dup2 = ft_strdup(str2);
    if (strcmp(dup2, str2) == 0)
        print_table_row("Dupliquer chaîne vide", "[SUCCÈS]");
    else
        print_table_row("Dupliquer chaîne vide", "[ÉCHOUÉ]");
    free(dup2);

    print_table_footer();
}
int main()
{
    test_ft_strdup();
    return 0;
}

