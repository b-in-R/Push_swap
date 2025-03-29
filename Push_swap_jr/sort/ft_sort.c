/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/23 17:22:43 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bigsort(t_node **head, t_node **stackb)
{
	simplifier(*head);
	radix(head, stackb);
	freelink(stackb);
}

void	notsorted(int len, t_node **head, t_node **stackb)
{
	simplifier(*head);
	len = ft_node_length(*head);
	if (len == 2)
		sa(head);
	else if (len == 3)
		tinysort(head);
	else if (len <= 5)
		sortfive(head);
	else
		bigsort(head, stackb);
}

// push the node to stack b if the bit is 1, else rotate the node

void	push_to_stackb(t_node **head, t_node **stackb, int size, int i)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if ((((*head)->index >> i) & 1) == 1)
			ra(head);
		else
			pushb(head, stackb);
		j++;
	}
}

// do the sorting using radix sort
void	radix(t_node **head, t_node **stackb)
{
	int		maxindex;
	int		bit;
	int		i;
	int		size;
	
	maxindex = findmaxindex(*head);
	bit = ft_log(maxindex, 2) + 1;
	i = 0;
	while (i < bit)
	{
		size = ft_node_length(*head);
		push_to_stackb(head, stackb, size, i);
		while (*stackb)
			pusha(head, stackb);
		i++;
	}
}
