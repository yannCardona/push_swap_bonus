/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:29:15 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/08 22:16:23 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcomp(char *str_a, char *str_b)
{
	int	i;

	i = 0;
	while (str_a[i] && str_b[i])
	{
		if (str_a[i] != str_b[i])
			return (0);
		i++;
	}
	if ((str_a[i] && !str_b[i]) || (!str_a[i] && str_b[i]))
		return (0);
	else
		return (1);
}

int	ft_ini_list_bonus(t_list **list_a, int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		return (0);
	i = 0;
	while (++i < argc)
	{
		if (ft_isnumeric(argv[i]) != 1
			|| ft_atoi(argv[i]) < INT_MIN || INT_MAX < ft_atoi(argv[i]))
		{
			write(2, "ERROR\n", 6);
			return (0);
		}
		ft_lstadd_back(list_a, ft_lstnew(ft_atoi(argv[i])));
	}
	if (ft_no_doubles(*list_a) == 0)
		return (0);
	return (1);
}
