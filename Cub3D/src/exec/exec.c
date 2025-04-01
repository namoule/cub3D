/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:34:53 by elsikira          #+#    #+#             */
/*   Updated: 2025/03/25 18:12:57 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	init_mlx(t_data *game)
{
	game->window = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "girls' cub3d");
	if (!game->window)
		return (printf("Error initializing mlx window.\n"), 1);
	mlx_key_hook(game->window, key_release, game);
	mlx_hook(game->window, 17, 0, close_win, game);
	mlx_hook(game->window, 2, 1L << 0, key_ex, game);
	mlx_hook(game->window, 3, 1L << 1, key_release, game);
	return (0);
}

int	exec(char *map_file, t_data *game)
{
	game->img.image = NULL;
	init_mlx(game);
	settings(game);
	init_keys(game);
	mlx_loop_hook(game->mlx_ptr, render_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
