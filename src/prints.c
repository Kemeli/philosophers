/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:50:48 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/04/19 01:50:48 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_messsage(int id, int long timer, char *msg)
{
	printf ("%ld philosopher %d %s\n", timer, id, msg);
}

int	print_actions(t_philo *philo, char *action, int is_fork)
{
	long	timer;

	pthread_mutex_lock(philo->data->print);
	if (check_death(philo))
	{
		pthread_mutex_unlock(philo->data->print);
		return (0);
	}
	timer = get_time() - philo->data->start_timer;
	print_messsage (philo->id, timer, action);
	if (is_fork)
		print_messsage (philo->id, timer, action);
	pthread_mutex_unlock(philo->data->print);
	return (1);
}
