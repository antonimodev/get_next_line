/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:19:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/06/05 18:37:06 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffersize(int fd, char *stat_buff)
{
	char	*buffer;
	int		read_result;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char *));
	if (!buffer)
		return (NULL);
	read_result = 1;
	while (ft_strchr(buffer, '\n') == 0 && read_result != 0)
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_result] = '\0';
		stat_buff = ft_strjoin(stat_buff, buffer);
	}
	return (stat_buff);
}

char	*ft_lineremaining(char *str)
{
	int		i;
	int		j;
	char	*remaining;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
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
	while (str[i] != '\0')
		remaining[j++] = str[i++];
	remaining[j] = '\0';
	free(str);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*stat_buff[4096];
	char		*final;

	final = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat_buff[fd] = read_buffersize(fd, stat_buff[fd]);
	if (stat_buff[fd] == NULL)
		return (free(stat_buff[fd]), stat_buff[fd] = NULL, NULL);
	final = ft_strdup_n(stat_buff[fd]);
	if (final == NULL)
		return (free(final), final = NULL, final);
	stat_buff[fd] = ft_lineremaining(stat_buff[fd]);
	if (stat_buff[fd] == NULL)
		return (free(stat_buff[fd]), stat_buff[fd] = NULL, final);
	return (final);
}
/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("linealarga.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Primera línea del archivo vacío; %s\n", line);
	free(line);
	return (0);
} */

/* int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;
	int		fd6;
	char	*line;

	fd = open("ejemplo.txt", O_RDONLY);
	fd2 = open("empty.txt", O_RDONLY);
	fd3 = open("linealarga.txt", O_RDONLY);
	fd4 = open("saltodelinea.txt", O_RDONLY);
	fd5 = open("saltodelinea2.txt", O_RDONLY);
	fd6 = open("1char.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Primero; %s\n", line);
		free(line);
	}
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("Segundo; %s\n", line);
		free(line);
	}
	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("Tercero; %s\n", line);
		free(line);
	}
	while ((line = get_next_line(fd4)) != NULL)
	{
		printf("Cuarto; %s\n", line);
		free(line);
	}
	while ((line = get_next_line(fd5)) != NULL)
	{
		printf("Quinto; %s\n", line);
		free(line);
	}
	while ((line = get_next_line(fd6)) != NULL)
	{
		printf("Sexto; %s\n", line);
		free(line);
	}
	close(fd);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);

	return (0);
}
 */