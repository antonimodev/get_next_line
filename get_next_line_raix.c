/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_raix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:27:09 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/27 17:11:45 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer;
	char	read_result;
	char	*final;
	int		i;

	line = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!line)
		return (NULL);
	read_result = 1;
	i = 0;
	while (read_result > 0 && i < BUFFER_SIZE)
	{
		read_result = read(fd, &buffer, 1);
		if (buffer == '\n')
			break ;
		line[i] = buffer;
		i++;
	}
	line[i] = '\0';
	if (read_result < 0)
		return (NULL);
	final = ft_strdup(line);
	free(line);
	return (final);
}

int	main(void)
{
	int	fd;

	fd = open("ejemplo.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}
