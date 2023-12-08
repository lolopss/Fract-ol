/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:45:02 by ldaniel           #+#    #+#             */
/*   Updated: 2023/07/14 14:23:03 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_name(char **av)
{
	if (!ft_strcmp(av[1], "Mandelbrot")
		|| !ft_strcmp(av[1], "mandelbrot")
		|| !ft_strcmp(av[1], "Mandel") || !ft_strcmp(av[1], "mandel"))
		return (0);
	else if (!ft_strcmp(av[1], "Julia") || !ft_strcmp(av[1], "julia"))
		return (0);
	else if (!ft_strcmp(av[1], "Julia2")
		|| !ft_strcmp(av[1], "julia2"))
		return (0);
	else if (!ft_strcmp(av[1], "random")
		|| !ft_strcmp(av[1], "Random"))
		return (0);
	return (2);
}
