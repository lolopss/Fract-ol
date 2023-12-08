/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:40:57 by ldaniel           #+#    #+#             */
/*   Updated: 2023/07/13 18:15:18 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data_julia(t_data *data)
{
	data->x1 = -1.7;
	data->x2 = 1.7;
	data->y1 = -1.7;
	data->y2 = 1.7;
	data->zoom = 50;
	data->max_iter = 2000;
}

void	julia_algo(t_data *data)
{
	data->c_r = 0.285;
	data->c_i = 0.01;
	data->z_r = (data->x / data->x_s) * (data->x2 - data->x1) + data->x1;
	data->z_i = (data->y / data->y_s) * (data->y2 - data->y1) + data->y1;
	data->i = 0;
	while (data->i < data->max_iter && data->z_r * data->z_r
		+ data->z_i * data->z_i < 4)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = 2 * data->z_i * data->tmp + data->c_i;
		data->i++;
	}
	data->color = get_colors(data, data->i);
	my_mlx_pixel_put(data, data->x, data->y, data->color);
	data->y++;
}

void	julia(t_data *data)
{
	data->img = mlx_new_image(data->mlx, data->x_s, data->y_s);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->x = 0;
	while (data->x < data->x_s)
	{
		data->y = 0;
		while (data->y < data->y_s)
		{
			julia_algo(data);
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	julia_algo2(t_data *data)
{
	data->c_r = -0.4;
	data->c_i = 0.6;
	data->z_r = (data->x / data->x_s) * (data->x2 - data->x1) + data->x1;
	data->z_i = (data->y / data->y_s) * (data->y2 - data->y1) + data->y1;
	data->i = 0;
	while (data->i < data->max_iter && data->z_r * data->z_r
		+ data->z_i * data->z_i < 4)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = 2 * data->z_i * data->tmp + data->c_i;
		data->i++;
	}
	data->color = get_colors(data, data->i);
	my_mlx_pixel_put(data, data->x, data->y, data->color);
	data->y++;
}

void	julia2(t_data *data)
{
	data->img = mlx_new_image(data->mlx, data->x_s, data->y_s);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->x = 0;
	while (data->x < data->x_s)
	{
		data->y = 0;
		while (data->y < data->y_s)
		{
			julia_algo2(data);
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
