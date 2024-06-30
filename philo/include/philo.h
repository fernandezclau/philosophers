#ifndef PHILO_H
# define PHILO_H

// ........... MACROS ...........
// __________ actions ___________
# define THINK		0
# define EAT		1
# define SLEEP		2
# define DIE		3
# define TAKE_FORK	4
// ___________ errors ___________
# define INIT		5
# define SIM		6
# define ARGS		7
// ___________ forks ____________
# define LEFT_FORK	8
# define RIGHT_FORK	9

// ............ LIBS ............
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>
# include <limits.h>


// .......... STRUCTS ...........
// ----------- FORK ----------
typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
}					t_fork;
// ----------- OPTIONS ----------
typedef struct s_global
{
	int				num_philo;
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	int				num_must_eat;
	bool			is_someone_dead;
	uint64_t		start;
	pthread_t		t_id;
	pthread_mutex_t	mtx_write;
	pthread_mutex_t	mtx_dead;
	pthread_mutex_t	mtx_eat;
}	t_options;
// --------- PHILOSPHER ---------
typedef struct s_philo
{
	t_options		*opt;
	int				id;
	pthread_t		t_id;
	int				count_meals;
	uint64_t			last_meal;
	t_fork			*right_fork;
	t_fork			*left_fork;
	bool			right_taken;
	bool			left_taken;
}	t_philo;


// -------- THREADS & MONITORING ----------
int		start_simulation(t_options *g, t_philo **philos);
int		is_someone_dead(t_philo *philo);
// --------------- ACTIONS ----------------
void	*p_eat(t_philo *philo);
void	*p_sleep(t_philo *philo);
void	*p_think(t_philo *philo);
void	*p_die(t_philo *philo, t_options *opt);
void	finish_eating(int id, t_philo *philo);
void    take_forks(t_philo *philo);
// ---------------- UTILS -----------------
int		initialize_philosophers(t_options *g, t_philo **philos, t_fork **forks);
int		initialize_options(t_options *opt, char **argv);
uint64_t	get_time(void);
int		free_all(t_options *g, t_philo *philo, t_fork *forks);
void	write_timestamp(int start);
int		are_arguments_valid(int argc, char **argv);
long	ft_atoi(char *str);
void	error_msg(int type);
void	print_action(t_philo *philo, int action);
#endif
