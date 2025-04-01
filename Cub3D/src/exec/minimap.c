/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:54:24 by elsikira          #+#    #+#             */
/*   Updated: 2025/03/31 17:36:37 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	blend_color(int bg, int fg, double filter)
{
	int	r;
	int	g;
	int	b;

	r = ((fg >> 16) & 0xFF) * filter + ((bg >> 16) & 0xFF) * (1 - filter);
	g = ((fg >> 8) & 0xFF) * filter + ((bg >> 8) & 0xFF) * (1 - filter);
	b = (fg & 0xFF) * filter + (bg & 0xFF) * (1 - filter);
	return ((r << 16) | (g << 8) | b);
}

void	draw_walls(t_data *game, int wall_x, int wall_y, int wall_width, int wall_height, int color)
{
	int	x;
	int	y;
	int	draw_x;
	int	draw_y;

	y = 0;
	while (y < wall_height)
	{
		x = 0;
		while (x < wall_width)
		{
			draw_x = wall_x + x;
			draw_y = wall_y + y;
			if (draw_x >= 0 && draw_x < WIDTH && draw_y >= 0 && draw_y < HEIGHT)
				game->minimap.pixels[draw_y * (game->line_length / 4) + draw_x] = color;
			x++;
		}
		y++;

	}
}
void draw_walls_on_minimap(t_data *game, char **map, int tile, int color)
{
	int x, y;
	int draw_x, draw_y;

	int player_x = game->player.x; 
	int player_y = game->player.y;
	double player_angle = game->player.angle; 

	int visibility = 6;
	double minimap_scale = 5.0; 

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '1') 
			{
				int world_wall_x = x * tile + tile ; 
				int world_wall_y = y * tile + tile ; 

				int rel_x = world_wall_x - player_x;
				int rel_y = world_wall_y - player_y;

				double rotated_x = cos(player_angle) * rel_x - sin(-player_angle) * rel_y;
				double rotated_y = sin(-player_angle) * rel_x + cos(-player_angle) * rel_y;

				draw_x = game->minimap.width + (rotated_x / minimap_scale);
				draw_y = game->minimap.height + (rotated_y / minimap_scale);

				draw_walls(game, draw_x, draw_y, tile / minimap_scale, tile / minimap_scale, color);
			}
			x++;
		}
		y++;
	}
}

void	draw_circle(t_data *game, int radius, int color, double filter)
{
	int	x;
	int	y;
	int	draw_x;
	int	draw_y;
	int	blended;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
			{
				draw_x = game->minimap.width + x;
				draw_y = game->minimap.height + y;
				if (draw_x >= 0 && draw_x < WIDTH
					&& draw_y >= 0 && draw_y < HEIGHT)
				{
					game->minimap.bg_color = game->minimap.pixels[draw_y
						* (game->line_length / 4) + draw_x];
					blended = blend_color(game->minimap.bg_color,
							color, filter);
					game->minimap.pixels[draw_y * (game->line_length / 4)
						+ draw_x] = blended;
				}
			}
			x++;
		}
		y++;
	}
}

void	draw_teardrop(t_data *game, int radius, int color)
{
	int	x;
	int	y;
	int	draw_x;
	int	draw_y;
	int	taper_width;

	game->minimap.height = game->minimap.height - 1 + radius / 2;
	draw_circle(game, radius * 1.5, color, 1.0);
	y = -radius * 1.5;
	while (y <= 0)
	{
		taper_width = (radius * (1.5 + y / (float)(radius * 1.2)));
		x = -taper_width;
		while (x <= taper_width)
		{
			draw_x = game->minimap.width + x;
			draw_y = game->minimap.height + y - 1;
			if (draw_x >= 0 && draw_x < WIDTH && draw_y >= 0 && draw_y < HEIGHT)
				game->minimap.pixels[draw_y * (game->line_length / 4)
					+ draw_x] = color;
			x++;
		}
		y++;
	}
}

void	init_minimap(t_data *game)
{
	game->minimap.player_x = game->player.x;
	game->minimap.player_y = game->player.y;
	game->minimap.width = 180;
	game->minimap.height = HEIGHT - 180;
	game->minimap.pixels = (int *)mlx_get_data_addr(game->img.image,
			&game->bits_per_pixel, &game->line_length, &game->endian);
	if (!game->minimap.pixels)
	{
		printf("mlx_get_data_addr failed !\n");
		exit(1);
	}
}

void	minimap(t_data *game)
{
	init_minimap(game);
	draw_circle(game, MINIMAP_RADIUS, 0xFFFFFF, 0.3);
	draw_walls_on_minimap(game, game->map.map, 5, 0xFF0000);
	draw_teardrop(game, 5, 0xFFFFFF);
	//draw_compass_directions();
}
