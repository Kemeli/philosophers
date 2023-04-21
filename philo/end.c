/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:50:23 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/04/19 01:50:23 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_threads(t_philo *philo, pthread_t *threads)
{
	int	i;

	i = -1;
	while (++i < philo->data->num_philo + 1)
		pthread_join (threads[i], NULL);
}

static void	destroy_forks(t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	while (++i < philo->data->num_philo)
		pthread_mutex_destroy(&forks[i]);
}

static void	destroy_mutexes(t_philo *philo)
{
	pthread_mutex_destroy(philo->data->gate);
	free(philo->data->gate);
	pthread_mutex_destroy(philo->data->lock);
	free(philo->data->lock);
	pthread_mutex_destroy(philo->data->monitor);
	free(philo->data->monitor);
	pthread_mutex_destroy(philo->data->satisfied);
	free(philo->data->satisfied);
	pthread_mutex_destroy(philo->data->print);
	free(philo->data->print);
}

void	end(t_philo *philo, pthread_mutex_t *forks, pthread_t *threads)
{
	join_threads(philo, threads);
	destroy_forks(philo, forks);
	destroy_mutexes(philo);
	free (threads);
	free (forks);
	free (philo);
}
