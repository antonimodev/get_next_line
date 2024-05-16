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
    int		cll;
    char	*str;

    fd = open ("ejemplo.txt", O_RDWR);
    if (fd == -1)
        return (-1);
    str = malloc(5 * sizeof(char));
    if (str == NULL)
    {
        close(fd);
        return (-1);
    }
    if (write(fd, "hola", 4) == -1)
    {
        free(str);
        return (-1);
    }
    close(fd);  // Cerrar el archivo después de escribir

    fd = open("ejemplo.txt", O_RDONLY);  // Volver a abrir el archivo para leer
    if (fd == -1)
    {
        free(str);
        return (-1);
    }

    cll = ft_count_line_lenght(fd);
    close(fd);
    return (cll);
}

int	main(void)
{
    printf("El archivo tiene %d caracteres", ft_prueba());
    return (0);
}

/* Tener en cuenta que cuando se escribe por ejemplo el cursor (OFFSET) se queda
en el ultimo punto de la escritura */