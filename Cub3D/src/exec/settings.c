/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 00:15:15 by elsikira          #+#    #+#             */
/*   Updated: 2025/03/31 17:15:06 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	set_player_speed(t_data *game)
{
	game->player.move_speed = 0.3;
	game->player.rot_speed = 0.5;
}

void	settings(t_data *game)
{
	set_player_orientation(game);
	set_player_speed(game);
}
