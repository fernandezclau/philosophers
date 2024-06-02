#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_options	opt;

	if (are_arguments_valid(argc, argv))
	{
		if (!initialize_params(&opt, argv))
		{
			destroy_mutexs(&opt);
			return (1);
		}
		if (start_simulation(&opt))
		{
			destroy_mutexs(&opt);
			return (1);
		}
		destroy_mutexs(&opt);
		return (0);
	}
	else
		printf("Argument error");
}
