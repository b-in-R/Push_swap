/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:49:13 by rabiner           #+#    #+#             */
/*   Updated: 2025/02/11 23:20:49 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node_a	*create_a(int value)
{
	t_node_a	*newnode;
	
	newnode = (t_node_a*)malloc(sizeof(t_node_a));
	if(newnode == NULL)
	{
		//ft_printf("Error"); a voir
		return (NULL);
	}
	newnode->data = value;
	newnode->next = NULL;
	return (newnode);
}

t_node_a	*insert_head_a(t_node_a *head, int value)
{
	t_node_a	*newnode;
	
	newnode = create_a(value);
	if (newnode == NULL)
	{
		//ft_printf("Error"); a voir
		return head;
	}
	newnode->next = head;
	head = newnode;
	return (head);
}

t_node_a	*insert_bot_a(t_node_a *head, int value)
{
	t_node_a	*newnode;
	t_node_a	*current;

	newnode = create_a(value);
	if (newnode == NULL)
		return (head);
	if (head == NULL)
		return (newnode);
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = newnode;
	return (head);
}

t_node_a *del_node_a(t_node_a *head, int value)
{
	t_node_a	*current;
	t_node_a	*temp;

	if (head == NULL)
	{
		//ft_printf("Error"); a voir
		return (NULL);
	}
	if (head->data == value)
	{
		temp = head;
		head = head->next;
		free(temp);
		return (head);
	}
	current = head;
	while (current->next != NULL && current->next->data != value)
		current = current->next;
	if (current->next != NULL)
	{
		temp = current->next;
		current->next = temp->next;
		free(temp);
	}
	return (head);
}
