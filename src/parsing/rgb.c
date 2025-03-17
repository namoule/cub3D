/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:07:20 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/08 17:34:31 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int give_rgb(char *str)
{
	char **rgb = ft_split(str, ',');
	if(!rgb[0] || !rgb[1] || !rgb[2] || rgb[0][0] == '\0' || rgb[1][0] == '\0' || rgb[2][0] == '\n')
		return(printf("Wrong rgb\n"), -1);
	int red = ft_atoi(rgb[0]);
	int green = ft_atoi(rgb[1]); 
	int blue = ft_atoi(rgb[2]); 

	if(red < 0 || green < 0 || blue < 0)
		return(printf("Wrong color\n"), -1);
	int col = (red << 16) | (green << 8) | blue;
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(rgb);
	return(col);
}