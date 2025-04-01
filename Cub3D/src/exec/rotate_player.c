/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:38:47 by elsikira          #+#    #+#             */
/*   Updated: 2025/03/31 17:13:58 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	rotate_right(t_data *game)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(game->player.rot_speed)
		- game->player.dir_y * sin(game->player.rot_speed);
	game->player.dir_y = old_dir_x * sin(game->player.rot_speed)
		+ game->player.dir_y * cos(game->player.rot_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(game->player.rot_speed)
		- game->player.plane_y * sin(game->player.rot_speed);
	game->player.plane_y = old_plane_x * sin(game->player.rot_speed)
		+ game->player.plane_y * cos(game->player.rot_speed);
	game->player.angle = atan2(game->player.dir_y, game->player.dir_x);
	game->key[RIGHT] = 0;
}

void	rotate_left(t_data *game)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(-game->player.rot_speed)
		- game->player.dir_y * sin(-game->player.rot_speed);
	game->player.dir_y = old_dir_x * sin(-game->player.rot_speed)
		+ game->player.dir_y * cos(-game->player.rot_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(-game->player.rot_speed)
		- game->player.plane_y * sin(-game->player.rot_speed);
	game->player.plane_y = old_plane_x * sin(-game->player.rot_speed)
		+ game->player.plane_y * cos(-game->player.rot_speed);
	game->player.angle = atan2(game->player.dir_y, game->player.dir_x);
	game->key[LEFT] = 0;
}
