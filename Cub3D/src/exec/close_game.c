/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:03:40 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/25 18:12:03 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	free_tab(char **tab)
{
	while (*tab)
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
