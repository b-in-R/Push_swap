/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:22:03 by raphael           #+#    #+#             */
/*   Updated: 2025/02/11 22:46:42 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// OK
int	check_nbrs(char **av)
{
	int	i;
	int	j;
	
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] > 47 && av[i][j] < 58)
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);		
}

int	main(int ac, char **av)
{
	if (ac <= 1 || check_nbrs(av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	else
	{
		//ft_printf("ok\n"); OK
		
		
		// Ailleurs //
	/*
		if (ac <= 5)
			easy_sort(av);// voir pour renvoyer tous les chiffres
		else
			binary_sort(av);
	*/
	}
	return (0);
}