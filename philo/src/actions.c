/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:18:43 by claferna          #+#    #+#             */
/*   Updated: 2024/06/10 17:53:32 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	take_fork(int a, int b, int take_bigger);

/*
** DESC: The 'p_think' function simulates the action of thinking of a
** philosopher.
*/
void	p_think(t_philo *philo)
{
	print_action(philo, THINK);
}

/*
** DESC: The 'p_sleep' function simulates the action of sleeping of a 
** philosopher.
*/
void	p_sleep(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork[take_fork(philo->left_fork, \
			philo->right_fork, 1)]);
	pthread_mutex_unlock(&philo->fork[take_fork(philo->left_fork, \
			philo->right_fork, 0)]);
	print_action(philo, SLEEP);
	usleep(philo->opt->time_to_sleep * 1000);
}

/*
** DESC: The 'p_eat' function simulates the action of eating of a philosopher.
*/
int	p_eat(t_philo *p)
{
	pthread_mutex_lock(&p->fork[take_fork(p->left_fork, p->right_fork, 0)]);
	print_action(p, TAKE_FORK);
	if (p->left_fork == p->right_fork)
	{
		pthread_mutex_unlock(&p->fork[take_fork(p->left_fork, \
			p->right_fork, 0)]);
		return (1);
	}
	pthread_mutex_lock(&p->fork[take_fork(p->left_fork, p->right_fork, 1)]);
	print_action(p, TAKE_FORK);
	pthread_mutex_lock(&p->opt->mtx_eat);
	p->last_meal = get_time();
	p->count_eats++;
	pthread_mutex_unlock(&p->opt->mtx_eat);
	print_action(p, EAT);
	usleep(p->opt->time_to_eat * 1000);
	return (0);
}

/*
** DESC: The 'take_fork' funtcion selects the appropiate fork depending the
** situation.
*/
int	take_fork(int a, int b, int take_bigger)
{
	if (take_bigger)
	{
		if (a > b)
			return (a);
		return (b);
	}
	if (a < b)
		return (a);
	return (b);
}
