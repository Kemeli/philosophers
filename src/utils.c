/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:51:06 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/04/19 01:51:06 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	number;
	int	i;
	int	signal;

	signal = 1;
	number = 0;
	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+'))
		if (nptr[i++] == '-')
			signal *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = (nptr[i] - '0') + (number * 10);
		i++;
	}
	return (number * signal);
}

void	ft_usleep(int sleep)
{
	long	start;
	long	current;

	start = get_time();
	current = get_time();
	sleep = sleep / 1000;
	while (current - start < sleep)
	{
		current = get_time();
		usleep(100);
	}
}

void	*ft_calloc(size_t cnt, size_t n)
{
	void	*ptr;
	int		result;

	if (cnt == 0 || n == 0)
		return (NULL);
	result = (cnt * n);
	if (result / cnt != n)
		return (NULL);
	ptr = ((void *) malloc (cnt * n));
	if (!ptr)
		return (NULL);
	memset(ptr, 0, n * cnt);
	return (ptr);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
