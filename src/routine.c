#include "philo.h"

int	check_death(t_philo *philo)
{
	pthread_mutex_lock (philo->data->lock);
	if (philo->died == 1)
	{
		pthread_mutex_unlock (philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock (philo->data->lock);
	return (0);
}

void	*routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	if (philo->data->num_philo == 1)
		return (NULL);
	// while (philo->died != 1 || ++count > philo->meals_num || philo->meals_num == 0)
	while (philo->died != 1)
	{
		if (check_death(philo))
			return (NULL);
		to_eat (philo);
		if (check_death(philo))
			return (NULL);
		to_sleep (philo);
		if (check_death(philo))
			return (NULL);
		to_think (philo);

		pthread_mutex_lock (philo->data->gate);
		if (philo->meals_num == 1)
			break ;
		pthread_mutex_unlock (philo->data->gate);
	}
	pthread_mutex_lock (philo->data->satisfied);
	philo->satisfied = 1;
	pthread_mutex_unlock (philo->data->satisfied);
	return (NULL);
}
