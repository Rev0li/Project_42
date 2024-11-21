/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:25:46 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/20 09:50:32 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
// Utils
int	ft_printf(const char *format, ...);
int	ft_strlen(const char *string);
int	ft_putnbr(int n, int written);
int	ft_putnbr_base(unsigned long int n, char *b, int l_b, int wt);
//Handle Base
int	handle_pointer(unsigned long int args, int written);
int	handle_decimal(int args, int written);
int	handle_unsigned(unsigned int args, int written);
int	handle_hexa_low(unsigned int args, int written);
int	handle_hexa_up(unsigned int args, int written);
//Handle Put
int	handle_character(char c);
int	handle_string(char *str, int written);
int	handle_percent(void);

#endif
