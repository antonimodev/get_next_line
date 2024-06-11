/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:38:44 by antonimo          #+#    #+#             */
/*   Updated: 2024/06/11 13:28:31 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// Definition of BUFFER_SIZE.

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

// get_next_line.c
char	*ft_line_remaining(char *stat_buff);
char	*ft_line(char *stat_buff);
char	*ft_read_buffersize(int fd, char *stat_buff);
char	*get_next_line(int fd);

// get_next_line_utils.c
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, char chr);
void	*ft_calloc(size_t size, size_t type);

#endif