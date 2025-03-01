/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:52:17 by rabiner           #+#    #+#             */
/*   Updated: 2025/03/01 17:45:04 by raphael          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"
#include <stdlib.h>


//////////////////////////////////////////////////////////////////////////////////
//			au dessous a effacer: fonctions des autres fichiers					//
//////////////////////////////////////////////////////////////////////////////////

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

//----------------------------------------

void	print_list(t_list_ps **lst)
{
	t_list_ps	*current;
	
	if (!lst || !*lst)
	{
		//printf("printf_list: lst ou *lst = NULL\n");
		return;
	}
	printf("\n\nprint list_a: ");
	current = *lst;
	while (current)
	{
		printf("%d -> ", current->value);
		current = current->next;
	}
	printf("NULL\n");
}

//--------------------------------------

int	ft_nbr_bit(t_list_ps *list_a)
{
	int	biggest;
	int	nbr_bit;
	int	temp;

	biggest = 0;
	nbr_bit = 0;
	temp = 1;
	while (list_a)
	{
		if (list_a->value > biggest)
			biggest = list_a->value;
		list_a = list_a->next;
	}
	while (temp <= biggest)
	{
		temp *= 2;
		nbr_bit++;
	}
	printf("nbr_bit: %i\n", nbr_bit);
	return (nbr_bit);
}

t_list_ps	copy_list(t_list_ps **list_a)// , t_list_ps **copy // a voir, + voir si on retourne un pointeur?
{
	t_list_ps	*copy;

	copy->value = (*list_a)->value;
	while (&(*list_a)->value != NULL)// a voir mais sa semble complique tout ca
	{
		
	}
}

void    ft_logic(t_list_ps **list_a)
{
	t_list_ps	*list_b;
	t_list_ps	**temp;
	//t_list_ps	*copy; //peut etre pas besoin ici, return t_list_ps
	int     	pos;
	int			nbr_bit;
	int	iteration = 1;// pour test iteration
	int	operations = 0;// pour test

	list_b = NULL;// voir si suppr
	pos = 0;
	nbr_bit = ft_nbr_bit(*list_a);
	//copy = NULL;// a voir si suppr
	//copy = copy_list(list_a, &copy);// directement copy_list (return t_list_ps)
	copy_list(list_a);
	while (pos <= nbr_bit)
	{
		print_list(list_a);// pour test
		temp = list_a;
		printf("\niteration %i\n\n", iteration);// pour test
		iteration++;// pour test
		while (*temp)
		{
			if (((*temp)->value >> pos & 1) == 0)//if (ft_wich_bit((*temp)->value, pos) == 0)// si 0 -> list_b, si 1 -> next
			{
				printf("swap B");// pour test
				operations++;// pour test
				ft_swap(temp, &list_b, 1);// ft_node.c
				printf("\n");// pour test
			}
			else
			{
				printf("rotate A\n");// pour test
				temp = &((*temp)->next);
				operations++;// pour test
			}
		}
		// retour sur list_a --> ok
		while (list_b)
		{
			printf("swap A");// pour test
			ft_swap(&list_b, list_a, 1);
			printf("\n");// pour test
			operations++;// pour test
		}
		pos++;
		print_list(temp);// pour test
		if (check_sort(*list_a) == 1)
		{
			printf("\n\noperations: %i\n\n", operations);// pour test
			return ;
		}
		//			ft_printf("%s\n", operation);// emplacement a voir
	}
}

//////////////////////////////////////////////////////////////////////////////////
//							au dessus a effacer 								//
//////////////////////////////////////////////////////////////////////////////////

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

int	main(void)
{
	int	ac = 0;
	char	*str[] = {"./a.out", "4", "2", "6", "3", "7", (char *)0};
	char	**av = str;
	ft_sort(ac, av);
	return 0;
}

/*
	----	appels de fonctions pour tests:		----

	strtol (atoi):		temp = (int)strtol(av[i++], NULL, 10);

*/


/*//		MEME FNC OPTIMISEE QUE CHECK_DOUBLE
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