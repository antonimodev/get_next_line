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

int	ft_strlen(char const *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*strfinal;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	strfinal = ft_calloc(len + 1, sizeof(char));
	if (strfinal == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		strfinal[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		strfinal[i++] = s2[j++];
	strfinal[i] = '\0';
	return (strfinal);
}

int	ft_strchr(char const *str, char c)
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

char	*ft_strdup_n(char const *str)
{
    char	*new_str;
    int		i;

    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    new_str = ft_calloc(i + 1, sizeof(char));
    if (new_str == NULL)
        return (NULL);
    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}


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
