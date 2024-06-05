/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:23:46 by antonimo          #+#    #+#             */
/*   Updated: 2024/06/05 10:56:00 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// Definition of BUFFER_SIZE.

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

// get_next_line.c
char	*get_next_line(int fd);
char	*ft_lineremaining(char *str);
char	*read_buffersize(int fd, char *stat_buff);

// get_next_line_utils.c
int		ft_strlen(char *str);
char	*ft_strdup_n(char *str);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strchr(char *str, char c);

#endif
