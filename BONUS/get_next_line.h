/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:35:01 by ycardona          #+#    #+#             */
/*   Updated: 2023/02/13 12:44:06 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
int		ft_strlen(char *s);
void	ft_shiftbuff(char *str, int start);
char	*ft_strjoin(char *str, char *str_add, int size);
char	*ft_calloc(size_t size);
void	ft_bzero(char *str);

#endif