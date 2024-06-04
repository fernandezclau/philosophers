#include "../include/philosophers_bonus.h"

/*
** DESC: The 'p_sleep' function makes a philosopher sleep.
*/
void	p_sleep(t_options *opt, t_philo *philo)
{
	print_action(SLEEP, philo, opt);
	usleep(opt->time_to_sleep * 1000);
}

/*
** DESC: The 'p_eat' function makes a philosopher eat.
*/
void	p_eat(t_options *opt, t_philo *philo)
{
	sem_wait(opt->forks);
	print_action(TAKE_FORK, philo, opt);
	sem_wait(opt->forks);
	print_action(TAKE_FORK, philo, opt);
	sem_wait(opt->eating);
	print_action(EAT, philo, opt);
	philo->last_meal = get_time();
	sem_post(opt->eating);
	usleep(opt->time_to_eat * 1000);
	philo->count_meals++;
	sem_post(opt->forks);
	sem_post(opt->forks);
}

/*
** DESC: The 'p_think' function makes a philosopher think.
*/
void	p_think(t_options *opt, t_philo *philo)
{
	print_action(THINK, philo, opt);
}
