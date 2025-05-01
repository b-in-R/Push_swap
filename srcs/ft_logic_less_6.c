/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_less_6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binr <binr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:43:29 by rabiner           #+#    #+#             */
/*   Updated: 2025/05/01 17:37:04 by binr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a_by_index(t_list_ps **list_a, t_list_ps **list_b)
{
	if ((*list_b)->index == 0)
	{
		ft_push(list_b, list_a, 1);
		ft_printf("pa\n");
	}
	else if ((*list_b)->index == 1)
		sort_index_one(list_a, list_b);
	else if ((*list_b)->index == 2)
		sort_index_two(list_a, list_b);
	else if ((*list_b)->index == 3)
		sort_index_three(list_a, list_b);
	else if ((*list_b)->index == 4)
	{
		ft_push(list_b, list_a, 1);
		ft_printf("pa\n");
		ft_rotate(list_a, 1);
	}
}

void	sort_three(t_list_ps **lst, int a_index, int b_index, int c_index)
{
	if (a_index < b_index)
	{
		if (a_index > c_index)
			ft_r_rotate(lst);
		else if (b_index > c_index)
		{
			ft_r_rotate(lst);
			ft_swap(lst, 1);
		}
	}
	else
	{
		if (a_index < c_index)
			ft_swap(lst, 1);
		else if (b_index < c_index)
			ft_rotate(lst, 1);
		else
		{
			ft_swap(lst, 1);
			ft_r_rotate(lst);
		}
	}
}

void	tinysort(t_list_ps **lst)
{
	t_list_ps	*a;
	t_list_ps	*b;
	t_list_ps	*c;

	if (ft_check_sort(*lst))
		return ;
	a = *lst;
	b = a->next;
	c = b->next;
	sort_three(lst, a->index, b->index, c->index);
}

void	sort_five(t_list_ps **lst, t_logic *val)
{
	t_list_ps	*list_a;
	t_list_ps	*list_b;

	list_a = *lst;
	list_b = NULL;
	ft_push(&list_a, &list_b, 1);
	ft_printf("pb\n");
	if (val->len == 5)
	{
		ft_push(&list_a, &list_b, 1);
		ft_printf("pb\n");
		if (!ft_check_sort(list_b))
			ft_swap(&list_b, 2);
	}
	tinysort(&list_a);
	while (list_b)
		push_a_by_index(&list_a, &list_b);
	*lst = list_a;
}

t_list_ps	*ft_logic_less_6(t_list_ps **list_a, t_logic *val)
{
	if (val->len == 2)
	{
		ft_swap(list_a, 1);
		return (*list_a);
	}
	if (val->len == 3)
	{
		tinysort(list_a);
		return (*list_a);
	}
	else
	{
		sort_five(list_a, val);
		return (*list_a);
	}
}
