/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:26:22 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/28 10:20:54 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

static int	check_cub(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	i -= 5;
	if (i <= 0)
		return (1);
	if (str[i] == '.' && str[i + 1] == 'c' && str[i + 2] == 'u' && str[i
			+ 3] == 'b' && str[i + 4] == '\0')
		return (0);
	else
		return (1);
	return (0);
}

int	open_file(char *file_name, t_data *game)
{
	if (check_cub(file_name) == 0 && (open(file_name, O_RDONLY) != -1))
		game->file_name = file_name;
	else
		return (1);
	return (0);
}

int	check_game(t_data *game)
{
	if (all_inited(game) == false)
		return (printf("something is missing...\n"), 1);
	if (game->player.dir == 0 || game->player.dir == -1)
		return (printf("no player or no dir...\n"), 1);
	return (0);
}

int	parsing(char *argv, t_data *game)
{
	int	fd;

	if (argv[1])
		init_all(game);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (deal_error(game, "error while mlx_init\n"), 1);
	if (open_file(argv, game) == 1)
	{
		printf("Error !\nThe given file is not valid...\n");
		get_next_line(-42);
		exit(1);
	}
	fd = open(game->file_name, O_RDONLY);
	if (catch_texture(fd, game) == 1)
		return (1);
	if (check_game(game) == 1)
		return (1);
	return (0);
}
