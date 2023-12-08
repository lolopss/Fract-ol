/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:29:20 by ldaniel           #+#    #+#             */
/*   Updated: 2023/07/14 12:54:14 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_color(t_data *data, t_colors *c)
{
	if (data->usecolor2 == 1)
	{
		c->num_colors = 23;
		init_colors_bis(c);
	}
	else if (data->usecolor2 == 2)
	{
		c->num_colors = 23;
		init_colors_bis2(c);
	}
	else
	{
		c->num_colors = 23;
		init_colors(c);
	}
}

int	get_colors(t_data *data, int i)
{
	t_colors	c;

	if (i == data->max_iter)
		return (0x00);
	choose_color(data, &c);
	c.pos = (double)i / data->max_iter;
	c.color_index1 = c.pos * (c.num_colors - 1);
	c.color_index2 = c.color_index1 + 1;
	c.c1 = c.colors[c.color_index1];
	c.c2 = c.colors[c.color_index2];
	c.r = ((c.c2 >> 16) & 0xFF) * c.pos + ((c.c1 >> 16) & 0xFF) * (1 - c.pos);
	c.g = ((c.c2 >> 8) & 0xFF) * c.pos + ((c.c1 >> 8) & 0xFF) * (1 - c.pos);
	c.b = (c.c2 & 0xFF) * c.pos + (c.c1 & 0xFF) * (1 - c.pos);
	c.final_color = (c.r << 16) | (c.g << 8) | c.b;
	return (c.final_color);
}
