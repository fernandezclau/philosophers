#include "../../include/philosophers.h"

long	ft_atoi(char *str)
{
	long	sign;
	long	result;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		str++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

void	ft_putnbr(int num)
{
	char str[10] = "0123456789";
	
	if (num > 9)
		ft_putnbr(num / 10);
	write(1, &str[num % 10], 1);
}
