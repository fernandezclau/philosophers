/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:43:27 by claferna          #+#    #+#             */
/*   Updated: 2024/06/04 17:45:50 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	write_action(int action)
{
	if (action == EAT)
		write(1, " is eating\n", 11);
	else if (action == SLEEP)
		write(1, " is sleeping\n", 13);
	else if (action == THINK)
		write(1, " is thinking\n", 13);
	else if (action == TAKE_FORK)
		write(1, " has taken a fork\n", 18);
	else if (action == END)
		printf("The number of meals has been reached");
	else
		write(1, " died\n", 6);
}

static void	write_timestamp(int start)
{
	int	timestamp;

	timestamp = get_time() - start;
	ft_putnbr(timestamp);
}

/*
** DESC: The 'print_action' function logs the actio of a certain
** philosopher with timestamps.
*/
void	print_action(int action, t_philo *philo, t_options *opt)
{
	static int	is_dead;

	is_dead = 0;
	pthread_mutex_lock(&philo->opt->mtx_write);
	if (!is_dead)
	{
		write_timestamp(opt->start);
		write(1, "\t", 1);
		if (action != END)
			ft_putnbr(philo->id + 1);
		if (action >= DIE)
			is_dead = 1;
		write_action(action);
	}
	pthread_mutex_unlock(&philo->opt->mtx_write);
}
