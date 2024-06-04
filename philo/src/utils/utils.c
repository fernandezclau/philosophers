/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:04:48 by claferna          #+#    #+#             */
/*   Updated: 2024/05/30 17:07:15 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

long	ft_atoi(char *str)
{
	long	sign;
	long	result;
	int		i;

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
<<<<<<< HEAD:src/utils/utils.c
	char	str[10];

	str = "0123456789";
=======
	char str[10] = "0123456789";
	
>>>>>>> 4b33ababbc76534c4b8b1c6704bb662668f9270d:philo/src/utils/utils.c
	if (num > 9)
		ft_putnbr(num / 10);
	write(1, &str[num % 10], 1);
}
