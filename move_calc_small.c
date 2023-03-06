/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calc_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:51:47 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/02 21:46:19 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pos_in_a(t_list *list, int i)
{
	int	pos;

	if (list->content == ft_minlst(list)
		&& (i < list->content || ft_maxlst(list) < i))
		return (0);
	if (list->content == ft_maxlst(list)
		&& (list->content < i || i < ft_minlst(list)))
		return (0);
	if (i < list->content && ft_lstlast(list)->content < i)
		return (0);
	list = list->next;
	pos = 1;
	while (list != NULL)
	{
		if (((list->prev)->content < i && i < list->content)
			|| (list->content == ft_minlst(list)
				&& (i < ft_minlst(list) || ft_maxlst(list) < i)))
			return (pos);
		pos++;
		list = list->next;
	}
	return (pos);
}

static int	ft_set_ops(int size_a, int size_b, int *pos_b, int *pos_in_a)
{
	if (size_a / 2 < *pos_b && size_b / 2 < *pos_in_a)
	{
		*pos_b = size_a - *pos_b;
		*pos_in_a = size_b - *pos_in_a;
	}
	if (*pos_b <= *pos_in_a)
		return (*pos_in_a);
	else
		return (*pos_b);
}

int	ft_count_ops_small(int pos_b, t_list *current,
	t_list **list_a, t_list **list_b)
{
	int	ops;
	int	pos_in_a;

	pos_in_a = ft_pos_in_a(*list_a, current->content);
	if ((pos_b <= ft_lstsize(*list_a) / 2
			&& pos_in_a <= ft_lstsize(*list_b) / 2)
		|| (ft_lstsize(*list_a) / 2 < pos_b
			&& ft_lstsize(*list_b) / 2 < pos_in_a))
		ops = ft_set_ops(ft_lstsize(*list_a), ft_lstsize(*list_b),
				&pos_b, &pos_in_a);
	else
	{
		if (pos_b <= ft_lstsize(*list_a) / 2
			&& ft_lstsize(*list_b) / 2 < pos_in_a)
			ops = pos_b + ft_lstsize(*list_b) - pos_in_a;
		else
			ops = ft_lstsize(*list_a) - pos_b + pos_in_a;
	}
	return (ops);
}

t_list	*ft_best_move_small(t_list **list_a, t_list **list_b)
{
	int		i;
	int		least_ops;
	t_list	*current;
	t_list	*best;

	if (ft_lstsize(*list_b) == 1)
		return (*list_b);
	least_ops = ft_lstsize(*list_a) + ft_lstsize(*list_b);
	current = *list_b;
	i = 0;
	while (current != NULL)
	{
		if (ft_count_ops_small(i, current, list_a, list_b) < least_ops)
		{
			best = current;
			least_ops = ft_count_ops_small(i, current, list_a, list_b);
		}
		current = current->next;
		i++;
	}
	return (best);
}
