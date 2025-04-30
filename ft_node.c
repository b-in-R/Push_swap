/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binr <binr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:05:01 by binr              #+#    #+#             */
/*   Updated: 2025/04/30 22:05:03 by binr             ###   ########.fr       */
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

void	ft_add_front(t_list_ps **lst_dest, t_list_ps *new_node)
{
	if (!lst_dest || !new_node)
		return ;
	new_node->next = *lst_dest;
	*lst_dest = new_node;
}

void	ft_add_back(t_list_ps **lst_dest, t_list_ps *new_node)
{
	t_list_ps	*tmp;

	if (!lst_dest || !new_node)
		return ;
	if (!*lst_dest)
	{
		*lst_dest = new_node;
		return ;
	}
	tmp = *lst_dest;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return ;
}

void	ft_start_list(char **str, t_list_ps **list_a)
{
	t_list_ps	*newnode;
	int			i;
	int			temp;

	i = 0;
	temp = 0;
	while (str[i])
	{
		temp = ft_atoi(str[i++]);
		newnode = ft_create(temp);
		if (!newnode)
		{
			ft_free_list(*list_a);
			return ;
		}
		ft_add_back(list_a, newnode);
	}
}
