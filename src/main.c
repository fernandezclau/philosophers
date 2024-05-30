/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:03:36 by claferna          #+#    #+#             */
/*   Updated: 2024/05/30 17:12:42 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_options	opt;
	int			i;

	if (are_arguments_valid(argc, argv))
	{
		initialize_params(&opt, argv);
		i = 0;
		while (i < opt.num_philo)
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
