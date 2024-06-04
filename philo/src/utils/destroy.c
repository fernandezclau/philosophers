/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:11:49 by claferna          #+#    #+#             */
/*   Updated: 2024/06/04 17:11:50 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

/*
** The 'destroy_mutex' function destroys all the muxtex used.
*/
void	destroy_mutexs(t_options *opt)
{
	int	i;

	if (opt->mtx_forks)
	{
		i = 0;
		while (i < opt->num_philo)
			pthread_mutex_destroy(&opt->mtx_forks[i++]);
		free(opt->mtx_forks);
	}
	if (opt->tids)
		free(opt->tids);
	if (opt->philos)
	{
		i = 0;
		while (i < opt->num_philo)
		{
			pthread_mutex_destroy(&opt->philos[i].mtx);
			pthread_mutex_destroy(&opt->philos[i++].mtx_eat);
		}
		free(opt->philos);
	}
	pthread_mutex_destroy(&opt->mtx_write);
	pthread_mutex_destroy(&opt->someone_dead);
}
