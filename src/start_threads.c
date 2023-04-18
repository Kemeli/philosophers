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
	pthread_t		*philosopher;
	pthread_mutex_t	*forks;
	t_philo			*philo;
	t_data			*data;
	int				i;

	philosopher = ft_calloc (args->num_philo + 1, sizeof (pthread_t));
	philo = ft_calloc (args->num_philo, sizeof (t_data));
	data = ft_calloc (1, sizeof (t_data));
	init_forks(args, &forks);
	init_data(data, args);
	init_philo(args, philo, &forks, data);
	i = -1;
	while (++i < args->num_philo)
	{
		pthread_create (&philosopher[i], NULL, routine, &philo[i]);
		usleep(1);
	}
	pthread_create (&philosopher[i], NULL, monitoring, philo);
	end(philo, forks, philosopher);
	free (args);
	free (data);
}
