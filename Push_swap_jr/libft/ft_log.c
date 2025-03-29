
#include "libft.h"

int	ft_log(int n, int log)
{
	int	res;

	res = 0;
	while (n > 1)
	{
		n /= log;
		res++;
	}
	return (res);
}