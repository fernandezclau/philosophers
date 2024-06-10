/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:27:53 by claferna          #+#    #+#             */
/*   Updated: 2024/06/10 17:37:53 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (close_mutex(opt, philo), free_structs(opt, philo), \
			error_msg(SIM), 1);
		return (close_mutex(opt, philo), free_structs(opt, philo), 0);
	}
	else
		return (error_msg(ARGS), 1);
}
