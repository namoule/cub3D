/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:38:34 by jealefev          #+#    #+#             */
/*   Updated: 2023/11/15 08:40:01 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
char    *ft_strjoin(char const *s1, char const *s2)
{
    int i;
    int j;
    char *str;

    i = 0;
    j = 0;
    str = (char *)malloc((sizeof (char)) * (ft_strlen(s1) +ft_strlen(s2) +1));

    if(str == NULL)
        return(NULL);
    
    while(s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while(s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return(str);    
}