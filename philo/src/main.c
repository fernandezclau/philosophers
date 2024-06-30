#include "philo.h"

int	main(int argc, char **argv)
{
	t_options	opt;
	t_philo		*philos;
	t_fork		*forks;

	if (are_arguments_valid(argc, argv))
	{
		if (!initialize_options(&opt, argv))
			return (free_all(&opt, philos, forks), (error_msg(INIT), 1));
		if (!initialize_philosophers(&opt, &philos, &forks))
			return (free_all(&opt, philos, forks), (error_msg(INIT), 1));
		if (!start_simulation(&opt, &philos))
			return (free_all(&opt, philos, forks), (error_msg(SIM), 1));
		return (free_all(&opt, philos, forks));
	}
	else
		return (error_msg(ARGS), 1);
}
