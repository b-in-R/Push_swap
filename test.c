
#include "push_swap.h"


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
		ft_add_front(dest, node);// dest 0x0
	else
		ft_add_back(dest, node);
}

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

//MODIFIE
int	check_sort(t_list_ps *list_a)
{
	if (!list_a)
	{
		printf("--- erreur !list_a ---\n");
		return 0;
	}
	while (list_a->next != NULL)
	{
		if (list_a->value > list_a->next->value)
		{
			//printf("check_sort: 'list->value' > 'list->next->value'!\n");
			return (0);
		}
		list_a = list_a->next;
	}
	return (1);
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

// ok
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

// ok
void	allocate_num(t_list_ps **list)
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


void	ft_copy_list(t_list_ps *list_a, int ac)
{
	t_list_ps	*list_copy;
	t_list_ps	*first;
	t_list_ps	*head_a;

	// creation list_copy selon list_a
	list_copy = NULL;
	head_a = list_a;
	while (list_a)
	{
		first =  ft_create(list_a->value);
		if (!first)
			return ;
		ft_add_back(&list_copy, first);
		list_a = list_a->next;
	}
	
	//tri list_copy et attribution list_copy->num
	sort_copy(&list_copy, ac);
	allocate_num(&list_copy);
	

	
	//attribution list_a->num selon list_copy->num
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

void	print_lst_num(t_list_ps **lst)
{
	t_list_ps	*current;
	
	if (!lst || !*lst)
		return;
	current = *lst;
	while (current)
	{
		printf("%d -> ", current->num);
		current = current->next;
	}
	printf("NULL\n");
}

void	print_list(t_list_ps **lst)
{
	t_list_ps	*current;
	
	if (!lst || !*lst)
		return;
	current = *lst;
	while (current)
	{
		printf("%d -> ", current->value);
		current = current->next;
	}
	printf("NULL\n");
}

void	ft_start(char **av, t_list_ps **list_a)
{
	int	i;
	int	temp;

	i = 1;
	temp = 0;
	while (av[i])
	{
		temp = (int)strtol(av[i++], NULL, 10);//testA
		//testAtemp = ft_atoi(av[i++]);// chaque nombre en int
		ft_add_back(list_a, ft_create(temp));
	}
	print_list(list_a);// pour test
}

void	ft_sort(int ac, char **av)
{
	t_list_ps	*list_a;

	list_a = NULL;
	//(void)ac;
	ft_start(av, &list_a);// ici
	if (check_double(list_a) == 0)// ici
	{
		printf("Error\n");//test
		//ft_printf("Error\n");// ./libft/ft_printf.c/
		return ;
	}

	ft_copy_list(list_a, ac);

	printf("\nAvant tri:\nlist_a->value:\t");
	print_list(&list_a);
	printf("list_a->num:\t");
	print_lst_num(&list_a);

	if (check_sort(list_a) != 1)
	{
		// -----------------appel fonction tri-------------
		printf("ft_sort pas trie-> vers logic\n");//test
		ft_logic(&list_a);
	}
	printf("\nApres tri:\nlist_a->value:\t");
	print_list(&list_a);
	printf("list_a->num:\t");
	print_lst_num(&list_a);
	printf("ft_sort ok\n");
	//while ()
		// envoyer dans atoi (const char *str) --> ok dans ft_start_sort
		// check si plusieurs fois le meme nbr -> Error --> ok
		// envoyer chaque nombre dans list_a add_back --> ok
	// retourne a push_swap.c -> main > fin
}

int	main(void)
{
	int	ac = 6;
	char	*str[] = {"./a.out", "4", "2", "6", "3", "7", (char *)0};
	char	**av = str;
	ft_sort(ac, av);
	return 0;
}

