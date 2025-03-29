
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

void	ft_swap(t_list_ps **src, t_list_ps **dest, int front)
{
	t_list_ps	*node;

	if (!src || !*src || !dest)
		return ;
	node = *src;
	*src = node->next;
	node->next = NULL;
	if (front == 1)
		ft_add_front(dest, node);
	else
		ft_add_back(dest, node);
}


int	nbr_bit(t_list_ps *list_a)
{
	int	biggest;
	int	n_bit;
	int	temp;

	biggest = 0;
	n_bit = 0;
	temp = 1;
	while (list_a)
	{
		if (list_a->num > biggest)
			biggest = list_a->value;
		list_a = list_a->next;
	}
	while (temp <= biggest)
	{
		temp *= 2;
		n_bit++;
	}
	return (n_bit);
}

void	logic_bis(t_list_ps **list_a, t_list_ps **list_b, int *p)
{
	t_list_ps	**temp;

	temp = list_a;
		while (*temp)
		{
			if (((*temp)->num >> *p & 1) == 0)
		 	{
				ft_printf("pb\n");
				ft_swap(temp, list_b, 1);
			}
			else
			{
				ft_printf("ra\n");
				temp = &((*temp)->next);
			}
		}
		while (*list_b)
		{
			ft_printf("pa\n");
			ft_swap(list_b, list_a, 1);
		}
		(*p)++;
		if (check_sort(*list_a) == 1)
			return ;
}

void    ft_logic(t_list_ps **list_a)
{
	t_list_ps	*list_b;
	int     	pos;
	int			n_bit;
	int			*p;

	list_b = NULL;
	pos = 0;
	p = &pos;
	n_bit = nbr_bit(*list_a);
	while (pos <= n_bit)
	{
		logic_bis(list_a, &list_b, p);
	}
}


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

void	ft_start(char **av, t_list_ps **list_a)
{
	t_list_ps	*newnode;
	int			i;
	int			temp;

	i = 1;
	temp = 0;
	while (av[i])
	{
		temp = ft_atoi(av[i++]);
		newnode = ft_create(temp);
		if (!newnode)
		{
			ft_free_list(*list_a);
			return;
		}
		ft_add_back(list_a, newnode);
	}
}

int	check_double(t_list_ps *list_a)
{
	t_list_ps	*temp;

	while (list_a && list_a->next)
	{
		temp = list_a->next;
		while (temp)
		{
			if (list_a->value == temp->value)
				return (0);
			temp = temp->next;
		}
		list_a = list_a->next;
	}
	return (1);
}

int	check_sort(t_list_ps *list_a)
{
	if (!list_a)
		return (0);
	while (list_a->next != NULL)
	{
		if (list_a->value > list_a->next->value)
			return (0);
		list_a = list_a->next;
	}
	return (1);
}

void	ft_sort(int ac, char **av)
{
	t_list_ps	*list_a;

	list_a = NULL;
	ft_start(av, &list_a);
	if (check_double(list_a) == 0)
	{
		write(2, "Error\n", 6);
		ft_free_list(list_a);
		return ;
	}
	ft_copy_list(list_a, ac);

	if (check_sort(list_a) != 1)// ici
	{
		ft_logic(&list_a);
	}
	ft_free_list(list_a);
	return ;
}



int	check_nbrs(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] > 47 && av[i][j] < 58) || av[i][j] == '-')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	n_args(char *str)
{
	int	i;
	int	spaces;

	i = 0;
	spaces = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			spaces++;
		i++;
	}
	spaces++;
	return (spaces);
}

long long	atouille(const char *str)
{
	int	i;
	long long	n;
	long long	neg;

	i = 0;
	n = 0;
	neg = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	return (n * neg);
}

void	checker(char **av)
{
	char		**str;
	int			i;
	int			new_ac;

	i = 0;
	str = ft_split(av[1], ' ');
	new_ac = 0;
	while (str[new_ac])
		new_ac++;
	if (check_nbrs(str) == 0)
	{
		write(2, "Error\n", 6);
		ft_free_str(str);
		return ;
	}
	while (str[i])
	{
		if (atouille(str[i]) > 2147483647 || atouille(str[i]) < -2147483648)
		{
			write(2, "Error\n", 6);
			ft_free_str(str);
			return ;
		}
		i++;
	}
	ft_sort(new_ac, str);
	ft_free_str(str);
}

int	main(int ac, char **av)
{
	int		i;

	i = 0;
	if ((ac != 2 && (ac < 2 || check_nbrs(av) == 0 || av[1] == NULL || av[1][0]
			== '\0')) || ((ac == 2 && (av[1] == NULL || av[1][0] == '\0'))))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (ac == 2)
		checker(av);
	else
	{
		while (av[i])
		{
			if (atouille(av[i]) > 2147483647 || atouille(av[i]) < -2147483648)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			i++;
		}	
		ft_sort(ac, av);
	}
	return (0);
}