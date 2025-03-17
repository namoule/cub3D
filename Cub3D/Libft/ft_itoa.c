/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:50:55 by jealefev          #+#    #+#             */
/*   Updated: 2023/11/15 09:02:57 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>
#include "libft.h"
#include <stdlib.h>


 char *ft_strcpy(char *dest, const char *src)
 {
    int i;
    i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
 }

char* ft_itoa(int n)
{
    char *str;
    str = (char *)malloc(sizeof(char) * 2);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
    if(n < 0)
    {
        str[0] = '-';
        str[1] = '\0';
        str = ft_strjoin(str, ft_itoa(-n));
    }
    else if(n >= 10)
        str = ft_strjoin((ft_itoa(n / 10)), (ft_itoa(n % 10)));
    else if(n < 10 && n >= 0)
    {
        str[0] = n + '0';
        str[1] = '\0';
    }
    return(str);
}