/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:22:03 by raphael           #+#    #+#             */
/*   Updated: 2025/03/08 20:26:01 by raphael          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

// OK
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


//--------------------------------------------------------

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
	tab = ft_calloc((count_word(s, c) + 2), sizeof(char *));
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
//---------------------------------------------------------

long long	ft_atouille(const char *str)
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

//---------------------------------------------------------

int	main(int ac, char **av)
{
	char			**str;
	int				i;
	long long		j;
	int				new_ac;
	
	i = 0;
	j = 0;
	if (ac <= 1 || check_nbrs(av) == 0 && ac != 2)
	{
		printf("Error\n");
		//ft_printf("Error\n");// ./libft/ft_printf.c
		return (0);
	}
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		new_ac = 0;
		while (str[new_ac])
			new_ac++;
		if (check_nbrs(str) == 0)
		{
			printf("Error\n");
			return (0);
		}
		while (str[i])
		{
			j = ft_atouille(av[i]);
			if (j > 2147483647 || j < -2147483647)
			{
				printf("Error int\n");
				return (0);
			}
			i++;
		}		
		ft_sort(new_ac, str, 0);
	}
	else
	{
		while (av[i])
		{
			j = ft_atouille(av[i]);
			if (j > 2147483647 || j < -2147483648)
			{
				printf("Error int\n");
				return (0);
			}
			i++;
		}	
		ft_sort(ac, av, 1);
	}
	return (0);
}
