/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:14:58 by claferna          #+#    #+#             */
/*   Updated: 2024/06/10 17:37:35 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// ........... MACROS ...........
// __________ actions ___________
# define EAT		1
# define SLEEP		2
# define THINK		3
# define TAKE_FORK	4
# define DIE		5
// ___________ errors ___________
# define INIT		6
# define SIM		7
# define ARGS		8

// ............ LIBS ............
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdint.h>

// .......... STRUCTS ...........
// ----------- OPTIONS ----------
typedef struct s_options
{
	int				num_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				num_must_eat;
	uint64_t		start;
	int				done;
	int				died;
	pthread_t		*t_id;
	pthread_mutex_t	mtx_write;
	pthread_mutex_t	mtx_eat;
	pthread_mutex_t	mtx_end;
	pthread_mutex_t	mtx_dead;
}					t_options;
// --------- PHILOSPHER ---------
typedef struct s_philo
{
	int				id;
	uint64_t		last_meal;
	int				count_eats;
	int				left_fork;
	int				right_fork;
	pthread_mutex_t	*fork;
	t_options		*opt;
}					t_philo;

// -------- THREADS & MONITORING ----------
int			start_simulation(t_options *opt, t_philo *philo);
void		*p_lifecycle(void *arg);
int			meal_checker(t_options *opt, t_philo *philo);
void		is_someone_dead(t_options *opt, t_philo *philo);
void		free_structs(t_options *opt, t_philo *philo);
void		close_mutex(t_options *opt, t_philo *philo);
// --------------- ACTIONS ----------------
int			p_eat(t_philo *philo);
void		p_sleep(t_philo *philo);
void		p_think(t_philo *philo);
int			take_fork(int a, int b, int take_bigger);
// ---------------- UTILS -----------------
int			are_arguments_valid(int argc, char **argv);
int			initialize_params(t_options **opt, t_philo **philo, char **av);
void		print_action(t_philo *philo, int action);
void		error_msg(int type);
int			is_done(t_philo *philo, int n);
int			is_dead(t_philo *philo, int n);
uint64_t	get_time(void);
long		ft_atoi(char *str);
#endif
