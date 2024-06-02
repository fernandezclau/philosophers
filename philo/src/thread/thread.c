#include "../../include/philosophers.h"

static int	do_join(t_options *opt, pthread_t tid)
{
	int	i;

	i = 0;
	while (i < opt->num_philo)
	{
		if (pthread_join(opt->tids[i], NULL))
			return (1);
		i++;
	}
	if (opt->num_must_eat > 0)
	{
		if (pthread_join(tid, NULL))
			return (1);
	}
	return (0);
}

int	start_simulation(t_options *opt)
{
	int		i;
	pthread_t	tid;
	void		*philo;

	opt->start = get_time();
	if (opt->num_must_eat > 0)
	{
		if (pthread_create(&tid, NULL, &have_eaten, (void *) opt))
			return (1);
	}
	i = 0;
	while (i < opt->num_philo)
	{
		philo = (void *)(&opt->philos[i]);
		if (pthread_create(&opt->tids[i], NULL, &p_lifecycle, philo))
			return (1);
		usleep(100);
		i++;
	}
	if (opt->num_philo == 1)
	{
		pthread_detach(opt->tids[0]);
		while (opt->dead == 0)
			usleep(0);
		return (0);
	}
	do_join(opt, tid); 
	return (0);
}
