#include "philo.h"

void	init_philo(t_data *args, t_philo *philo,
		pthread_mutex_t **forks, t_data *data)
{
	int	i;

	i = 0;
	while (i < args->num_philo)
	{
		philo[i].data = data;
		philo[i].id = i + 1;
		philo[i].right_fork = &(*forks)[i];
		philo[i].left_fork = &(*forks)[(i + 1) % args->num_philo];
		philo[i].meals_num = args->meals_num;
		philo[i].last_meal = data->start_timer;
		i++;
	}
}

void	init_forks(t_data *args, pthread_mutex_t **forks)
{
	int	i;

	*forks = ft_calloc (args->num_philo, sizeof (pthread_mutex_t));
	i = -1;
	while (++i < args->num_philo)
		pthread_mutex_init(&(*forks)[i], NULL);
}

pthread_mutex_t	*init_mutex()
{
	pthread_mutex_t	*mutex;

	mutex = ft_calloc (1, sizeof (pthread_mutex_t));
	pthread_mutex_init (mutex, NULL);
	return (mutex);
}

void	init_data(t_data *data, t_data *args)
{
	data->num_philo = args->num_philo;
	data->time2die = args->time2die;
	data->time2eat = args->time2eat;
	data->time2sleep = args->time2sleep;
	data->gate = init_mutex();
	data->lock = init_mutex();
	data->monitor = init_mutex();
	data->satisfied = init_mutex();
	data->print = init_mutex();
	data->start_timer = get_time();
}
