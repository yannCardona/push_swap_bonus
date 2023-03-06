/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:08:58 by ycardona          #+#    #+#             */
/*   Updated: 2022/12/20 15:10:52 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchex(unsigned int n, int fd, int count)
{
	if (15 < n)
	{
		count = ft_printchex(n / 16, fd, count);
		count = ft_printchex(n % 16, fd, count);
	}
	else
		count = ft_printchar("0123456789ABCDEF"[n], fd, count);
	return (count);
}
