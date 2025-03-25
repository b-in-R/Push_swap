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
	int					index;
	struct s_list_ps	*next;
}						t_list_ps;

void	ft_split_free(char **tab);
int		exit_error(char **str, int need_free);

void	ft_sort(char **str);

#endif