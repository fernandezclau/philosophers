#include "../include/philosophers_bonus.h"

void	*p_is_dead(void *param)
{
	t_philo		*philo;

	philo = (t_philo *)param;
	while (!philo->opt->end)
	{
			sem_wait(philo->opt->eating);
			if (get_time() > philo->last_meal + philo->opt->time_to_die)
			{
				print_action(DIE, philo, philo->opt);
				philo->opt->dead = 1;
			}
			sem_post(philo->opt->eating);
			if (philo->opt->dead)
					break ;
	}
	return ((void *)0);
}

void *have_eaten(void *param)
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
		{
			print_action(END, philo, philo->opt);
			opt->end = 1;
		}
		if (opt->dead)
			break ;
	}
	return ((void *)0);
}

