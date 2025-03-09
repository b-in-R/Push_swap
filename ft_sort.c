/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:52:17 by rabiner           #+#    #+#             */
/*   Updated: 2025/03/01 18:12:18 by raphael          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	ft_start(char **av, t_list_ps **list_a, int start)
{
	int	i;
	int	temp;

	i = start;
	temp = 0;
	while (av[i])
	{
		temp = ft_atoi(av[i++]);
		ft_add_back(list_a, ft_create(temp));
	}
}

int	check_double(t_list_ps *list_a)
{
	t_list_ps	*temp;

	while (list_a && list_a->next)
	{
		temp = list_a->next;
		while (temp)
		{
			if (list_a->value == temp->value)
				return (0);
			temp = temp->next;
		}
		list_a = list_a->next;
	}
	return (1);
}

int	check_sort(t_list_ps *list_a)
{
	if (!list_a)
		return (0);
	while (list_a->next != NULL)
	{
		if (list_a->value > list_a->next->value)
			return (0);
		list_a = list_a->next;
	}
	return (1);
}

void	ft_sort(int ac, char **av, int start)
{
	t_list_ps	*list_a;

	list_a = NULL;
	ft_start(av, &list_a, start);
	if (check_double(list_a) == 0)
	{
		write(2, "Error\n", 6);
		return ;
	}
	ft_copy_list(list_a, ac);

	if (check_sort(list_a) != 1)// ici
	{
		ft_logic(&list_a);
	}
	return ;
}

