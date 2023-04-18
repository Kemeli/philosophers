/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:51:02 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/04/19 01:57:07 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	handle_time(t_philo *philo)
{
	long	count_time;
	long	result;

	count_time = get_time();
	result = count_time - philo->data->start_timer;
	return (result);
}

long	get_time(void)
{
	struct timeval	time;
	long			result;

	gettimeofday(&time, NULL);
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}
