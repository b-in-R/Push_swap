
#include "push_swap.h"

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

int	lst_len(t_list_ps *lst)
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

void	ft_logic(t_list_ps **list_a, char *result, int *i, int len)
{
	t_list_ps	*list_b;
	int			n_bit;
	int			pos;

	list_b = NULL;
	n_bit = nbr_bits(*list_a);
	pos = 0;
	while (pos < n_bit)
	{
		*i = 0;
		while (*i < len)
		{
			if (((*list_a)->index >> pos & 1) == 0)
			{
				preprint(result, "pb\n");
				ft_swap(list_a, &list_b, 1);
			}
			else
			{
				preprint(result, "ra\n");
				ft_rotate(list_a, 1);// a voir
			}
			*i++;
		}
		while (list_b)
		{
			preprint(result, "pa\n");
			ft_swap(&list_b, list_a, 1);
		}
		pos++;
	}
}
