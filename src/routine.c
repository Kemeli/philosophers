#include "philo.h"

void	*routine(void *args)
{
	t_philo *philo;
	// int count;

	// count = 1;
	philo = (t_philo *)args;
	if (philo->data->num_philo == 1)
		return (NULL);
	// while (philo->died != 1 || ++count > philo->meals_num || philo->meals_num == 0)
	while (philo->died != 1)
	{
		if (philo->died == 1)
			return (NULL);
		to_eat (philo);
		// printf ("TESTE\n");
		if (philo->died == 1)
			return (NULL);
		to_sleep (philo);
		if (philo->died == 1)
			return (NULL);
		to_think (philo);
		if (philo->meals_num == 1)
			break ;
	}
	pthread_mutex_lock (philo->data->satisfied);
	philo->satisfied = 1;
	pthread_mutex_unlock (philo->data->satisfied);
	return (NULL);
}
