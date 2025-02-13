/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:03:40 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/13 11:22:07 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int close_win(t_data *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx_ptr, game->window);
	if (game->img.image)
		mlx_destroy_image(game->mlx_ptr, game->img.image);
	if (game->map.map)
		freetab(game->map.map);
	if(game->map.n_text)
		mlx_destroy_image(game->mlx_ptr, game->map.n_text);
	if(game->map.s_text)
		mlx_destroy_image(game->mlx_ptr, game->map.s_text);
	if(game->map.e_text)
		mlx_destroy_image(game->mlx_ptr, game->map.e_text);
	if(game->map.w_text)
		mlx_destroy_image(game->mlx_ptr, game->map.w_text);
	if(game->map.c_col)
		free(game->map.c_col);
	if(game->map.f_col)
		free(game->map.f_col);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}
