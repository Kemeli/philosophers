/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:50:53 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/04/19 01:50:53 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	pthread_mutex_lock (philo->data->lock);
	if (philo->data->dead_philo == 1)
	{
		pthread_mutex_unlock (philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock (philo->data->lock);
	return (0);
}

static int	count_meals(t_philo *philo)
{
	pthread_mutex_lock (philo->data->gate);
	if (philo->meals_num == 1)
	{
		pthread_mutex_unlock (philo->data->gate);
		return (0);
	}
	pthread_mutex_unlock (philo->data->gate);
	return (1);
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (!check_death(philo))
	{
		if (!to_eat (philo))
			return (NULL);
		to_sleep (philo);
		to_think (philo);
		if (!count_meals(philo))
			break ;
	}
	pthread_mutex_lock (philo->data->satisfied);
	philo->satisfied = 1;
	pthread_mutex_unlock (philo->data->satisfied);
	return (NULL);
}
