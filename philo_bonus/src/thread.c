#include "../include/philosophers.h"

void	free_structs(t_options *opt, t_philo *philo)
{
	if (philo && philo->fork)
		free(philo->fork);
	if (philo)
		free(philo);
	if (opt->t_id)
		free(opt->t_id);
	if (opt)
		free(opt);
}

void	close_semaphores(t_options *opt, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->opt->num_philo)
		pthread_mutex_destroy(&philo->fork[i++]);
	pthread_mutex_destroy(&opt->mtx_write);
	pthread_mutex_destroy(&opt->mtx_eat);
	pthread_mutex_destroy(&opt->mtx_end);
	pthread_mutex_destroy(&opt->mtx_dead);
}

int	start_simulation(t_options *opt, t_philo *philo)
{
	int			i;

	i = 0;
	while (i < opt->num_philo)
	{
		if (pthread_create(&opt->t_id[i], NULL, p_lifecycle, &philo[i]))
			return (1);
		i++;
	}
	is_someone_dead(opt, philo);
	i = 0;
	while (i < opt->num_philo)
	{
		if (pthread_join(opt->t_id[i], NULL))
			return (1);
		i++;
	}	
	return (0);
}




