/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:50:18 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/04/19 01:50:18 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	grab_forks(t_philo *philo)
{
	if (philo->id % 2 == 0 
			|| (philo->id % 2 != 0 && philo->id == philo->data->num_philo))
		usleep (philo->data->time2eat);
	pthread_mutex_lock(philo->first_fork);
	pthread_mutex_lock(philo->second_fork);
	if (check_death(philo))
		return (0);
	if (!print_actions(philo, FORKS, 1))
		return (0);
	return (1);
}

static void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->second_fork);
	pthread_mutex_unlock(philo->first_fork);
}

int	to_eat(t_philo *philo)
{
	if (!grab_forks (philo))
	{
		unlock_forks(philo);
		return (0);
	}
	pthread_mutex_lock (philo->data->monitor);
	philo->last_meal = get_time();
	pthread_mutex_unlock (philo->data->monitor);
	if (!print_actions(philo, EAT, 0))
	{
		unlock_forks(philo);
		return (0);
	}
	ft_usleep (philo->data->time2eat);
	unlock_forks(philo);
	if (check_death(philo))
		return (0);
	pthread_mutex_lock (philo->data->gate);
	if (philo->meals_num)
		philo->meals_num--;
	pthread_mutex_unlock (philo->data->gate);
	if (check_death(philo))
		return (0);
	return (1);
}

int	to_sleep(t_philo *philo)
{
	if (!print_actions(philo, SLEEP, 0))
		return (0);
	ft_usleep(philo->data->time2sleep);
	if (check_death(philo))
		return (0);
	return (1);
}

int	to_think(t_philo *philo)
{
	if (!print_actions(philo, THINK, 0))
		return (0);
	return (1);
}
