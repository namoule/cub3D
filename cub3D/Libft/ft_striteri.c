/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:38:26 by jealefev          #+#    #+#             */
/*   Updated: 2023/11/17 09:47:24 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int i;
    i = 0;
    while(s[i])
    {
        f(i,&s[i]);
        i++;
    }
}