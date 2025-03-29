/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:50:16 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/23 12:01:10 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_node **head, int a_index, int b_index, int c_index)
{
	if (a_index < b_index)
	{
		if (a_index > c_index)
			rra(head);
		else if (b_index > c_index)
		{
			rra(head);
			sa(head);
		}
	}
	else
	{
		if (a_index < c_index)
			sa(head);
		else if (b_index < c_index)
			ra(head);
		else
		{
			sa(head);
			rra(head);
		}
	}
}

void	tinysort(t_node **head)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	if (sortedlist(*head))
		return ;
	a = *head;
	b = a->next;
	c = b->next;
	sort_three(head, a->index, b->index, c->index);
}
