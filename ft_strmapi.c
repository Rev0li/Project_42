#include "libft.h"
#include <stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *result;
    unsigned int i;

    if (!s || !f)
        return (NULL);

    result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!result)
        return (NULL);

    i = 0;
    while (s[i])
    {
        result[i] = f(i, s[i]); // Application de la fonction f
        i++;
    }
    result[i] = '\0';
    return (result);
}
