
#include "philo.h"

/*
** DESC: The 'p_eat' function simulates the action of eating of a philosopher.
*/
void	*p_eat(t_philo *philo)
{
	print_action(philo, EAT);
	pthread_mutex_lock(&(philo->opt->mtx_eat));
	philo->last_meal = get_time();
	pthread_mutex_unlock(&(philo->opt->mtx_eat));
	usleep(philo->opt->time_to_eat);
	pthread_mutex_lock(&(philo->opt->mtx_eat));
	philo->count_meals++;
	pthread_mutex_unlock(&(philo->opt->mtx_eat));
	return (NULL);
}

/*
** DESC: The 'p_sleep' function simulates the action of sleeping of a 
** philosopher.
*/
void	*p_sleep(t_philo *philo)
{
	print_action(philo, SLEEP);
	usleep(philo->opt->time_to_sleep);
	return (NULL);
}

/*
** DESC: The 'p_think' function simulates the action of thinking of a
** philosopher.
*/
void	*p_think(t_philo *philo)
{
	print_action(philo, THINK);
	return (NULL);
}

/*
** DESC: The 'p_die' function simulates the action of dying of a
** philosopher.
*/
void	*p_die(t_philo *philo, t_options *opt)
{
	pthread_mutex_lock(&(opt->mtx_dead));
	opt->is_someone_dead = true;
	pthread_mutex_unlock(&(opt->mtx_dead));
	print_action(philo, DIE);
	return (NULL);
}
