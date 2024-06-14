/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:23:46 by antonimo          #+#    #+#             */
/*   Updated: 2024/06/12 11:10:17 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// Definition of BUFFER_SIZE.

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

// Get_Next_Line.c

char	*ft_line_remaining(char *stat_buff);
char	*ft_line(char *stat_buff);
char	*ft_read_buffersize(int fd, char *stat_buff);
char	*get_next_line(int fd);

// Get_Next_Line_Utils.c

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, char chr);
void	*ft_calloc(size_t size, size_t type);

#endif