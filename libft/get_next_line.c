/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:23:59 by kammi             #+#    #+#             */
/*   Updated: 2024/02/13 18:04:20 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill(int fd, char *data)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_gnl(data, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			if (data)
				free(data);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		data = ft_strjoin_gnl(data, buffer);
	}
	free(buffer);
	return (data);
}

char	*ft_extract_line(char *data)
{
	char	*line;
	int		i;
	size_t	len;

	if (data[0] == '\0')
		return (NULL);
	i = 0;
	while (data[i] && data[i] != '\n')
		i++;
	len = i + (data[i] == '\n');
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_strcpy_gnl(line, data, 1);
	return (line);
}

char	*ft_update_data(char *old_data)
{
	char	*new_data;
	int		i;

	i = 0;
	while (old_data[i] && old_data[i] != '\n')
		i++;
	if (old_data[i] == '\0')
	{
		free(old_data);
		return (NULL);
	}
	new_data = malloc(sizeof(char) * (ft_strlen_gnl(old_data + i) + 1));
	if (!new_data)
		return (NULL);
	ft_strcpy_gnl(new_data, old_data + i + 1, 0);
	free(old_data);
	return (new_data);
}

char	*get_next_line(int fd, int error)
{
	static char	*data;
	char		*line;

	if (error == 1)
	{
		free(data);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = ft_fill(fd, data);
	if (!data)
		return (NULL);
	line = ft_extract_line(data);
	data = ft_update_data(data);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main()
{
	int	fd;
	char	*line;

	fd = open("file1.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}
*/
