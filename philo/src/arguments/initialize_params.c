/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:07:46 by claferna          #+#    #+#             */
/*   Updated: 2024/06/04 17:08:47 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

static int	initialize_philosophers(t_options *opt, int total)
{
	int	i;

	opt->philos = (t_philo *)malloc(sizeof(t_philo) * total);
	if (!opt->philos)
		return (0);
	i = 0;
	while (i < total)
	{
		opt->philos[i].id = i;
		opt->philos[i].left_fork = i;
		opt->philos[i].right_fork = ((i + 1) % total);
		opt->philos[i].is_eating = 0;
		opt->philos[i].eat_count = 0;
		pthread_mutex_init(&opt->philos[i].mtx, NULL);
		pthread_mutex_init(&opt->philos[i].mtx_eat, NULL);
		pthread_mutex_lock(&opt->philos[i].mtx_eat);
		opt->philos[i].opt = opt;
		i++;
	}
	return (1);
}

static int	initialize_mutex(t_options *opt)
{
	int	i;

	pthread_mutex_init(&opt->mtx_write, NULL);
	pthread_mutex_init(&opt->someone_dead, NULL);
	pthread_mutex_lock(&opt->someone_dead);
	opt->tids = (pthread_t *)malloc(sizeof(pthread_t) * opt->num_philo);
	if (!opt->tids)
		return (0);
	opt->mtx_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
			opt->num_philo);
	if (!opt->mtx_forks)
		return (0);
	i = 0;
	while (i < opt->num_philo)
	{
		if (pthread_mutex_init(&opt->mtx_forks[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

static int	initialize_options(t_options *opt, char **argv)
{
	opt->num_philo = (int) ft_atoi(argv[1]);
	if (opt->num_philo > 200)
		return (0);
	opt->time_to_die = (uint64_t) ft_atoi(argv[2]);
	opt->time_to_eat = (uint64_t) ft_atoi(argv[3]);
	opt->time_to_sleep = (uint64_t) ft_atoi(argv[4]);
	opt->num_must_eat = 0;
	if (argv[5])
		opt->num_must_eat = (int) ft_atoi(argv[5]);
	opt->mtx_forks = NULL;
	opt->philos = NULL;
	opt->dead = 0;
	if (!initialize_mutex(opt))
		return (0);
	return (1);
}

int	initialize_params(t_options *opt, char **argv)
{
	if (!initialize_options(opt, argv))
		return (0);
	else if (!initialize_philosophers(opt, opt->num_philo))
		return (0);
	return (1);
}
