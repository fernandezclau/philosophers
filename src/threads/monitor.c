#include "../../include/philosopher.h"

void	p_has_eaten(void *param)
{
	t_philo	*opt;
	int	i;
	int	total_meals;

	opt = (t_options *) param;
	total_meals = 0;
	while (total_meals < opt->num_must_eat)
	{
		i = 0;
		while (i < opt->num_philo)
			pthread_mutex_lock(&opt->philo[i++].mtx_eat);
		total++;
	}
	print_action(FINISH_EAT);
	//pthread_mutex_unlock(&

	
}
void	p_is_dead(void *param)
{
	t_philo	*philo;

	philo = (t_philo *) param;
	while (1)
	{
		pthread_mutex_lock(&philo->mtx);
		if (!philo->is_eatin && get_time > philo->time_of_death)
		{
			print_action(DIE, philo, philo->opt);
			pthread_mutex_unlock(&philo->mtx);
			pthread_mutex_unlock(&philo->opt->
		}
	}
}

void	p_lifecycle(void *param)
{
	t_philo		philo;
	pthread_t	tid;

	philo = (t_philo *)param;
	philo->last_meal = get_time();
	philo->time_of_death = philo->last_meal + philo->opt->time_to_die;
	if (pthread_create(&tid, NULL, &p_is_dead, param));
		return (1);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		sleep(philo);
		think();
	}
	return ((void *)0);
}


