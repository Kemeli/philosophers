#include "philo.h"

void	start_threads(t_data *args)
{
	pthread_t philosopher[args->num_philo];
	pthread_mutex_t *forks;
	t_philo *philo;
	t_data *data;
	int	i;

	philo = calloc (args->num_philo, sizeof (t_data));
	data = calloc (1, sizeof (t_data));
	init_forks(args, &forks);
	init_data(data, args);
	init_philo(args, philo, &forks, data);

	i = -1;
	while (++i < args->num_philo)
	{
		pthread_create (&philosopher[i], NULL, routine, &philo[i]);
		usleep(1);
	}
	// monitoring (philo);
	end(philo, forks, philosopher);
}
