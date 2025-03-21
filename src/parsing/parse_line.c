/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:04:44 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/08 17:40:02 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"


int	parse_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'E' && str[i] != 'W' && str[i] != ' '
			&& str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_text(char *line, t_data *game)
{
	char	**tab;

	if (!line)
		return (-1);
	tab = ft_split(line, ' ');
	if (!tab)
		return (-1);
	if (tab[0] && tab[1])
	{
		if (ft_strncmp("NO", tab[0], 3) == 0)
			return (game->map.n_text = give_ptr_img(tab[1], game, "NO"),
				free_tab(tab), 0);
		else if (ft_strncmp("SO", tab[0], 3) == 0)
			return (game->map.s_text = give_ptr_img(tab[1], game, "SO"),
				free_tab(tab), 0);
		else if (ft_strncmp("EA", tab[0], 3) == 0)
			return (game->map.e_text = give_ptr_img(tab[1], game, "EA"),
				free_tab(tab), 0);
		else if (ft_strncmp("WE", tab[0], 3) == 0)
			return (game->map.w_text = give_ptr_img(tab[1], game, "WE"),
				free_tab(tab), 0);
		else if (ft_strncmp("F", tab[0], 2) == 0)
		{
			game->map.f_col = give_rgb(tab[1]);
			free_tab(tab);
			return(game->map.f_col);
		}
		else if (ft_strncmp("C", tab[0], 2) == 0)
		{
			game->map.c_col = give_rgb(tab[1]);
			free_tab(tab);
			return(game->map.c_col);
		}
	}
	return (1);
}
