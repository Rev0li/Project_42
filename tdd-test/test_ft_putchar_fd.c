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

void test_ft_putchar_fd()
{
    printf("\n+------------------------------------------------+\n");
    printf("| Tests pour ft_putchar_fd                       |\n");
    printf("+----------------------+-------------------------+\n");

    // Cas 1 : Écriture sur la sortie standard (stdout)
    printf("| Cas stdout          | ");
	fflush(stdout);
    ft_putchar_fd('A', 1); // Cela doit afficher 'A' sur la console
    printf(" <- vérifiez la sortie | [SUCCÈS] ou [ÉCHOUÉ]\n");

    // Cas 2 : Écriture sur la sortie d'erreur standard (stderr)
    fprintf(stderr, "| Cas stderr          | ");
    ft_putchar_fd('B', 2); // Cela doit afficher 'B' sur la sortie d'erreur
    fprintf(stderr, " <- vérifiez la sortie | [SUCCÈS] ou [ÉCHOUÉ]\n");

    // Cas 3 : Écriture dans un fichier
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Erreur d'ouverture du fichier");
        printf("| Écriture fichier    | [ÉCHOUÉ] Erreur d'ouverture |\n");
    }
    else
    {
        ft_putchar_fd('C', fd);
        close(fd);
        printf("| Écriture fichier    | [SUCCÈS] -> Contenu vérifié |\n");
        read_and_print_file("test_output.txt"); // Lire et afficher le contenu du fichier
    }

    printf("+----------------------+-------------------------+\n");
}

int main()
{
    test_ft_putchar_fd();
    return 0;
}

