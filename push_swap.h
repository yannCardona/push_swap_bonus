/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycardona <ycardona@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:30:42 by ycardona          #+#    #+#             */
/*   Updated: 2023/03/08 21:01:01 by ycardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int i);
t_list		*ft_best_move(t_list **list_a, t_list **list_b, int pivot);
t_list		*ft_best_move_small(t_list **list_a, t_list **list_b);
int			ft_lstsize(t_list *lst);
int			ft_isdigit(int c);
int			ft_max_ab(int a, int b);
int			ft_min_ab(int a, int b);
int			ft_no_doubles(t_list *list);
int			ft_isnumeric(char *str);
int			ft_is_ascending(t_list *list);
int			ft_is_descending(t_list *list);
int			ft_maxlst(t_list *list);
int			ft_minlst(t_list *list);
int			ft_pivot(t_list *list);
int			ft_pos_in_b(t_list *list, int i);
int			ft_pos_in_a(t_list *list, int i);
int			ft_count_ops(int i, t_list *current, t_list **list_a,
				t_list **list_b);
int			ft_count_ops_small(int pos_b, t_list *current,
				t_list **list_a, t_list **list_b);
int			ft_ini_list(t_list **list_a, int argc, char *argv[]);
long long	ft_atoi(const char *str);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_free(t_list **list);
void		ft_del_max(t_list **list);
void		ft_del_min(t_list **list);
void		ft_copy_lst(t_list *list, t_list **copy);
void		ft_swap_a(t_list **list_a);
void		ft_swap_b(t_list **list_b);
void		ft_swap_ab(t_list **list_a, t_list **list_b);
void		ft_swap(t_list **list);
void		ft_push_a(t_list **list_a, t_list **list_b);
void		ft_push_b(t_list **list_a, t_list **list_b);
void		ft_push(t_list **list_a, t_list **list_b);
void		ft_rotate(t_list **list);
void		ft_rotate_a(t_list **list_a);
void		ft_rotate_b(t_list **list_b);
void		ft_rotate_ab(t_list **list_a, t_list **list_b);
void		ft_rotate_r(t_list **list);
void		ft_rotate_r_a(t_list **list_a);
void		ft_rotate_r_b(t_list **list_b);
void		ft_rotate_r_ab(t_list **list_a, t_list **list_b);
void		ft_execute_move(t_list *move, t_list **list_a, t_list **list_b);
void		ft_first_move(t_list **list_a, t_list **list_b, int pivot);
void		ft_sort_3(t_list **list_a);
void		push_swap(t_list **list_a, t_list **list_b);
void		push_swap_small(t_list **list_a, t_list **list_b);
void		ft_execute_move_b(t_list *move, t_list **list_a, t_list **list_b);

#endif
