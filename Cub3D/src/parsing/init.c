/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:01:34 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/27 17:51:53 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	init_all(t_data *game)
{
	ft_memset(game, 0, sizeof(t_data));
	game->map.f_col = -1;
	game->map.c_col = -1;
	game->map.n_text_adr = (int *)-42;
	game->map.s_text_adr = (int *)-42;
	game->map.e_text_adr = (int *)-42;
	game->map.w_text_adr = (int *)-42;
}
