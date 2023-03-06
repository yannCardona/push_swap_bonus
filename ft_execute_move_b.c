/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_move_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:50:18 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/01 15:50:49 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_execute_move_b(t_list *move, t_list **list_a, t_list **list_b)
{
	int		pos_a;
	int		pos_b;
	int		i;
	t_list	*current;

	pos_b = 0;
	current = *list_b;
	while (current->content != move->content)
	{
		current = current->next;
		pos_b++;
	}
	pos_a = ft_pos_in_a(*list_a, move->content);
	if (pos_a <= ft_lstsize(*list_a)/2 && pos_b <= ft_lstsize(*list_b)/2)
	{
		i = 0;
		while (i < ft_min_ab(pos_a, pos_b))
		{
			ft_rotate_ab(list_a, list_b);
			i++;
		}
		while (i < ft_max_ab(pos_a, pos_b))
		{
			if (pos_b < pos_a)
				ft_rotate_a(list_a);
			if (pos_a < pos_b)
				ft_rotate_b(list_b);
			i++;
		}
	}
	else if (ft_lstsize(*list_a)/2 < pos_a && ft_lstsize(*list_b)/2 < pos_b)
	{
		pos_a = ft_lstsize(*list_a) - pos_a;
		pos_b = ft_lstsize(*list_b) - pos_b;
		i = 0;
		while (i < ft_min_ab(pos_a, pos_b))
		{
			ft_rotate_r_ab(list_a, list_b);
			i++;
		}
		while (i < ft_max_ab(pos_a, pos_b))
		{
			if (pos_b < pos_a)
				ft_rotate_r_a(list_a);
			if (pos_a < pos_b)
				ft_rotate_r_b(list_b);
			i++;
		}
	}
	else if (pos_a <= ft_lstsize(*list_a)/2 && ft_lstsize(*list_b)/2 < pos_b)
	{
		i = 0;
		while (i < pos_a)
		{
			ft_rotate_a(list_a);
			i++;
		}
		pos_b = ft_lstsize(*list_b) - pos_b;
		i = 0;
		while (i < pos_b)
		{
			ft_rotate_r_b(list_b);
			i++;
		}
	}
	else if (ft_lstsize(*list_a)/2 < pos_a && pos_b <= ft_lstsize(*list_b)/2)
	{
		pos_a = ft_lstsize(*list_a) - pos_a;
		i = 0;
		while (i < pos_a)
		{
			ft_rotate_r_a(list_a);
			i++;
		}
		i = 0;
		while (i < pos_b)
		{
			ft_rotate_b(list_b);
			i++;
		}
	}
	ft_push_a(list_a, list_b);
}