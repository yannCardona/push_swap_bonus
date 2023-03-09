/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:10:23 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/09 15:05:51 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_ab(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	ft_min_ab(int a, int b)
{
	if (b < a)
		return (b);
	else
		return (a);
}

int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && ft_isdigit(str[1]) == 1)
		i = 1;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
