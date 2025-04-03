
#include "push_swap.h"

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	neg;

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


void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*res;

	res = (char *) b;
	i = 0;
	while (i < len)
	{
		res[i] = c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	res = ft_memset(res, 0, count * size);
	return (res);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}


int	ft_puthex(unsigned long nbr, char format)
{
	int	nb;

	if (nbr == 0)
		return (write(1, "0", 1));
	else if (nbr >= 16)
	{
		nb = ft_puthex(nbr / 16, format);
		return (nb + ft_puthex(nbr % 16, format));
	}
	else if (nbr <= 9)
		return (ft_putchar(nbr + 48));
	else if (format == 'X')
		return (ft_putchar(SYMB_MAX[nbr]));
	else
		return (ft_putchar(SYMB_MIN[nbr]));
}

int	ft_putnbr(long nbr, char format)
{
	int		nb;

	if (format == 'u' && nbr < 0)
		nbr = (unsigned long)nbr;
	if (nbr == -2147483648 && (format == 'i' || format == 'd'))
		return (nb = write(1, "-2147483648", 11));
	else if (nbr < 0 && (format == 'i' || format == 'd'))
	{
		nb = write(1, "-", 1);
		return (ft_putnbr(-nbr, format) + 1);
	}
	else if (nbr > 9)
	{
		nb = ft_putnbr(nbr / 10, format);
		return (nb + ft_putnbr(nbr % 10, format));
	}
	else
		return (ft_putchar(nbr + 48));
}


int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	nb;

	nb = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*str)
	{
		ft_putchar((int)*str);
		nb++;
		str++;
	}
	return (nb);
}

int	check_ptr(char format, va_list ap)
{
	void	*ptr;
	int		nb;

	nb = 0;
	ptr = va_arg(ap, void *);
	if (ptr == NULL)
		nb += write(1, NULL_PTR_STR, NULL_PTR_LEN);
	else
	{
		nb += write(1, "0x", 2);
		nb += ft_puthex((unsigned long)ptr, format);
	}
	return (nb);
}

int	check_uint(char format, va_list ap)
{
	unsigned int	nbmax;
	int				nb;

	nb = 0;
	nbmax = va_arg(ap, unsigned long);
	if (nbmax >= 4294967295)
		nb += ft_putstr("4294967295");
	else
		nb += ft_putnbr(nbmax, format);
	return (nb);
}

int	check_format(char format, va_list ap)
{
	int				nb;

	nb = 0;
	if (format == 'c')
		nb += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		nb += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		nb += check_ptr(format, ap);
	else if (format == 'd' || format == 'i')
		nb += ft_putnbr(va_arg(ap, int), format);
	else if (format == 'u')
		nb += check_uint(format, ap);
	else if (format == 'x' || format == 'X')
		nb += ft_puthex(va_arg(ap, unsigned int), format);
	else
		nb += write(1, &format, 1);
	return (nb);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		nb;

	va_start(ap, format);
	nb = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			nb += ft_putchar('%');
			format++;
		}
		else if (*format == '%')
			nb += check_format(*(++format), ap);
		else
			nb += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (nb);
}


void	ft_split_free(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	count_word(const char *str, char sep)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (*str)
	{
		if (*str != sep && i == 0)
		{
			i = 1;
			cnt++;
		}
		else if (*str == sep)
			i = 0;
		str++;
	}
	return (cnt);
}

static void	*ft_free(char **tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static void	ft_initiate_vars(size_t *i, size_t *j, int *start_word )
{
	*i = 0;
	*j = 0;
	*start_word = -1;
}

static char	*putword(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (0);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		j;
	int			start_word;

	ft_initiate_vars(&i, &j, &start_word);
	tab = ft_calloc((count_word(s, c) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start_word < 0)
			start_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start_word >= 0)
		{
			tab[j] = putword(s, start_word, i);
			if (!(tab[j]))
				return (ft_free(tab, j));
			start_word = -1;
			j++;
		}
		i++;
	}
	return (tab);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}







/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/


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

void	logic_bis(t_list_ps **list_a, t_list_ps **list_b, char *result,
			t_logic *val)
{
	if (((*list_a)->index >> val->pos & 1) == 0)
	{
		ft_preprint(result, "pb\n", &val->i);
		ft_swap(list_a, list_b, 1);
	}
	else
	{
		ft_preprint(result, "ra\n", &val->i);
		ft_swap(list_a, list_a, 0);
	}
}

t_list_ps	*ft_logic(t_list_ps **list_a, char *result, t_logic *val, int len)
{
	t_list_ps	*list_b;
	int			j;

	list_b = NULL;
	val->pos = 0;
	while (val->pos < nbr_bits(*list_a))
	{
		val->i = 0;
		j = 0;
		while (j < len)
		{
			logic_bis(list_a, &list_b, result, val);
			j++;
		}
		while (list_b)
		{
			ft_preprint(result, "pa\n", &val->i);
			ft_swap(&list_b, list_a, 1);
		}
		val->pos++;
	}
	return (*list_a);
}

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


void	ft_copy_list(t_list_ps *list_a, t_list_ps **list_copy)
{
	t_list_ps	*newnode;

	*list_copy = NULL;
	while (list_a)
	{
		newnode = ft_create(list_a->value);
		if (!newnode)
		{
			ft_free_list((*list_copy));
			return ;
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

void	ft_preprint(char *str, char *to_add, int *i)
{
	int	iter;

	iter = 0;
	while (to_add[iter])
	{
		str[*i] = to_add[iter];
		(*i)++;
		iter++;
	}
}


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

int	check_sort(t_list_ps *list_a)
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
	t_list_ps	*list_copy;
	t_logic		val;
	char		*result;

	list_a = NULL;
	ft_start_list(str, &list_a);
	if (check_double(list_a) == 1)
		return (ft_exit_error(str, list_a, free_split, 1));
	result = ft_calloc(ft_lst_len(list_a) * 3 + 1, sizeof(char));
	if (!result)
		return (1);
	first_sort(list_a);
	while (check_sort(list_a) != 1)
	{
		ft_copy_list(list_a, &list_copy);
		list_a = ft_logic(&list_a, result, &val, ft_lst_len(list_a));
		if (!ft_check_copy(list_a, list_copy))
			ft_printf(result);
		val.i = 0;
		ft_free_list(list_copy);
	}
	free(result);
	ft_free_list(list_a);
	return (0);
}



int	ft_exit_error(char **str, t_list_ps *lst, int free_s, int free_l)
{
	if (free_s == 1)
		ft_free_str(str);
	if (free_l == 1)
		ft_free_list(lst);
	write(2, "Error\n", 6);
	return (1);
}

int	check_sign_error(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] == '+' || str[i][j] == '-') &&
					(!ft_isdigit(str[i][j + 1]) || j != 0))
				return (1);
			if (ft_isdigit(str[i][j]) && (str[i][j + 1] == '+' ||
					str[i][j + 1] == '-'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_min_max_value(const char *str)
{
	int			i;
	long long	n;
	long long	neg;

	i = 0;
	n = 0;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i])
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	if (n * neg > 2147483647 || n * neg < -2147483648)
		return (1);
	return (0);
}

int	check_errors(char **str, int free_split)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((ft_isdigit(str[i][j]) == 0 && str[i][j] != '-' &&
					str[i][j] != '+') || str[i][0] == '\0')
				return (ft_exit_error(str, NULL, free_split, 0));
			j++;
		}
		if (check_min_max_value(str[i]))
			return (ft_exit_error(str, NULL, free_split, 0));
		i++;
	}
	if (check_sign_error(str))
		return (ft_exit_error(str, NULL, free_split, 0));
	return (0);
}

int	main(int ac, char **av)
{
	char	**str;
	int		free_split;

	free_split = 0;
	if (ac < 2)
		return (ft_exit_error(NULL, NULL, 0, 0));
	if (ac == 2)
	{
		free_split = 1;
		str = ft_split(av[1], ' ');
	}
	else
		str = av + 1;
	if (check_errors(str, free_split))
		return (ft_exit_error(str, NULL, free_split, 0));
	if (ft_sort(str, free_split))
		return (1);
	if (free_split == 1)
		ft_free_str(str);
	return (0);
}
