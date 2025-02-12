/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:00:22 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/12 17:12:31 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub.h"

void	draw_line(void *img, int x1, int y1, int x2, int y2, int color,
		t_data *data)
{
	int		i;
	int		steps;
	float	x;
	float	y;
	float	x_inc;

	i = 0;
	steps = 0;
	int dx = x2 - x1; // largeur de ligne
	int dy = y2 - y1; // longueur de ligne
	if (abs(dx) > abs(dy))
		// si la distance de pas de x est moins grande que x on la prend,
		steps = abs(dx);
	else
		steps = abs(dy); // nombre detapes pour aller de a a b
	x_inc = dx / (float)steps;
	// deplacer de tant de x par step pour gerer langle de la ligne
	float y_inc = dy / (float)steps; // same mais pour y
	x = x1;
	y = y1;
	while (i++ <= steps)
	{
		mlx_pixel_put(data->mlx_ptr, data->window, (int)x, (int)y, color);
		// poser chaque pixel un par un
		x += x_inc;
		// si ya une inclinaison plus grande on augmentera ou reduira lecart en x
		y += y_inc;
		// pareil pour y
	}
}
