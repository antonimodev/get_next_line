/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:19:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/23 15:19:42 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer;
	int		read_result;
	int		i;

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	read_result = read(fd, &buffer, 1);
	i = 0;
	while (read_result > 0 && i < BUFFER_SIZE)
	{
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
		read_result = read(fd, &buffer, 1);
	}
	line[i] = '\0';
	if (read_result <= 0)
		return (NULL);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("ejemplo.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

/*GET NEXT LINE DEBE DEVOLVER BUFFER SIZE CARACTERES, Y CADA
VEZ QUE SE EJECUTE DE NUEVO, DEBE DEVOLVER BUFFER SIZE CARACTERES
DESDE DÓNDE SE QUEDO LA ÚLTIMA VEZ*/

/* TENER EN CUENTA QUE SI UTILIZO LA FUNCION READ EN ALGUN MOMENTO
SIN CERRAR EL ARCHIVO,
EL PUNTERO SE QUEDA DÓNDE TERMINÓ LA LECTURA */