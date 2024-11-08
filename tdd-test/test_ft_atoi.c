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

void test_ft_atoi()
{
    print_table_header("Tests pour ft_atoi");

    // Cas 1 : Nombre positif
    const char *str1 = "12345";
    if (ft_atoi(str1) == atoi(str1))
        print_table_row("Nombre positif", "[SUCCÈS]");
    else
        print_table_row("Nombre positif", "[ÉCHOUÉ]");

    // Cas 2 : Nombre négatif
    const char *str2 = "-12345";
    if (ft_atoi(str2) == atoi(str2))
        print_table_row("Nombre négatif", "[SUCCÈS]");
    else
        print_table_row("Nombre négatif", "[ÉCHOUÉ]");

    // Cas 3 : Nombre avec espaces initiaux
    const char *str3 = "   456";
    if (ft_atoi(str3) == atoi(str3))
        print_table_row("Nombre avec espaces initiaux", "[SUCCÈS]");
    else
        print_table_row("Nombre avec espaces initiaux", "[ÉCHOUÉ]");

    // Cas 4 : Nombre avec signe +
    const char *str4 = "+789";
    if (ft_atoi(str4) == atoi(str4))
        print_table_row("Nombre avec signe +", "[SUCCÈS]");
    else
        print_table_row("Nombre avec signe +", "[ÉCHOUÉ]");

    // Cas 5 : Chaîne vide
    const char *str5 = "";
    if (ft_atoi(str5) == atoi(str5))
        print_table_row("Chaîne vide", "[SUCCÈS]");
    else
        print_table_row("Chaîne vide", "[ÉCHOUÉ]");

    // Cas 6 : Chaîne avec des caractères non numériques
    const char *str6 = "123abc";
    if (ft_atoi(str6) == atoi(str6))
        print_table_row("Chaîne avec caractères non numériques", "[SUCCÈS]");
    else
        print_table_row("Chaîne avec caractères non numériques", "[ÉCHOUÉ]");

    print_table_footer();
}

int main()
{
    test_ft_atoi();
    return 0;
}

