/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:50:21 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/16 14:14:28 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// prueba
#include "get_next_line.h"

int	ft_prueba(void)
{
	int		fd;
	char	*str;

	fd = open ("ejemplo.txt", O_RDWR);
	if (fd == -1)
		return (-1);
	str = malloc(5 * sizeof(char));
	if (str == NULL)
	{
		close(fd);
		return (NULL);
	}
	if (write(fd, "hola", 4) == -1)
	{
		free(str);
		return (-1);
	}
	read(fd, str, sizeof(char));
	close(fd);
	return (0);
}

int	main(void)
{
	ft_prueba();
	return (0);
}
