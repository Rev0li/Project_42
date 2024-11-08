#ifndef LIBFT_H
# define LIBFT_H

#include <stddef.h>
// Prototypes des fonctions
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_strlen(char *string);
void *ft_memset(void *startAddr, int copie, size_t n);
#endif

