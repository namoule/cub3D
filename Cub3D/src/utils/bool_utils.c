/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:57:11 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/25 18:13:37 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

bool	is_dir(char c)
{
	return (c == 'N' || c == 'E' || c == 'W' || c == 'S');
}

bool	check_line(char **tab, int y, bool last_line_non_empty)
{
	if (check_empty_line(tab[y]))
		if (y != 0 && !last_line_non_empty)
			return (false);
	return (true);
}

bool	is_map(char c)
{
	return (c == 'N' || c == 'E' || c == 'W' || c == 'S' || c == '0');
}

bool	just_deal_line(char **tab, int y, int x)
{
	int	count;

	count = count_tab(tab);
	if (y == 0 || y == count - 1 || x == 0 || x == ft_strlen(tab[y]) - 1)
		if (tab[y][x] == '0')
			return (false);
	if (is_map(tab[y][x]) == true && check_around(tab, y, x, count) == false)
		return (false);
	return (true);
}

bool	check_char(char c)
{
	return (c == '1' || c == 'N' || c == 'E' || c == 'W' || c == 'S' || c == '0'
		|| c == '\n' || c == '\0' || c == ' ');
}
