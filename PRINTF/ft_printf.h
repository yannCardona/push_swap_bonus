/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:04:27 by ycardona          #+#    #+#             */
/*   Updated: 2023/02/13 14:07:15 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
int				ft_printi(va_list ap, char i, int count, int *index);
int				ft_printchar(char c, int fd, int count);
int				ft_printstr(char *s, int fd, int count);
int				ft_printnbr(int n, int fd, int count);
int				ft_printhex(unsigned int n, int fd, int count);
int				ft_printchex(unsigned int n, int fd, int count);
int				ft_printuint(unsigned int n, int fd, int count);
int				ft_printp(unsigned long int n, int fd, int count);

#endif