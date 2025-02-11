/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:22:52 by jealefev          #+#    #+#             */
/*   Updated: 2023/11/15 11:45:13 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void    *ft_memchr(const void *s, int c, size_t n)
{
    size_t    i;

    i = 0;
    while (i < n)
    {
        if (((char *)s)[i] == (char)c)
            return ((void *)&((char *)s)[i]);
        i++;
    }
    return (NULL);
}