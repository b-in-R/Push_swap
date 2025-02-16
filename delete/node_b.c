/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:03:53 by rabiner           #+#    #+#             */
/*   Updated: 2025/02/11 23:19:56 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node_b	*create_b(int value)
{
	t_node_b	*newnode;
	
	newnode = (t_node_b*)malloc(sizeof(t_node_b));
	if(newnode == NULL)
	{
		ft_printf("Error");
		return (NULL);
	}
	newnode->data = value;
	newnode->next = NULL;
	return (newnode);
}

t_node_b	*insert_head_b(t_node_b *head, int value)
{
	t_node_b	*newnode;
	
	newnode = create_b(value);
	if (newnode == NULL)
	{
		//ft_printf("Error"); a voir
		return head;
	}
	newnode->next = head;
	head = newnode;
	return (head);
}

t_node_b	*insert_bot_b(t_node_b *head, int value)
{
	t_node_b	*newnode;
	t_node_b	*current;

	newnode = create_b(value);
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

t_node_b *del_node_b(t_node_b *head, int value)
{
	t_node_b	*current;
	t_node_b	*temp;

	if (head == NULL)
		return (NULL);
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