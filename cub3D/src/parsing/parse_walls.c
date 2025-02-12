/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:22:07 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/12 19:23:00 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"


//check les char aux alentours pour savoir si il y a une sortie collee
static bool check_char(char **map, int y, int x)
{
    if(map[y+1] == NULL && (map[y][x] == '0' || is_dir(map[y][x])))
        return(printf("AAAAAA\n"),false);
    if(!map[y][x-1] || map[y][x-1] == ' ' || map[y][x-1] == '\0')
        return(printf("a\n"), false);
    if(map[y][x+1] == '\0' ||!map[y][x+1] || map[y][x+1] == ' ')
        return(printf("b\n"), false);
    if(map[y-1][x] == '\0' || map[y-1][x] == ' ' || map[y-1][x] == '\0')
        return(printf("c\n"), false);
    if(map[y+1][x] == ' ' || map[y+1][x] == '\0')
        return(printf("d\n"), false);
    return(true);
}

static bool check_zero(char **map, int y, int x)
{
    if(map[y][x] == '0')
        map[y][x] = 'v';
    if(check_char(map, y, x) == false)
        return(printf("1"), false);
    if(map[y][x-1] == '0' || is_dir(map[y][x-1]) == true)
        if(check_zero(map, y, x-1) == false)
            return(printf("2"), false);
    if(map[y][x+1] == '0' || is_dir(map[y][x+1]) == true)
        if(check_zero(map, y, x+1) == false)
            return(printf("3"), false);
    if(y != 0 && map[y-1][x] == '0' || is_dir(map[y-1][x]) == true)
        if(check_zero(map, y-1, x) == false)
            return(printf("4"), false);
    if(map[y+1] && map[y+1][x] == '0' || is_dir(map[y-1][x]) == true)
        if(check_zero(map, y+1, x) == false)
            return(printf("5"), false);
    return(true);
}

bool wall_map(char **map)
{
    int x = 0;
    int y = 0;

    while(map[y])
    {
        while(map[y][x])
        {
            if(map[y][x] == '0' || is_dir(map[y][x]) == true)
            {
                if(check_zero(map, y, x) == false)
                    return(printf("\nthe map is not closed line [%d] soit [%s]..\n", y, map[y]), false);
            }
            x++;
        }
        x = 0;
        y++;
    }
    return(true);
}