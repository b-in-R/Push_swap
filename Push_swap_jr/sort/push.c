/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:33 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/24 13:53:58 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pusha(t_node **stacka, t_node **stackb)
{
	ft_printf("pa\n");
	push(stackb, stacka);
}

void	pushb(t_node **stacka, t_node **stackb)
{
	ft_printf("pb\n");
	push(stacka, stackb);
}

void	push(t_node **src, t_node **dest)
{
	t_node	*tmp;

	if (src == NULL || *src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}
