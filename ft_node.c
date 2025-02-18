/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:49:00 by by rabiner        #+#    #+#             */
/*   Updated: 2025/02/18 20:34:34 by raphael          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
// ex appel ajout noeud: 
//			ft_add_front(&list_a, ft_create(42));
//
// complet: 
// 			t_list_ps	*temp = NULL;
//			
//			temp = ft_create(42);
//			ft_add_front(&list_a, temp);


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

// ex.appel de fonction: ft_swap(&list_a, &list_b, 42, 1[add_front])
void	ft_swap(t_list_ps **src, t_list_ps **dest, int front)
{
	t_list_ps	*node;

	if (!src || !*src || !dest)
		return ;
	node = *src;
	*src = node->next;
	node->next = NULL;
	if (front == 1)
		ft_add_front(dest, node);
	else
		ft_add_back(dest, node);
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
