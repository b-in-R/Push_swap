/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:19 by raphael           #+#    #+#             */
/*   Updated: 2025/02/26 22:01:41 by raphael          ###   ########.fr       */
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
	printf("nbr_bit: %i\n", nbr_bit);
	return (nbr_bit);
}

void    ft_logic(t_list_ps **list_a)
{
	t_list_ps	*list_b;
	t_list_ps	**temp;
	int     	pos;
	int			nbr_bit;
	// pas ici		char    	*operation;// pour print l'operateur utilise
	
	//				operation = NULL;
	PL();
	list_b = NULL;
	pos = 0;
	nbr_bit = ft_nbr_bit(*list_a);// ici
	while (pos <= nbr_bit)
	{
		print_list(*list_a);
		temp = list_a;
		while (*temp)
		{
			if (((*temp)->value >> pos & 1) == 0)
			//if (ft_wich_bit((*temp)->value, pos) == 0)// si 0 -> list_b, si 1 -> next
				ft_swap(temp, &list_b, 1);// ft_node.c
			else
				temp = &((*temp)->next);
		}
		// retour sur list_a --> ok
		while (list_b)
			ft_swap(&list_b, list_a, 1);
		pos++;
			print_list(*temp);		
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