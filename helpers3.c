/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:10:23 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/06 15:29:50 by ycardona         ###   ########.fr       */
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
