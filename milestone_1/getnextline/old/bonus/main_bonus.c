#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2, fd3;
    char *line;

    // Ouvrir plusieurs fichiers pour les tests
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    fd3 = open("file3.txt", O_RDONLY);

    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
    {
        perror("Error opening file");
        return 1;
    }

    printf("===== Reading from file1.txt =====\n");
    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd1);

    printf("\n===== Reading from file2.txt =====\n");
    while ((line = get_next_line(fd2)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd2);

    printf("\n===== Reading from file3.txt =====\n");
    while ((line = get_next_line(fd3)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd3);

    // Test d'un descripteur invalide
    printf("\n===== Testing invalid file descriptor =====\n");
    line = get_next_line(-1);
    if (line == NULL)
        printf("Returned NULL as expected for invalid FD\n");

    return 0;
}

