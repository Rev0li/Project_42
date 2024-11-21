int	main ()
{
	int fd;

    fd = open("monfichier.txt", O_RDONLY);
    if (fd == -1)
	{
        perror("Erreur lors de l'ouverture");
        return 1;
    }

    printf("Fichier ouvert avec succès, descripteur : %d\n", fd);
	get_next_line(fd);
    close(fd);
    return 0;

}
