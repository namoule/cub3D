/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:46:12 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/17 12:18:17 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	freetab(char **tab, int alloc_lines)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

bool	all_inited(t_data *game)
{
	if (!game->map.n_text)
		return (false);
	if (!game->map.s_text)
		return (false);
	if (!game->map.e_text)
		return (false);
	if (!game->map.w_text)
		return (false);
	if (game->map.c_col < 0)
		return (false);
	if (game->map.f_col < 0)
		return (false);
	return (true);
}

char	*less_n(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	count_tab(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}
