#include "libft.h"
#include <fcntl.h> // Pour ouvrir et créer des fichiers
#include <unistd.h>
#include <stdio.h>
#include <string.h>

// Fonction utilitaire pour lire le contenu d'un fichier
void read_and_print_file(const char *filename)
{
    int fd;
    char buffer[1024];
    ssize_t bytes_read;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0)
    {
        buffer[bytes_read] = '\0'; // Ajouter le caractère nul pour terminer la chaîne
        printf("| Contenu fichier: \"%s\"\n", buffer);
    }
    close(fd);
}

void test_ft_putnbr_fd()
{
    printf("\n+------------------------------------------------+\n");
    printf("| Tests pour ft_putnbr_fd                        |\n");
    printf("+----------------------+-------------------------+\n");

    // Cas 1 : Écriture d'un nombre positif sur la sortie standard (stdout)
    printf("| Cas stdout (42)     | ");
    fflush(stdout); // Vide le tampon pour afficher immédiatement le texte
    ft_putnbr_fd(42, 1);
    printf(" <- vérifiez la sortie\n");

    // Cas 2 : Écriture de zéro
    printf("| Cas stdout (0)      | ");
    fflush(stdout);
    ft_putnbr_fd(0, 1);
    printf(" <- vérifiez la sortie\n");

    // Cas 3 : Écriture d'un nombre négatif
    printf("| Cas stdout (-1234)  | ");
    fflush(stdout);
    ft_putnbr_fd(-1234, 1);
    printf(" <- vérifiez la sortie\n");

    // Cas 4 : Écriture de INT_MIN
    printf("| Cas stdout (INT_MIN)| ");
    fflush(stdout);
    ft_putnbr_fd(-2147483648, 1);
    printf(" <- vérifiez la sortie\n");

    // Cas 5 : Écriture de INT_MAX
    printf("| Cas stdout (INT_MAX)| ");
    fflush(stdout);
    ft_putnbr_fd(2147483647, 1);
    printf(" <- vérifiez la sortie\n");

    // Cas 6 : Écriture dans un fichier
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Erreur d'ouverture du fichier");
        printf("| Écriture fichier    | [ÉCHOUÉ] Erreur d'ouverture |\n");
    }
    else
    {
        ft_putnbr_fd(123456789, fd);
        close(fd);
        printf("| Écriture fichier    | [SUCCÈS] -> Contenu vérifié |\n");
        read_and_print_file("test_output.txt"); // Lire et afficher le contenu du fichier
    }

    printf("+----------------------+-------------------------+\n");
}

int main()
{
    test_ft_putnbr_fd();
    return 0;
}

