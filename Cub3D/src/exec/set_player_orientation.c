/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_orientation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:18:24 by elsikira          #+#    #+#             */
/*   Updated: 2025/03/27 17:18:37 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	set_west(t_data *game)
{
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = -0.66;
}

void	set_east(t_data *game)
{
	game->player.dir_x = 1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
}

void	set_south(t_data *game)
{
	game->player.dir_x = 0;
	game->player.dir_y = 1;
	game->player.plane_x = 0.66;
	game->player.plane_y = 0;
}

void	set_north(t_data *game)
{
	game->player.dir_x = 0;
	game->player.dir_y = -1;
	game->player.plane_x = -0.66;
	game->player.plane_y = 0;
}

void	set_player_orientation(t_data *game)
{
	if (game->player.dir == 'N')
		set_north(game);
	else if (game->player.dir == 'S')
		set_south(game);
	else if (game->player.dir == 'E')
		set_east(game);
	else if (game->player.dir == 'W')
		set_west(game);
}
