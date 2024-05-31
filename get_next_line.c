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

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_result = 1;
	while (read_result > 0)
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		buffer[read_result] = '\0';
		if (stat_buff)
			stat_buff = ft_strjoin(stat_buff, buffer);
		else
			stat_buff = buffer;
		if (strchr(buffer, '\n'))
			break ;
	}
	if (read_result <= 0)
	{
		free(buffer);
		buffer = NULL;
	}
	return (stat_buff);
}

static char	*ft_lineremaining(char *str)
{
	char	*remaining;
	int		i;
	int		j;
	int		len;

	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	len = 0;
	while (str[i + len] != '\0')
		len++;
	remaining = malloc((len + 1) * sizeof(char));
	if (!remaining)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
		remaining[j++] = str[i++];
	remaining[j] = '\0';
	free(str);
	return (remaining);
}

char	*get_next_line(int fd)
{
	char static	*stat_buff = NULL;
	char		*final;

	if (fd < 0)
		return (NULL);
	stat_buff = read_buffersize(fd, stat_buff);
	if (ft_strchr(stat_buff, '\n') == 1)
	{
		final = ft_strdup_n(stat_buff);
		stat_buff = ft_lineremaining(stat_buff);
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

/*GET NEXT LINE DEBE DEVOLVER BUFFER SIZE CARACTERES, Y CADA
VEZ QUE SE EJECUTE DE NUEVO, DEBE DEVOLVER BUFFER SIZE CARACTERES
DESDE DÓNDE SE QUEDO LA ÚLTIMA VEZ*/

/* TENER EN CUENTA QUE SI UTILIZO LA FUNCION READ EN ALGUN MOMENTO
SIN CERRAR EL ARCHIVO,
EL PUNTERO SE QUEDA DÓNDE TERMINÓ LA LECTURA */