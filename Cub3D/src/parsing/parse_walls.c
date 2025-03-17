/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:22:07 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/08 14:44:47 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

bool	check_char_map(char **map, int y, int x)
{
	if(y == 0 || x == 0)
		return(false);
	if (map[y + 1] == NULL && (map[y][x] == '0' || is_dir(map[y][x])))
		return (false);
	if (!map[y][x - 1] || map[y][x - 1] == ' ' || map[y][x - 1] == '\0')
		return (false);
	if (map[y][x + 1] == '\0' || !map[y][x + 1] || map[y][x + 1] == ' ')
		return (false);
	if (map[y - 1][x] == '\0' || map[y - 1][x] == ' ' || map[y - 1][x] == '\0')
		return (false);
	if (map[y + 1] && (map[y + 1][x] == ' ' || map[y + 1][x] == '\0'))
		return (false);
	return (true);
}

static bool	check_zero(char **map, int y, int x)
{
	if (map[y][x] == '0')
		map[y][x] = 'v';
	if (check_char_map(map, y, x) == false)
		return (false);
	if (map[y][x - 1] == '0' || is_dir(map[y][x - 1]) == true)
		if (check_zero(map, y, x - 1) == false)
			return (false);
	if (map[y][x + 1] == '0' || is_dir(map[y][x + 1]) == true)
		if (check_zero(map, y, x + 1) == false)
			return (false);
	if (y != 0 && map[y - 1][x] == '0' || is_dir(map[y - 1][x]) == true)
		if (check_zero(map, y - 1, x) == false)
			return (false);
	if (map[y + 1] && map[y + 1][x] == '0' || is_dir(map[y - 1][x]) == true)
		if (check_zero(map, y + 1, x) == false)
			return (false);
	return (true);
}

bool	wall_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '0' || is_dir(map[y][x]) == true)
			{
				if (check_zero(map, y, x) == false)
					return (false);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (true);
}
