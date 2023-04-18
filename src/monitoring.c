#include "philo.h"

void	funeral(t_philo *philo, int i)
{
	long timer;

	pthread_mutex_lock(philo->data->monitor);
	timer = handle_time(philo);
	printf ("%ld philo %d died\n", timer, philo[i].id);
	philo->died = 1;
	pthread_mutex_unlock(philo->data->monitor);
}

void	check_life(t_philo *philo)
{
	int	i;
	long last_meal;

	i = 0;
	while (i < philo->data->num_philo)
	{
		pthread_mutex_lock(philo->data->monitor);
		last_meal = philo[i].last_meal;
		pthread_mutex_unlock(philo->data->monitor);
		if (get_time() >= last_meal + philo->data->time2die)
		{
			funeral(philo, i);
			return ;
		}
		i++;
	}
}

void	*monitoring (void *args)
{
	int i;
	t_philo *philo;

	philo = (t_philo *)args;
	while (!philo->died)
	{
		check_life(philo);
		if (philo->satisfied == 1)
			return NULL ;
	}
	i = -1;
	while (++i < philo->data->num_philo)
		philo[i].died = 1;
	// printf ("TESTE\n");
	return NULL ;
}
