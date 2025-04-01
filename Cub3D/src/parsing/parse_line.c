/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:04:44 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/28 10:28:25 by elsikira         ###   ########.fr       */
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
			&& str[i] != '\n' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_duptab(char *str)
{
	int		i;
	int		count;
	char	*res;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != 9 || (str[i] <= 13 && str[i] >= 11))
			count++;
		i++;
	}
	res = malloc(sizeof(char) * (count + 1));
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\t')
			res[count++] = str[i];
		else
			res[count++] = ' ';
		i++;
	}
	res[count] = '\0';
	return (res);
}

int	is_text(t_data *game, char **tab)
{
	if (ft_strcmp("NO", tab[0]) == 0 && game->map.n_text_adr != NULL)
		return (game->map.n_text = give_ptr_img(tab[1], game, "NO"),
			free_tab(tab), 0);
	else if (ft_strcmp("SO", tab[0]) == 0 && game->map.s_text_adr != NULL)
		return (game->map.s_text = give_ptr_img(tab[1], game, "SO"),
			free_tab(tab), 0);
	else if (ft_strcmp("EA", tab[0]) == 0 && game->map.e_text_adr != NULL)
		return (game->map.e_text = give_ptr_img(tab[1], game, "EA"),
			free_tab(tab), 0);
	else if (ft_strcmp("WE", tab[0]) == 0 && game->map.w_text_adr != NULL)
		return (game->map.w_text = give_ptr_img(tab[1], game, "WE"),
			free_tab(tab), 0);
	else
		return (-42);
}

int	is_col(t_data *game, char **tab)
{
	if (ft_strcmp("F", tab[0]) == 0)
	{
		game->map.f_col = give_rgb(tab[1]);
		free_tab(tab);
		return (game->map.f_col);
	}
	else if (ft_strcmp("C", tab[0]) == 0)
	{
		game->map.c_col = give_rgb(tab[1]);
		free_tab(tab);
		return (game->map.c_col);
	}
	return (-42);
}

int	check_text(char *line, t_data *game)
{
	char	**tab;
	char	*tmp;

	tmp = ft_duptab(line);
	if (!line)
		return (1);
	tab = ft_split(tmp, ' ');
	if (!tab || tab[2])
		return (-1);
	if (tab[0] && tab[1])
	{
		if (is_text(game, tab) != 0)
			if (is_col(game, tab) == -42)
				return (printf("cest ici\n"), 1);
		free(tab);
		return (0);
	}
	return (1);
}
