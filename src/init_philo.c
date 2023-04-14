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
		// philo[i].meals_num = args->meals_num;
		philo[i].right_fork = &(*forks)[i];
		philo[i].left_fork = &(*forks)[(i + 1) % args->num_philo];
		philo[i].meals_num = args->meals_num; //deixar só 1
		if (philo[i].id % 2 == 0)
			philo[i].key = 1;
		else
			philo[i].key = 0;
		if (philo[i].id == args->num_philo && philo[i].id % 2 != 0) //se for o ultimo e impar
			philo[i].key = 1;
		i++;
	}
}

void	init_forks(t_data *args, pthread_mutex_t **forks)
{
	int	i;

	*forks = calloc (args->num_philo, sizeof (pthread_mutex_t));
	i = -1;
	while (++i < args->num_philo)
		pthread_mutex_init(&(*forks)[i], NULL);
}

void	init_mutex(t_data *args, pthread_mutex_t **gate, pthread_mutex_t **lock)
{
	int	i;

	*gate = calloc (args->num_philo, sizeof (pthread_mutex_t));
	*lock = calloc (args->num_philo, sizeof (pthread_mutex_t));
	i = -1;
	while (++i < args->num_philo)
	{
		pthread_mutex_init (&(*gate)[i], NULL);
		pthread_mutex_init (&(*lock)[i], NULL);
	}
}

void	init_data(t_data *data, t_data *args,
		pthread_mutex_t **gate, pthread_mutex_t **lock)
{
	long int start;

	start = get_time();
	data->num_philo = args->num_philo;
	data->time2die = args->time2die;
	data->time2eat = args->time2eat;
	data->time2sleep = args->time2sleep;
	data->gate = (*gate);
	data->lock = (*lock);
	data->first_time = start;
	data->start_timer = get_time(); //deixar só 1
}
