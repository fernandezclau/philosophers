/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:13:12 by claferna          #+#    #+#             */
/*   Updated: 2024/07/07 18:13:13 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
** DESC: The 'free_all' function frees all the heap initialiazed
** memory.
*/
int	free_all(t_options *opt, t_philo *philo, t_fork *forks)
{
	if (opt)
	{
		if (pthread_mutex_destroy(&opt->mtx_dead))
			return (EXIT_FAILURE);
		if (pthread_mutex_destroy(&opt->mtx_eat))
			return (EXIT_FAILURE);
	}
	if (philo)
		free(philo);
	if (forks)
	{
		if (pthread_mutex_destroy(&forks->fork_mutex))
			return (EXIT_FAILURE);
		free(forks);
	}
	return (EXIT_SUCCESS);
}

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
