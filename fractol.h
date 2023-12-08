/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:09:20 by ldaniel           #+#    #+#             */
/*   Updated: 2023/07/14 16:16:52 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx-linux/mlx.h"
# include <stdlib.h> 
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <time.h>
# include <math.h>

typedef struct s_coord {
	int		x;
	int		y;
	int		i;
	double	x2;
	double	x1;
	double	y1;
	double	y2;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	void	*mlx;
	void	*win;
	double	x_s;
	double	y_s;
	double	zoom;
	int		max_iter;
	double	image_x;
	double	image_y;
	double	zoom_x;
	double	zoom_y;
	double	tmp;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	int		usecolor2;
	char	*name;
}				t_data;

typedef struct s_colors {
	int		r;
	int		g;
	int		b;
	double	pos;
	int		num_colors;
	int		colors[40];
	int		c1;
	int		c2;
	int		final_color;
	int		color_index1;
	int		color_index2;
}				t_colors;

void	init_data_random(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_colors(t_data *data, int i);
void	init_data_mandel(t_data *data);
void	mandelbrot(t_data *data);
void	init_data_julia(t_data *data);
void	julia_algo(t_data *data);
void	julia(t_data *data);
void	julia2(t_data *data);
void	mandelbrot(t_data *data);
int		key_hook(int keycode, t_data *data);
int		ft_close(t_data *data);
void	run_name(t_data *data);
void	run_name2(t_data *data);
int		put_color_1(t_data *data, int i);
void	init_colors(t_colors *color);
void	init_colors_bis(t_colors *color);
void	init_colors_bis2(t_colors *color);
void	random_fract(t_data *data);
int		check_name(char **av);
int		ft_printf(const char *str, ...);
int		ft_strcmp(char *s1, char *s2);

#endif
