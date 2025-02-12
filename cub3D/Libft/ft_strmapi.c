/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:01:12 by jealefev          #+#    #+#             */
/*   Updated: 2023/11/15 10:16:08 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *str;
    unsigned int i;
    i = 0;
    str = malloc(sizeof (char *) * ft_strlen(s)+ 1);
    
    while(s[i])
    {
        str[i] = f(i, *s);
        i++;
    }

    return(str);
}