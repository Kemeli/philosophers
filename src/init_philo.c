#include "philo.h"

void	init_args(t_args *args, t_args **phil_args, pthread_mutex_t **forks)
{
	int i = 0;
	while (i < args->num_philo)
	{
		(*phil_args)[i].id = i + 1;
		(*phil_args)[i].num_philo = args->num_philo;
		(*phil_args)[i].time2die = args->time2die;
		(*phil_args)[i].time2eat = args->time2eat;
		(*phil_args)[i].time2sleep = args->time2sleep;
		(*phil_args)[i].right_fork = &(*forks)[i];
		(*phil_args)[i].left_fork = &(*forks)[(i + 1) % args->num_philo];
		gettimeofday(&(*phil_args)[i].first_time, NULL);
		i++;
	}
}

void	init_forks(t_args *args, pthread_mutex_t **forks)
{
	int	i;

	*forks = calloc (args->num_philo, sizeof (pthread_mutex_t));
	i = -1;
	while (++i < args->num_philo)
		pthread_mutex_init(&(*forks)[i], NULL);
}

void	start_threads(t_args *args)
{
	pthread_t Philosopher[args->num_philo];
	pthread_mutex_t *forks;
	t_args *phil_args = calloc (args->num_philo, sizeof (t_args));
	int	i;

	init_forks(args, &forks);

	init_args(args, &phil_args, &forks);

    i = -1;
	while (++i < args->num_philo)
		pthread_create (&Philosopher[i], NULL, routine, &phil_args[i]);
	i = -1;
	while (++i < args->num_philo)
		pthread_join (Philosopher[i], NULL);
	i = -1;
	while (++i < args->num_philo)
		pthread_mutex_destroy(&forks[i]);
	i = 0;
	while (++i < args->num_philo)
		free (phil_args);
}
