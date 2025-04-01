/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:55:04 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/22 23:33:03 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t nb)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i])
	{
		while (str[i + j] == to_find[j] && (i + j) < nb)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)str + i);
		}
		j = 0;
		i++;
		if (j == nb)
			return (NULL);
	}
	return (NULL);
}
