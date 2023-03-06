/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:52:42 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/06 13:40:58 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list **list)
{
	t_list	*temp;

	temp = *list;
	while (temp != NULL)
	{
		temp = temp->next;
		free(*list);
		*list = temp;
	}
	free(list);
}

int	ft_no_doubles(t_list *list)
{
	t_list	*current;

	while (list -> next != NULL)
	{
		current = list -> next;
		while (current != NULL)
		{
			if (list -> content == current -> content)
			{
				write(2, "ERROR\n", 6);
				return (0);
			}
			current = current -> next;
		}
		list = list -> next;
	}	
	return (1);
}

void	ft_del_max(t_list **list)
{
	t_list	*current;

	while ((*list)->content != ft_maxlst(*list))
		ft_rotate(list);
	current = *list;
	free(*list);
	(current->next)->prev = NULL;
	*list = current->next;
}

void	ft_del_min(t_list **list)
{
	t_list	*current;

	while ((*list)->content != ft_minlst(*list))
		ft_rotate(list);
	current = *list;
	free(*list);
	(current->next)->prev = NULL;
	*list = current->next;
}

void	ft_copy_lst(t_list *list, t_list **copy)
{
	t_list	*new;

	*copy = NULL;
	while (list != NULL)
	{
		new = ft_lstnew(list->content);
		ft_lstadd_back(copy, new);
		list = list -> next;
	}
}
