/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:03:40 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/12 17:11:16 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	close_win(t_data *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx_ptr, game->window);
	if (game->img.image)
		mlx_destroy_image(game->mlx_ptr, game->img.image);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	// if (game->map.map)
	// ft_freemap(game->map.map);
	free(game->mlx_ptr);
	exit(0);
}
