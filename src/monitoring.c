/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:50:38 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/04/19 01:50:38 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	funeral(t_philo *philo, int i)
{
	long	timer;

	pthread_mutex_lock(philo->data->print);
	timer = handle_time(philo);
	printf ("%ld philo %d died\n", timer, philo[i].id);
	pthread_mutex_unlock(philo->data->print);
	pthread_mutex_lock (philo->data->lock);
	philo->died = 1;
	pthread_mutex_unlock (philo->data->lock);
}

static void	check_life(t_philo *philo)
{
	int		i;
	long	last_meal;

	i = 0;
	while (i < philo->data->num_philo)
	{
		pthread_mutex_lock(philo->data->monitor);
		last_meal = philo[i].last_meal;
		pthread_mutex_unlock(philo->data->monitor);
		if (get_time() >= last_meal + philo->data->time2die + 1)
		{
			funeral(philo, i);
			return ;
		}
		i++;
	}
}

void	*monitoring(void *args)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)args;
	while (!philo->died)
	{
		check_life(philo);
		if (philo->satisfied == 1)
			return (NULL);
	}
	i = -1;
	while (++i < philo->data->num_philo)
	{
		pthread_mutex_lock (philo->data->lock);
		philo[i].died = 1;
		pthread_mutex_unlock (philo->data->lock);
	}
	return (NULL);
}
