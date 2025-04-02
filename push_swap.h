/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner  <marvin@42lausanne.ch>            +#+  +:+       +#+        */
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
	int					index;
	struct s_list_ps	*next;
}						t_list_ps;

int			exit_error(char **str, t_list_ps *lst);
void		ft_free_list(t_list_ps *lst);
void		ft_free_str(char **str);

int			ft_sort(char **str);

t_list_ps	*ft_create(int value);
void		ft_add_front(t_list_ps **lst, t_list_ps *new);
void		ft_add_back(t_list_ps **lst, t_list_ps *new);
void		ft_swap(t_list_ps **src, t_list_ps **dest, int front);



#endif