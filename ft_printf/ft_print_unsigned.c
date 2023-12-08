/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:52:03 by ldaniel           #+#    #+#             */
/*   Updated: 2023/04/21 16:52:03 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int num)
{
	int	i;

	i = 0;
	while (num)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		i;

	i = ft_num_len(n);
	num = malloc(sizeof(char) * (i + 1));
	if (!num)
		return (NULL);
	num[i] = '\0';
	while (n)
	{
		num[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		print_length += ft_printstr(num);
		free(num);
	}
	return (print_length);
}
