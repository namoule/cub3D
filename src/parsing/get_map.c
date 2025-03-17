/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:01:10 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/08 17:43:39 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

#include <stdio.h>

static int	get_passed_lines(int fd)
{
	char	*ptr;
	int		count;

	count = 0;
	while (1)
	{
		ptr = get_next_line(fd);
		if (!ptr)
			break ;
		free(ptr);
		count++;
	}
	return (count);
}

int	check_and_make_map(t_data *game, int new_fd)
{
	int	i;

	i = 0;
	while (1)
	{
		game->map.map[i] = get_next_line(new_fd);
		if (!game->map.map[i])
			break ;
		i++;
	}
	game->map.map[i] = NULL;
	free(get_next_line(new_fd));
	if (check_tab(game->map.map, game) == false)
		return (1);
	return (0);
}

int	get_map(int fd, t_data *game, int passed_lines)
{
	int	count;
	int	map_size;
	int	new_fd;

	count = 0;
	map_size = get_passed_lines(fd);
	game->map.map = malloc(sizeof(char *) * (map_size + 2));
	game->map.height = map_size;
	new_fd = open(game->file_name, O_RDONLY);
	while (passed_lines > 1)
	{
		free(get_next_line(new_fd));
		passed_lines--;
	}
	if (check_and_make_map(game, new_fd) == 1)
		return (1);
	return (0);
}

int	catch_texture(int fd, t_data *game)
{
	int		count;
	int		check;
	char	*line;

	count = 0;
	check = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		if (parse_line(line) != 0)
		{
			if (check_text(line, game) < 0)
				return (free(line), 1);
		}
		else
		{
			if (all_inited(game) == true && line_not_empty(line) == true)
				return (free(line), get_map(fd, game, count));
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}
