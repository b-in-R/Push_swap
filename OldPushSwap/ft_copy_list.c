

#include "push_swap.h"

void	swap_next(t_list_ps **list_copy)
{
	t_list_ps	*first;
	t_list_ps	*second;

	first = *list_copy;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list_copy = second;
}

void	sort_copy(t_list_ps **list_copy, int ac)
{
	t_list_ps	**temp;

	while (check_sort(*list_copy) != 1)
	{
		temp = list_copy;
		while ((*temp) && (*temp)->next && ac > 1)
		{
			if ((*temp)->value > (*temp)->next->value)
				swap_next(temp);
			temp = &((*temp)->next);
		}
		ac--;
	}
}

void	allocate_num_copy(t_list_ps **list)
{
	t_list_ps	*temp;
	int			i;

	temp = *list;
	i = 0;
	while (temp)
	{
		temp->num = i;
		i++;
		temp = temp->next;
	}
}

void	allocate_num_a(t_list_ps *list_copy, t_list_ps *list_a)
{
	t_list_ps	*head_a;

	head_a = list_a;
	while (list_copy)
	{
		while (list_a)
		{
			if (list_copy->value == list_a->value)
			{
				list_a->num = list_copy->num;
				break ;
			}
			list_a = list_a->next;
		}
		list_a = head_a;
		list_copy = list_copy->next;
	}
}

void	ft_copy_list(t_list_ps *list_a, int ac)
{
	t_list_ps	*list_copy;
	t_list_ps	*node_act;
	t_list_ps	*head_a;

	list_copy = NULL;
	head_a = list_a;
	while (list_a)
	{
		node_act = ft_create(list_a->value);
		if (!node_act)
		{
			ft_free_list(list_copy);
			return ;
		}
		ft_add_back(&list_copy, node_act);
		list_a = list_a->next;
	}
	sort_copy(&list_copy, ac);
	allocate_num_copy(&list_copy);
	list_a = head_a;
	allocate_num_a(list_copy, list_a);
	ft_free_list(list_copy);
}