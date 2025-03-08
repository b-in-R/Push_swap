/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:24:25 by raphael           #+#    #+#             */
/*   Updated: 2025/03/08 18:56:24 by raphael          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>

/*
	sa (swap a)		interverti les 2 premiers elements au sommet a
	sb (swap b)													 b
	ss (sa et sb)
	
	pa (push a)		prend le 1er au sommet de b et le met sur a
	pb (push b)								  a				  b
	
	ra (rotate a)	decale d'1 pos tous les elements de a, 1er devient dernier
	rb (rotate b)										b
	rr (ra et rb)
	
	rra (reverse rotate a)	decale d'1 pos tous les elements de a,
							dernier devient 1er
	rrb (reverse rotate b)										b
	rrr (rra et rrb)
*/

typedef struct s_list_ps
{
	int					value;
	int					num;
	struct s_list_ps	*next;
}						t_list_ps;

// -- pour tests ---
# include <stdio.h>
# include <stdlib.h>

#define PL() printf("-----\nfile: %s\nfunction: %s\nline: %d\n-----\n",\
		 __FILE__, __func__, __LINE__);

void		print_list(t_list_ps **lst);
void		print_lst_num(t_list_ps **lst);

// -----------------


void		ft_sort(int ac, char **av, int start);
void		ft_start(char **av, t_list_ps **list_a, int start);
int			check_double(t_list_ps *list_a);
int			check_sort(t_list_ps *list_a);

t_list_ps	*ft_create(int value);
void		ft_add_front(t_list_ps **lst, t_list_ps *new);
void		ft_add_back(t_list_ps **lst, t_list_ps *new);
void		ft_swap(t_list_ps **src, t_list_ps **dest, int front);
// inutile?		void		ft_del_node(t_list_ps **lst, int value);

void		ft_logic(t_list_ps **list_a);
int			ft_nbr_bit(t_list_ps *list_a);// uniquement ft_logic?
t_list_ps	copy_list(t_list_ps **list_a);// uniquement ft_logic?


// inutile		void	push_a(t_list_ps *list_a, t_list_ps *list_b);
// inutile		void	push_b(t_list_ps *list_a, t_list_ps *list_b);

#endif