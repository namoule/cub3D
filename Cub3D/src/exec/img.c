/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:55:30 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/25 18:10:00 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	give_adr(void *ptr, t_data *game, char *code)
{
	if (strcmp("NO", code) == 0)
		game->map.n_text_adr = (int *)mlx_get_data_addr(ptr,
				&game->bits_per_pixel, &game->line_length, &game->endian);
	else if (strcmp("SO", code) == 0)
			game->map.s_text_adr = (int *)mlx_get_data_addr(ptr,
				&game->bits_per_pixel, &game->line_length, &game->endian);
	else if (strcmp("EA", code) == 0)
		game->map.e_text_adr = (int *)mlx_get_data_addr(ptr,
				&game->bits_per_pixel, &game->line_length, &game->endian);
	else if (strcmp("WE", code) == 0)
		game->map.w_text_adr = (int *)mlx_get_data_addr(ptr,
				&game->bits_per_pixel, &game->line_length, &game->endian);
}

bool	is_alr_full(t_data *game, char *code)
{
	if (strcmp("NO", code) == 0 && game->map.n_text != NULL)
		return (true);
	else if (strcmp("SO", code) == 0 && game->map.s_text != NULL)
		return (true);
	else if (strcmp("EA", code) == 0 && game->map.e_text != NULL)
		return (true);
	else if (strcmp("WE", code) == 0 && game->map.w_text != NULL)
		return (true);
	return (false);
}

void	*give_ptr_img(char *img, t_data *game, char *code)
{
	void	*ptr;
	char	*temp;

	if (is_alr_full(game, code) == true)
		return (printf("already filled texture !\n"), NULL);
	temp = less_n(img);
	ptr = mlx_xpm_file_to_image(game->mlx_ptr, temp, &game->img.image_width,
			&game->img.image_lenght);
	if (!ptr)
	{
		get_next_line(-42);
		return (printf("Invalid texture %s\n", temp), NULL);
	}
	give_adr(ptr, game, code);
	free(temp);
	return (ptr);
}
