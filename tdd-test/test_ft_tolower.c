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

void test_ft_tolower()
{
    print_table_header("Tests pour ft_tolower");

    // Cas 1 : Lettre majuscule (A-Z)
    int success = 1;
    int c = 'A';
    while (c <= 'Z')
    {
        if (ft_tolower(c) != c + ('a' - 'A'))
        {
            print_table_row("Majuscule A-Z", "[ÉCHOUÉ]");
            success = 0;
            break;
        }
        c++;
    }
    if (success)
        print_table_row("Majuscule A-Z", "[SUCCÈS]");

    // Cas 2 : Lettre minuscule (a-z)
    success = 1;
    c = 'a';
    while (c <= 'z')
    {
        if (ft_tolower(c) != c)
        {
            print_table_row("Minuscule a-z", "[ÉCHOUÉ]");
            success = 0;
            break;
        }
        c++;
    }
    if (success)
        print_table_row("Minuscule a-z", "[SUCCÈS]");

    // Cas 3 : Chiffres (0-9)
    success = 1;
    c = '0';
    while (c <= '9')
    {
        if (ft_tolower(c) != c)
        {
            print_table_row("Chiffres 0-9", "[ÉCHOUÉ]");
            success = 0;
            break;
        }
        c++;
    }
    if (success)
        print_table_row("Chiffres 0-9", "[SUCCÈS]");

    // Cas 4 : Caractères spéciaux
    char specials[] = "!@#$%^&*()_+-=[]{}|;:'\",.<>?/\\`~";
    int i = 0;
    success = 1;
    while (specials[i] != '\0')
    {
        if (ft_tolower(specials[i]) != specials[i])
        {
            print_table_row("Caractères spéciaux", "[ÉCHOUÉ]");
            success = 0;
            break;
        }
        i++;
    }
    if (success)
        print_table_row("Caractères spéciaux", "[SUCCÈS]");

    // Cas 5 : Valeurs non-ASCII
    success = 1;
    for (c = 128; c <= 255; c++)
    {
        if (ft_tolower(c) != c)
        {
            print_table_row("Valeurs non-ASCII", "[ÉCHOUÉ]");
            success = 0;
            break;
        }
    }
    if (success)
        print_table_row("Valeurs non-ASCII", "[SUCCÈS]");

    print_table_footer();
}

int main()
{
    test_ft_tolower();
    return 0;
}

