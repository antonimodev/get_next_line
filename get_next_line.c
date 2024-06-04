/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:19:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/31 17:51:58 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffersize(int fd, char *stat_buff)
{
    char	*buffer;
    int		read_result;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	read_result = 1;
	while (ft_strchr(buffer, '\n') == 0 && read_result != 0)
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_result] = '\0';
		stat_buff = ft_strjoin(stat_buff, buffer);
	}
	free(buffer);
	return (stat_buff);
}

static char	*ft_lineremaining(char *str)
{
	int		i;
	int		j;
	char	*remaining;

	i = 0;
	while(str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	remaining = malloc(ft_strlen(str) - i) + 1 * sizeof(char);
	if (!remaining)
		return (NULL);
	i++;
	j = 0;
	while(str[i] != '\0')
		remaining[j++] = str[i++];
	remaining[j] = '\0';
	free(str);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*stat_buff[4096];
	char		*final;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat_buff[fd] = read_buffersize(fd, stat_buff[fd]);
	if (ft_strchr(stat_buff[fd], '\n') == 1)
	{
		final = ft_strdup_n(stat_buff[fd]);
		stat_buff[fd] = ft_lineremaining(stat_buff[fd]);
	}
	return (final);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("ejemplo.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Primero; %s\n", line);
	line = get_next_line(fd);
	printf("Segundo; %s\n", line);
	return (0);
}
