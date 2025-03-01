/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:52:17 by rabiner           #+#    #+#             */
/*   Updated: 2025/03/01 17:48:26 by raphael          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	ft_start(char **av, t_list_ps **list_a)
{
	int	i;
	int	temp;

	i = 1;
	temp = 0;
	while (av[i])
	{
		temp = (int)strtol(av[i++], NULL, 10);//testA
		//testAtemp = ft_atoi(av[i++]);// chaque nombre en int
		ft_add_back(list_a, ft_create(temp));
	}
	print_list(list_a);// pour test
}


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
	if (!list_a)
	{
		printf("--- erreur !list_a ---\n");
		return 0;
	}
	while (list_a->next != NULL)
	{
		if (list_a->value > list_a->next->value)
		{
	
			//printf("check_sort: 'list_a->value' > 'list_a->next->value'!\n");
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
	ft_start(av, &list_a);// ici
	if (check_double(list_a) == 0)// ici
	{
		printf("Error\n");//test
		//ft_printf("Error\n");// ./libft/ft_printf.c/
		return ;
	}
	// CONDITION A CORRIGER: ACTUEL: des que 2 noeud sont dans l'ordre, checksort return 1
	//while (check_sort(list_a) != 1)// ac < 3 &&		pour test
	if (check_sort(list_a) != 1)
	{
		// -----------------appel fonction tri-------------
		printf("ft_sort pas trie-> vers logic\n");//test
		ft_logic(&list_a);
		
		//ac++;//testA
		//testAft_logic(&list_a); // ft_logic.c
	}
	print_list(&list_a);
	printf("ft_sort ok\n");
	//while ()
		// envoyer dans atoi (const char *str) --> ok dans ft_start_sort
		// check si plusieurs fois le meme nbr -> Error --> ok
		// envoyer chaque nombre dans list_a add_back --> ok
	// retourne a push_swap.c -> main > fin
}

/*
	----	appels de fonctions pour tests:		----

	strtol (atoi):		temp = (int)strtol(av[i++], NULL, 10);

*/


/*	//		MEME FNC OPTIMISEE QUE CHECK_DOUBLE
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