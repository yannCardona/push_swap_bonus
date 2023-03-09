/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:27:34 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/09 14:54:50 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	**list_a;
	t_list	**list_b;

	if (argc < 2)
		return (0);
	list_a = malloc(sizeof(list_a));
	list_b = malloc(sizeof(list_b));
	if (ft_ini_list(list_a, argc, argv) == 0)
	{
		ft_free(list_a);
		ft_free(list_b);
		return (0);
	}
	if (ft_lstsize(*list_a) <= 5)
		push_swap_small(list_a, list_b);
	else
		push_swap(list_a, list_b);
	ft_free(list_a);
	ft_free(list_b);
}
