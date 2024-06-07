/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:19:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/06/06 13:57:22 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_lineremaining(char *line)
{
	char	*remaining;
	int		i;
	int		j;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	i++;
	remaining = ft_calloc(ft_strlen(line) - i + 1, sizeof(char));
	j = 0;
	while (line[i] != '\0')
		remaining[j++] = line [i++];
	remaining[j] = '\0';
	if (remaining[0] == '\0')
	{
		free(remaining);
		return (NULL);
	}
	free(line);
	return (remaining);
}

/* Read buffersize from FD, we use strjoin to get characters
until find '\n' and return str with '\n' contained inside*/

char	*ft_read_buffersize(int fd, char *str)
{
    char	*buffer;
    int		read_result;

    if (!str)
        str = ft_calloc(1, sizeof(char));
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (buffer == NULL)
        return (NULL);
    read_result = 1;
    while (read_result > 0)
    {
        read_result = read(fd, buffer, BUFFER_SIZE);
        if (read_result < 0)
        {
            free(buffer);
            return (NULL);
        }
        buffer[read_result] = '\0';
        str = ft_strjoin(str, buffer);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free(buffer);
    return (str);
}

char	*get_next_line(int fd)
{
    static char	*stat_buffer[1024];
    char		*final;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (read(fd, 0, 0) < 0)
    {
        if (stat_buffer[fd] != NULL)
        {
            free(stat_buffer[fd]);
            stat_buffer[fd] = NULL;
        }
        return (NULL);
    }
    stat_buffer[fd] = ft_read_buffersize(fd, stat_buffer[fd]);
    if (stat_buffer[fd] == NULL)
        return (NULL);
    final = ft_strdup_n(stat_buffer[fd]);
    stat_buffer[fd] = ft_lineremaining(stat_buffer[fd]);
    return (final);
}
