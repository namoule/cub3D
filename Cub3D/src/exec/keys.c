/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:22:12 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/25 19:20:11 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	s_and_d(int val_key, t_data *game)
{
	if (val_key == XK_S || val_key == XK_s)
	{
		if (game->key['S'] == 0)
			game->key['S'] = 1;
	}
	if (val_key == XK_D || val_key == XK_d)
	{
		if (game->key['D'] == 0)
			game->key['D'] = 1;
	}
}

void	w_and_a(int val_key, t_data *game)
{
	if (val_key == XK_W || val_key == XK_w)
	{
		if (game->key['W'] == 0)
			game->key['W'] = 1;
	}
	if (val_key == XK_A || val_key == XK_a)
	{
		if (game->key['A'] == 0)
			game->key['A'] = 1;
	}
}

int	key_ex(int val_key, t_data *game)
{
	if (val_key == 0xff1b)
		close_win(game);
	w_and_a(val_key, game);
	s_and_d(val_key, game);
	if (val_key == XK_Left)
	{
		if (game->key[LEFT] == 0)
			game->key[LEFT] = 1;
	}
	if (val_key == XK_Right)
	{
		if (game->key[RIGHT] == 0)
			game->key[RIGHT] = 1;
	}
	return (0);
}

int	key_release(int val_key, t_data *game)
{
	if (val_key == XK_Left)
		game->key[LEFT] = 0;
	if (val_key == XK_Right)
		game->key[RIGHT] = 0;
	if (val_key == XK_W || val_key == XK_w)
		game->key['W'] = 0;
	if (val_key == XK_A || val_key == XK_a)
		game->key['A'] = 0;
	if (val_key == XK_S || val_key == XK_s)
		game->key['S'] = 0;
	if (val_key == XK_D || val_key == XK_d)
		game->key['D'] = 0;
	return (0);
}

void	init_keys(t_data *game)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		game->key[i] = 0;
		i++;
	}
}
