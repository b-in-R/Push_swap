/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:52:17 by rabiner           #+#    #+#             */
/*   Updated: 2025/03/08 20:11:53 by raphael          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

//////////////////////////////////////////////////////////////////////////////
//																			//
//////////////////////////////////////////////////////////////////////////////

// ok
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

// ok 
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

// ok
void	ft_add_front(t_list_ps **lst, t_list_ps *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// ok
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

void	print_lst_num(t_list_ps **lst)
{
	t_list_ps	*current;
	
	if (!lst || !*lst)
		return;
	current = *lst;
	while (current)
	{
		printf("%d -> ", current->num);
		current = current->next;
	}
	printf("NULL\n");
}

void	print_list(t_list_ps **lst)
{
	t_list_ps	*current;
	
	if (!lst || !*lst)
	{
		return;
	}
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
//	printf("nbr_bit: %i\n", nbr_bit);
	return (nbr_bit);
}

void    ft_logic(t_list_ps **list_a)
{
	t_list_ps	*list_b;
	t_list_ps	**temp;
	int     	pos;
	int			nbr_bit;
	int	iteration = 1;// pour test iteration
	int	operations = 0;// pour test
	
	list_b = NULL;// voir si suppr
	pos = 0;
	nbr_bit = ft_nbr_bit(*list_a);
/*
	printf("Depart:");
	printf("\nlist_a:\t\t");
	print_list(list_a);
	printf("list_a->num\t");
	print_lst_num(list_a);
	printf("\nlist_b:\t\t");
	print_list(&list_b);
	printf("\nlist_b->num\t");
	print_lst_num(&list_b);
	printf("\n");
*/
	
	while (pos <= nbr_bit)
	{
//		print_lst_num(list_a);// pour test
		temp = list_a;
//		printf("\niteration %i\n\n", iteration);// pour test
		iteration++;// pour test
		while (*temp)
		{
			if (((*temp)->num >> pos & 1) == 0)//if (ft_wich_bit((*temp)->value, pos) == 0)// si 0 -> list_b, si 1 -> next
			{
				printf("pb\n");// pour test
				operations++;// pour test
				ft_swap(temp, &list_b, 1);// ft_node.c
			}
			else
			{
				printf("ra\n");// pour test
				temp = &((*temp)->next);
				operations++;// pour test
			}
		}
/*		// retour sur list_a --> ok
		printf("\n-----\nAvant tri:");
		printf("\nlist_a:\t\t");
		print_list(list_a);
		printf("list_a->num\t");
		print_lst_num(list_a);
		printf("\nlist_b:\t\t");
		print_list(&list_b);
		printf("list_b->num\t");
		print_lst_num(&list_b);
		printf("\n");
*/

		while (list_b)
		{
			printf("pa\n");// pour test
			ft_swap(&list_b, list_a, 1);
			operations++;// pour test
		}
		pos++;
/*
		printf("\n---------\nApres tri:");
		printf("\nlist_a:\t\t");
		print_list(list_a);
		printf("list_a->num\t");
		print_lst_num(list_a);
		printf("\nlist_b:\t\t");
		print_list(&list_b);
		printf("\nlist_b->num:\t");
		print_lst_num(&list_b);
		printf("\n");
//		print_list(temp);// pour test
*/
		if (check_sort(*list_a) == 1)
		{
			//printf("\n\noperations: %i\n\n", operations);// pour test
			return ;
		}
		//			ft_printf("%s\n", operation);// emplacement a voir
	}
}

//////////////////////////////////////////////////////////////////////////////////
//																				//
//////////////////////////////////////////////////////////////////////////////////

void	ft_start(char **av, t_list_ps **list_a, int start)
{
	int	i;
	int	temp;

	i = start;
	temp = 0;
	while (av[i])
	{
		temp = (int)strtol(av[i++], NULL, 10);//testA
		//testAtemp = ft_atoi(av[i++]);// chaque nombre en int
		ft_add_back(list_a, ft_create(temp));
	}
//	print_list(list_a);// pour test
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

// ok
int	check_sort(t_list_ps *list_a)
{
	if (!list_a)
	{
//		printf("--- erreur !list_a ---\n");
		return 0;
	}
	while (list_a->next != NULL)
	{
		if (list_a->value > list_a->next->value)
			return (0);
		list_a = list_a->next;
	}
	return (1);
}

//-------------------------	A VOIR	--------------


// ok
void	swap_next(t_list_ps **list_copy)
{
	t_list_ps	*first;
	t_list_ps	*second;

	first = *list_copy;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list_copy = second;
}

// ok
void	sort_copy(t_list_ps **list_copy, int ac)
{
	t_list_ps	**temp;

	while (check_sort(*list_copy) != 1)
	{
		temp = list_copy;
		while ((*temp) && (*temp)->next && ac > 1)
		{
			if ((*temp)->value > (*temp)->next->value)
				swap_next(temp);
			temp = &((*temp)->next);
		}
		ac--;
	}
}

void	allocate_num(t_list_ps **list)
{
	t_list_ps	*temp;
	int			i;

	temp = *list;
	i = 0;
	while (temp)
	{
		temp->num = i;
		i++;
		temp = temp->next;
	}
}


void	ft_copy_list(t_list_ps *list_a, int ac)
{
	t_list_ps	*list_copy;
	t_list_ps	*node_act;
	t_list_ps	*head_a;

	// creation list_copy selon list_a
	list_copy = NULL;
	head_a = list_a;
	while (list_a)
	{
		node_act =  ft_create(list_a->value);
		if (!node_act)
			return ;
		ft_add_back(&list_copy, node_act);
		list_a = list_a->next;
	}
	
	//tri list_copy et attribution list_copy->num
	sort_copy(&list_copy, ac);
	allocate_num(&list_copy);
	

	
	//attribution list_a->num selon list_copy->num
	while (list_copy)
	{
		while (list_a)
		{
			if (list_copy->value == list_a->value)
			{
				list_a->num = list_copy->num;
				break ;
			}
			list_a = list_a->next;
		}
		list_a = head_a;
		list_copy = list_copy->next;
	}
}

//-------------------------------------------------------

void	ft_sort(int ac, char **av, int start)
{
	t_list_ps	*list_a;

	list_a = NULL;
	ft_start(av, &list_a, start);// ici
	if (check_double(list_a) == 0)// ici
	{
		printf("Error\n");//test
		//ft_printf("Error\n");// ./libft/ft_printf.c/
		return ;
	}
	ft_copy_list(list_a, ac);

/*	printf("\nAvant tri:\nlist_a->value:\t");
	print_list(&list_a);
	printf("list_a->num:\t");
	print_lst_num(&list_a);
*/
	
	if (check_sort(list_a) != 1)
	{
		// -----------------appel fonction tri-------------
//		printf("ft_sort pas trie-> vers logic\n");//test
		ft_logic(&list_a);
	}
/*
	printf("\nApres tri:\nlist_a->value:\t");
	print_list(&list_a);
	printf("list_a->num:\t");
	print_lst_num(&list_a);
	printf("ft_sort ok\n");
*/
	//while ()
		// envoyer dans atoi (const char *str) --> ok dans ft_start_sort
		// check si plusieurs fois le meme nbr -> Error --> ok
		// envoyer chaque nombre dans list_a add_back --> ok
	// retourne a push_swap.c -> main > fin
}
/*
int	main(void)
{
	int	ac = 6;
	char	*str[] = {"./a.out", "4", "2", "6", "3", "7", (char *)0};
	char	**av = str;
	ft_sort(ac, av);
	return 0;
}
*/

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