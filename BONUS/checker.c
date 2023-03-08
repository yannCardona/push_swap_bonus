/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:30:06 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/08 22:34:30 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exec_op_rot(char *move, t_list **list_a, t_list **list_b)
{
	if (ft_strcomp(move, "ra\n") == 1)
		ft_rotate(list_a);
	else if (ft_strcomp(move, "rb\n") == 1)
		ft_rotate(list_b);
	else if (ft_strcomp(move, "rr\n") == 1)
	{
		ft_rotate(list_a);
		ft_rotate(list_b);
	}
	else if (ft_strcomp(move, "rra\n") == 1)
		ft_rotate_r(list_a);
	else if (ft_strcomp(move, "rrb\n") == 1)
		ft_rotate_r(list_b);
	else if (ft_strcomp(move, "rrr\n") == 1)
	{
		ft_rotate_r(list_a);
		ft_rotate_r(list_b);
	}
}

static void	exec_op_p_s(char *move, t_list **list_a, t_list **list_b)
{
	if (ft_strcomp(move, "sa\n") == 1)
		ft_swap(list_a);
	else if (ft_strcomp(move, "sb\n") == 1)
		ft_swap(list_b);
	else if (ft_strcomp(move, "ss\n") == 1)
	{
		ft_swap(list_a);
		ft_swap(list_b);
	}
	else if (ft_strcomp(move, "pa\n") == 1)
		ft_push(list_a, list_b);
	else if (ft_strcomp(move, "pb\n") == 1)
		ft_push(list_b, list_a);
}

static void	no_operation(char *move, t_list **list_a, t_list **list_b)
{
	if (ft_strcomp(move, "sa\n") != 1 && ft_strcomp(move, "sb\n") != 1
		&& ft_strcomp(move, "ss\n") != 1 && ft_strcomp(move, "pa\n") != 1
		&& ft_strcomp(move, "pb\n") != 1 && ft_strcomp(move, "ra\n") != 1
		&& ft_strcomp(move, "rb\n") != 1 && ft_strcomp(move, "rr\n") != 1
		&& ft_strcomp(move, "rra\n") != 1 && ft_strcomp(move, "rrb\n") != 1
		&& ft_strcomp(move, "rrr\n") != 1)
	{
		write(2, "ERROR\n", 6);
		ft_free(list_a);
		ft_free(list_b);
		exit(1);
	}
}

static void	ft_free_ab(t_list **list_a, t_list **list_b)
{
	ft_free(list_a);
	ft_free(list_b);
}

int	main(int argc, char *argv[])
{
	t_list	**list_a;
	t_list	**list_b;
	char	*move;

	list_a = malloc(sizeof(list_a));
	list_b = malloc(sizeof(list_b));
	if (ft_ini_list_bonus(list_a, argc, argv) == 0)
	{
		ft_free_ab(list_a, list_b);
		exit(1);
	}
	move = get_next_line(0);
	while (move != NULL)
	{
		exec_op_rot(move, list_a, list_b);
		exec_op_p_s(move, list_a, list_b);
		no_operation(move, list_a, list_b);
		move = get_next_line(0);
	}
	if (ft_is_ascending(*list_a) == 1 && ft_lstsize(*list_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_ab(list_a, list_b);
}
