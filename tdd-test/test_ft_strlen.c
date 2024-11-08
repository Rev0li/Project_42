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
    printf("| %-41.41s | %-16s |\n", test_case, result);
}

void print_table_footer()
{
    printf("+------------------------------------------+-----------------+\n");
}

void test_ft_strlen()
{
    print_table_header("Tests pour ft_strlen");

    // Cas 1 : Chaîne vide
    if (ft_strlen("") == 0)
        print_table_row("Cas chaîne vide", "[SUCCÈS]");
    else
        print_table_row("Cas chaîne vide", "[ÉCHOUÉ]");

    // Cas 2 : Chaîne d'un caractère
    if (ft_strlen("a") == 1)
        print_table_row("Cas 1 caractère", "[SUCCÈS]");
    else
        print_table_row("Cas 1 caractère", "[ÉCHOUÉ]");

    // Cas 3 : Chaîne de plusieurs caractères
    if (ft_strlen("Bonjour") == 7)
        print_table_row("Cas plusieurs caractères", "[SUCCÈS]");
    else
        print_table_row("Cas plusieurs caractères", "[ÉCHOUÉ]");

    print_table_footer();
}

int main()
{
    test_ft_strlen();
    return 0;
}

