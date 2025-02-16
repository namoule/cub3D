/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:22:07 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/16 18:07:01 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

bool player_stuck(char **map, int y, int x)
{
    if(map[y+1] == NULL && (map[y][x] == '0' || is_dir(map[y][x])))
        return(printf("AAAAAA\n"),false);
    if(!map[y][x-1] || map[y][x-1] == ' ' || map[y][x-1] == '\0')
        return(printf("a\n"), false);
    if(map[y][x+1] == '\0' ||!map[y][x+1] || map[y][x+1] == ' ')
        return(printf("b\n"), false);
    if(map[y-1][x] == '\0' || map[y-1][x] == ' ' || map[y-1][x] == '\0')
        return(printf("c\n"), false);
    if(map[y+1] && (map[y+1][x] == ' ' || map[y+1][x] == '\0'))
        return(printf("d\n"), false);
    return(true);
}

// bool check_char(t_data *game, char **map, int y, int x)
// {
//     map[y][x] = 'v';
//     if(y == 0)
//         return(false);
//     else
//     {
//         if (map[y][x] != 'v' && (map[y + 1] == NULL || x == 0 || y == 0 || invalid_char(map, y, x) == false))
//             game->map.error = true;
//         if(map[y][x+1] && (not_ins_map(map[y][x + 1]) == true && map[y][x+1] != 'v'))
//             game->map.error = true;
//         if(map[y][x-1] && (not_ins_map(map[y][x - 1]) == true && map[y][x-1] != 'v'))
//             game->map.error = true;
//         if(map[y+1] != NULL && (not_ins_map(map[y + 1][x]) == true && map[y+1][x] != 'v'))
//             game->map.error = true;
//         if(y != 0 && (not_ins_map(map[y - 1][x]) == true && map[y-1][x] != 'v'))
//             game->map.error = true;
//         if(check_char_bis(map, y, x) == false)
//             return(printf("false\n"), false);
//                 if((map[y][x + 1] == '0' || is_dir(map[y][x + 1]) == true))
//         if(check_char(game, map, y, x + 1) == false && map[y][x+1] != 'v')
//             game->map.error = true;
//         if(map[y][x - 1] == '0' || is_dir(map[y][x - 1]) == true)
//             if(check_char(game, map, y, x - 1) == false && map[y][x -1] != 'v')
//                 game->map.error = true;
//         if (map[y+1] && (map[y + 1][x] == '0' || is_dir(map[y + 1][x]) == true))
//             if (check_char(game, map, y + 1, x) == false && map[y+1][x] != 'v')
//                 game->map.error = true;
//         if ((map[y - 1][x] == '0' || is_dir(map[y - 1][x]) == true))
//             if (check_char(game, map, y - 1, x) == false && map[y-1][x] != 'v')
//                 game->map.error = true;
//     }
//     return (true);
// }

// static bool check_char_around(t_data *game, char **map, int y, int x)
// {
//     if (check_char(game, map, y, x) == false || game->map.error == true)
//         return (printf("check_char false\n"), false);

//     int i = 0;
//     while(map[i])
//     {
//         printf("%s\n", map[i]);
//         i++;
//     }
//     return (printf("salope va !\n"), true);
// }

// bool wall_map(char **map, t_data *game)
// {
//     int y = 0;
//     int x = 0;

//     while (map[y])
//     {
//         while (map[y][x])
//         {
//             if (is_dir(map[y][x]) == true)
//             {
//                 game->joueur.x = x;
//                 game->joueur.y = y;
//                 game->joueur.dir = map[y][x];
//                 if (player_stuck(map, y, x) == true)
//                     return (printf("Error !\nThe player is stuck...\n"), false);
//                 return (check_char_around(game, map, y, x));
//             }
//             x++;
//         }
//         x = 0;
//         y++;
//     }
//     return (printf("Error !\nNo player found..\n"), false);
// }
