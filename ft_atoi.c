/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:55:52 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/01 15:59:14 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

long long	ft_atoi(const char *str)
{
	int			i;
	long long	r;
	int			sign;

	sign = 1;
	i = 0;
	r = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i +1]) == 1)
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		r = 10 * r + str[i] - 48;
		i++;
	}
	return (sign * r);
}
