/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:21:41 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/03 10:55:49 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	//init last_node
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	// when str_buf don t finish and str_buf != '\n', continue
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		i++;
	// when str_buf != '\0'
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buf[k++] = last_node->str_buf[i]; // copy new str in buf
	buf[k] = '\0';
	clean_node->str_buf = buf; // copy buf in clear_node->str_buf
	clean_node->next = NULL;
	// Free all old list
	dealloc(list, clean_node, buf);
}

char	*get_line(t_list *list)
{
	char	*next_str;
	int		str_len;

	if (list == NULL)
		return (NULL);
	// Count chara to \n
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	// copi char by char to str
	copy_str(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	// init last_node
	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	// If list empty, create new node
	if (last_node == NULL)
		*list = new_node;
	else // else add new_node after last node
		last_node->next = new_node;
	// assigne buf in list buf
	new_node->str_buf = buf;
	// init next for other call
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	//when buf don't found \n continue
	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		// len of read
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		// add buf in new_node and prepare next call
		append(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	// Save entire line on chain list 
	create_list (&list, fd);
	if (list == NULL)
		return (NULL);
	// count and dup string to \n
	next_line = get_line (list);
	// save result after \n in new_list and delete and free old list
	polish_list(&list);
	return (next_line);
}
