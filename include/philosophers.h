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
        int	id;
        int	left_fork;
        int	right_fork;
	int	is_eating;
	int	eat_count;
}               t_philo;

typedef struct s_options
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;
	t_philo	*philo;

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
