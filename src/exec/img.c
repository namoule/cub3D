/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:55:30 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/08 17:39:24 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	*give_ptr_img(char *img, t_data *game, char *code)
{
	void	*ptr;

	char *temp;
	temp = less_n(img);
	ptr = mlx_xpm_file_to_image(game->mlx_ptr,temp, &game->img.image_width,
			&game->img.image_lenght);
	if (!ptr)
	{
		get_next_line(-42);
		return (printf("Invalid texture %s\n",temp), NULL);
	}
	if (strcmp("NO", code) == 0)
		game->map.n_text =temp;
	else if (strcmp("SO", code) == 0)
		game->map.s_text =temp;
	else if (strcmp("EA", code) == 0)
		game->map.e_text =temp;
	else if (strcmp("WE", code) == 0)
		game->map.w_text =temp;
	free(temp);
	return (ptr);
}
