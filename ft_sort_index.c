/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binr <binr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:37:45 by binr              #+#    #+#             */
/*   Updated: 2025/04/30 22:27:54 by binr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_max(t_list_ps *lst)
{
	int	max;

	max = 0;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	return (max);
}

void	sort_index_one(t_list_ps **list_a, t_list_ps **list_b)
{
	ft_push(list_b, list_a, 1);
	ft_printf("pa\n");
	ft_swap(list_a, 1);
}

void	sort_index_two(t_list_ps **list_a, t_list_ps **list_b)
{
	ft_rotate(list_a, 1);
	ft_rotate(list_a, 1);
	ft_push(list_b, list_a, 1);
	ft_printf("pa\n");
	ft_r_rotate(list_a);
	ft_r_rotate(list_a);
}

void	sort_index_three(t_list_ps **list_a, t_list_ps **list_b)
{
	if (find_index_max(*list_b) == 3 && find_index_max(*list_a) != 4)
	{
		ft_push(list_b, list_a, 1);
		ft_printf("pa\n");
		ft_rotate(list_a, 1);
	}
	else
	{
		ft_r_rotate(list_a);
		ft_push(list_b, list_a, 1);
		ft_printf("pa\n");
		if (find_index_max(*list_b) == 4)
			ft_swap(list_a, 1);
		ft_rotate(list_a, 1);
		ft_rotate(list_a, 1);
	}
}
