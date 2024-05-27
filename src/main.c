#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_options	opt;

	if (are_arguments_valid(argc, argv))
	{
		initialize_params(&opt, argv);
		printf("%d", opt.time_to_eat);	
	}
	else
		printf("Argument error");
}
