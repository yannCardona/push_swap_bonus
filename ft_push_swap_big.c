/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:36:32 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/08 21:04:49 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **list_a, t_list **list_b)
{
	int	pivot;

	pivot = ft_pivot(*list_a);
	while (3 < ft_lstsize(*list_a))
		ft_execute_move(ft_best_move(list_a, list_b, pivot), list_a, list_b);
	ft_sort_3(list_a);
	if (*list_b != NULL)
	{
		if (ft_pos_in_b(*list_b, (*list_a)->content) <= ft_lstsize(*list_b) / 2)
		{
			while ((*list_b)->content != ft_maxlst(*list_b))
				ft_rotate_b(list_b);
		}
		else
		{
			while ((*list_b)->content != ft_maxlst(*list_b))
				ft_rotate_r_b(list_b);
		}
		while (*list_b != NULL)
			ft_push_a(list_a, list_b);
	}
}
