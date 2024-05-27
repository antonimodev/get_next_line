/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:19:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/27 20:30:49 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;

	str = ft_read_line(fd);
	return (str);
}
char	*read_line(int fd)
{
	int		read_result;
	char	buffer;
	char	*final;

	while ()
	{
		read_result = read(fd, &buffer, 1);
		
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

int	i;
char *line;
char buffer;
char read_result = 1;

line = malloc(BUFFER_SIZE + 1 * sizeof(char));
while (1)
{
	read_result = read(fd, line, BUFFER_SIZE);
}
line[i] = '\0';

/*GET NEXT LINE DEBE DEVOLVER BUFFER SIZE CARACTERES, Y CADA
VEZ QUE SE EJECUTE DE NUEVO, DEBE DEVOLVER BUFFER SIZE CARACTERES
DESDE DÓNDE SE QUEDO LA ÚLTIMA VEZ*/

/* TENER EN CUENTA QUE SI UTILIZO LA FUNCION READ EN ALGUN MOMENTO
SIN CERRAR EL ARCHIVO,
EL PUNTERO SE QUEDA DÓNDE TERMINÓ LA LECTURA */