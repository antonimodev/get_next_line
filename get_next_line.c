/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:19:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/28 16:12:51 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	return ("hola");
}
char	*ft_porqueria(char *tmp)
{
}

char	*read_line(int fd)
{
	static char	*tmp;
	int			read_result;

	tmp = malloc(BUFFER_SIZE * sizeof(char));
	if (!tmp)
		return (NULL);
	read_result = read(fd, tmp, BUFFER_SIZE);
	if (read_result <= 0)
	{
		free(tmp);
		return (NULL);
	}
	tmp[read_result] = '\0';
	return (tmp);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("ejemplo.txt", O_RDONLY);
	line = read_line(fd);
	printf("Primero; %s\n", line);
	line = read_line(fd);
	printf("Segundo; %s\n", line);
	return (0);
}

/*GET NEXT LINE DEBE DEVOLVER BUFFER SIZE CARACTERES, Y CADA
VEZ QUE SE EJECUTE DE NUEVO, DEBE DEVOLVER BUFFER SIZE CARACTERES
DESDE DÓNDE SE QUEDO LA ÚLTIMA VEZ*/

/* TENER EN CUENTA QUE SI UTILIZO LA FUNCION READ EN ALGUN MOMENTO
SIN CERRAR EL ARCHIVO,
EL PUNTERO SE QUEDA DÓNDE TERMINÓ LA LECTURA */