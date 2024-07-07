/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:12:40 by claferna          #+#    #+#             */
/*   Updated: 2024/07/07 18:12:53 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*p_lifecycle(void *arg);
static void	*meal_death_checker(void *arg);

int	start_simulation(t_options *opt, t_philo **philos)
{
	int	i;

	i = 0;
	while (i < opt->num_philo)
	{
		if (pthread_create(&((*philos)[i].t_id), NULL, \
			p_lifecycle, &((*philos)[i])))
			return (0);
		i++;
	}
	if (pthread_create(&(opt->t_id), NULL, meal_death_checker, philos))
		return (0);
	while (i--)
	{
		if (pthread_join((*philos)[i].t_id, NULL))
			return (0);
	}
	if (pthread_join(opt->t_id, NULL))
		return (0);
	return (true);
}

static void	*p_lifecycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(1000);
	while (!is_someone_dead(philo) && \
			philo->count_meals != philo->opt->num_must_eat)
	{
		take_forks(philo);
		if (philo->left_taken && philo->right_taken)
		{
			p_eat(philo);
			finish_eating(RIGHT_FORK, philo);
			finish_eating(LEFT_FORK, philo);
			p_sleep(philo);
			p_think(philo);
		}
	}
	if (philo->right_taken)
		pthread_mutex_unlock(&(philo->right_fork->fork_mutex));
	if (philo->left_taken)
		pthread_mutex_unlock(&(philo->left_fork->fork_mutex));
	return (NULL);
}

static void	*meal_death_checker(void *arg)
{
	t_options	*opt;
	t_philo		**philos;
	int			i;

	philos = (t_philo **)arg;
	opt = (*philos)->opt;
	i = -1;
	while (true)
	{
		if (++i == opt->num_philo)
			i = 0;
		pthread_mutex_lock(&(opt->mtx_eat));
		if ((*philos)[i].count_meals == opt->num_must_eat)
		{
			pthread_mutex_unlock(&(opt->mtx_eat));
			return (NULL);
		}
		if (get_time() - (*philos)[i].last_meal > opt->time_to_die / 1000)
		{
			pthread_mutex_unlock(&(opt->mtx_eat));
			return (p_die(&((*philos)[i]), opt));
		}
		pthread_mutex_unlock(&(opt->mtx_eat));
	}
	return (NULL);
}

int	is_someone_dead(t_philo *philo)
{
	bool	state;

	pthread_mutex_lock(&(philo->opt->mtx_dead));
	state = philo->opt->is_someone_dead;
	pthread_mutex_unlock(&(philo->opt->mtx_dead));
	return (state);
}
