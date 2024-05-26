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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*str2;
	int		i;

	i = 0;
	str2 = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (str2 == NULL)
		return (NULL);
	while (str[i] != '\0')
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
	return(final_str);
}