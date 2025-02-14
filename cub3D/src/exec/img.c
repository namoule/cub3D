/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:09:04 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/13 17:10:03 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void *give_ptr_img(char *img, t_data *game, char *code)
{
    void * ptr;
    
    ptr = mlx_xpm_file_to_image(game->mlx_ptr, img, &game->img.image_width, &game->img.image_lenght);
    if (!ptr)
    {
        get_next_line(-42);   
        return(printf("Invalid texture %s\n", img), NULL);
    }
    if (ft_strncmp("NO", code, 3) == 0)
            game->map.n_text = img;
    else if (ft_strncmp("SO", code, 3) == 0)
        game->map.s_text = img;
    else if (ft_strncmp("EA", code, 3) == 0)
        game->map.e_text = img;
    else if (ft_strncmp("WE", code, 3) == 0)
        game->map.w_text  = img;
    return(ptr);
}
