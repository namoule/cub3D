/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:02:06 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/13 14:16:40 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

static char *puthex(int nb)
{
    char *hex = NULL;
    char tab[16] = "0123456789ABCDEF";
    int tmp = nb;
    int count = 1;
    hex = malloc(sizeof(char) * (count + 1));
    if(nb <= 16)
        hex[0] = '0';
    while(count >= 0)
    {
        hex[count] = tab[nb % 16];
        count--;
        nb /= 16;
    }
    return(hex);
}

bool check_rgb(char **tab)
{
    int red= 0;
    int green = 0;
    int blue = 0;
    
    red = ft_atoi(tab[0]);
    green = ft_atoi(tab[1]);
    blue = ft_atoi(tab[2]);
    if(red < 0 || green < 0 || blue < 0 || red > 255 || green > 255 || blue > 255)
        return(printf("Error !\nFloor or ceiling color Invalid, send RGB pwease...\n"), false);
    return(true);
}

char *give_rgb(char *rgb_char)
{
    char *hex_value;
    char **tab;
    char *red = NULL;
    char *green = NULL;
    char *blue = NULL;
    
    if(!rgb_char)
        return(NULL);
    tab = ft_split(rgb_char, ',');
    if(!tab[0] || !tab[1] || !tab[2]|| check_rgb(tab) == false)
        return(freetab(tab), NULL); 
    red = puthex(ft_atoi(tab[0]));
    green = puthex(ft_atoi(tab[1]));
    blue = puthex(ft_atoi(tab[2]));
    if(!red || !green || ! blue)
        return(printf("Wrong colors..\n"), NULL);
    hex_value = malloc(sizeof(char) * 7);
    hex_value[0] = red[0];
    hex_value[1] = red[1];
    hex_value[2] = green[0];
    hex_value[3] = green[1];
    hex_value[4] = blue[0];
    hex_value[5] = blue[1];
    free(red);
    free(green);
    free(blue);
    freetab(tab);
    if(!hex_value)
        return(printf("Error while strjoin..,\n"), NULL);
    return(hex_value);
}
