#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	count = 0;
	int	in_word = 0;

	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*malloc_word(char const *s, char c)
{
	int		len = 0;
	char	*word;

	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (len--)
		word[len] = s[len];
	return (word);
}

static char	**free_all(char **result, int i)
{
    while (i > 0)
    {
        i--;
        free(result[i]);
    }
    free(result);
    return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			result[i] = malloc_word(s, c);
			if (!result[i++])
				return (free_all(result, i - 1));
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	result[i] = '\0';
	return (result);
}
