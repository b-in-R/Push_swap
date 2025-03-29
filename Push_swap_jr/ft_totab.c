/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:05:11 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/23 10:22:44 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return a string array from the input
int	*tabtoint(char **chartab)
{
	int	i;
	int	*inttab;

	i = 0;
	while (chartab[i])
		i++;
	inttab = malloc(sizeof(int) * i);
	i = 0;
	while (chartab[i])
	{
		inttab[i] = ft_atoi(chartab[i]);
		i++;
	}
	return (inttab);
}

// return 1 if there is no double in the string array
int	doublechecker(char **tab)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (tab[len])
		len++;
	while (i < len)
	{
		j = len - 1;
		while (j > i)
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (0);
			j--;
		}
		i++;
	}
	return (1);
}

// return 1 if the string array is valid (MIN_INT < digit < MAX_INT)
int	checker(char **tab)
{
	int			i;
	int			j;
	long int	digit;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '-' || tab[i][j] == '+')
				j++;
			if (!ft_isdigit(tab[i][j]))
				return (0);
			j++;
		}
		digit = ft_atoli(tab[i]);
		if (digit < INT_MIN || digit > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

// create and return a string array from the input
char	**create_tab(int ac, char **av, int *i)
{
	char	**tab;

	*i = 0;
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		while (tab[*i])
			(*i)++;
	}
	else
	{
		tab = malloc(sizeof(char *) * (ac + 1));
		if (tab == NULL)
			return (NULL);
		while (*i < ac - 1)
		{
			tab[*i] = malloc(sizeof(char) * (ft_strlen(av[*i + 1]) + 1));
			if (tab[*i] == NULL)
				return (freetab(tab, ac), NULL);
			ft_strcpy(tab[*i], av[*i + 1]);
			(*i)++;
		}
		tab[*i] = NULL;
	}
	return (tab);
}

// return a int array from the input
int	*tabint(int ac, char **av, int *len)
{
	char	**tab;
	int		i;
	int		*inttab;

	tab = create_tab(ac, av, &i);
	if (tab == NULL || checker(tab) == 0 || doublechecker(tab) == 0)
		return ((freetab(tab, ac), NULL));
	inttab = tabtoint(tab);
	*len = i;
	freetab(tab, ac);
	return (inttab);
}
