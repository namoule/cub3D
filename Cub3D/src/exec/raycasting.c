/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:23:52 by elsikira          #+#    #+#             */
/*   Updated: 2025/03/25 19:02:25 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	calculate_projection(t_data *game)
{
	if (game->ray.side == 0)
		game->ray.perpwall_dist = (game->ray.map_x - game->player.x
				+ (1 - game->ray.step_x) / 2) / game->ray.raydir_x;
	else
		game->ray.perpwall_dist = (game->ray.map_y - game->player.y
				+ (1 - game->ray.step_y) / 2) / game->ray.raydir_y;
	game->ray.line_height = (int)(HEIGHT / game->ray.perpwall_dist);
	game->ray.vertical_shift = 60;
	game->ray.draw_start = HEIGHT / 2 - game->ray.line_height / 2
		- game->ray.vertical_shift;
	game->ray.draw_end = HEIGHT / 2 + game->ray.line_height / 2
		- game->ray.vertical_shift;
	if (game->ray.draw_end >= HEIGHT)
		game->ray.draw_end = HEIGHT - 1;
}

void	dda_algo(t_data *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.sidedist_x < game->ray.sidedist_y)
		{
			game->ray.sidedist_x += game->ray.deltadist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedist_y += game->ray.deltadist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map.map[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.hit = 1;
	}
}

void	calculations_step_sidedist(t_data *game)
{
	if (game->ray.raydir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.sidedist_x = (game->player.x - game->ray.map_x)
			* game->ray.deltadist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.sidedist_x = (game->ray.map_x + 1.0 - game->player.x)
			* game->ray.deltadist_x;
	}
	if (game->ray.raydir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.sidedist_y = (game->player.y - game->ray.map_y)
			* game->ray.deltadist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.sidedist_y = (game->ray.map_y + 1.0 - game->player.y)
			* game->ray.deltadist_y;
	}
}

void	calculations_ray(t_data *game, int x)
{
	game->ray.x = x;
	game->ray.cam_x = 2 * x / (double)WIDTH - 1;
	game->ray.raydir_x = game->player.dir_x + game->player.plane_x
		* game->ray.cam_x;
	game->ray.raydir_y = game->player.dir_y + game->player.plane_y
		* game->ray.cam_x;
	game->ray.map_x = (int)game->player.x;
	game->ray.map_y = (int)game->player.y;
	game->ray.deltadist_x = fabs(1 / game->ray.raydir_x);
	game->ray.deltadist_y = fabs(1 / game->ray.raydir_y);
	game->ray.hit = 0;
}

void	raycasting(t_data *game, int x)
{
	calculations_ray(game, x);
	calculations_step_sidedist(game);
	dda_algo(game);
	calculate_projection(game);
}
