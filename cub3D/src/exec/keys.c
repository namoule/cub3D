/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:22:12 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/12 17:12:42 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	key_ex(int val_key, t_data *game)
{
	if (val_key == 0xff1b)
		close_win(game);
	if (val_key == XK_W || val_key == XK_w )
		printf("w\n");
	if (val_key == XK_A || val_key == XK_a)
		printf("a\n");
		// move(game, game->joueur.x - 1, game->joueur.y);
	if (val_key == XK_S || val_key == XK_s)
		printf("s\n");
		// move(game, game->joueur.x, game->joueur.y + 1);
	if (val_key == XK_D || val_key == XK_d)
		printf("d\n");
		// move(game, game->joueur.x + 1, game->joueur.y);
	if(val_key == XK_Up)
		printf("^\n"); // bouger la camera pour ces touches la...
	if(val_key == XK_Left)
		printf("<\n");
	if(val_key == XK_Down)
		printf("_\n");
	if(val_key == XK_Right)
		printf(">\n");
	return (0);
}
