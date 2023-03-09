/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:25:27 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/09 14:53:57 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ini_list(t_list **list_a, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_isnumeric(argv[i]) != 1
			|| ft_atoi(argv[i]) < INT_MIN || INT_MAX < ft_atoi(argv[i]))
		{
			write(2, "ERROR\n", 6);
			return (0);
		}
		ft_lstadd_back(list_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	if (ft_no_doubles(*list_a) == 0 || ft_is_ascending(*list_a) == 1)
		return (0);
	return (1);
}
