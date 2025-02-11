/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:24:25 by raphael           #+#    #+#             */
/*   Updated: 2025/02/11 22:50:38 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

/*
	sa (swap a)		interverti les 2 premiers elements au sommet a
	sb (swap b)													 b
	ss (sa et sb)
	
	pa (push a)		prend le 1er au sommet de b et le met sur a
	pb (push b)								  a				  b
	
	ra (rotate a)	decale d'1 pos tous les elements de a, 1er devient dernier
	rb (rotate b)										b
	rr (ra et rb)
	
	rra (reverse rotate a)	decale d'1 pos tous les elements de a, dernier devient 1er
	rrb (reverse rotate b)										b
	rrr (rra et rrb)
*/

typedef struct	s_node_a
{
	int				data;
	struct s_node_a	*next;
}	t_node_a;

typedef struct	s_node_b
{
	int				data;
	struct s_node_b	*next;
}	t_node_b;




#endif