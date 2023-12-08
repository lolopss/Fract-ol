/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:56:01 by ldaniel           #+#    #+#             */
/*   Updated: 2023/07/14 12:35:13 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data_mandel(t_data *data)
{
	data->x1 = -2.1;
	data->x2 = 0.6;
	data->y1 = -1.2;
	data->y2 = 1.2;
	data->zoom = 100;
	data->max_iter = 100;
}

void	mandelbrot_algo(t_data *d)
{
	d->y = 0;
	while (d->y < d->y_s)
	{
		d->c_r = d->x / d->zoom_x + d->x1;
		d->c_i = d->y / d->zoom_y + d->y1;
		d->z_r = 0;
		d->z_i = 0;
		d->i = 0;
		while (d->i < d->max_iter && d->z_r
			* d->z_r + d->z_i * d->z_i < 4)
		{
			d->tmp = d->z_r;
			d->z_r = d->z_r * d->z_r - d->z_i * d->z_i + d->c_r;
			d->z_i = 2 * d->z_i * d->tmp + d->c_i;
			d->i++;
		}
		d->color = get_colors(d, d->i);
		my_mlx_pixel_put(d, d->x, d->y, d->color);
		d->y++;
	}
	d->x++;
}

void	mandelbrot(t_data *data)
{
	data->zoom_x = data->x_s / (data->x2 - data->x1);
	data->zoom_y = data->y_s / (data->y2 - data->y1);
	data->img = mlx_new_image(data->mlx, data->x_s, data->y_s);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	data->x = 0;
	while (data->x < data->x_s)
		mandelbrot_algo(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
