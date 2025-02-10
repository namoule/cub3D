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

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *buf)
{
	char	*buffer;
	int		byte_read;

	if (!buf)
		buf = ft_calloc(1, 1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		buf = ft_free(buf, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
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

void	ft_error(t_data *game, char *str)
{
	write(1, str, (int)ft_strlen(str));
	close_win(game);
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
