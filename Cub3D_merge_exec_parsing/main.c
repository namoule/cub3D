/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:27:04 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/10 23:12:58 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub.h"
#include <stdbool.h>



//ici on gagne des lignes sinon le code est ultra mimi cracra

void *give_ptr_img(char *img, t_data *game)
{
    void * ptr;
    
    ptr = mlx_xpm_file_to_image(game->mlx_ptr, img, &game->img.image_width, &game->img.image_lenght);
    if (!ptr)
        return(printf("\nInvalid texture %s\n", img), NULL);
    else
        return(ptr);
}


//jsp si ya besoin de noticer celui la...

// int main(int argc, char **argv)
// {
//     t_data game;
//     init_data(&game, argv);
//     game.mlx_ptr = mlx_init();
//     // if(!game.mlx_ptr)
//     //     return(deal_error(&game, "error while mlx_init\n"), 1);
//     if(parse_cub(argc, argv, &game) != 0)
//         return(0);
//     fill_map(&game, open(argv[1], O_RDONLY));
//     return 0;
// }


int main(int argc, char **argv)
{
    void *mlx;
    void *mlx_win;
    
    t_data game;
    // if(parse_cub(argc, argv, &game) == 1)
    //     return(deal_error(NULL, "wrong arguments...\n"), 1);
    init_data(&game, argv);
    game.mlx_ptr = mlx_init();
    // if(!game.mlx_ptr)
    //     return(deal_error(&game, "error while mlx_init\n"), 1);
    game.window = mlx_new_window(game.mlx_ptr,  WIDTH, HEIGHT, "CUB");
    if (!game.window)
		return (ft_error(&game, "windows error\n"), 0);
    game.img.image = mlx_xpm_file_to_image(game.mlx_ptr, "floor.xpm",
			&game.img.image_width, &game.img.image_lenght);
    int i = 0;
    while(i++ < WIDTH)
    {
        draw_line(game.img.image, i, 0, i, HEIGHT / 2, 0xFFA500, &game);
        draw_line(game.img.image, i, HEIGHT / 2, i, 1023, 0x00FFFF, &game);
    }
    mlx_hook(game.window, 17, 1L << 0, close_win, &game);
	mlx_hook(game.window, 2, 1L << 0, key_ex, &game);
	mlx_loop(game.mlx_ptr);
    return(0);
}
