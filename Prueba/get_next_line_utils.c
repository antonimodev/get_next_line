/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:55:53 by antonimo          #+#    #+#             */
/*   Updated: 2024/06/06 11:21:28 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(size_t size, size_t type)
{
	char	*buffer;
	int		i;

	buffer = malloc(size * type);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < size)
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}
