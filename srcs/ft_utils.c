/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binr <binr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:48:19 by binr              #+#    #+#             */
/*   Updated: 2025/05/02 12:27:54 by binr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_list(t_list_ps *lst)
{
	t_list_ps	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_exit_error(char **str, t_list_ps *lst, int free_s, int free_l)
{
	if (free_s == 1)
		ft_free_str(str);
	if (free_l == 1)
		ft_free_list(lst);
	write(2, "Error\n", 6);
	exit(1);
}
