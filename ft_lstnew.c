/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:39:28 by ycardona          #+#    #+#             */
/*   Updated: 2023/02/27 14:37:59 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int i)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head -> content = i;
	head -> next = NULL;
	head -> prev = NULL;
	return (head);
}
