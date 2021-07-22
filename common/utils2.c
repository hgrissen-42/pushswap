#include "push_swap.h"

int	ft_isint(long nbr)
{
	return (nbr >= -2147483648 && nbr <= 2147483647);
}

long	ft_atol(char *str)
{
	long	nbr;
	 int	sign;

	nbr = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - 48;
		str++;
	}
	return (nbr * sign);
}