/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:23:09 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/06 14:14:11 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **list)
{
	t_list	*head;

	if (1 < ft_lstsize(*list))
	{
		head = *list;
		*list = head -> next;
		head->prev = ft_lstlast(*list);
		ft_lstlast(*list)->next = head;
		(head->next)->prev = NULL;
		head->next = NULL;
	}
}

void	ft_rotate_a(t_list **list_a)
{
	if (ft_lstsize(*list_a) < 2)
		return ;
	ft_rotate(list_a);
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_list **list_b)
{
	if (ft_lstsize(*list_b) < 2)
		return ;
	ft_rotate(list_b);
	write(1, "rb\n", 3);
}

void	ft_rotate_ab(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) < 2 && ft_lstsize(*list_b) < 2)
		return ;
	ft_rotate(list_a);
	ft_rotate(list_b);
	write(1, "rr\n", 3);
}
