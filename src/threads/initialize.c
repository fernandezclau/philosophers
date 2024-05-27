#include "../../include/philosophers.h"

/*
** DESC: The 'initialize_params' function initializes the params of
** the program.
*/
void	initialize_params(t_options *opt, char **argv)
{
	opt->num_philo = (int) ft_atoi(argv[1]);
	opt->time_to_die = (int) ft_atoi(argv[2]);
	opt->time_to_eat = (int) ft_atoi(argv[3]);
	opt->time_to_sleep = (int) ft_atoi(argv[4]);
	opt->num_must_eat = 0;
	if (argv[5])
		opt->num_must_eat = (int) ft_atoi(argv[5]);
}
