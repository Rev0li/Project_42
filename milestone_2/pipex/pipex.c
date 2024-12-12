#include "pipex.h"

void    error_exit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv, char **envp)
{
    int     infile;
	int		outfile;
	//    int     pipe_fd[2];
	//    pid_t   pid1;
	//    pid_t   pid2;

	if (argc != 5)
		error_exit("Number of arg is incorrect");
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
        error_exit("Error when open infile");
    if (dup2(infile, STDIN_FILENO) == -1)
	{
        perror("Error redirection of stdin");
        close(infile);
        exit(EXIT_FAILURE);
    }
    close(infile);
/*
	char buffer[100];
	fgets(buffer, sizeof(buffer), stdin);
	printf("Contenu lu : %s\n", buffer); 
*/

	outfile = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (outfile == -1)
		error_exit("Error when open outfile");
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
        perror("Error redirection of stdout");
        close(outfile);
        exit(EXIT_FAILURE);
    }
    close(outfile);

		return (EXIT_SUCCESS);
}

