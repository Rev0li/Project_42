/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:01:10 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/05 07:39:53 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*polish(char *storage)
{
	char	*clean_buf;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	if (!ptr)
	{
		clean_buf = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	clean_buf = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_free(&storage);
	if (!clean_buf)
		return (NULL);
	return (clean_buf);
}

char	*get_current_line(char *storage)
{
	char	*next_str;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	len = (ptr - storage) + 1;
	next_str = ft_substr(storage, 0, len);
	if (!next_str)
		return (NULL);
	return (next_str);
}

char	*create_buf(char *storage, int fd)
{
	int		return_read;
	char	*tmp;

	return_read = 1;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (ft_free(&storage));
	tmp[0] = '\0';
	while (return_read > 0 && !ft_strchr(tmp, '\n'))
	{
		return_read = read(fd, tmp, BUFFER_SIZE);
		if (return_read > 0)
		{
			tmp[return_read] = '\0';
			storage = ft_strjoin(storage, tmp);
		}
	}
	free(tmp);
	if (return_read == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char		*storage[1024];
	char			*line;

	if (fd < 0)
		return (NULL);
	if ((storage[fd] && !ft_strchr(storage[fd], '\n')) || !storage[fd])
		storage[fd] = create_buf(storage[fd], fd);
	if (!storage[fd])
		return (NULL);
	line = get_current_line(storage[fd]);
	if (!line)
		return (ft_free(&storage[fd]));
	storage[fd] = polish(storage[fd]);
	return (line);
}
