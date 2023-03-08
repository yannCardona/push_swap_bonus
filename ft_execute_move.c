/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:40:55 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/08 20:44:04 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ex_rot_ab(int pos_a, int pos_b, t_list **list_a, t_list **list_b)
{
	int	i;

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

static void	ex_rev_rot_ab(int pos_a, int pos_b,
	t_list **list_a, t_list **list_b)
{
	int	i;

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

static void	ex_rot_revrot(int pos_a, int pos_b,
	t_list **list_a, t_list **list_b)
{
	int	i;

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

static void	ex_revrot_rot(int pos_a, int pos_b,
	t_list **list_a, t_list **list_b)
{
	int	i;

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

void	ft_execute_move(t_list *move, t_list **list_a, t_list **list_b)
{
	int		pos_a;
	int		pos_b;
	t_list	*current;

	pos_a = 0;
	current = *list_a;
	while (current->content != move->content)
	{
		current = current->next;
		pos_a++;
	}
	pos_b = ft_pos_in_b(*list_b, move->content);
	if (pos_a <= ft_lstsize(*list_a) / 2 && pos_b <= ft_lstsize(*list_b) / 2)
		ex_rot_ab(pos_a, pos_b, list_a, list_b);
	else if (ft_lstsize(*list_a) / 2 < pos_a && ft_lstsize(*list_b) / 2 < pos_b)
		ex_rev_rot_ab(pos_a, pos_b, list_a, list_b);
	else if (pos_a <= ft_lstsize(*list_a) / 2
		&& ft_lstsize(*list_b) / 2 < pos_b)
		ex_rot_revrot(pos_a, pos_b, list_a, list_b);
	else if (ft_lstsize(*list_a) / 2 < pos_a
		&& pos_b <= ft_lstsize(*list_b) / 2)
		ex_revrot_rot(pos_a, pos_b, list_a, list_b);
	ft_push_b(list_a, list_b);
}
