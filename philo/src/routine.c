/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:29:04 by claferna          #+#    #+#             */
/*   Updated: 2024/06/10 17:32:55 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
** DESC: The 'p_lifecycle' function simulates the whole lifecycle of a
** philosopher.
*/
void	*p_lifecycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(1000);
	while (1)
	{
		if (is_dead(philo, 0) || p_eat(philo))
			break ;
		if (is_done(philo, 0))
		{
			pthread_mutex_unlock(&philo->fork[take_fork(philo->left_fork, \
					philo->right_fork, 1)]);
			pthread_mutex_unlock(&philo->fork[take_fork(philo->left_fork, \
					philo->right_fork, 0)]);
			break ;
		}
		p_sleep(philo);
		p_think(philo);
	}
	return (NULL);
}

/*
** DESC: The 'meal_checker' function checks if all the philosohers have eaten.
*/
int	meal_checker(t_options *opt, t_philo *philo)
{
	int	i;
	int	done;
	int	count_eats;

	if (opt->num_must_eat == -1)
		return (0);
	i = 0;
	done = -1;
	while (i < opt->num_philo)
	{
		pthread_mutex_lock(&philo->opt->mtx_eat);
		count_eats = philo[i].count_eats;
		pthread_mutex_unlock(&philo->opt->mtx_eat);
		if (count_eats >= opt->num_must_eat)
			if (++done == opt->num_philo - 1)
				return (1);
		usleep(50);
		i++;
	}
	return (0);
}

/*
** DESC: The 'is_someone_dead' function checks if a philosopher is dead.
*/
void	is_someone_dead( t_options *opt, t_philo *philo)
{
	int			i;
	uint64_t	last_meal;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&opt->mtx_eat);
		last_meal = philo[i].last_meal;
		pthread_mutex_unlock(&opt->mtx_eat);
		if (meal_checker(opt, philo) && last_meal)
		{
			is_done(philo, 1);
			break ;
		}
		if (last_meal && get_time() - last_meal > opt->time_to_die)
		{
			is_dead(philo, 1);
			print_action(&philo[i], DIE);
			break ;
		}
		i = (i + 1) % opt->num_philo;
		usleep(200);
	}
	return ;
}
