/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:12:25 by claferna          #+#    #+#             */
/*   Updated: 2024/07/07 18:12:26 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_number(char argument)
{
	return (argument >= '0' && argument <= '9');
}

static int	is_argument_numeric(char *argument)
{
	int	i;

	i = 0;
	while (argument[i] != '\0')
	{
		if (!is_number(argument[i++]))
			return (0);
	}
	return (1);
}

static int	is_argument_int(char *argument)
{
	return (ft_atoi(argument) <= INT_MAX && ft_atoi(argument) >= INT_MIN);
}

/*
** DESC: The 'are_arguments_valid' function checks if the entered arguments
** are valid.
*/
int	are_arguments_valid(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (0);
	while (i < argc)
	{
		if (!is_argument_numeric(argv[i]))
			return (0);
		if (!is_argument_int(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
