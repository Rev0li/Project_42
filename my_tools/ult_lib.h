/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ult_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:03:47 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/10 20:55:11 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ULT_LIB_H
# define ULT_LIB_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100 
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

/***** char_utils.c *****/
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
/***** conversion_utils.c *****/
char		*ft_itoa(int n);
int			ft_tolower(int c);
int			ft_toupper(int c);
/***** conversion_utils_2.c *****/
int			ft_atoi(const char *str);
/***** list_utils.c *****/
t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
/***** list_utils_2.c *****/
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_lstsize(t_list *lst);
/***** memory_utils.c *****/
void		*ft_memset(void *startAddr, int copie, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
/***** memory_utils_2.c *****/
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
/***** output_utils.c *****/
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
/***** string_utils_1.c *****/
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
/***** string_utils_2.c *****/
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strjoin(char const *s1, char const *s2);
/***** string_utils_3.c *****/
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strtrim(char const *s1, char const *set);
/***** string_utils_4.c *****/
char		**ft_split(char const *s, char c);
/***** printf_and_utils *****/
int			ft_printf(const char *s, ...);
int			ft_hexa(unsigned int n, const char *s);
int			ft_pointer(uintptr_t ptr);
int			ft_putunbr(unsigned int n);
int			printf_putchar(char c);
int			printf_putnbr(int n);
int			printf_putstr(char *s);
/***** get_next_line *****/
char		*get_next_line(int fd);
#endif
