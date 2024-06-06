#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_options	*opt;
	t_philo		*philo;

	if (are_arguments_valid(argc, argv))
	{
		if (!initialize_params(&opt, &philo, argv))
			return (free_structs(opt, philo), error_msg(INIT), 1);
		if (start_simulation(opt, philo))
			return (destroy_mutexes(opt, philo), free_structs(opt, philo), \
			error_msg(-1), 1);
		return (destroy_mutexes(opt, philo), free_structs(opt, philo), 0);
	}
	else
		return (error_msg(ARGS), 1);
}

