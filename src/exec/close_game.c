/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:03:40 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/08 17:40:59 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void free_tab(char **tab)
{
	while(*tab)
	{
		free(*tab);
		tab++;
	}
}

int	close_win(t_data *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx_ptr, game->window);
	if (game->img.image)
		mlx_destroy_image(game->mlx_ptr, game->img.image);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}

int close_game(t_data *game)
{
	if(game->map.map)
		free_tab(game->map.map);
	mlx_destroy_window(game->mlx_ptr, game->window);
	mlx_destroy_image(game->mlx_ptr, game->map.n_text);
	mlx_destroy_image(game->mlx_ptr, game->map.s_text);
	mlx_destroy_image(game->mlx_ptr, game->map.e_text);
	mlx_destroy_image(game->mlx_ptr, game->map.w_text);
	free(game->map.n_text);
	free(game->map.s_text);
	free(game->map.e_text);
	free(game->map.w_text);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	return(0);
}