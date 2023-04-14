#include "philo.h"

// void	free_stuff(t_philo *philo, pthread_mutex_t *forks)
// {
//	 int i;

//	 i = 0;
//	 while (++i < phil_philophilo->num_philo)
// 	{
// 		if (forks)
// 			free (forks);
// 		if (phil_philo)
// 			free (phil_philo);
// 		// if (gate)
// 		// 	free (&gate[i]);
// 	}
// }

void	join_threads(t_philo *philo, pthread_t *philosopher)
{
	int i;

	i = -1;
	while (++i < philo->data->num_philo)
		pthread_join (philosopher[i], NULL);
}

void	destroy_mutexes (t_philo *philo, pthread_mutex_t *forks)
{
	int i;

	i = -1;
	while (++i < philo->data->num_philo)
		pthread_mutex_destroy(&forks[i]);
}

void	end(t_philo *philo, pthread_mutex_t *forks, pthread_t *philosopher)
{
	join_threads(philo, philosopher);
	destroy_mutexes(philo, forks);
	// free_stuff();
}
