/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:37:39 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/22 23:13:18 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(const char *str, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (str[i] == c)
			w++;
		i++;
	}
	w++;
	return (w);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(n + 1);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

static char	*get_word(const char *s, char c, int *i)
{
	int	start;

	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	return (ft_strndup(s + start, *i - start));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * ((ft_countword(s, c)) + 1));
	if (!tab)
		return (NULL);
	while (k < ft_countword(s, c))
	{
		tab[k] = get_word(s, c, &i);
		if (!tab[k])
			return (NULL);
		k++;
	}
	tab[k] = NULL;
	return (tab);
}
