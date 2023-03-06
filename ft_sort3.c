/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:42:30 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/01 16:07:23 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **list_a)
{
	if (ft_is_ascending(*list_a) == 1)
		return ;
	else if ((*list_a)->content == ft_maxlst(*list_a))
	{
		ft_rotate_a(list_a);
		if ((*list_a)->content != ft_minlst(*list_a))
			ft_swap_a(list_a);
	}
	else if ((*list_a)->content == ft_minlst(*list_a)
		&& ft_lstlast(*list_a)->content != ft_minlst(*list_a))
	{
		ft_rotate_r_a(list_a);
		ft_swap_a(list_a);
	}
	else if (ft_lstlast(*list_a)->content == ft_minlst(*list_a)
		&& (*list_a)->content != ft_maxlst(*list_a))
		ft_rotate_r_a(list_a);
	else if (ft_maxlst(*list_a) == ft_lstlast(*list_a)->content
		&& (*list_a)->content != ft_minlst(*list_a))
		ft_swap_a(list_a);
}
