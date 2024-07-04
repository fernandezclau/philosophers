#include "philo.h"

static void	take_one_fork(int id, t_philo *philo);

void    take_forks(t_philo *philo)
{
	if (philo->right_fork->id < philo->left_fork->id)
    {
        take_one_fork(RIGHT_FORK, philo);
		if (philo->opt->num_philo > 1)
        	take_one_fork(LEFT_FORK, philo);
    }
    else
    {
        take_one_fork(LEFT_FORK, philo);
		if (philo->opt->num_philo > 1)
        	take_one_fork(RIGHT_FORK, philo);
    }
}

void	finish_eating(int id, t_philo *philo)
{
	t_fork	*fork;
	bool	*status;
	(void) id;

	if (id == LEFT_FORK)
	{
		status = &(philo->right_taken);
		fork = philo->right_fork;
	}
	else if (id == RIGHT_FORK)
	{
		status = &(philo->left_taken);
		fork = philo->left_fork;
	}
	*status = 0;
	pthread_mutex_unlock(&(fork->fork_mutex));
}

static void	take_one_fork(int id, t_philo *philo)
{
	bool	*status;
	t_fork	*fork;

	if (id == LEFT_FORK)
	{
		status = &(philo->left_taken);
		fork = philo->left_fork;
	}
	else if (id == RIGHT_FORK)
	{
		status = &(philo->right_taken);
		fork = philo->right_fork;
	}
	if (is_someone_dead(philo))
		return ;
	if (*status == 0)
	{
		pthread_mutex_lock(&(fork->fork_mutex));
		*status = 1;
		print_action(philo, TAKE_FORK);
	}
}
