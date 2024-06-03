#include "../include/philosophers_bonus.h"

void	is_someone_dead(t_options *opt, t_philo *philo)
{
	int i;

	while (!(opt->end))
	{
		i = -1;
		while (++i < opt->num_philo && !(opt->dead))
		{
			sem_wait(opt->eating);
			if (get_time() - philo[i].last_meal > opt->time_to_die)
			{
				print_action(DIE, philo, opt);
				opt->dead = 1;
			}
			sem_post(opt->eating);
			usleep(100);
		}
		if (opt->dead)
			break ;
	}
}

