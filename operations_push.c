/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:48:47 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/06 14:47:22 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **list_a, t_list **list_b)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*new_a;

	if (*list_b == NULL)
		return ;
	head_b = *list_b;
	head_a = *list_a;
	new_a = ft_lstnew(head_b->content);
	if (*list_a != NULL)
	{
		head_a->prev = new_a;
		new_a->next = head_a;
	}
	*list_a = new_a;
	if (1 < ft_lstsize(*list_b))
	{
		head_b = head_b->next;
		head_b->prev = NULL;
	}
	else
		head_b = NULL;
	free (*list_b);
	*list_b = head_b;
}

void	ft_push_a(t_list **list_a, t_list **list_b)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*new_a;

	if (*list_b == NULL)
		return ;
	head_b = *list_b;
	head_a = *list_a;
	new_a = ft_lstnew(head_b->content);
	if (*list_a != NULL)
	{
		head_a->prev = new_a;
		new_a->next = head_a;
	}
	*list_a = new_a;
	if (1 < ft_lstsize(*list_b))
	{
		head_b = head_b->next;
		head_b->prev = NULL;
	}
	else
		head_b = NULL;
	free (*list_b);
	*list_b = head_b;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_list **list_a, t_list **list_b)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*new_b;

	if (*list_a == NULL)
		return ;
	head_a = *list_a;
	head_b = *list_b;
	new_b = ft_lstnew(head_a->content);
	if (*list_b != NULL)
	{
		head_b->prev = new_b;
		new_b->next = head_b;
	}
	*list_b = new_b;
	if (1 < ft_lstsize(*list_a))
	{
		head_a = head_a->next;
		head_a->prev = NULL;
	}
	else
		head_a = NULL;
	free (*list_a);
	*list_a = head_a;
	write(1, "pb\n", 3);
}
