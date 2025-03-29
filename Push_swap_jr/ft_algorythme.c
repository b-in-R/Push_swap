/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/23 17:19:20 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index_two(t_node **stacka, t_node **stackb)
{
	pusha(stacka, stackb);
	sa(stacka);
}

void	sort_index_three(t_node **stacka, t_node **stackb)
{
	ra(stacka);
	ra(stacka);
	pusha(stacka, stackb);
	rra(stacka);
	rra(stacka);
}

void	sort_index_four(t_node **stacka, t_node **stackb)
{
	if (findmaxindex(*stackb) == 4 && findmaxindex(*stacka) != 5)
	{
		pusha(stacka, stackb);
		ra(stacka);
	}
	else
	{
		rra(stacka);
		pusha(stacka, stackb);
		if (findmaxindex(*stackb) == 5)
			sa(stacka);
		ra(stacka);
		ra(stacka);
	}
}

void	insert_node_by_index(t_node **stacka, t_node **stackb)
{
	int	index;

	index = (*stackb)->index;
	if (index == 1)
		pusha(stacka, stackb);
	else if (index == 2)
		sort_index_two(stacka, stackb);
	else if (index == 3)
		sort_index_three(stacka, stackb);
	else if (index == 4)
		sort_index_four(stacka, stackb);
	else if (index == 5)
	{
		pusha(stacka, stackb);
		ra(stacka);
	}
}

// sort the linked list of 5 nodes - stacka
void	sortfive(t_node **head)
{
	t_node	*stacka;
	t_node	*stackb;
	int		size;

	stacka = *head;
	stackb = NULL;
	size = ft_node_length(*head);
	pushb(&stacka, &stackb);
	if (size == 5)
	{
		pushb(&stacka, &stackb);
		if (!sortedlist(stackb))
			sb(&stackb);
	}
	tinysort(&stacka);
	while (stackb)
	{
		insert_node_by_index(&stacka, &stackb);
	}
	*head = stacka;
}
