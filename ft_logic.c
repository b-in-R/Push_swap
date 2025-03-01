/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:19 by raphael           #+#    #+#             */
/*   Updated: 2025/03/01 17:57:02 by raphael          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"


/*      ---generique, voir dessous pour adapte----
int ft_wich_bit(int n)
{
	int tot_bits;
	int i;
	int bit;

	tot_bits = (sizeof(int) * 8);// * 8 a modifier selon le nombre de bit utilise
	i = 0;
	bit = 0;
	while (i < tot_bits)
	{
		bit = ((n >> i) & 1);
		i++;
	}
	return (bit);
}
*/
/*		--- directement dans ft_logic > if (((*temp)->value >> pos & 1) == 0) ---
int ft_wich_bit(int n, int pos)
{
	int bit;
	
	bit = ((n >> pos) & 1);
	return (bit);
}
*/

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
	PL();
	printf("nbr_bit: %i\n", nbr_bit);// pour test
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


void    ft_logic(t_list_ps **list_a)// a verif annotations etc
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


/*
	- printf les operations sauf si meme ordre de la liste que precedemment
		> copier list_a complet dans list_tmp 
	
	- si le binaire cherche du noeud list_a->value == 1 : list_a->next
	- si le binaire cherche du noeud list_a->value == 0 : push b
	
	- a voir: quand trie dans b possibilite de sa et sb

	- remettre list_b dans list_a (push a) !(apres logique complem. a voir)

	- pour voir quel bit selon position i, va lire les 32 bits:
	
		int tot_bits = (sizeof(int) * 8);
		int i = 0;
		int bit = 0;
		while (i < total_bits)
		{
			bit = (n >> i) & 1; // recup bit a la position i
			i++;
		}

*/