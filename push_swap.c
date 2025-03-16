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
		return ;
	}
	while (str[i])
	{
		if (atouille(str[i]) > 2147483647 || atouille(str[i]) < -2147483648)
		{
			write(2, "Error\n", 6);
			return ;
		}
		i++;
	}
	ft_sort(new_ac, str);
}

int	main(int ac, char **av)
{
	int		i;
	
	i = 0;
	if ((ac <= 1 || check_nbrs(av) == 0) && ac != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (ac == 2)
	{
		if (av[0][0] == '\0')
		{
			write(2, "Error\n", 6);
			return (1);
		}
		checker(av);
	}
	else
	{
		while (av[i])
		{
			if (atouille(av[i]) > 2147483647 || atouille(av[i]) < -2147483648 || av[1][0] == '\0')
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
