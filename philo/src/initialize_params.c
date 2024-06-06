#include "../include/philosophers.h"

static void	initialize_mutexs(t_options **opt)
{
	pthread_mutex_init(&(*opt)->mtx_write, NULL);
	pthread_mutex_init(&(*opt)->mtx_eat, NULL);
	pthread_mutex_init(&(*opt)->mtx_end, NULL);
	pthread_mutex_init(&(*opt)->mtx_dead, NULL);
}

static int	initialize_options(t_options **opt, char **argv)
{
	(*opt)->num_philo = ft_atoi(argv[1]);
	if ((*opt)->num_philo > 250)
		return (0);
	(*opt)->time_to_die = ft_atoi(argv[2]);
	(*opt)->time_to_eat = ft_atoi(argv[3]);
	(*opt)->time_to_sleep = ft_atoi(argv[4]);
	(*opt)->num_must_eat = -1;
	if (argv[5])
		(*opt)->num_must_eat = ft_atoi(argv[5]);
	(*opt)->start = get_time();
	(*opt)->done = 0;
	(*opt)->died = 0;
	(*opt)->t_id = malloc(sizeof(pthread_t) * (*opt)->num_philo);
	if ((*opt)->t_id == NULL)
		return (0);
	initialize_mutexs(opt);
	return (1);
}

static int	initialize_philosophers(t_philo **philo, t_options *opt)
{
	pthread_mutex_t	*fork;
	int				i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * opt->num_philo);
	if (*philo == NULL)
		return (0);
	fork = malloc(sizeof(pthread_mutex_t) * opt->num_philo);
	if (fork == NULL)
		return (0);
	i = 0;
	while (i < opt->num_philo)
		pthread_mutex_init(&fork[i++], NULL);
	i = 0;
	while (i < opt->num_philo)
	{
		(*philo)[i].id = i;
		(*philo)[i].last_meal = opt->start;
		(*philo)[i].count_eats = 0;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % opt->num_philo;
		(*philo)[i].fork = fork;
		(*philo)[i].opt = opt;
		i++;
	}
	return (1);
}

int	initialize_params(t_options **opt, t_philo **philo, char **av)
{
	*opt = (t_options *)malloc(sizeof(t_options));
	if (*opt == NULL)
		return (0);
	if (!initialize_options(opt, av))
		return (0);
	if (!initialize_philosophers(philo, *opt))
		return (0);
	return (1);
}

