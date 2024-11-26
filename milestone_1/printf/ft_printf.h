/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:35:06 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/21 14:03:41 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(const char c);
int		convert(const char *s, va_list args, int len);
int		ft_putstr(char const *s);
int		ft_strlen(const char *s);
int		ft_pointer(uintptr_t ptr);
int		ft_hexa(unsigned int n, const char *s);
int		ft_putunbr(unsigned int n);
int		ft_putnbr(int n);

#endif
