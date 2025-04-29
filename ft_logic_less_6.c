/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_less_6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <rabiner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:43:29 by rabiner           #+#    #+#             */
/*   Updated: 2025/04/29 15:53:43 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

t_list_ps	*ft_logic_less_6(t_list_ps **list_a, t_logic *val)
{
	t_list_ps 	*head;
	t_list_ps	*temp;

	head = *list_a;
	temp = (*list_a)->next;
	if (val->len == 2)
	{
		while (ft_check_sort(*list_a) != 1)
		{
			ft_swap(list_a, list_a, 0);
			ft_printf("ra\n");
		}
		return (*list_a);
	}
	if (val->len == 3)
	{
		while (ft_check_sort(*list_a) != 1 && temp)
		{
			temp = (*list_a)->next;
			if ((*list_a)->value > (*list_a)->next->value)
			{
				ft_swap()
			}
		}
	}
	else
	{
		while (ft_check_sort(*list_a) != 1)
		{
			
		}
	}
}