/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:10:47 by claferna          #+#    #+#             */
/*   Updated: 2024/06/04 17:11:18 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

static int	do_join(t_options *opt)
{
	int	i;

	i = 0;
	while (i < opt->num_philo)
	{
		if (pthread_join(opt->tids[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	start_simulation(t_options *opt)
{
	int		i;
	void	*philo;

	opt->start = get_time();
	i = 0;
	while (i < opt->num_philo)
	{
		philo = (void *)(&opt->philos[i]);
		if (pthread_create(&opt->tids[i], NULL, &p_lifecycle, philo))
			return (1);
		usleep(100);
		i++;
	}
	if (opt->num_must_eat > 0 && opt->num_philo > 1)
		have_eaten(opt);
	if (opt->num_philo == 1)
	{
		pthread_detach(opt->tids[0]);
		while (opt->dead == 0)
			usleep(0);
		return (0);
	}
	do_join(opt);
	return (0);
}
