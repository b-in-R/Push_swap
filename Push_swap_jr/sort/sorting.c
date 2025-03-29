/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/24 17:24:47 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//return a node by it's value
t_node	*findnodebyvalue(t_node *head, int value)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->value == value)
			return (current);
		current = current->next;
	}
	return (NULL);
}

// add index from 1 to x to the list
void	simplifier(t_node *head)
{
	int		index;
	int		max;
	t_node	*smallest;

	index = 1;
	max = ft_node_length(head);
	while (index <= max)
	{
		smallest = findminnode(head);
		if (smallest != NULL)
		{
			smallest->index = index;
			index++;
		}
		else
			break ;
	}
}

//return 1 if the list is sorted, else 0
int	sortedlist(t_node *head)
{
	t_node	*current;

	current = head;
	while (current && current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
