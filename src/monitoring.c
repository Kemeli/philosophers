#include "philo.h"

void	monitoring (t_philo *philo)
{
	int	is_dead;
	int	last_meal;
	int i;
	pthread_mutex_t lock;
	pthread_mutex_init(&lock, NULL);

	is_dead = 0;
	while (!is_dead)
	{
		i = 0;
		while (i < philo->data->num_philo && !is_dead)
		{
			pthread_mutex_lock(&lock);
			last_meal = philo[i].last_meal;
			pthread_mutex_unlock(&lock);
			if (get_time() >= last_meal + philo->data->time2die)
			{
				// printf ("\tphilosopher %d died\n\n", philo[i].id);
				pthread_mutex_lock(&lock);
				is_dead = 1;
				pthread_mutex_unlock(&lock);
			}
			i++;
		}
	}
}