/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binr <binr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:44:00 by binr              #+#    #+#             */
/*   Updated: 2025/04/30 22:26:44 by binr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1 for add_front, 0 for add_back (no print)
void	ft_push(t_list_ps **src, t_list_ps **dest, int front)
{
	t_list_ps	*node;

	if (!src || !*src || !dest)
		return ;
	node = *src;
	*src = (*src)->next;
	node->next = NULL;
	if (front == 1)
		ft_add_front(dest, node);
	else
		ft_add_back(dest, node);
}

// swap 1st and 2nd nodes
void	ft_swap(t_list_ps **lst, int print_a_b)
{
	t_list_ps	*first;
	t_list_ps	*second;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	if (print_a_b == 1)
		ft_printf("sa\n");
	if (print_a_b == 2)
		ft_printf("sb\n");
}

// 1st node become last
void	ft_rotate(t_list_ps **lst, int print_a)
{
	t_list_ps	*first;
	t_list_ps	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	last = *lst;
	while (last->next)
		last = last->next;
	(*lst) = (*lst)->next;
	first->next = NULL;
	last->next = first;
	if (print_a == 1)
		ft_printf("ra\n");
}

// last node become 1st
void	ft_r_rotate(t_list_ps **lst)
{
	t_list_ps	*sec_last;
	t_list_ps	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	sec_last = *lst;
	while (sec_last->next->next)
		sec_last = sec_last->next;
	last = sec_last->next;
	last->next = (*lst);
	sec_last->next = NULL;
	*lst = last;
	ft_printf("rra\n");
}
