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

typedef struct s_list_ps
{
	int					value;
	int					num;
	struct s_list_ps	*next;
}						t_list_ps;

void		ft_sort(int ac, char **av);
void		ft_start(char **av, t_list_ps **list_a);
int			check_double(t_list_ps *list_a);
int			check_sort(t_list_ps *list_a);

t_list_ps	*ft_create(int value);
void		ft_add_back(t_list_ps **lst, t_list_ps *new);
void		ft_add_front(t_list_ps **lst, t_list_ps *new);

void		ft_swap(t_list_ps **src, t_list_ps **dest, int front);

void		ft_logic(t_list_ps **list_a);

void		ft_copy_list(t_list_ps *list_a, int ac);

#endif