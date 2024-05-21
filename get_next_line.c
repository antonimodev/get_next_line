/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:19:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/15 14:19:46 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *line;
    char    buffer;
    char    *result;
    int     read_result;
    int     i;

    if (BUFFER_SIZE <= 0)
        return (NULL);
    line = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (line == NULL)
    {
        free(line);
        return (NULL);
    }
    read_result = read(fd, &buffer, 1);
    i = 0;
    while(read_result > 0)
    {
        line[i++] = buffer;
        if (buffer == '\n')
            break ;
        read_result = read(fd, &buffer, 1);
    }
    line[i] = '\0';
    if (read_result <= 0 && i == 0)
        return (NULL);
    result = ft_strdup(line);
    free(line);
    return (result);
}

/* int main()
{
    int fd = open("ejemplo.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    char *line;
    line = get_next_line(fd);

    printf("%s\n", line);
    free(line);

    close(fd);
    return 0;
} */

/* TENER EN CUENTA QUE SI UTILIZO LA FUNCION READ EN ALGUN MOMENTO SIN CERRAR EL ARCHIVO,
EL PUNTERO SE QUEDA DÓNDE TERMINÓ LA LECTURA */