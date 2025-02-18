/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:19 by raphael           #+#    #+#             */
/*   Updated: 2025/02/18 21:54:52 by raphael          ###   ########.fr       */
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
int ft_wich_bit(int n, int pos)
{
	int bit;
	
	bit = ((n >> pos) & 1);
	return (bit);
}

void    ft_logic(t_list_ps **list_a)
{
	t_list_ps	*list_b;
	t_list_ps	**temp;
	int     	pos;
	// pas ici		char    	*operation;// pour print l'operateur utilise
	
	//				operation = NULL;
	list_b = NULL;
	pos = 0;
	while (pos < 4)// a corriger
	{
		temp = list_a;
		while (*temp)
		{
			if (ft_wich_bit((*temp)->value, pos) == 0)
				ft_swap(temp, &list_b, 1);
			else
				temp = &((*temp)->next);
		}
		// retour sur list_a --> ok
		while (list_b)
			ft_swap(&list_b, list_a, 1);
		pos++;
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