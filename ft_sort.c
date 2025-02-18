/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:52:17 by rabiner           #+#    #+#             */
/*   Updated: 2025/02/18 21:21:12 by raphael          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	ft_start(char **av, t_list_ps *list_a)
{
	int	i;
	int	temp;

	i = 1;
	temp = 0;
	while (av[i])
	{
		temp = ft_atoi(av[i++]);// chaque nombre en int
		ft_add_back(&list_a, ft_create(temp));
	}
	ft_printf("start: \t\t");// pour test
	print_list(list_a);// pour test
}


/*//		MEME FNC OPTIMISEE QU'EN BAS
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
*/
int	check_double(t_list_ps *list_a)
{
	t_list_ps	*temp;
	int			sto;
	
	temp = list_a;
	sto = 0;
	while (list_a && list_a->next != NULL)
	{
		sto = list_a->value;
		while (temp->next != NULL)
		{
			if (sto == temp->next->value)
				return (0);
			temp = temp->next;
		}
		list_a = list_a->next;
		temp = list_a;
	}
	return (1);
}

int	check_sort(t_list_ps *list_a)
{
	while (list_a && list_a->next)
	{
		if (list_a->value > list_a->next->value)
		{
			return (0);
		}
		list_a = list_a->next;
	}
	return (1);
}

void	ft_sort(int ac, char **av)
{
	t_list_ps	*list_a;

	list_a = NULL;
	(void)ac;
	ft_start(av, list_a);
	if (ft_check_double(list_a) == 0)
	{
		ft_printf("Error\n");
		return ;
	}
	while (check_sort(list_a) != 1)
	{
		ft_logic(&list_a);
	}
	//while ()
		// envoyer dans atoi (const char *str) --> ok dans ft_start_sort
		// check si plusieurs fois le meme nbr -> Error --> ok
		// envoyer chaque nombre dans list_a add_back --> ok
	// retourne a push_swap.c -> main > fin
}