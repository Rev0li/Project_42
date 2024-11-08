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


void test_ft_strlcat()
{
    // Cas de test pour comparer ft_strlcat et strlcat
    char src[] = " World!";
    
    // Cas 1 : Concaténation simple
    char dest1[20] = "Hello";
    char dest2[20] = "Hello";
    size_t result1 = ft_strlcat(dest1, src, sizeof(dest1));
    size_t result2 = strlcat(dest2, src, sizeof(dest2));
    if (strcmp(dest1, dest2) == 0 && result1 == result2)
        print_table_row("Concaténation simple", "[SUCCÈS]");
    else
        print_table_row("Concaténation simple", "[ÉCHOUÉ]");

    // Cas 2 : Destination trop petite
    char dest_small1[10] = "Hello";
    char dest_small2[10] = "Hello";
    result1 = ft_strlcat(dest_small1, src, sizeof(dest_small1));
    result2 = strlcat(dest_small2, src, sizeof(dest_small2));
    if (strcmp(dest_small1, dest_small2) == 0 && result1 == result2)
        print_table_row("Destination trop petite", "[SUCCÈS]");
    else
        print_table_row("Destination trop petite", "[ÉCHOUÉ]");

    // Cas 3 : Taille 0
    char dest_zero1[20] = "Initial";
    char dest_zero2[20] = "Initial";
    result1 = ft_strlcat(dest_zero1, src, 0);
    result2 = strlcat(dest_zero2, src, 0);
    if (strcmp(dest_zero1, dest_zero2) == 0 && result1 == result2)
        print_table_row("Taille destination 0", "[SUCCÈS]");
    else
        print_table_row("Taille destination 0", "[ÉCHOUÉ]");

    // Cas 4 : Source vide
    char dest_empty1[20] = "Hello";
    char dest_empty2[20] = "Hello";
    char src_empty[] = "";
    result1 = ft_strlcat(dest_empty1, src_empty, sizeof(dest_empty1));
    result2 = strlcat(dest_empty2, src_empty, sizeof(dest_empty2));
    if (strcmp(dest_empty1, dest_empty2) == 0 && result1 == result2)
        print_table_row("Source vide", "[SUCCÈS]");
    else
        print_table_row("Source vide", "[ÉCHOUÉ]");
}
int main()
{
    print_table_header("Tests pour ft_strlcat");
    test_ft_strlcat();
    print_table_footer();
    return 0;
}

