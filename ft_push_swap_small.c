/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_small.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:45:26 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/01 16:04:33 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_move(t_list **list_a, t_list **list_b, int pivot)
{
	int		pos;
	t_list	*current;

	pos = 0;
	current = *list_a;
	while (pivot <= current->content)
	{
		pos++;
		current = current->next;
	}	
	current = *list_a;
	while (pivot <= (*list_a)->content)
	{
		if (pos <= ft_lstsize(*list_a) / 2)
			ft_rotate_a(list_a);
		else
			ft_rotate_r_a(list_a);
	}
	ft_push_b(list_a, list_b);
}

void	push_swap_small(t_list **list_a, t_list **list_b)
{
	int		pivot;
	int		pos_min;
	t_list	*current;

	pivot = ft_pivot(*list_a);
	while (3 < ft_lstsize(*list_a))
		ft_first_move(list_a, list_b, pivot);
	ft_sort_3(list_a);
	while (*list_b != NULL)
		ft_execute_move_b(ft_best_move_small(list_a, list_b), list_a, list_b);
	pos_min = 0;
	current = *list_a;
	while (current->content != ft_minlst(*list_a))
	{
		pos_min++;
		current = current->next;
	}
	while ((*list_a)->content != ft_minlst(*list_a))
	{
		if (pos_min <= ft_lstsize(*list_a) / 2)
			ft_rotate_a(list_a);
		else
			ft_rotate_r_a(list_a);
	}
}
