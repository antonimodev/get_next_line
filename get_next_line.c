/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:19:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/06/10 12:08:03 by antonimo         ###   ########.fr       */
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
		remaining[j++] = line[i++];
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
	static char	*stat_buffer;
	char		*final;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (stat_buffer != NULL)
		{
			free(stat_buffer);
			stat_buffer = NULL;
		}
		return (NULL);
	}
	stat_buffer = ft_read_buffersize(fd, stat_buffer);
	if (stat_buffer == NULL)
		return (NULL);
	final = ft_strdup_n(stat_buffer);
	if (final == NULL)
		return (NULL);
	stat_buffer = ft_lineremaining(stat_buffer);
	if (stat_buffer == NULL)
		return (NULL);
	return (final);
}

int	main(void)
{
    int		fd1;
    int		fd2;
    int		fd3;
    int		fd4;
    int		fd5;
    int		fd6;
    char	*line;

    fd1 = open("1char.txt", O_RDONLY);
    if (fd1 == -1)
        printf("1 Char ha fallado.\n");
    
    fd2 = open("ejemplo.txt", O_RDONLY);
    if (fd2 == -1)
        printf("lineas normales ha fallado.\n");

    fd3 = open("empty.txt", O_RDONLY);
    if (fd3 == -1)
        printf("empty ha fallado.\n");

    fd4 = open("linealarga.txt", O_RDONLY);
    if (fd4 == -1)
        printf("linealarga ha fallado.\n");

    fd5 = open("saltodelinea.txt", O_RDONLY);
    if (fd5 == -1)
        printf("saltodelinea ha fallado.\n");

    fd6 = open("saltodelinea2.txt", O_RDONLY);
    if (fd6 == -1)
        printf("saltodelina2 ha fallado.\n");
	
	printf("1 Char; \n");
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd1);

	printf("Texto normal; \n");
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("%s \n", line);
		free(line);
	}
	close(fd2);

	printf("Vacío; \n");
	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("%s \n", line);
		free(line);
	}
	close(fd3);

	printf("Línea larga; \n");
	while ((line = get_next_line(fd4)) != NULL)
	{
		printf("%s \n", line);
		free(line);
	}
	close(fd4);

	printf("Salto de línea; \n");
	while ((line = get_next_line(fd5)) != NULL)
	{
		printf("%s \n", line);
		free(line);
	}
	close(fd5);

	printf("Salto de línea 2; \n");
	while ((line = get_next_line(fd6)) != NULL)
	{
		printf("%s \n", line);
		free(line);
	}
	close(fd6);

	return 0;
}
