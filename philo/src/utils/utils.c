/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:45:07 by claferna          #+#    #+#             */
/*   Updated: 2024/06/10 17:46:45 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

/*
** DESC: The 'ft_atoi' function converts a string to int.
*/
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

/*
** DESC: The 'get_time' function gets the current time in ms.
*/
uint64_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/*
** DESC: The 'error_msg' function handles the error messages.
*/
void	error_msg(int type)
{
	if (type == INIT)
		printf("Error while initialising... -.-\n");
	else if (type == ARGS)
		printf("Error in arguments... :/ ╦╤─\n");
	else
		printf("Error starting simulation... ;(\n");
}
