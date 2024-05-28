#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_options	opt;

	if (are_arguments_valid(argc, argv))
	{
		initialize_params(&opt, argv);
		int i = 0;

		while(i < opt.num_philo)
		      {	
		printf("Id %d\n", opt.philo[i].id);
		printf("left_fork %d\n", opt.philo[i].left_fork);
		printf("right_fork %d\n", opt.philo[i].right_fork);
		printf("Is_eating %d\n", opt.philo[i].is_eating);
		printf("Eat count %d\n", opt.philo[i++].eat_count);
		     	}
	}
	else
		printf("Argument error");
}
