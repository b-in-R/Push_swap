/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binr <binr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:56:20 by binr              #+#    #+#             */
/*   Updated: 2025/05/02 16:45:58 by binr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pushing_mins_else(t_list_ps **a, t_list_ps **b)
{
	int	count;

	count = 0;
	while (count < 2)
	{
		if ((*a)->index == 1 || (*a)->index == 2)
		{
			ft_push(a, b, 1);
			ft_printf("pb\n");
			count++;
		}
		else
			ft_r_rotate(a);
	}
}

void	pushing_mins(t_list_ps **a, t_list_ps **b, int *pos)
{
	int	count;

	count = 0;
	if ((pos[3] == 1 || pos[3] == 2) && (pos[4] == 1 || pos[4] == 2))
	{
		while (count < 2)
		{
			if ((*a)->index == 1 || (*a)->index == 2)
			{
				ft_push(a, b, 1);
				ft_printf("pb\n");
				count++;
			}
			else
				ft_r_rotate(a);
		}
	}
	else
		pushing_mins_else(a, b);
}

void	extract_two_mins(t_list_ps **a, t_list_ps **b)
{
	t_list_ps	*tmp;
	int			pos[5];
	int			i;

	tmp = *a;
	i = 0;
	ft_memset(pos, 0, 5);
	while (tmp)
	{
		pos[i++] = tmp->index;
		tmp = tmp->next;
	}
	pushing_mins(a, b, pos);
}

void	extract_one_min(t_list_ps **a, t_list_ps **b)
{
	t_list_ps	*tmp;
	int			pos;

	tmp = *a;
	pos = 0;
	while (tmp->index != 1)
	{
		pos++;
		tmp = tmp->next;
	}
	while ((*a)->index != 1 && pos == 3)
		ft_r_rotate(a);
	while ((*a)->index != 1 && pos < 3)
		ft_rotate(a, 1);
	ft_push(a, b, 1);
}

void	sort_five(t_list_ps **lst, t_logic *val)
{
	t_list_ps	*list_a;
	t_list_ps	*list_b;

	list_a = *lst;
	list_b = NULL;
	if (val->len == 4)
	{
		extract_one_min(&list_a, &list_b);
		ft_printf("pb\n");
	}
	else if (val->len == 5)
	{
		extract_two_mins(&list_a, &list_b);
		if (ft_check_sort(list_b) == 1)
			ft_swap(&list_b, 2);
	}
	tinysort(&list_a);
	while (list_b)
	{
		ft_push(&list_b, &list_a, 1);
		ft_printf("pa\n");
	}
	*lst = list_a;
}
