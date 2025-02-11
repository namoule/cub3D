/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:26:22 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/10 23:06:46 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_ext(char *str, char *ext)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i++])
		;
	i -= 5;
	if (i <= 0)
		return (1);
	while (str[i])
	{
		if (ext[j] != str[i])
			return (1);
		j++;
		i++;
	}
	return (0);
}

int parse_args(int argc, char **argv, t_data *game)
{
	if(argc != 2)
		return(ft_error(game, "Error !\nNot enought arguments...\n") ,1);
	if(check_ext(argv[1], ".cub") == 0)
	{
		game->file_name = ft_strdup(argv[1]);
		return(open(game->file_name, O_RDONLY));
	}
	return(0);
}
