/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:46:12 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/12 22:57:26 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

// ici cest pcq si cest en fin de ligne et quil y a un saut a la ligne bah...cest pas le bon nom de fichier en gros..

void freetab(char **tab, int alloc_lines)
{
    int i = 0;
    while(tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

bool all_inited(t_data *game)
{
    if (!game->map.n_text)
        return (false);
    if (!game->map.s_text)
        return (false);
    if (!game->map.e_text)
        return (false);
    if (!game->map.w_text)
        return (false);
    if (game->map.c_col == NULL)
        return (false);
    if (game->map.f_col == NULL)
        return (false);
    return (true);
}

char *less_n(char *str)
{
    char *dest;
    int i = 0;
    while(str[i] && str[i] != '\n')
        i++;
    dest = malloc(sizeof(char) * (i + 1));
    i = 0;
    while(str[i] && str[i] != '\n')
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}