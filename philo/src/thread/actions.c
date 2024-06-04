/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:09:38 by claferna          #+#    #+#             */
/*   Updated: 2024/06/04 17:09:39 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

/*
** DESC: The 'p_sleep' function makes a philosopher sleep.
*/
void	p_sleep(t_options *opt, t_philo *philo)
{
	print_action(SLEEP, philo, opt);
	pthread_mutex_unlock(&opt->mtx_forks[philo->left_fork]);
	pthread_mutex_unlock(&opt->mtx_forks[philo->right_fork]);
	usleep(opt->time_to_sleep * 1000);
}

/*
** DESC: The 'p_eat' function makes a philosopher eat.
*/
void	p_eat(t_options *opt, t_philo *philo)
{
	pthread_mutex_lock(&philo->mtx);
	philo->is_eating = 1;
	philo->last_meal = get_time();
	philo->time_of_death = philo->last_meal + opt->time_to_die;
	print_action(EAT, philo, opt);
	usleep(opt->time_to_eat * 1000);
	philo->eat_count++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mtx);
	pthread_mutex_unlock(&philo->mtx_eat);
}

/*
** DESC: The 'p_think' function makes a philosopher think.
*/
void	p_think(t_options *opt, t_philo *philo)
{
	print_action(THINK, philo, opt);
}

/*
** DESC: The 'take_forks' function makes a philosopher take forks.
*/
void	p_take_forks(t_options *opt, t_philo *philo)
{
	pthread_mutex_lock(&opt->mtx_forks[philo->left_fork]);
	print_action(TAKE_FORK, philo, opt);
	pthread_mutex_lock(&opt->mtx_forks[philo->right_fork]);
	print_action(TAKE_FORK, philo, opt);
}
