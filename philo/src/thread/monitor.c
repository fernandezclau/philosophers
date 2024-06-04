#include "../../include/philosophers.h"

void	*have_eaten(void	*param)
{
	t_options	*opt;
	int		i;
	int		count_meals;

	opt = (t_options *) param;
	count_meals = 0;
	while (count_meals < opt->num_must_eat)
	{
		i = 0;
		while (i < opt->num_philo)
			pthread_mutex_lock(&opt->philos[i++].mtx_eat);
		count_meals++;
		if (opt->dead == 1)
			break;
	}
	print_action(END, opt->philos, opt);
	opt->dead = 1;
	pthread_mutex_unlock(&opt->someone_dead);
	return (NULL);

}
static void	*p_is_dead(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (philo->opt->dead == 0)
	{
		pthread_mutex_lock(&philo->mtx);
		if (get_time() > philo->time_of_death && !philo->is_eating)
		{
			print_action(DIE, philo, philo->opt);
			philo->opt->dead = 1;
			pthread_mutex_unlock(&philo->mtx);
			pthread_mutex_unlock(&philo->opt->someone_dead);
			return ((void *)0);
		}
		pthread_mutex_unlock(&philo->mtx);
		usleep(1000);
	}
	return (NULL);
}

void	*p_lifecycle(void *param)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)param;
	philo->last_meal = get_time();
	philo->time_of_death = philo->last_meal + philo->opt->time_to_die;
	if (pthread_create(&tid, NULL, &p_is_dead, param))
		return (NULL);
	while (philo->opt->dead == 0)
	{
		p_take_forks(philo->opt, philo);
		p_eat(philo->opt, philo);
		p_sleep(philo->opt, philo);
		p_think(philo->opt, philo);
	}
	if (pthread_join(tid, NULL))
		return ((void *)1);
	return (NULL);
}
