/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:17:16 by efaustin          #+#    #+#             */
/*   Updated: 2024/06/18 16:17:17 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_to_storage(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(storage, '\n') && (bytes_read != 0))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

static char	*extract_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*save_remaining(char *storage)
{
	char	*remaining;
	int		i;
	int		j;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	remaining = (char *)malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!remaining)
		return (NULL);
	i++;
	j = 0;
	while (storage[i])
		remaining[j++] = storage[i++];
	remaining[j] = '\0';
	free(storage);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*storage[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (0);
	storage[fd] = read_to_storage(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = extract_line(storage[fd]);
	storage[fd] = save_remaining(storage[fd]);
	return (line);
}
