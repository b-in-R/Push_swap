/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binr <binr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:04:25 by binr              #+#    #+#             */
/*   Updated: 2025/05/01 21:26:07 by binr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	nbr_bits(t_list_ps *list_a)
{
	int	biggest;
	int	n_bit;
	int	temp;

	biggest = 0;
	n_bit = 0;
	temp = 1;
	while (list_a)
	{
		if (list_a->index > biggest)
			biggest = list_a->index;
		list_a = list_a->next;
	}
	while (temp <= biggest)
	{
		temp *= 2;
		n_bit++;
	}
	return (n_bit);
}

int	ft_lst_len(t_list_ps *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	logic_bis(t_list_ps **list_a, t_list_ps **list_b, char *result,
	t_logic *val)
{
	while (val->j < val->len)
	{
		if (((*list_a)->index >> val->pos & 1) == 0)
		{
			ft_preprint(result, "pb\n", &val->i);
			ft_push(list_a, list_b, 1);
		}
		else
		{
			ft_preprint(result, "ra\n", &val->i);
			ft_rotate(list_a, 0);
		}
		val->j++;
	}
	while (*list_b)
	{
		ft_preprint(result, "pa\n", &val->i);
		ft_push(list_b, list_a, 1);
	}
}

t_list_ps	*ft_logic(t_list_ps **list_a, t_logic *val)
{
	t_list_ps	*list_b;
	t_list_ps	*list_copy;
	char		*result;

	list_b = NULL;
	val->pos = 0;
	result = ft_calloc(val->len * 3 * 2 + 1, sizeof(char));
	while (val->pos < nbr_bits(*list_a) && ft_check_sort(*list_a) != 1)
	{
		val->i = 0;
		ft_copy_list(*list_a, &list_copy);
		val->i = 0;
		val->j = 0;
		logic_bis(list_a, &list_b, result, val);
		if (!ft_check_copy(*list_a, list_copy))
			ft_printf(result);
		ft_free_list(list_copy);
		val->pos++;
	}
	free(result);
	return (*list_a);
}
