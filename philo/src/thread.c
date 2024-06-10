/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:33:13 by claferna          #+#    #+#             */
/*   Updated: 2024/06/10 17:37:07 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
** DESC: The 'free_structs' function frees all the heap initialiazed
** memory.
*/
void	free_structs(t_options *opt, t_philo *philo)
{
	if (philo && philo->fork)
		free(philo->fork);
	if (philo)
		free(philo);
	if (opt->t_id)
		free(opt->t_id);
	if (opt)
		free(opt);
}

/*
** DESC: The 'close_mutex' function closes all the initialized mutex.
*/
void	close_mutex(t_options *opt, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->opt->num_philo)
		pthread_mutex_destroy(&philo->fork[i++]);
	pthread_mutex_destroy(&opt->mtx_write);
	pthread_mutex_destroy(&opt->mtx_eat);
	pthread_mutex_destroy(&opt->mtx_end);
	pthread_mutex_destroy(&opt->mtx_dead);
}

/*
** DESC: The 'start_simulation' function starts the simulation.
*/
int	start_simulation(t_options *opt, t_philo *philo)
{
	int			i;

	i = 0;
	while (i < opt->num_philo)
	{
		if (pthread_create(&opt->t_id[i], NULL, p_lifecycle, &philo[i]))
			return (1);
		i++;
	}
	is_someone_dead(opt, philo);
	i = 0;
	while (i < opt->num_philo)
	{
		if (pthread_join(opt->t_id[i], NULL))
			return (1);
		i++;
	}
	return (0);
}
