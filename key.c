/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:55:52 by ldaniel           #+#    #+#             */
/*   Updated: 2023/07/14 16:18:28 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	x_arrow(t_data *data, int keycode)
{
	double	move_factor;

	move_factor = 0.1 / (data->x2 - data->x1);
	if (keycode == 65361)
	{
		data->x1 += move_factor * 1;
		data->x2 += move_factor * 1;
	}
	if (keycode == 65363)
	{
		data->x1 -= move_factor * 1;
		data->x2 -= move_factor * 1;
	}
	run_name(data);
}

void	y_arrow(t_data *data, int keycode)
{
	double	move_factor;

	move_factor = 0.1 / (data->y2 - data->y1);
	if (keycode == 65362)
	{
		data->y1 += move_factor * 1;
		data->y2 += move_factor * 1;
	}
	if (keycode == 65364)
	{
		data->y1 -= move_factor * 1;
		data->y2 -= move_factor * 1;
	}
	run_name(data);
}

void	change_color(t_data *data, int keycode)
{
	if (keycode == 49)
	{
		data->usecolor2 = 0;
		run_name(data);
	}
	else if (keycode == 50)
	{
		data->usecolor2 = 1;
		run_name(data);
	}
	else if (keycode == 51)
	{
		data->usecolor2 = 2;
		run_name(data);
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(-1);
	}
	else if (keycode == 65362 || keycode == 65364)
		y_arrow(data, keycode);
	else if (keycode == 65361 || keycode == 65363)
		x_arrow(data, keycode);
	change_color(data, keycode);
	if (keycode == 65451)
		data->max_iter += 25;
	if (keycode == 65453)
		data->max_iter -= 25;
	run_name(data);
	return (-1);
}
