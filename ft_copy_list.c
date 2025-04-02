
#include "push_swap.h"

void	ft_copy_list(t_list_ps *list_a, t_list_ps **list_copy)
{
	t_list_ps	*newnode;

	*list_copy = NULL;
	while (list_a)
	{
		newnode = ft_create(list_a->value);
		if (!newnode)
		{
			ft_free_list((list_copy));
			return;
		}
		newnode->index = list_a->index;
		ft_add_back(list_copy, newnode);
		list_a = list_a->next;
	}
}

int	ft_check_copy(t_list_ps *list_a, t_list_ps *list_copy)
{
	while (list_a)
	{
		if (list_a->index != list_copy->index)
		{
			return (0);
		}
		list_a = list_a->next;
		list_copy = list_copy->next;
	}
	return (1);
}