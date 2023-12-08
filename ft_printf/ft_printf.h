/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:18:36 by ldaniel           #+#    #+#             */
/*   Updated: 2023/04/19 10:18:37 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned long long num, const char format);
int		ft_printpercent(void);
int		ft_ptr_len(unsigned long long num);
int		ft_num_len(unsigned int num);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
void	ft_putstr(char *str);
void	ft_put_ptr(unsigned long long num);
void	ft_put_hex(unsigned int num, const char format);

#endif
