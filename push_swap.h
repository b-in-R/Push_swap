/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binr <binr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:33:54 by binr              #+#    #+#             */
/*   Updated: 2025/05/01 21:25:47 by binr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_list_ps
{
	int					value;
	int					index;
	struct s_list_ps	*next;
}						t_list_ps;

typedef struct s_logic
{
	int					pos;
	int					i;
	int					j;
	int					len;
}						t_logic;

//push_swap.c
int			ft_exit_error(char **str, t_list_ps *lst, int free_s, int free_l);

//ft_free.c
void		ft_free_list(t_list_ps *lst);
void		ft_free_str(char **str);

//ft_sort.c
int			ft_sort(char **str);
int			ft_check_sort(t_list_ps *list_a);

//ft_node.c
void		ft_start_list(char **str, t_list_ps **list_a);
t_list_ps	*ft_create(int value);
void		ft_add_front(t_list_ps **lst_dest, t_list_ps *new_node);
void		ft_add_back(t_list_ps **lst_dest, t_list_ps *new_node);

//ft_copy_list.c
void		ft_preprint(char *str, char *to_add, int *i);
int			ft_check_copy(t_list_ps *list_a, t_list_ps *list_copy);
void		ft_copy_list(t_list_ps *list_a, t_list_ps **list_copy);

//ft_logic.c
t_list_ps	*ft_logic(t_list_ps **list_a, t_logic *val);
int			ft_lst_len(t_list_ps *lst);

//ft_oprations.c
void		ft_push(t_list_ps **src, t_list_ps **dest, int front);
void		ft_swap(t_list_ps **lst, int print_a_b);
void		ft_rotate(t_list_ps **lst, int print_a);
void		ft_r_rotate(t_list_ps **lst);

//ft_logic_less_6.c
t_list_ps	*ft_logic_less_6(t_list_ps **list_a, t_logic *val);
void		sort_five(t_list_ps **lst, t_logic *val);
void		tinysort(t_list_ps **lst);
void		sort_three(t_list_ps **lst, int a_index, int b_index, int c_index);
void		push_a_by_index(t_list_ps **list_a, t_list_ps **list_b);

//ft_sort_index.c
void		sort_index_one(t_list_ps **list_a, t_list_ps **list_b);
void		sort_index_two(t_list_ps **list_a, t_list_ps **list_b);
void		sort_index_three(t_list_ps **list_a, t_list_ps **list_b);

#endif