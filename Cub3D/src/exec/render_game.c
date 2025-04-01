/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 00:23:51 by elsikira          #+#    #+#             */
/*   Updated: 2025/03/27 17:39:13 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	textures_algo(t_data *game, int x, int y)
{
	game->ray.tex_y = (int)((y - game->ray.draw_start)
			* 64 / game->ray.line_height);
	if (game->ray.tex_y < 0)
		game->ray.tex_y = 0;
	if (game->ray.tex_y >= 64)
		game->ray.tex_y = 64 - 1;
	if (game->ray.side == 0)
	{
		if (game->ray.step_x == 1)
			game->ray.pixels[y * (game->line_length / 4) + x]
				= game->map.e_text_adr[game->ray.tex_y * 64
				+ game->ray.tex_x];
		else
			game->ray.pixels[y * (game->line_length / 4) + x]
				= game->map.w_text_adr[game->ray.tex_y * 64
				+ game->ray.tex_x];
	}
	else
	{
		if (game->ray.step_y == 1)
			game->ray.pixels[y * (game->line_length / 4) + x]
				= game->map.s_text_adr[game->ray.tex_y * 64
				+ game->ray.tex_x];
		else
			game->ray.pixels[y * (game->line_length / 4) + x]
				= game->map.n_text_adr[game->ray.tex_y * 64
				+ game->ray.tex_x];
	}
}

void	render_textures(t_data *game, int x)
{
	int	y;

	game->ray.pixels = (int *)mlx_get_data_addr(game->img.image,
			&game->bits_per_pixel, &game->line_length, &game->endian);
	y = game->ray.draw_start;
	if (y < 0)
		y = 0;
	if (game->ray.side == 0)
		game->ray.wall_x = game->player.y + game->ray.perpwall_dist
			* game->ray.raydir_y;
	else
		game->ray.wall_x = game->player.x + game->ray.perpwall_dist
			* game->ray.raydir_x;
	game->ray.tex_x = (int)(game->ray.wall_x * 64) % 64;
	if (game->ray.tex_x < 0)
		game->ray.tex_x += 64;
	while (y < game->ray.draw_end)
	{
		textures_algo(game, x, y);
		y++;
	}
}

void	render_walls(t_data *game)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		raycasting(game, x);
		render_textures(game, x);
		x++;
	}
}

void	render_ceiling_floor(t_data *game)
{
	int	x;
	int	y;
	int	*pixels;

	pixels = (int *)mlx_get_data_addr(game->img.image, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	if (!pixels)
		return (printf("Error: Failed to get the image address.\n"), exit(1));
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixels[y * (game->line_length / 4) + x] = game->map.c_col;
			x++;
		}
		y++;
	}
	y = HEIGHT / 2.3;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixels[y * (game->line_length / 4) + x] = game->map.f_col;
			x++;
		}
		y++;
	}
}

int	render_game(t_data *game)
{
	if (game->mlx_ptr && game->img.image)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.image);
		game->img.image = NULL;
	}
	game->img.image = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->img.image)
		return (printf("Error: Failed to create image.\n"), 1);
	move_player(game);
	render_ceiling_floor(game);
	render_walls(game);
	minimap(game);
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->img.image, 0, 0);
	return (0);
}
