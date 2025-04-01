/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:55:01 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/22 23:15:13 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	a;

	i = 0;
	a = n;
	while (i != a)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
		{
			i++;
		}
	}
	return (0);
}
