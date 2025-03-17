/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:11:54 by elsikira          #+#    #+#             */
/*   Updated: 2025/03/17 12:25:05 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	move_backwards(t_data *game, double new_x, double new_y, double speed)
{
	new_x = game->joueur.x - game->joueur.dir_x * speed;
	new_y = game->joueur.y - game->joueur.dir_y * speed;
	if (game->map.map[(int)new_y][(int)new_x] != '1')
	{
		game->joueur.x = new_x;
		game->joueur.y = new_y;
	}
}
void	move_forward(t_data *game, double new_x, double new_y, double speed)
{
	new_x = game->joueur.x + game->joueur.dir_x * speed;
	new_y = game->joueur.y + game->joueur.dir_y * speed;
	if (game->map.map[(int)new_y][(int)new_x] != '1')
	{
		game->joueur.x = new_x;
		game->joueur.y = new_y;
	}
}

void	move_player(t_data *game, double move_speed, double rot_speed)
{
	double	new_x;
	double	new_y;	

	if (game->key['W'])
		move_forward(game, new_x, new_y, move_speed);
	if (game->key['S'])
		move_backwards(game, new_x, new_y, move_speed);
    // Strafe Left (A)
    if (game->key['A']) {
        new_x = game->joueur.x - game->joueur.plane_x * move_speed;
        new_y = game->joueur.y - game->joueur.plane_y * move_speed;
        if (game->map.map[(int)new_y][(int)new_x] != '1') {
            game->joueur.x = new_x;
            game->joueur.y = new_y;
        }
    }
    // Strafe Right (D)
    if (game->key['D']) {
        new_x = game->joueur.x + game->joueur.plane_x * move_speed;
        new_y = game->joueur.y + game->joueur.plane_y * move_speed;
        if (game->map.map[(int)new_y][(int)new_x] != '1') {
            game->joueur.x = new_x;
            game->joueur.y = new_y;
        }
    }
    if (game->key[LEFT])
	{
		//rotate_left;
        double old_dirX = game->joueur.dir_x;
        game->joueur.dir_x = game->joueur.dir_x * cos(-rot_speed) - game->joueur.dir_y * sin(-rot_speed);
        game->joueur.dir_y = old_dirX * sin(-rot_speed) + game->joueur.dir_y * cos(-rot_speed);

        double oldPlaneX = game->joueur.plane_x;
        game->joueur.plane_x = game->joueur.plane_x * cos(-rot_speed) - game->joueur.plane_y * sin(-rot_speed);
        game->joueur.plane_y = oldPlaneX * sin(-rot_speed) + game->joueur.plane_y * cos(-rot_speed);
		game->key[LEFT] = 0;  // Reset flag so it only rotates once per press
    }

    if (game->key[RIGHT])
	{
		//rotate_left;
        double old_dirX = game->joueur.dir_x;
        game->joueur.dir_x = game->joueur.dir_x * cos(rot_speed) - game->joueur.dir_y * sin(rot_speed);
        game->joueur.dir_y = old_dirX * sin(rot_speed) + game->joueur.dir_y * cos(rot_speed);

        double oldPlaneX = game->joueur.plane_x;
        game->joueur.plane_x = game->joueur.plane_x * cos(rot_speed) - game->joueur.plane_y * sin(rot_speed);
        game->joueur.plane_y = oldPlaneX * sin(rot_speed) + game->joueur.plane_y * cos(rot_speed);
		game->key[RIGHT] = 0;  // Reset flag so it only rotates once per press
    }
}
