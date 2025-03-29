/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkedlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:50:16 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/24 16:42:02 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find the max index in the linked list and return it
t_node	*getbottomnode(t_node *stack)
{
	t_node	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

// return a node with value from input
t_node	*ft_node_create_new(int value)
{
	t_node		*result;

	result = malloc(sizeof(t_node));
	if (!result)
		return (NULL);
	result->value = value;
	result->index = 0;
	result->next = NULL;
	return (result);
}

// insert a node at the end of the linked list
void	ft_node_insert_to_end(t_node **head, t_node *newnode)
{
	t_node	*current;

	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newnode;
	}
}

//return the length of the linked list
int	ft_node_length(t_node *head)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

// return a node at input index
t_node	*get_node_at_index(t_node *head, int index)
{
	t_node	*current;
	int		i;

	current = head;
	i = 0;
	while (i < index)
	{
		current = current->next;
		if (current == head)
			return (NULL);
		i++;
	}
	return (current);
}
