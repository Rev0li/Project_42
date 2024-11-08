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

void test_ft_memmove()
{
    print_table_header("Tests pour ft_memmove");

    // Cas 1 : Copie basique sans chevauchement
    char src[] = "Hello, World!";
    char dest[20] = {0};
    ft_memmove(dest, src, 13);
    if (strcmp(dest, src) == 0)
        print_table_row("Copie basique (sans chevauchement)", "[SUCCÈS]");
    else
        print_table_row("Copie basique (sans chevauchement)", "[ÉCHOUÉ]");

    // Cas 2 : Chevauchement avant (dest commence dans src)
    char buffer1[] = "12345";
    ft_memmove(buffer1 + 1, buffer1, 4); // Move "1234" to start at buffer1[1]
    if (strcmp(buffer1, "11234") == 0)
        print_table_row("Chevauchement avant", "[SUCCÈS]");
    else
        print_table_row("Chevauchement avant", "[ÉCHOUÉ]");

    // Cas 3 : Chevauchement arrière (src commence dans dest)
    char buffer2[] = "12345";
    ft_memmove(buffer2, buffer2 + 1, 4); // Move "2345" to start at buffer2[0]
    if (strcmp(buffer2, "23455") == 0)
        print_table_row("Chevauchement arrière", "[SUCCÈS]");
    else
        print_table_row("Chevauchement arrière", "[ÉCHOUÉ]");

    // Cas 4 : Copie de 0 octets
    char buffer3[] = "Test";
    ft_memmove(buffer3, buffer3, 0);
    if (strcmp(buffer3, "Test") == 0)
        print_table_row("Copie de 0 octets", "[SUCCÈS]");
    else
        print_table_row("Copie de 0 octets", "[ÉCHOUÉ]");

    print_table_footer();
}

int main()
{
    test_ft_memmove();
    return 0;
}

