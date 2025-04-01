/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:57:40 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/22 23:41:56 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] <= '9' && str[i] >= '0')
			res = res * 10 + (str[i] - '0');
		else
			return (-42);
		i++;
	}
	return (res);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;

// 		printf("%d/",ft_atoi("   \n  \r  -42"));
// 		printf("%d",atoi("   \n  \r  -42"));
// 	return (0);
// }
