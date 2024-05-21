/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:23:46 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/16 14:08:24 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>

// Definition of BUFFER_SIZE.
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

// get_next_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c
int 	ft_strlen(char *str);
char 	*ft_strdup(char *str);

#endif
