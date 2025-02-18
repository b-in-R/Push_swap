/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:24:25 by raphael           #+#    #+#             */
/*   Updated: 2025/02/18 23:13:31 by raphael          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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
	struct s_list_ps	*next;
}						t_list_ps;

//void		print_list(t_list_ps *lst);

void		ft_sort(int ac, char **av);
void		ft_start(char **av, t_list_ps *list_a);
int			check_double(t_list_ps *list_a);
int			check_sort(t_list_ps *list_a);

t_list_ps	*ft_create(int value);
// que pour 	ft_swap?	void		ft_add_front(t_list_ps **lst, t_list_ps *new);
// que pour 	ft_swap?	void		ft_add_back(t_list_ps **lst, t_list_ps *new);
void		ft_swap(t_list_ps **src, t_list_ps **dest, int front);
// inutile?		void		ft_del_node(t_list_ps **lst, int value);

void		ft_logic(t_list_ps **list_a);
// que pour 	ft_logic?	int			ft_wich_bit(int n, int pos);

// inutile		void	push_a(t_list_ps *list_a, t_list_ps *list_b);
// inutile		void	push_b(t_list_ps *list_a, t_list_ps *list_b);

#endif