/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:57:59 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/17 12:50:00 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

bool give_dir(int y, int x, char **tab, t_data *game)
{
	game->player.dir = tab[y][x];
	if(game->player.dir == 'N')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 1;
	}
	else if(game->player.dir == 'S')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 1;
	}	
	else if(game->player.dir == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 1;
	}	
	else if(game->player.dir == 'W')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 1;
	}
	game->player.x = x;
	game->player.y = y;
	return(true);
}

bool	check_around(char **tab, int y, int x, int count)
{
	if (x + 1 < ft_strlen(tab[y]) && (!tab[y][x + 1] || (tab[y][x + 1] == ' ')
			|| tab[y][x + 1] == '\n' || tab[y][x + 1] == '\0'))
		return (false);
	if (x - 1 >= 0 && (!tab[y][x] || (tab[y][x - 1] == ' ') || tab[y][x
			- 1] == '\n' || tab[y][x - 1] == '\0'))
		return (false);
	if (y - 1 >= 0 && (!tab[y][x] || (tab[y - 1][x] == ' ') || tab[y
			- 1][x] == '\n' || tab[y - 1][x] == '\0'))
		return (false);
	if (y + 1 < count && (!tab[y][x] || (tab[y + 1][x] == ' ') || tab[y
			+ 1][x] == '\n' || tab[y + 1][x] == '\0'))
		return (false);
	return (true);
}

bool	check_empty_line(char *line)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] != ' ' && line[x] != '\n')
			return (false);
		x++;
	}
	if (x == 0)
		return (false);
	return (true);
}

bool	check_tab_bis(t_data *game, char **tab, int y, int x)
{
	if (is_dir(tab[y][x]) == true && game->player.dir != 0)
		return (printf("already one game->player.dir %c\n", tab[y][x]), false);
	else if (is_dir(tab[y][x]) == true && game->player.dir == 0)
	{
		give_dir(y, x, tab, game);
	}
	if (check_char(tab[y][x]) == false)
		return (printf("Erreur : caractère invalide '%c' dans le tableau\n",
				tab[y][x]), false);
	else 
	{
		if (just_deal_line(tab, y, x) == false)
			return (printf("Erreur : case mal entourée ou bord mal formé !\n"),
			false);
	}
	return (true);
}

bool	check_tab(char **tab, t_data *game)
{
	int		y;
	int		x;
	bool	last_line_non_empty;
	int		count;

	y = 0;
	last_line_non_empty = false;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if(tab[y][x] == '\t')
				return(printf("a%da\n", y),false);
			if (check_tab_bis(game, tab, y, x) == false)
				return (false);
			x++;
		}
		last_line_non_empty = !check_empty_line(tab[y]);
		y++;
	}
	if (game->player.dir == 0)
		return (printf("Needs one player\n"), false);
	return (true);
}
