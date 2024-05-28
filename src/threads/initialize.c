#include "../../include/philosophers.h"

/*
** DESC: The 'initialize_philos' function initializes all the philosophers
** in the table.
*/
void	initialize_philos(int total, t_options *opt)
{
	int	i;

	i = 0;
	while (i < total)
	{
		opt->philo[i].id = i;
		opt->philo[i].left_fork = i;
		opt->philo[i].right_fork = ((i + 1) % total);
		opt->philo[i].is_eating = 0;
		opt->philo[i].eat_count = 0;
		i++;
	}
}

/*
** DESC: The 'initialize_params' function initializes the params of
** the program.
*/
int	initialize_params(t_options *opt, char **argv)
{
	opt->num_philo = (int) ft_atoi(argv[1]);
	opt->time_to_die = (int) ft_atoi(argv[2]);
	opt->time_to_eat = (int) ft_atoi(argv[3]);
	opt->time_to_sleep = (int) ft_atoi(argv[4]);
	opt->num_must_eat = 0;
	if (argv[5])
		opt->num_must_eat = (int) ft_atoi(argv[5]);
	opt->philo = (t_philo *)malloc(sizeof(*(opt->philo)) * opt->num_philo);
	if (!opt->philo)
		return (0);
	initialize_philos(opt->num_philo, opt);
	return (1);
}
