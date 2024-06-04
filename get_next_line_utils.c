/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:55:53 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/31 17:15:57 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// UTILIDADES
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_n(char *str)
{
	int		i;
	char	*str2;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	str2 = malloc((i + 2) * sizeof(char));
	if (!str2)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		str2[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*final_str;

	if (!str1)
	{
		str1 = malloc(1 * sizeof(char));
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	final_str = malloc(((ft_strlen(str1) + ft_strlen(str2)) + 1) * sizeof(char));
	if (final_str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str1)
		while (str1[++i] != '\0')
			final_str[i] = str1[i];
	while (str2[j] != '\0')
		final_str[i++] = str2[j++];
	final_str[ft_strlen(str1) + ft_strlen(str2)] = '\0';
	free(str1);
	return (final_str);
}
//i en -1 con preincremento en el bucle para ahorrar líneas.
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