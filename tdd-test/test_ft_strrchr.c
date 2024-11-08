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

void test_ft_strrchr()
{
    print_table_header("Tests pour ft_strrchr");

    // Cas 1 : Recherche d'un caractère présent une seule fois
    char str1[] = "Hello, World!";
    char *result1 = ft_strrchr(str1, 'W');
    char *expected1 = strrchr(str1, 'W');
    if (result1 == expected1)
        print_table_row("Caractère présent une fois", "[SUCCÈS]");
    else
        print_table_row("Caractère présent une fois", "[ÉCHOUÉ]");

    // Cas 2 : Recherche d'un caractère présent plusieurs fois
    char str2[] = "banana";
    char *result2 = ft_strrchr(str2, 'a');
    char *expected2 = strrchr(str2, 'a');
    if (result2 == expected2)
        print_table_row("Caractère présent plusieurs fois", "[SUCCÈS]");
    else
        print_table_row("Caractère présent plusieurs fois", "[ÉCHOUÉ]");

    // Cas 3 : Recherche d'un caractère non présent
    char str3[] = "apple";
    char *result3 = ft_strrchr(str3, 'z');
    char *expected3 = strrchr(str3, 'z');
    if (result3 == expected3)
        print_table_row("Caractère non présent", "[SUCCÈS]");
    else
        print_table_row("Caractère non présent", "[ÉCHOUÉ]");

    // Cas 4 : Recherche du caractère nul '\0'
    char str4[] = "test";
    char *result4 = ft_strrchr(str4, '\0');
    char *expected4 = strrchr(str4, '\0');
    if (result4 == expected4)
        print_table_row("Recherche du caractère '\\0'", "[SUCCÈS]");
    else
        print_table_row("Recherche du caractère '\\0'", "[ÉCHOUÉ]");

    // Cas 5 : Chaîne vide
    char str5[] = "";
    char *result5 = ft_strrchr(str5, 'a');
    char *expected5 = strrchr(str5, 'a');
    if (result5 == expected5)
        print_table_row("Chaîne vide", "[SUCCÈS]");
    else
        print_table_row("Chaîne vide", "[ÉCHOUÉ]");

    print_table_footer();
}

int main()
{
    test_ft_strrchr();
    return 0;
}

