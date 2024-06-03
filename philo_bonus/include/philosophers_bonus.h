
#ifndef PHILO_H
# define PHILO_H


// ........... MACROS ...........
# define EAT            1
# define SLEEP          2
# define THINK          3
# define TAKE_FORK      4
# define DIE            5
# define END            6

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdint.h>
# include <limits.h>

struct s_options;

typedef	struct			s_philosopher
{
	int					id;
	pthread_t			t_id;
	int					count_meals;
	int					left_fork;
	int					right_fork;
	long long			last_meal;
	struct s_options		*opt;
	
}						t_philo;

typedef struct			s_options
{
	int					num_philo;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	int					num_must_eat;
	int					dead;
	int					end;
	u_int64_t			start;
	sem_t				*eating;
	sem_t				*forks;
	sem_t				*write;
	t_philo				*philos;
}						t_options;

int						initialize_params(t_options *opt, char **argv);
int						start_simulation(t_options *opt);
int	are_arguments_valid(int argc, char **argv);
long						ft_atoi(char *str);
void    print_action(int action, t_philo *philo, t_options *opt);
void	is_someone_dead(t_options *opt, t_philo *philo);
void	p_sleep(t_options *opt, t_philo *philo);
void	p_eat(t_options *opt, t_philo *philo);
void	p_think(t_options *opt, t_philo *philo);
uint64_t	get_time(void);
void	ft_putnbr(int num);
#endif
