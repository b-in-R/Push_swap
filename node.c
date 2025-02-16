/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:49:00 by by rabiner        #+#    #+#             */
/*   Updated: 2025/02/16 21:45:36 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps	*ft_create(int value)
{
	t_list_ps	*new;

	new = (t_list_ps *)malloc(sizeof(t_list_ps));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_add_front(t_list_ps **lst, t_list_ps *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_add_back(t_list_ps **lst, t_list_ps *new)
{
	t_list_ps	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return ;
}

// ex.appel de fonction: ft_swap(&list_a, &list_b, 42[int voulu], 1[add_front])
void	ft_swap(t_list_ps **src, t_list_ps **dest, int value, int front)
{
	t_list_ps	**node_ptr;
	t_list_ps	*current;

	node_ptr = src;
	current = *src;
	if (!src || !*src || !dest)
		return ;
	while (current && current->value != value)
	{
		node_ptr = &current->next;
		current = current->next;
	}
	if (!current)
		return ;
	*node_ptr = current->next;
	current->next = NULL;
	if (front == 1)
		ft_add_front(dest, current);
	else
		ft_add_back(dest, current);
}

// voir si possible de suppr
void	ft_del_node(t_list_ps **lst, int value)
{
	t_list_ps	*current;
	t_list_ps	*temp;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	if (temp && temp->value == value)
	{
		*lst = temp->next;
		free(temp);
		return ;
	}
	while (temp && temp->value != value)
	{
		current = temp;
		temp = temp->next;
	}
	if (!temp)
		return ;
	current->next = temp->next;
	free(temp);
	return ;
}
