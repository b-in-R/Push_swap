/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:19 by raphael           #+#    #+#             */
/*   Updated: 2025/03/08 15:47:49 by raphael          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	nbr_bit(t_list_ps *list_a)
{
	int	biggest;
	int	n_bit;
	int	temp;

	biggest = 0;
	n_bit = 0;
	temp = 1;
	while (list_a)
	{
		if (list_a->num > biggest)
			biggest = list_a->value;
		list_a = list_a->next;
	}
	while (temp <= biggest)
	{
		temp *= 2;
		n_bit++;
	}
	return (n_bit);
}

void	logic_bis(t_list_ps **list_a, t_list_ps **list_b, int *p)
{
	t_list_ps	**temp;

	temp = list_a;
		while (*temp)
		{
			if (((*temp)->num >> *p & 1) == 0)
		 	{
				ft_printf("pb\n");
				ft_swap(temp, list_b, 1);
			}
			else
			{
				ft_printf("ra\n");
				temp = &((*temp)->next);
			}
		}
		while (*list_b)
		{
			ft_printf("pa\n");
			ft_swap(list_b, list_a, 1);
		}
		(*p)++;
		if (check_sort(*list_a) == 1)
			return ;
}

void    ft_logic(t_list_ps **list_a)
{
	t_list_ps	*list_b;
	int     	pos;
	int			n_bit;
	int			*p;

	list_b = NULL;
	pos = 0;
	p = &pos;
	n_bit = nbr_bit(*list_a);
	while (pos <= n_bit)
	{
		logic_bis(list_a, &list_b, p);
	}
}
