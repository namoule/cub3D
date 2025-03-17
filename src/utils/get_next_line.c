/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:56:45 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/17 11:56:59 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	ft_getcountline(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (count);
	while (s[count] && s[count] != '\n')
		count++;
	return (count);
}

char	*ft_new_line(char *buffer)
{
	int		i;
	int		j;
	char	*new_line;

	i = ft_getcountline(buffer);
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	new_line = ft_calloc((ft_strlen(buffer) - i), sizeof(char));
	if (!new_line)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_line[j++] = buffer[i++];
	new_line[j] = '\0';
	return (free(buffer), new_line);
}

char	*ft_first_line(char *buffer)
{
	int		bytes_read;
	char	*line;

	bytes_read = 0;
	if (!buffer || *buffer == '\0')
		return (NULL);
	line = ft_calloc(ft_getcountline(buffer) + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (buffer[bytes_read] && buffer[bytes_read] != '\n')
	{
		line[bytes_read] = buffer[bytes_read];
		bytes_read++;
	}
	if (buffer[bytes_read] == '\n')
		line[bytes_read] = '\n';
	return (line);
}

char	*ft_read_file(int fd, char *line)
{
	int		bytes_read;
	char	*buffer;
	char	*temp;

	if (!line)
		line = ft_calloc(1, sizeof(char));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(line), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(line, buffer);
		if (!temp)
			return (free(line), free(buffer), NULL);
		free(line);
		line = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[1024];

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (fd == -42)
	{
		free_buffer(buffer);
		return (NULL);
	}
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_first_line(buffer[fd]);
	buffer[fd] = ft_new_line(buffer[fd]);
	return (line);
}
