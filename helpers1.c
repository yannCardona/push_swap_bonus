/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:47:55 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/08 20:15:49 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_ascending(t_list *list)
{
	t_list	*current;

	if (list == NULL)
		return (0);
	current = list;
	while (current -> next != NULL)
	{
		if ((current->next)->content <= current->content)
			return (0);
		current = current -> next;
	}
	return (1);
}

int	ft_is_descending(t_list *list)
{
	t_list	*current;

	if (list == NULL)
		return (0);
	current = list;
	while (current -> next != NULL)
	{
		if (current->content <= (current->next)->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_maxlst(t_list *list)
{
	t_list	*current;
	int		max;

	if (list == NULL)
		return (0);
	current = list;
	max = current->content;
	while (current != NULL)
	{
		if (max < current->content)
			max = current->content;
		current = current->next;
	}
	return (max);
}

int	ft_minlst(t_list *list)
{
	t_list	*current;
	int		min;

	if (list == NULL)
		return (0);
	current = list;
	min = current->content;
	while (current != NULL)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}
