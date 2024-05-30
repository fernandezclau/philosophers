/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:04:28 by claferna          #+#    #+#             */
/*   Updated: 2024/05/30 17:10:56 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

/*
** DESC: The 'write_action' function write the selected acction (only
** the action).
*/
void	write_action(int action)
{
	if (action == EAT)
		write(1, " is eating\n", 11);
	else if (action == SLEEP)
		write(1, " is sleeping\n", 13);
	else if (action == THINK)
		write(1, " is thinking\n", 13);
	else if (action == TAKE_FORK)
		write(1, "has taken a fork\n", 17);
	else if (action == FINISH_EAT)
		write(1, "must eat count reached\n", 23);
	else
		write(1, " died\n", 6);
}

/*
** DESC: The 'write_timestamp' function write the timestamp of a certain
** action.
*/
void	write_timestamp(int start)
{
	int	timestamp;

	timestamp = getime() - start;
	ft_putnbr(timestamp);
}

/*
** DESC: The 'print_action' function logs the actio of a certain 
** philosopher with timestamps.
*/
void	print_action(int action, t_philo *philo, t_options *opt)
{
	static int	id_dead;

	is_dead = 0;
	pthread_mutex_lock(&opt->mtx_writting);
	if (!is_dead)
	{
		write_timestamp(opt->start);
		if (action != FINISH_EAT)
			write_philo_id(philo->id + 1);
		if (action == FINISH_EAT || action == DIE)
			is_dead = 1;
		write_action(action);
	}
	pthread_mutex_unlock(&opt->mtx_writtint);
}
