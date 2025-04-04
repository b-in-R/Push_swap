
#include "push_swap.h"

int	check_double(t_list_ps *list_a)
{
	t_list_ps	*temp;
	t_list_ps	*check;

	check = list_a;
	while (check)
	{
		temp = check->next;
		while (temp)
		{
			if (check->value == temp->value)
				return (1);
			temp = temp->next;
		}
		check = check->next;
	}
	return (0);
}

void	ft_index(t_list_ps *list_a, t_list_ps *copy)
{
	t_list_ps	*temp;
	int			i;

	i = 0;
	while (copy)
	{
		temp = list_a;
		while (temp)
		{
			if (temp->value == copy->value)
			{
				temp->index = i++;
				break ;
			}
			temp = temp->next;
		}
		copy = copy->next;
	}
}

void	first_sort(t_list_ps *list_a)
{
	t_list_ps	*copy;
	t_list_ps	*curr;
	t_list_ps	*next;
	int			tmp;

	ft_copy_list(list_a, &copy);
	curr = copy;
	while (curr)
	{
		next = curr->next;
		while (next)
		{
			if (curr->value > next->value)
			{
				tmp = curr->value;
				curr->value = next->value;
				next->value = tmp;
			}
			next = next->next;
		}
		curr = curr->next;
	}
	ft_index(list_a, copy);
	ft_free_list(copy);
}

int	ft_check_sort(t_list_ps *list_a)
{
	while (list_a && list_a->next)
	{
		if (list_a->value > list_a->next->value)
		{
			return (0);
		}
		list_a = list_a->next;
	}
	return (1);
}

int	ft_sort(char **str, int free_split)
{
	t_list_ps	*list_a;
	t_logic		val;

	list_a = NULL;
	ft_start_list(str, &list_a);
	if (check_double(list_a) == 1)
		return (ft_exit_error(str, list_a, free_split, 1));
	first_sort(list_a);
	while (ft_check_sort(list_a) != 1)
	{
		list_a = ft_logic(&list_a, &val, ft_lst_len(list_a));
	//	val.i = 0;
	}
	ft_free_list(list_a);
	return (0);
}
