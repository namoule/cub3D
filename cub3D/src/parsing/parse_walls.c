/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:22:07 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/13 18:09:39 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

bool player_stuck(char **map, int y, int x)
{
    if (map[y + 1] == NULL || map[y][x] == '0' || map[y][x] == '0')
        return (true);
    if (map[y][x + 1] == '1' && map[y][x - 1] == '1' && map[y + 1][x] == '1' && map[y - 1][x] == '1')
        return (true);
    return (false);
}
static bool not_ins_map(char c)
{
    if (c == ' ' || c == '\0' || c == '\t' || c == '\n')
        return (true);
    return (false);
}


bool invalid_char(char **game, int y, int x)
{
    if(is_map(game[y+1][x]) == false && is_dir(game[y+1][x]) == false)
        return(printf("Error !\nWrong charracter in map %s %c\n", game[y], game[y+1][x]), false);
    else if(is_map(game[y-1][x]) == false && is_dir(game[y-1][x]) == false)
        return(printf("Error !\nWrong charracter in map %s %c\n", game[y], game[y-1][x]), false);
    else if(is_map(game[y][x+1]) == false && is_dir(game[y][x+1]) == false)
        return(printf("Error !\nWrong charracter in map %s %c\n", game[y], game[y][x+1]), false);
    else if(is_map(game[y][x-1]) == false && is_dir(game[y][x-1]) == false)
        return(printf("Error !\nWrong charracter in map %s %c\n", game[y], game[y][x-1]), false);
    return(true);
}

static bool check_char(char **map, int y, int x)
{
    map[y][x] = 'v';
    if (map[y + 1] == NULL || x == 0 || y == 0 || invalid_char(map, y, x) == false)
        return (false);
    if (not_ins_map(map[y][x + 1]) == true || is_dir(map[y][x + 1]) == true)
        return (false);
    if (not_ins_map(map[y][x - 1]) == true || is_dir(map[y][x - 1]) == true)
        return (false);
    if (not_ins_map(map[y + 1][x]) == true || is_dir(map[y + 1][x]) == true)
        return (false);
    if (not_ins_map(map[y - 1][x]) == true || is_dir(map[y - 1][x]) == true)
        return (false);
    if (map[y][x + 1] == '0' || is_dir(map[y][x + 1]) == true)
        if (check_char(map, y, x + 1) == false)
            return (false);
    if (map[y][x - 1] == '0' || is_dir(map[y][x - 1]) == true)
        if (check_char(map, y, x - 1) == false)
            return (false);
    if (map[y + 1][x] == '0' || is_dir(map[y + 1][x]) == true)
        if (check_char(map, y + 1, x) == false)
            return (false);
    if (map[y - 1][x] == '0' || is_dir(map[y - 1][x]) == true)
        if (check_char(map, y - 1, x) == false)
            return (false);
    return (true);
}

static bool check_char_around(char **map, int y, int x)
{
    if (check_char(map, y, x) == false)
        return (false);
    return (true);
}

bool wall_map(char **map, t_data *game)
{
    int y = 0;
    int x = 0;

    while (map[y])
    {
        while (map[y][x])
        {
            if (is_dir(map[y][x]) == true)
            {
                game->joueur.x = x;
                game->joueur.y = y;
                game->joueur.dir = map[y][x];
                if (player_stuck(map, y, x) == true)
                    return (printf("Error !\nThe player is stuck...\n"), false);
                return (check_char_around(map, y,
        }
        x = 0;
        y++;
    }
    return (printf("Error !\nNo player found..\n"), false);
}
