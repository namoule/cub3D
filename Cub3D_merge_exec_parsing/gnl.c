/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:34:11 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/10 21:45:59 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub.h"

void free_buffer(char **buffer)
{
	int i = 0;
	while(i < 1024)
	{
		if(buffer[i])
		{
			free(buffer[i]);
			buffer[i] = NULL;
		}
		i++;
	}
}

int	count_line(char *path)
{
	int		fd;
	char	*line;
	int		nb;

	nb = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		nb++;
	}
	close(fd);
	return (nb);
}

char	**gnl(char *path, t_data *game)
{
	int		fd;
	char	**tab;
	char	*line;
	int		nb;
	int		lenght;

	nb = 0;
	if (!path)
		return (NULL);
	lenght = count_line(path);
	tab = malloc(sizeof(char *) * (lenght + 1));
	fd = open(path, O_RDONLY);
	if (fd <= 0)
		ft_error(game, "fd error");
	line = get_next_line(fd);
	while (line)
	{
		tab[nb] = line;
		line = get_next_line(fd);
		nb++;
	}
	tab[nb] = line;
	close(fd);
	return (tab);
}
