/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:09:53 by claferna          #+#    #+#             */
/*   Updated: 2024/07/07 18:11:05 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	forks_init(t_fork **forks, int n_philo)
{
	int	i;

	*forks = (t_fork *)malloc(sizeof(t_fork) * n_philo);
	if (!*forks)
		return (false);
	i = -1;
	while (++i < n_philo)
	{
		(*forks)[i].id = i;
		if (pthread_mutex_init(&((*forks)[i].fork_mutex), NULL))
			return (false);
	}
	return (true);
}

int	initialize_philosophers(t_options *opt, t_philo **philos, t_fork *forks)
{
	t_philo	*philo;
	int		i;

	*philos = (t_philo *)malloc(sizeof(t_philo) * opt->num_philo);
	if (!philos)
		return (false);
	i = -1;
	while (++i < opt->num_philo)
	{
		philo = &(*philos)[i];
		philo->opt = opt;
		philo->id = i + 1;
		philo->last_meal = get_time();
		philo->count_meals = 0;
		philo->right_fork = &forks[i];
		philo->left_fork = &forks[(i + 1) % opt->num_philo];
		philo->right_taken = 0;
		philo->left_taken = 0;
	}
	return (true);
}

int	initialize_options(t_options *opt, char **argv)
{
	opt->num_philo = ft_atoi(argv[1]);
	opt->time_to_die = ft_atoi(argv[2]) * 1000;
	opt->time_to_eat = ft_atoi(argv[3]) * 1000;
	opt->time_to_sleep = ft_atoi(argv[4]) * 1000;
	opt->num_must_eat = -2;
	if (argv[5])
		opt->num_must_eat = ft_atoi(argv[5]);
	if (opt->num_philo > 200)
		return (0);
	opt->start = get_time();
	opt->is_someone_dead = false;
	if (pthread_mutex_init(&(opt->mtx_eat), NULL))
		return (0);
	if (pthread_mutex_init(&(opt->mtx_dead), NULL))
		return (0);
	if (pthread_mutex_init(&(opt->mtx_write), NULL))
		return (0);
	return (1);
}
