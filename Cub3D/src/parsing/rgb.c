/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:07:20 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/22 23:51:43 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	give_rgb(char *str)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;
	int		col;

	rgb = ft_split(str, ',');
	if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[0][0] == '\0' || rgb[1][0] == '\0'
			|| rgb[2][0] == '\n' || rgb[3] != NULL)
		return (printf("Wrong rgb\n"), -1);
	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	if (red < 0 || green < 0 || blue < 0 || red > 255 || green > 255
		|| blue > 255)
		return (printf("Wrong color\n"), -1);
	col = (red << 16) | (green << 8) | blue;
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(rgb);
	return (col);
}
