
#include "../include/philosophers_bonus.h"

void	*p_thread(void *void_philosopher)
{
	int				i;
	t_philo	*philo;
	t_options			*opt;

	i = 0;
	philo = (t_philo *)void_philosopher;
	opt = philo->opt;
	if (philo->id % 2)
		usleep(15000);
	while (!(opt->dead))
	{
		p_eat(opt, philo);
		if (opt->end)
			break ;
		p_sleep(opt, philo);
		p_think(opt, philo);
		i++;
	}
	return (NULL);
}

static void	join_and_close(t_options *opt, t_philo *philos, pthread_t tid)
{
	int i;

	i = 0;
	while (i < opt->num_philo)
		pthread_join(philos[i++].t_id, NULL);
	if (opt->num_must_eat > 0)
		pthread_join(tid, NULL);
	if (opt->philos)
		free(opt->philos);
	sem_close(opt->forks);
	sem_close(opt->write);
	sem_close(opt->eating);
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/eating");
}
static void *monitor_count(void *param)
{
	t_options *opt;
    t_philo   *philo;
	int		i;

	opt = (t_options*)param;
    philo = opt->philos;
	i = 0;
	while (!(opt->end))
	{
		while (opt->num_must_eat != -1 && i < opt->num_philo && philo[i].count_meals >= opt->num_must_eat)
			i++;
		if (i == opt->num_philo)
			opt->end = 1;
	}
	return ((void *)0);
}

int		start_simulation(t_options *opt)
{
	int				i;
	pthread_t       tid;
	t_philo	*philo;

	philo = opt->philos;
	opt->start = get_time();
	i = 0;
	while (i < opt->num_philo)
	{
		if (pthread_create(&(philo[i].t_id), NULL, p_thread, &(philo[i])))
			return (0);
		philo[i].last_meal = get_time();
		i++;
	}
	if (opt->num_must_eat > 0)
	{
		if (pthread_create(&tid, NULL, &monitor_count, (void *)opt))
                return (0);
	}
	is_someone_dead(opt, opt->philos);
	if (opt->dead == 1 && opt->num_philo == 1)
	{
		while (i < opt->num_philo)
			pthread_join(philo[0].t_id, NULL);
		if (opt->philos)
			free(opt->philos);
		sem_close(opt->forks);
		sem_close(opt->write);
		sem_close(opt->eating);
		sem_unlink("/forks");
		sem_unlink("/write");
		sem_unlink("/eating");
		return (1);
	}
	join_and_close(opt, philo, tid);
	return (1);
}
