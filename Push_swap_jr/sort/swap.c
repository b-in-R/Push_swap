/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:58 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/24 15:51:24 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node **stack)
{
	t_node	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

// switch top 2 on a
void	sa(t_node **stacka)
{
	ft_printf("sa\n");
	swap(stacka);
}

// switch top 2 on b
void	sb(t_node **stackb)
{
	ft_printf("sb\n");
	swap(stackb);
}

// switch top 2 on a and b
void	ss(t_node **stacka, t_node **stackb)
{
	swap(stacka);
	swap(stackb);
	ft_printf("ss\n");
}
