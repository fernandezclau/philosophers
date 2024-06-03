
#include "../include/philosophers_bonus.h"

int		main(int argc, char **argv)
{
	t_options	opt;
	
	if (are_arguments_valid(argc, argv))
	{
		if (!initialize_params(&opt, argv))
			return (1);
		if (!start_simulation(&opt))
			return (1);
	}
	else
		printf("Error in arguments\n");
	return (0);
}