#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define THINK	1
# define EAT	2
# define SLEEP	3

# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_options
{
	int		num_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_must_eat;
	t_philosopher	philo;

}		t_options;

typedef struct s_philosopher
{
	int		id;
	pthread_t	thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}		t_philosopher;

// --------------- THREADS----------------
void	initialize_params(t_options *opt, char **argv);
// ............... TIMINGS ...............
int	get_time(void);
// --------- ARGUMENTS VALIDATION --------
int	are_arguments_valid(int argc, char **argv);
// ---------------- UTILS ----------------
long	ft_atoi(char *argument);
#endif
