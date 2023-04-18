#include "philo.h"

void	join_threads(t_philo *philo, pthread_t *philosopher)
{
	int i;

	i = -1;
	while (++i < philo->data->num_philo + 1)
		pthread_join (philosopher[i], NULL);
}

void	destroy_forks(t_philo *philo, pthread_mutex_t *forks)
{
	int i;

	i = -1;
	while (++i < philo->data->num_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		// free (&forks[i]);
	}
}

void	destroy_mutexes(t_philo *philo)
{
	pthread_mutex_destroy(philo->data->gate);
	free(philo->data->gate);
	pthread_mutex_destroy(philo->data->lock);
	free(philo->data->lock);
	pthread_mutex_destroy(philo->data->monitor);
	free(philo->data->monitor);
	pthread_mutex_destroy(philo->data->satisfied);
	free(philo->data->satisfied);
	pthread_mutex_destroy(philo->data->print);
	free(philo->data->print);
}

void	end(t_philo *philo, pthread_mutex_t *forks, pthread_t *philosopher)
{
	join_threads(philo, philosopher);
	destroy_forks(philo, forks);
	destroy_mutexes(philo);
	free (philosopher);
	free (forks);
	free (philo);
	// printf("TESTE\n");
}
