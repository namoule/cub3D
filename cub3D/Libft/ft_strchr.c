/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:54:50 by jealefev          #+#    #+#             */
/*   Updated: 2023/11/17 09:58:39 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char    *ft_strchr(const char *s, int c)
{
    int    i;

    c = (char)c;
    i = 0;
    while (s[i] != c && s[i])
        i++;
    if (s[i] == c)
        return ((char *)&s[i]);
    return (NULL);
}
