/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:55:53 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/15 14:56:14 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// UTILIDADES
#include "get_next_line.h"

int	ft_count_line_lenght(int fd)
{
	static char	b;
	int			read_value;
	int			count;

	count = 0;
	read_value = read(fd, &b, sizeof(char));
	while (read_value > 0)
	{
		count++;
		read_value = read(fd, &b, sizeof(char));
	}
	if (read_value < 0)
		return (-1);
	return (count);
}