/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:24:49 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/06 14:44:05 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_r(t_list **list)
{
	t_list	*head;
	t_list	*last;

	if (1 < ft_lstsize(*list))
	{
		head = *list;
		last = ft_lstlast(*list);
		*list = last;
		last->next = head;
		head->prev = last;
		(last -> prev)->next = NULL;
		last->prev = NULL;
	}
}

void	ft_rotate_r_a(t_list **list_a)
{
	if (ft_lstsize(*list_a) < 2)
		return ;
	ft_rotate_r(list_a);
	write(1, "rra\n", 4);
}

void	ft_rotate_r_b(t_list **list_b)
{
	if (ft_lstsize(*list_b) < 2)
		return ;
	ft_rotate_r(list_b);
	write(1, "rrb\n", 4);
}

void	ft_rotate_r_ab(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) < 2 && ft_lstsize(*list_b) < 2)
		return ;
	ft_rotate_r(list_a);
	ft_rotate_r(list_b);
	write(1, "rrr\n", 4);
}
