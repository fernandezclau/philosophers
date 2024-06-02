#include "../../include/philosophers.h"

int	start_simulation(t_options *opt)
{
	int		i;
	pthread_t	tid;
	
	opt->start = get_time();
	if (opt->num_must_eat > 0)
	{
		if (pthread_create(&tid, NULL, &has_eaten(), (void *) opt))
			return (1);
		pthread_detach(tid);
	}
	i = 0;
	while (i < opt->num_philo)
	{
		if (pthread_create(&tid, NULL, &p_lifecycle(), (void *) opt))
			return (1);
		pthread_detach(tid);
		usleep(100);
		i++;
	}
	/*
	i = 0;
	while (i < opt->num_philo)
	{
		if (pthread_join(
	}*/
	return (0);
}


