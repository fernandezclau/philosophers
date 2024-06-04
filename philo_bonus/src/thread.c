
#include "../include/philosophers_bonus.h"

void	*p_lifecycle(void *param)
{
	t_philo			*philo;
	t_options		*opt;
	pthread_t		tid;

	philo = (t_philo *)param;
	opt = philo->opt;
	if (pthread_create(&tid, NULL, &p_is_dead, param))
		return (NULL);
	if (philo->id % 2)
		usleep(1500);
	while (!opt->dead)
	{
		p_eat(opt, philo);
		if (opt->end)
			break ;
		p_sleep(opt, philo);
		p_think(opt, philo);
	}
	if (pthread_join(tid, NULL))
		return ((void *)1);
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
static void	p_close(t_options *opt)
{
	if (opt->philos)
		free(opt->philos);
	sem_close(opt->forks);
	sem_close(opt->write);
	sem_close(opt->eating);
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/eating");
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
		if (pthread_create(&(philo[i].t_id), NULL, &p_lifecycle, &(philo[i])))
			return (0);
		philo[i++].last_meal = get_time();
	}
	if (opt->num_must_eat > 0)
		if (pthread_create(&tid, NULL, &have_eaten, (void *)opt))
                return (0);
	if (opt->num_philo == 1)
	{
		pthread_detach(philo[0].t_id);
		while (opt->dead == 0)
			usleep(0);
		return (p_close(opt), 1);
	}
	join_and_close(opt, philo, tid);
	return (1);
}
