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

void test_ft_strlcpy()
{
    print_table_header("Tests pour ft_strlcpy");

    // Cas 1 : Copie d'une chaîne simple
    char src[] = "Hello, World!";
    char dest[20] = {0};
    size_t len = ft_strlcpy(dest, src, sizeof(dest));
    if (strcmp(dest, src) == 0 && len == strlen(src))
        print_table_row("Copie d'une chaîne simple", "[SUCCÈS]");
    else
        print_table_row("Copie d'une chaîne simple", "[ÉCHOUÉ]");

    // Cas 2 : Taille de destination trop petite
    char dest_small[6] = {0};
    len = ft_strlcpy(dest_small, src, sizeof(dest_small));
    if (strcmp(dest_small, "Hello") == 0 && len == strlen(src))
        print_table_row("Destination trop petite", "[SUCCÈS]");
    else
        print_table_row("Destination trop petite", "[ÉCHOUÉ]");

    // Cas 3 : Taille de destination est 0
    char dest_zero[20] = "Initial";
    len = ft_strlcpy(dest_zero, src, 0);
    if (strcmp(dest_zero, "Initial") == 0 && len == strlen(src))
        print_table_row("Taille destination 0", "[SUCCÈS]");
    else
        print_table_row("Taille destination 0", "[ÉCHOUÉ]");

    // Cas 4 : Source vide
    char src_empty[] = "";
    char dest_empty[10] = {0};
    len = ft_strlcpy(dest_empty, src_empty, sizeof(dest_empty));
    if (strcmp(dest_empty, "") == 0 && len == 0)
        print_table_row("Source vide", "[SUCCÈS]");
    else
        print_table_row("Source vide", "[ÉCHOUÉ]");

    print_table_footer();
}

int main()
{
    test_ft_strlcpy();
    return 0;
}

