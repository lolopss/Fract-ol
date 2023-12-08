/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:52:46 by ldaniel           #+#    #+#             */
/*   Updated: 2023/07/14 13:50:26 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	init_colors2(t_colors *color)
{
	color->colors[18] = 0x40916C;
	color->colors[19] = 0x52B788;
	color->colors[20] = 0x74C69D;
	color->colors[21] = 0x95D5B2;
	color->colors[22] = 0xB7E4C7;
	color->colors[23] = 0xFF8C00;
	color->colors[24] = 0xFFC300;
	color->colors[25] = 0xFFDC60;
	color->colors[26] = 0xFFE888;
	color->colors[27] = 0xFFF1AA;
	color->colors[28] = 0xFFF8CC;
	color->colors[29] = 0xD8F3DC;
	color->colors[30] = 0xE2F5E4;
	color->colors[31] = 0x99E1D9;
	color->colors[32] = 0x3C9E81;
	color->colors[33] = 0x03312E;
	color->colors[34] = 0x5E96AE;
	color->colors[35] = 0x1C2541;
	color->colors[36] = 0x3A506B;
	color->colors[37] = 0x5BC0BE;
	color->colors[38] = 0x6FFFE9;
	color->colors[39] = 0xFFFFFF;
}

void	init_colors(t_colors *color)
{
	color->colors[0] = 0x000000;
	color->colors[1] = 0x03045E;
	color->colors[2] = 0x0077B6;
	color->colors[3] = 0x00B4D8;
	color->colors[4] = 0x90E0EF;
	color->colors[5] = 0xC7EAE4;
	color->colors[6] = 0xFFEDA0;
	color->colors[7] = 0xFFD700;
	color->colors[8] = 0xFF9F1C;
	color->colors[9] = 0xFF5400;
	color->colors[10] = 0xFF0062;
	color->colors[11] = 0xFF2B70;
	color->colors[12] = 0xFF598F;
	color->colors[13] = 0xFF7FAC;
	color->colors[14] = 0xFFA3C4;
	color->colors[15] = 0xFFC8DC;
	color->colors[16] = 0x1B4332;
	color->colors[17] = 0x2D6A4F;
	init_colors2(color);
}

void	init_colors_bis(t_colors *color)
{
	color->colors[0] = 0x020000;
	color->colors[1] = 0xFF00FF;
	color->colors[2] = 0x0000FF;
	color->colors[3] = 0x00FFFF;
	color->colors[4] = 0x00FF00;
	color->colors[5] = 0xFFFF00;
	color->colors[6] = 0xFF7F00;
	color->colors[7] = 0xFF007F;
	color->colors[8] = 0x7F00FF;
	color->colors[9] = 0x007FFF;
	color->colors[10] = 0x7FFF00;
	color->colors[11] = 0x008080;
	color->colors[12] = 0x808000;
	color->colors[13] = 0xFFC0CB;
	color->colors[14] = 0x800080;
	color->colors[15] = 0x808080;
	color->colors[16] = 0x800000;
	color->colors[17] = 0x008000;
	color->colors[18] = 0xC0C0C0;
	color->colors[19] = 0x008080;
	color->colors[20] = 0x808000;
	color->colors[21] = 0xFFC0CB;
	color->colors[22] = 0x800080;
}

void	init_colors_bis2(t_colors *color)
{
	color->colors[0] = 0x000000;
	color->colors[1] = 0x33FF66;
	color->colors[2] = 0x6600CC;
	color->colors[3] = 0xFF00FF;
	color->colors[4] = 0xCC00CC;
	color->colors[5] = 0xFF0099;
	color->colors[6] = 0xFF20066;
	color->colors[7] = 0xFF00303;
	color->colors[8] = 0xFF00F00;
	color->colors[9] = 0xFF330F0;
	color->colors[10] = 0xFF66F00;
	color->colors[11] = 0xFF9900;
	color->colors[12] = 0xFFCCF00;
	color->colors[13] = 0xFFFF00;
	color->colors[14] = 0xCCFF00;
	color->colors[15] = 0x99FFF00;
	color->colors[16] = 0x66FF00;
	color->colors[17] = 0x33FF0F0;
	color->colors[18] = 0x00FF00;
	color->colors[19] = 0x00FFF33;
	color->colors[20] = 0x00FF66;
	color->colors[21] = 0x00FFF99;
	color->colors[22] = 0x00FFFCC;
}

