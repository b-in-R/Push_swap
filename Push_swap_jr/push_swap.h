/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:24:23 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/24 17:11:19 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int		intchecker(char *number);
void	printerror(void);
void	lstcreator(int ac, char **av);
int		*tabint(int ac, char **av, int *len);
void	freetab(char **tab, int ac);
t_node	*ft_node_create_new(int value);
void	ft_node_insert_to_end(t_node **head, t_node *newnode);
int		ft_node_length(t_node *head);

void	pusha(t_node **stacka, t_node **stackb);
void	pushb(t_node **stacka, t_node **stackb);
void	push(t_node **src, t_node **dest);
void	rev(t_node **stack);
void	rra(t_node **stack);
void	rrb(t_node **stackb);
void	rrr(t_node **stacka, t_node **stackb);
void	swap(t_node **stack);
void	sa(t_node **stacka);
void	sb(t_node **stackb);
void	ss(t_node **stacka, t_node **stackb);
void	rotate(t_node **stack);
void	ra(t_node **stacka);
void	rb(t_node **stackb);
void	rr(t_node **stacka, t_node **stackb);
t_node	*getbottomnode(t_node *stack);

void	test_operations(void);
void	tinysort(t_node **head);
void	find_extreme_nodes(t_node *head, t_node **smallest, t_node **biggest);
int		sortedlist(t_node *head);
void	bigsort(t_node **head, t_node **stackb);
void	freelink(t_node **head);
t_node	*findminnode(t_node *head);
t_node	*findmaxnode(t_node *head);
void	simplifier(t_node *head);
t_node	*findnodebyvalue(t_node *head, int value);
t_node	*findnodebyindex(t_node *head, int index);
void	radix(t_node **stacka, t_node **stackb);

int		findmaxindex(t_node *head);
int		findminindex(t_node *head);
void	radix_sort(t_node **stacka, t_node **stackb);
void	distribute_elements(t_node **stacka, t_node **stackb, int exp);
void	sortfive(t_node **head);
void	ft_node_print_list(t_node *head, char car);
void	notsorted(int len, t_node **head, t_node **stackb);
#endif
