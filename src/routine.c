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
	if (philo->died == 1)
	{
		pthread_mutex_unlock (philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock (philo->data->lock);
	return (0);
}

int	count_meals(t_philo *philo)
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
	if (philo->data->num_philo == 1)
		return (NULL);
	while (philo->died != 1)
	{
		if (check_death(philo) || !to_eat (philo))
			return (NULL);
		if (!to_sleep (philo))
			return (NULL);
		if (check_death(philo))
			return (NULL);
		to_think (philo);
		if (!count_meals(philo))
			break ;
	}
	pthread_mutex_lock (philo->data->satisfied);
	philo->satisfied = 1;
	pthread_mutex_unlock (philo->data->satisfied);
	return (NULL);
}
