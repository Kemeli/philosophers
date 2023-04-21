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

static void	funeral(t_philo *philo)
{
	print_actions(philo, "died", 0);
	pthread_mutex_lock (philo->data->lock);
	philo->data->dead_philo = 1;
	pthread_mutex_unlock (philo->data->lock);
}

void	*monitoring(void *args)
{
	t_philo	*philo;
	int	i;
	long	last_meal;

	philo = (t_philo *)args;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(philo->data->monitor);
		last_meal = philo[i].last_meal;
		pthread_mutex_unlock(philo->data->monitor);
		if (get_time() >= last_meal + philo->data->time2die)
		{
			funeral(&philo[i]);
			break ;
		}
		i++;
		if (i == philo->data->num_philo)
			i = 0;
		if (philo->satisfied == 1 || philo->data->dead_philo == 1)
			break ;
		usleep(3000);
	}
	return (NULL);
}
