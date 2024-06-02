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

typedef struct s_philosopher
{
        pthread_t		tid;
	int			id;
        int			left_fork;
        int			right_fork;
	int			is_eating;
	int			eat_count;
	uint64_t		time_of_death;
	pthread_mutex_t		mtx;
	struct s_options	opt;
}               t_philo;

typedef struct s_options
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;
	pthread_mutex_t	*mtx_forks;
	pthread_mutex_t	*mtx;
	pthread_mutex_t	*mtx_write;
	t_philo	*philos;

}		t_options;

// --------------- THREADS----------------
int	initialize_params(t_options *opt, char **argv);
// ............... TIMINGS ...............
int	get_time(void);
// --------- ARGUMENTS VALIDATION --------
int	are_arguments_valid(int argc, char **argv);
// ---------------- UTILS ----------------
long	ft_atoi(char *argument);
#endif
