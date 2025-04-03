
#include "push_swap.h"

t_list_ps	*ft_create(int value)
{
	t_list_ps	*new;

	new = (t_list_ps *)malloc(sizeof(t_list_ps));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_add_front(t_list_ps **lst, t_list_ps *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_add_back(t_list_ps **lst, t_list_ps *new)
{
	t_list_ps	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return ;
}

void	ft_start_list(char **str, t_list_ps **list_a)
{
	t_list_ps	*newnode;
	int			i;
	int			temp;

	i = 0;
	temp = 0;
	while (str[i])
	{
		temp = ft_atoi(str[i++]);
		newnode = ft_create(temp);
		if (!newnode)
		{
			ft_free_list(*list_a);
			return ;
		}
		ft_add_back(list_a, newnode);
	}
}
