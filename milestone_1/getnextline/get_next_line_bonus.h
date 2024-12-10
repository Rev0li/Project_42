/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:06:20 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/05 07:39:45 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_free(char **str);
char	*polish(char *storage);
char	*get_current_line(char *storage);
char	*create_buf(char *storage, int fd);
char	*get_next_line(int fd);

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
#endif
