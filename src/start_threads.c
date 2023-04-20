/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:50:58 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/04/19 01:50:58 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_threads(t_data *args)
{
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	t_philo			*philo;
	t_data			*data;
	int				i;

	threads = ft_calloc (args->num_philo + 1, sizeof (pthread_t));
	philo = ft_calloc (args->num_philo, sizeof (t_philo));
	data = ft_calloc (1, sizeof (t_data));
	init_forks(args, &forks);
	init_data(data, args);
	init_philo(args, philo, &forks, data);
	i = -1;
	while (++i < args->num_philo)
	{
		pthread_create (&threads[i], NULL, routine, &philo[i]);
		usleep(100);
	}
	pthread_create (&threads[i], NULL, monitoring, philo);
	end(philo, forks, threads);
	free (data);
	free (args);
}
