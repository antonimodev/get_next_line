/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:19:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/29 18:28:11 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_n(char *str)
{
	char	*str2;
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	str2 = malloc((i + 1) * sizeof(char));
	if (!str2)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*final_str;
	int		i;
	int		j;

	final_str = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!final_str)
		return (NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		final_str[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j] != '\0')
	{
		final_str[i] = str2[j];
		i++;
		j++;
	}
	final_str[i] = '\0';
	free(str1);
	free(str2);
	return (final_str);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char static	*static_buffer;
	char		*final;

	if (fd < 0)
		return (NULL);
	static_buffer = read_buffersize(fd, static_buffer);
	final = ft_strdup_n(static_buffer);
	static_buffer = ft_lineremaining(static_buffer);
	return (final);
}

char	*read_buffersize(int fd, char *static_buffer)
{
	char	*buffer;
	int		read_result;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	// while comprobacion de n
	read_result = read(fd, buffer, BUFFER_SIZE);
	if (read_result < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	// strjoin(static_buffer, buffer)
	return (buffer);
}

char	*ft_lineremaining(char *str)
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
	remaining = (char *)malloc(sizeof(char) * (len + 1));
	if (!remaining)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
	{
		remaining[j++] = str[i++];
	}
	remaining[j] = '\0';
	free(str);
	return (remaining);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("ejemplo.txt", O_RDONLY);
	line = read_buffersize(fd);
	printf("Primero; %s\n", line);
	line = read_buffersize(fd);
	printf("Segundo; %s\n", line);
	return (0);
}

/*GET NEXT LINE DEBE DEVOLVER BUFFER SIZE CARACTERES, Y CADA
VEZ QUE SE EJECUTE DE NUEVO, DEBE DEVOLVER BUFFER SIZE CARACTERES
DESDE DÓNDE SE QUEDO LA ÚLTIMA VEZ*/

/* TENER EN CUENTA QUE SI UTILIZO LA FUNCION READ EN ALGUN MOMENTO
SIN CERRAR EL ARCHIVO,
EL PUNTERO SE QUEDA DÓNDE TERMINÓ LA LECTURA */