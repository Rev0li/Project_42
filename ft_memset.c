#include "libft.h"

void *ft_memset(void *startAddr, int copie, size_t n)
{
    size_t i; // Utilisation de size_t pour correspondre au type de n
    unsigned char *s = startAddr;

    i = 0;
    while (i < n)
    {
        s[i] = (unsigned char)copie; // Remplit chaque octet avec la valeur de copie
        i++;
    }
    return startAddr;
}

