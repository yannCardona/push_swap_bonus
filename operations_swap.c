/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:21:55 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/06 14:41:28 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list)
{
	t_list	*old_head;
	t_list	*new_head;

	if (ft_lstsize(*list) < 2)
		return ;
	new_head = (*list)->next;
	old_head = *list;
	if (3 <= ft_lstsize(*list))
		(new_head->next)->prev = old_head;
	old_head->next = new_head->next;
	old_head->prev = new_head;
	new_head->prev = NULL;
	new_head->next = old_head;
	*list = new_head;
}

void	ft_swap_a(t_list **list_a)
{
	if (ft_lstsize(*list_a) < 2)
		return ;
	ft_swap(list_a);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_list **list_b)
{
	if (ft_lstsize(*list_b) < 2)
		return ;
	ft_swap(list_b);
	write(1, "sb\n", 3);
}

void	ft_swap_ab(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) < 2 && ft_lstsize(*list_b) < 2)
		return ;
	ft_swap(list_a);
	ft_swap(list_b);
	write(1, "ss\n", 3);
}
