#include <stdio.h>
# include <stdlib.h>



long long	ft_atoi(const char *str)
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

int	main(int ac, char **av)
{
	int	i;
	(void)ac;
	i = printf("%lli\n", ft_atoi(av[1]));
	printf("%i\n", i);
	return 0;
}