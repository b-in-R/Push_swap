/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabiner <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:51:57 by rabiner           #+#    #+#             */
/*   Updated: 2025/03/25 16:14:20 by rabiner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	exit_error(char **str, int need_free)
{
	if (need_free)
		ft_split_free(str);
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
	int	i;
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
				return (exit_error(str, free_split));
			j++;
		}
		if (check_min_max_value(str[i]))
			return (exit_error(str, free_split));
		i++;
	}
	if (check_sign_error(str))
		return (exit_error(str, free_split));
	return (0);
}

int	main(int ac, char **av)
{
	char	**str;
	int		free_split;

	free_split = 0;
	if (ac < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ac == 2)
	{
		free_split++;
		str = ft_split(av[1], ' ');
	}
	else
		str = av + 1;
	if (check_errors(str, free_split))
		return (exit_error(str, free_split));
	ft_first_sort(str);
	if (free_split)
		ft_split_free(str);
	return (0);
}