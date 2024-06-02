#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// ........... MACROS ...........
# define EAT		1
# define SLEEP		2
# define THINK		3
# define TAKE_FORK	4
# define DIE		5
# define END		6

// ............ LIBS ............
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

// .......... STRUCTS ...........
struct	s_options;
// --------- PHILOSPHER ---------
typedef struct	s_philosopher
{
	int		id;
	pthread_t		tid;
	int		left_fork;
	int		right_fork;
	int		is_eating;
	uint64_t	time_of_death;
	uint64_t	last_meal;
	int		eat_count;
	pthread_mutex_t	mtx;
	pthread_mutex_t	mtx_eat;
	struct s_options	*opt;
}			t_philo;

// ----------- OPTIONS ----------
typedef struct	s_options
{
	int		num_philo;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	int		num_must_eat;
	uint64_t	start;
	int		dead;
	pthread_t	*tids;
	t_philo		*philos;
	pthread_mutex_t someone_dead;
	pthread_mutex_t	*mtx_forks;
	pthread_mutex_t	mtx_write;
}		t_options;
// ----------- OPTIONS -----------
int	initialize_params(t_options *opt, char **argv);
// ----------- THREADS ------------
int	start_simulation(t_options *opt);
// ............ monitor ...........
void	*p_lifecycle(void *param);
void	*have_eaten(void *param);
// ........... destroy mtx ........
void	destroy_mutexs(t_options *opt);
// ------------ ACTIONS -----------
void	p_eat(t_options *opt, t_philo *philo);
void	p_sleep(t_options *opt, t_philo *philo);
void	p_think(t_options *opt, t_philo *philo);
void	p_take_forks(t_options *opt, t_philo *philo);
// --------- VALIDATION ----------
int	are_arguments_valid(int argc, char **argv);
// ------------- UTILS ------------
void	print_action(int action, t_philo *philo, t_options *opt);
uint64_t	get_time(void);
int	display_error();
long	ft_atoi(char *str);
void	ft_putnbr(int num);
#endif
