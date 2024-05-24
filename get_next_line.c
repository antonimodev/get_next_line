/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:19:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/24 17:36:39 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char	*ft_buffer_to_line(char *buffer)
{
	char	*str;
	int		count;

	count = 0;
	while (count < BUFFER_SIZE)
	{
		if (buffer[count] == '\0' || buffer[count] == '\n')
			break ;
		count++;
	}
	str = malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	count = 0;
	while (buffer[count] != '\0')
	{
		str[count] = buffer[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;
	int		read_result;
	int		i;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_result = read(fd, buffer, BUFFER_SIZE);
	i = 0;
	while (read_result > 0 && i < BUFFER_SIZE)
		i++;
	buffer[i] = '\0';
	line = ft_buffer_to_line(buffer);
	free(buffer);
	if (read_result < 0)
		return (NULL);
	return (line);
} */

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
	int		fd;
	char	*line;

	fd = open("ejemplo.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Primero; %s\n", line);
	line = get_next_line(fd);
	printf("Segundo; %s\n", line);
	return (0);
}

/*GET NEXT LINE DEBE DEVOLVER BUFFER SIZE CARACTERES, Y CADA
VEZ QUE SE EJECUTE DE NUEVO, DEBE DEVOLVER BUFFER SIZE CARACTERES
DESDE DÓNDE SE QUEDO LA ÚLTIMA VEZ*/

/* TENER EN CUENTA QUE SI UTILIZO LA FUNCION READ EN ALGUN MOMENTO
SIN CERRAR EL ARCHIVO,
EL PUNTERO SE QUEDA DÓNDE TERMINÓ LA LECTURA */