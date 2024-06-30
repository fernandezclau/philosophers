#include "../../include/philosophers.h"

static void    write_timestamp(int start)
{
        int     timestamp;

        timestamp = get_time() - start;
        printf("%u\t", timestamp);
}

static void    write_action(int action)
{
    if (action == EAT)
        printf(" is eating\n");
    else if (action == SLEEP)
        printf(" is sleeping\n");
    else if (action == THINK)
        printf(" is thinking\n");
    else if (action == TAKE_FORK)
        printf(" has taken a fork\n");
	else
		printf(" died\n");
}

void	print_action(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->opt->mtx_write);
	if (action == DIE)
	{
		write_timestamp(philo->opt->start);
		printf("%d", philo->id + 1);
		write_action(action);	
	}
	if (!is_dead(philo, 0) && !is_done(philo, 0))
	{
		write_timestamp(philo->opt->start);
		printf("%d", philo->id + 1);
		write_action(action);	
	}
	pthread_mutex_unlock(&philo->opt->mtx_write);
}

int	is_dead(t_philo *philo, int is_dead)
{
	pthread_mutex_lock(&philo->opt->mtx_dead);
	if (is_dead)
		philo->opt->died = 1;
	if (philo->opt->died)
	{
		pthread_mutex_unlock(&philo->opt->mtx_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->opt->mtx_dead);
	return (0);
}

int	is_done(t_philo *philo, int is_dead)
{
	pthread_mutex_lock(&philo->opt->mtx_end);
	if (is_dead)
		philo->opt->done = 1;
	if (philo->opt->done)
	{
		pthread_mutex_unlock(&philo->opt->mtx_end);
		return (1);
	}
	pthread_mutex_unlock(&philo->opt->mtx_end);
	return (0);
}