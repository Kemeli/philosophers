#include "philo.h"

void	monitoring (t_philo *philo)
{
	long current;
	long timer;
	long time2live;
	int i;

	while (1)
	{
		i = 0;
		current = get_time();
		pthread_mutex_lock(philo->data->monitor);
		time2live = philo[i].last_meal + philo->data->time2die;
		pthread_mutex_unlock(philo->data->monitor);
		// printf ("time2live: %ld, current: %ld\n", time2live, current);
		if (current >= time2live)
		{
			timer = handle_time(philo);
			printf ("%ld philo %d died\n", timer, philo[i].id);
			int j = -1;
			while (++j < philo->data->num_philo)
				philo[j].died = 1;
			break ;
		}
		i++;
	}
}
