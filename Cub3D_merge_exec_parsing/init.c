/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:01:34 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/10 22:43:57 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// bah la jinit..(je suis une merguez en commentaires chais pas quoi mettre )  ʕノ•ᴥ•ʔノ ︵ ┻━┻
void init_data(t_data *game)
{
    game->joueur.x = 0;
    game->joueur.y = 0;
    game->joueur.dir = 0;
    game->file_name = NULL;

    game->map.n_text = NULL;
    game->map.s_text = NULL;
    game->map.e_text = NULL;
    game->map.w_text = NULL;
    game->map.f_col = -1;
    game->map.c_col = -1;

    game->map.map = NULL;

    game->img.image = NULL;
    game->img.image2 = NULL;
    game->img.perso = NULL;

    game->mlx_ptr = NULL;
    game->window = NULL;
    game->addr = NULL;
    game->bits_per_pixel = 32;
    game->line_length = 0;
    game->endian = 0;
}
