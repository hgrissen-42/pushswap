#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isdigits(const char *str)
{
	int	i;
	int	signe;

	i = 0;
	signe = 0;
	while (str[i])
	{
		if (!signe && (str[i] == '-' || str[i] == '+' ))
		{
			signe = 1;
			i++;
			continue ;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		else
			signe = 1;
		i++;
	}
	return (1);
}

int	ft_max(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putendl(const char *str)
{
	if (str)
	{
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
}
