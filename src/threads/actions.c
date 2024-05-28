#include "../../include/philosophers.h"

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
void	p_eat()
{
	print_action(EAT, philo, opt);
}

/*
** DESC: The 'p_think' function makes a philosopher think.
*/
void	p_think()
{
	print_action(THINK, philo, opt);
}

/*
** DESC: The 'take_forks' function makes a philosopher take forks.
*/
void	take_forks(t_options *opt, t_philo *philo)
{
	print_action(TAKE_FORKS, philo, opt);
}
