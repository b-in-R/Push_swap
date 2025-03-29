/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:47 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/23 17:20:58 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_node **head)
{
	t_node	*tmp;
	t_node	*bottom;

	if (!head || !(*head) || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	bottom = getbottomnode(*head);
	tmp->next = NULL;
	bottom->next = tmp;
	bottom = getbottomnode(*head);
}

void	ra(t_node **stacka)
{
	rotate(stacka);
	ft_printf("ra\n");
}

void	rb(t_node **stackb)
{
	rotate(stackb);
	ft_printf("rb\n");
}

void	rr(t_node **stacka, t_node **stackb)
{
	ra(stacka);
	rb(stackb);
	ft_printf("rr\n");
}
