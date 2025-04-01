/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:17:59 by elsikira          #+#    #+#             */
/*   Updated: 2025/03/27 17:27:50 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	move_left(t_data *game, double new_x, double new_y)
{
	new_x = game->player.x - game->player.plane_x * game->player.move_speed;
	new_y = game->player.y - game->player.plane_y * game->player.move_speed;
	if (game->map.map[(int)new_y][(int)new_x] != '1')
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_right(t_data *game, double new_x, double new_y)
{
	new_x = game->player.x + game->player.plane_x * game->player.move_speed;
	new_y = game->player.y + game->player.plane_y * game->player.move_speed;
	if (game->map.map[(int)new_y][(int)new_x] != '1')
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_backwards(t_data *game, double new_x, double new_y)
{
	new_x = game->player.x - game->player.dir_x * game->player.move_speed;
	new_y = game->player.y - game->player.dir_y * game->player.move_speed;
	if (game->map.map[(int)new_y][(int)new_x] != '1')
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_forward(t_data *game, double new_x, double new_y)
{
	new_x = game->player.x + game->player.dir_x * game->player.move_speed;
	new_y = game->player.y + game->player.dir_y * game->player.move_speed;
	if (game->map.map[(int)new_y][(int)new_x] != '1')
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_player(t_data *game)
{
	double	new_x;
	double	new_y;	

	if (game->key['W'])
		move_forward(game, new_x, new_y);
	if (game->key['S'])
		move_backwards(game, new_x, new_y);
	if (game->key['A'])
		move_left(game, new_x, new_y);
	if (game->key['D'])
		move_right(game, new_x, new_y);
	if (game->key[LEFT])
		rotate_left(game);
	if (game->key[RIGHT])
		rotate_right(game);
}
