
#include "../include/philosophers_bonus.h"

static void	initializes_semaphores(t_options *opt)
{
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/eating");
	opt->forks = sem_open("/forks", O_CREAT, S_IRWXU, opt->num_philo);
	opt->write = sem_open("/write", O_CREAT, S_IRWXU, 1);
	opt->eating = sem_open("/eating", O_CREAT, S_IRWXU, 1);
}

static int	initialize_philosophers(t_options *opt)
{
	int i;

	opt->philos = (t_philo *)malloc(sizeof(t_philo) * opt->num_philo);
	if (!opt->philos)
		return (0);
	i = 0;
	while (i < opt->num_philo)
	{
		opt->philos[i].id = i;
		opt->philos[i].count_meals = 0;
		opt->philos[i].last_meal = 0;
		opt->philos[i].opt = opt;
		i++;
	}
	return (1);
}

int	initialize_options(t_options *opt, char **argv)
{
	opt->num_philo = ft_atoi(argv[1]);
	if (opt->num_philo > 300)
		return (0);
	opt->time_to_die = ft_atoi(argv[2]);
	opt->time_to_eat = ft_atoi(argv[3]);
	opt->time_to_sleep = ft_atoi(argv[4]);
	opt->num_must_eat = 0;
	opt->end = 0;
	opt->dead = 0;
	opt->num_must_eat = -1;
	if (argv[5])
		opt->num_must_eat = ft_atoi(argv[5]);
	initializes_semaphores(opt);
	return (1);
}

int initialize_params(t_options *opt, char **argv)
{
	if (!initialize_options(opt, argv))
		return (0);
	if (!initialize_philosophers(opt))
		return (0);
	return (1);
}
