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

void test_ft_strncmp()
{
    print_table_header("Tests pour ft_strncmp");

    // Cas 1 : Chaînes identiques
    char str1[] = "Hello";
    char str2[] = "Hello";
    int result1 = ft_strncmp(str1, str2, 5);
    int expected1 = strncmp(str1, str2, 5);
    if (result1 == expected1)
        print_table_row("Chaînes identiques", "[SUCCÈS]");
    else
        print_table_row("Chaînes identiques", "[ÉCHOUÉ]");

    // Cas 2 : Chaînes différentes
    char str3[] = "Hello";
    char str4[] = "World";
    int result2 = ft_strncmp(str3, str4, 5);
    int expected2 = strncmp(str3, str4, 5);
    if (result2 == expected2)
        print_table_row("Chaînes différentes", "[SUCCÈS]");
    else
        print_table_row("Chaînes différentes", "[ÉCHOUÉ]");

    // Cas 3 : Comparaison partielle (n plus petit)
    char str5[] = "abcdef";
    char str6[] = "abcxyz";
    int result3 = ft_strncmp(str5, str6, 3);
    int expected3 = strncmp(str5, str6, 3);
    if (result3 == expected3)
        print_table_row("Comparaison partielle (n=3)", "[SUCCÈS]");
    else
        print_table_row("Comparaison partielle (n=3)", "[ÉCHOUÉ]");

    // Cas 4 : Chaîne vide
    char str7[] = "";
    char str8[] = "Non-vide";
    int result4 = ft_strncmp(str7, str8, 5);
    int expected4 = strncmp(str7, str8, 5);
    if (result4 == expected4)
        print_table_row("Comparaison avec une chaîne vide", "[SUCCÈS]");
    else
        print_table_row("Comparaison avec une chaîne vide", "[ÉCHOUÉ]");

    // Cas 5 : Comparaison de zéro caractère
    char str9[] = "Hello";
    char str10[] = "World";
    int result5 = ft_strncmp(str9, str10, 0);
    int expected5 = strncmp(str9, str10, 0);
    if (result5 == expected5)
        print_table_row("Comparaison avec n=0", "[SUCCÈS]");
    else
        print_table_row("Comparaison avec n=0", "[ÉCHOUÉ]");

    print_table_footer();
}

int main()
{
    test_ft_strncmp();
    return 0;
}

