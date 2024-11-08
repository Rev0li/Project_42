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

void test_ft_memcmp()
{
    // Cas 1 : Deux chaînes identiques
    char s1[] = "Hello";
    char s2[] = "Hello";
    if (ft_memcmp(s1, s2, 5) == 0)
        print_table_row("Deux chaînes identiques", "[SUCCÈS]");
    else
        print_table_row("Deux chaînes identiques", "[ÉCHOUÉ]");

    // Cas 2 : Deux chaînes différentes (premier caractère différent)
    char s3[] = "Hello";
    char s4[] = "Jello";
    if (ft_memcmp(s3, s4, 5) < 0)
        print_table_row("Chaînes différentes (premier caractère)", "[SUCCÈS]");
    else
        print_table_row("Chaînes différentes (premier caractère)", "[ÉCHOUÉ]");

    // Cas 3 : Comparaison partielle (seulement les premiers caractères)
    if (ft_memcmp(s1, s3, 1) == 0)
        print_table_row("Comparaison partielle", "[SUCCÈS]");
    else
        print_table_row("Comparaison partielle", "[ÉCHOUÉ]");

    // Cas 4 : Deux chaînes avec des longueurs différentes mais le même préfixe
    char s5[] = "HelloWorld";
    char s6[] = "Hello";
    if (ft_memcmp(s5, s6, 5) == 0)
        print_table_row("Même préfixe, longueurs différentes", "[SUCCÈS]");
    else
        print_table_row("Même préfixe, longueurs différentes", "[ÉCHOUÉ]");

    // Cas 5 : Comparaison de chaînes vides
    char s7[] = "";
    char s8[] = "";
    if (ft_memcmp(s7, s8, 0) == 0)
        print_table_row("Comparaison de chaînes vides", "[SUCCÈS]");
    else
        print_table_row("Comparaison de chaînes vides", "[ÉCHOUÉ]");
}

int main()
{
    print_table_header("Tests pour ft_memcmp");
    test_ft_memcmp();
    print_table_footer();
    return 0;
}

