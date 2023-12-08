/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:25:12 by ldaniel           #+#    #+#             */
/*   Updated: 2023/07/15 11:25:37 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	run_name(t_data *data)
{
	if (!ft_strcmp(data->name, "Mandelbrot")
		|| !ft_strcmp(data->name, "mandelbrot")
		|| !ft_strcmp(data->name, "Mandel")
		|| !ft_strcmp(data->name, "mandel"))
	{
		mlx_destroy_image(data->mlx, data->img);
		mandelbrot(data);
	}
	else if (!ft_strcmp(data->name, "Julia")
		|| !ft_strcmp(data->name, "julia"))
	{
		mlx_destroy_image(data->mlx, data->img);
		julia(data);
	}
	else if (!ft_strcmp(data->name, "Julia2")
		|| !ft_strcmp(data->name, "julia2"))
	{
		mlx_destroy_image(data->mlx, data->img);
		julia2(data);
	}
	else if (!ft_strcmp(data->name, "random"))
	{
		mlx_destroy_image(data->mlx, data->img);
		random_fract(data);
	}
}

int	zoom_in(int button, int x, int y, t_data *data)
{
	double	ratio_x;
	double	ratio_y;
	double	ratio;
	double	range_r;
	double	range_i;

	range_r = data->x2 - data->x1;
	range_i = data->y2 - data->y1;
	ratio_x = (double)x / data->x_s;
	ratio_y = (double)y / data->y_s;
	ratio = 0;
	if (button == 4)
		ratio = 0.5;
	else if (button == 5)
		ratio = 1.5;
	else if (button == 1 || button == 3 || button == 2)
		ratio = 1;
	data->x1 += ratio_x * range_r * (1 - ratio);
	data->y1 += ratio_y * range_i * (1 - ratio);
	data->x2 = data->x1 + range_r * ratio;
	data->y2 = data->y1 + range_i * ratio;
	run_name(data);
	return (0);
}

int	run(t_data *data, char **av)
{
	if (!ft_strcmp(av[1], "Mandelbrot")
		|| !ft_strcmp(av[1], "mandelbrot")
		|| !ft_strcmp(av[1], "Mandel") || !ft_strcmp(av[1], "mandel"))
	{
		init_data_mandel(data);
		mandelbrot(data);
	}
	else if (!ft_strcmp(av[1], "Julia2")
		|| !ft_strcmp(av[1], "julia2"))
	{
		init_data_julia(data);
		julia2(data);
	}
	else if (!ft_strcmp(av[1], "Julia") || !ft_strcmp(av[1], "julia"))
	{
		init_data_julia(data);
		julia(data);
	}
	else if (!ft_strcmp(av[1], "random")
		|| !ft_strcmp(av[1], "Random"))
	{
		init_data_random(data);
		random_fract(data);
	}
	return (1);
}

void	init_data(t_data *data, char **av)
{
	data->x_s = 900;
	data->y_s = 900;
	data->usecolor2 = 0;
	data->name = av[1];
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	data->win = mlx_new_window(data->mlx, data->x_s, data->y_s, "fractol");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_printf("Error\n");
		exit(-1);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2 && check_name(av) == 0)
	{
		init_data(&data, av);
		run(&data, av);
		mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
		mlx_mouse_hook(data.win, zoom_in, &data);
		mlx_loop(data.mlx);
		mlx_destroy_image(data.mlx, data.img);
		mlx_destroy_window(data.mlx, data.win);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (0);
	}
	ft_printf("You need to put in 2nd argument :\nMandelbrot\nJulia\nJulia2\n");
	return (-1);
}
