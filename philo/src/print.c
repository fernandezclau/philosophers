/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:26:33 by claferna          #+#    #+#             */
/*   Updated: 2024/07/07 18:12:12 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	write_action(int action);

void	print_action(t_philo *philo, int action)
{
	pthread_mutex_lock(&(philo->opt->mtx_write));
	if (action == DIE)
	{
		write_timestamp(philo->opt->start);
		printf("%d is dead\n", philo->id);
	}
	if (!is_someone_dead(philo))
	{
		write_timestamp(philo->opt->start);
		printf("%d", philo->id);
		write_action(action);
	}
	pthread_mutex_unlock(&(philo->opt->mtx_write));
}

void	write_timestamp(int start)
{
	int	timestamp;

	timestamp = get_time() - start;
	printf("%u\t", timestamp);
}

static void	write_action(int action)
{
	if (action == EAT)
		printf(" is eating\n");
	else if (action == SLEEP)
		printf(" is sleeping\n");
	else if (action == THINK)
		printf(" is thinking\n");
	else if (action == TAKE_FORK)
		printf(" has taken a fork\n");
}
