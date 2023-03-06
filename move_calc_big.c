/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calc_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:44:22 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/05 20:15:49 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pivot(t_list *list)
{
	int		pivot;
	int		i;
	t_list	**copy;

	if (ft_lstsize(list) <= 3)
		return (ft_minlst(list));
	copy = malloc(sizeof(copy));
	ft_copy_lst(list, copy);
	i = 0;
	//if (ft_lstsize(list) <= 100)
	//{
		while (i < 2)
		{
			ft_del_max(copy);
			i++;
		}
		pivot = ft_maxlst(*copy);
	//}
/* 	else if (ft_lstsize(list) <= 250)
	{
		while (i < 199)
		{
			ft_del_max(copy);
			i++;
		}
	}
	else if (ft_lstsize(list) <= 300)
	{
		while (i < 249)
		{
			ft_del_max(copy);
			i++;
		}
	}
	else if (ft_lstsize(list) <= 350)
	{
		while (i < 299)
		{
			ft_del_max(copy);
			i++;
		}
	}
	else if (ft_lstsize(list) <= 400)
	{
		while (i < 349)
		{
			ft_del_max(copy);
			i++;
		}
	}
	else if (ft_lstsize(list) <= 450)
	{
		while (i < 399)
		{
			ft_del_max(copy);
			i++;
		}
	}
	else if (ft_lstsize(list) <= 500)
	{
		while (i < 449)
		{
			ft_del_max(copy);
			i++;
		}
	} 
	else
	{
		while (i < 95)
		{
			ft_del_max(copy);
			i++;
		}
		pivot = ft_maxlst(*copy);
	}*/
//	pivot = ft_maxlst(*copy);
	ft_free(copy);
	return (pivot);
}

int	ft_pos_in_b(t_list *list, int i)
{
	t_list	*current;
	int		pos;
	int		max;
	int		min;

	if (list == NULL)
		return (0);
	max = ft_maxlst(list);
	min = ft_minlst(list);
	if ((list->content < i && i < ft_lstlast(list)->content)
		|| (list->content == max && (max < i || i < min)))
		return (0);
	current = list->next;
	pos = 1;
	while (current != NULL)
	{
		if ((current -> content == max && (max < i || i < min))
			|| (current->content < i && i < (current->prev)->content))
			return (pos);
		pos++;
		current = current->next;
	}
	return (pos);
}

int	ft_set_ops(int size_a, int size_b, int *pos_a, int *pos_next_b)
{
	if (size_a / 2 < *pos_a
		&& size_b / 2 < *pos_next_b)
	{
		*pos_a = size_a - *pos_a;
		*pos_next_b = size_b - *pos_next_b;
	}
	if (*pos_a <= *pos_next_b)
		return (*pos_next_b);
	else
		return (*pos_a);
}

int	ft_count_ops(int pos_a, t_list *current, t_list **list_a, t_list **list_b)
{
	int	ops;
	int	pos_next_b;

	pos_next_b = ft_pos_in_b(*list_b, current->content);
	if ((pos_a <= ft_lstsize(*list_a) / 2
			&& pos_next_b <= ft_lstsize(*list_b) / 2)
		|| (ft_lstsize(*list_a) / 2 < pos_a
			&& ft_lstsize(*list_b) / 2 < pos_next_b))
		ops = ft_set_ops(ft_lstsize(*list_a), ft_lstsize(*list_b),
				&pos_a, &pos_next_b);
	else
	{
		if (pos_a <= ft_lstsize(*list_a) / 2
			&& ft_lstsize(*list_b) / 2 < pos_next_b)
			ops = pos_a + ft_lstsize(*list_b) - pos_next_b;
		else
			ops = ft_lstsize(*list_a) - pos_a + pos_next_b;
	}
	return (ops);
}

t_list	*ft_best_move(t_list **list_a, t_list **list_b, int pivot)
{
	int		i;
	int		least_ops;
	t_list	*current;
	t_list	*best;
	//int		pivot = ft_pivot(*list_a);

	least_ops = ft_lstsize(*list_a) + ft_lstsize(*list_b);
	current = *list_a;
	i = 0;
	while (current != NULL)
	{
		if (ft_count_ops(i, current, list_a, list_b) < least_ops
			&& current->content < pivot)
		{
			best = current;
			least_ops = ft_count_ops(i, current, list_a, list_b);
		}
		current = current->next;
		i++;
	}
	return (best);
}
